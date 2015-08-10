#include "realcardextractor.h"

QString RealCardExtractor::removeBold(QString str)
{
    QString result = "";
    result = str.replace("<b>","");
    result = result.replace("</b>","");
    result = result.replace("<i>","");
    result = result.replace("</i>","");
    return result;
}

RealCardExtractor::RealCardExtractor()
{
}

DetectedCard RealCardExtractor::getRealCard(const std::vector<DetectedCard> &obj, const RecognizedCard &card)
{
    std::vector<DetectedCard> copy(obj);
    if(copy.empty()){
        return DetectedCard();
    }
    QString descr = card.getDescription();
    QString cls = card.getCls();
    std::vector<QString> mechs = card.getMechanics();
    for(auto itr = copy.begin(); itr != copy.end();) {
        if(cls != itr->getType()){
            itr = copy.erase(itr);
        }else{
            itr++;
        }
    }
    if(copy.empty()) copy = std::vector<DetectedCard>(obj);
    int minDiff = 10000;
    int maxSimilarIndex = 0;
   // qDebug() << descr;
    for(int i =0;i<copy.size();++i){
        QString realDescr = removeBold(copy[i].getDescription());
        QString sub = Util::maxSubstring(descr,realDescr);
        qDebug() << "REAL: "<< realDescr << " sub: " << sub;
        if(std::abs(sub.length() - realDescr.length()) < minDiff  && sub.length() > 2){
            minDiff = std::abs(sub.length() - realDescr.length()) ;
            maxSimilarIndex = i;
        }
    }
//    qDebug() << maxLength;
//    qDebug() <<descr.length();
    return copy[maxSimilarIndex];
}


