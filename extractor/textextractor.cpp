#include "textextractor.h"

std::vector<QString> TextExtractor::CLASSES = {"Beast","Demon","Dragon","Mech","Murloc","Pirate","Totem"};
std::vector<QString> TextExtractor::MECHANICS = {"Battlecry","Choose","Combo","Deathrattle","Divine Shield","Taunt",
                                                 "Enrage","Charge","Windfury","Overload","Stealth"};
QString TextExtractor::correctClass(QString cls)
{
    QString corrected = cls.simplified();
    if(corrected.length() <= 2) return "Minion";
    int maxSubLen = 0;
    QString maxSimilar = "";
    for(QString str:CLASSES){
        int len = Util::maxSubstring(str,corrected).length();
        if ( len > maxSubLen){
            maxSubLen = len;
            maxSimilar = str;
        }
    }
    return maxSimilar;
}

std::size_t TextExtractor::recognizeMana(QString m)
{
    QString result = "";
    for(int i = 0;i<m.length();++i){
        if(m[i].isDigit()){
            result += m[i];
        }
    }
    return result.toInt();
}

std::size_t TextExtractor::recognizeHealth(QString h)
{
    QString result = "";
    for(int i = 0;i<h.length();++i){
        if(h[i].isDigit()){
            result += h[i];
        }
    }
    return result.toInt();
}

std::size_t TextExtractor::recognizeAttack(QString a)
{
    QString result = "";
    for(int i = 0;i<a.length();++i){
        if(a[i].isDigit()){
            result += a[i];
        }
    }
    return result.toInt();
}

QString TextExtractor::correctDescription(QString descr)
{
    QString corrected = descr.simplified();
    return corrected;
}

std::vector<QString> TextExtractor::getMechanics(QString descr)
{
    std::vector<QString> result;
    for(int i =0; i< MECHANICS.size();++i){
        QString mech = MECHANICS[i];
        int mechLen = mech.length();
        int border = 2;
        if(mechLen > 5){
            border = mechLen / 3;
        }
        QString maxSubString = Util::maxSubstring(descr,mech);

        if (mech[0] == maxSubString[0] && mechLen - maxSubString.length() < border){
            result.push_back(mech);
        }
        if(result.size() >= 5) break;
    }
    return result;
}

TextExtractor::TextExtractor()
{
}

RecognizedCard TextExtractor::getExtractedCard(const Card &c)
{
    std::size_t health = recognizeHealth(c.getHealth());
    std::size_t mana = recognizeMana(c.getMana());
    std::size_t attack = recognizeAttack(c.getAttack());
    QString cls = correctClass(c.getCls());
    QString descr = correctDescription(c.getDescription());
    std::vector<QString> mechs(getMechanics(descr));

    return RecognizedCard(health,mana,attack,descr,cls,mechs);
}
