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
    for(auto itr = copy.begin(); itr != copy.end();) {
        if(cls != itr->getType()){
            itr = copy.erase(itr);
        }else{
            itr++;
        }
    }
    if(copy.empty()) copy = std::vector<DetectedCard>(obj);
    int maxLength = 0;
    int maxSimilarIndex = 0;
    for(int i =0;i<copy.size();++i){
        QString realDescr = removeBold(copy[i].getDescription());
        QString sub = Util::maxSubstring(descr,realDescr);
        if(sub.length() > maxLength){
            maxLength = sub.length();
            maxSimilarIndex = i;
        }
    }
//    qDebug() << maxLength;
//    qDebug() <<descr.length();
    return copy[maxSimilarIndex];
}


