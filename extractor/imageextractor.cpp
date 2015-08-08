#include "imageextractor.h"

QString ImageExtractor::deleteAllLetters(const QString &str)
{
    QString result;
    for(int i = 0;i<str.length();++i){
        if(str[i].isDigit()){
            result += str[i];
        }
    }
    return result;
}

ImageExtractor::ImageExtractor()
{
    api = new tesseract::TessBaseAPI();
    api->Init(NULL, "eng");
}

Card ImageExtractor::getExtractedCard(const ImageCard &img)
{
    QString description = extract(img.getDescription());
    QString crdcls = extract(img.getCrdclass());
    QString strAttack = extract(img.getAttack());
    QString strHealth = extract(img.getHealth());
    QString strMana = extract(img.getMana());
    return Card(strHealth,strMana,strAttack,description,crdcls);
}

QString ImageExtractor::extract(const cv::Mat &data)
{
    api->SetImage((uchar*)data.data,data.cols,data.rows,1,data.cols);
    return QString(api->GetUTF8Text());
}

ImageExtractor::~ImageExtractor()
{
    api->End();
}
