#ifndef IMAGEEXTRACTOR_H
#define IMAGEEXTRACTOR_H
#include "cards/card.h"
#include "cards/imagecard.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
#include <QString>
class ImageExtractor
{
    tesseract::TessBaseAPI *api;
    QString deleteAllLetters(const QString& str);
public:
    ImageExtractor();
    Card getExtractedCard(const ImageCard&);
    QString extract(const cv::Mat& data);
    ~ImageExtractor();
};

#endif // IMAGEEXTRACTOR_H
