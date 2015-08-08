#ifndef REALCARDEXTRACTOR_H
#define REALCARDEXTRACTOR_H
#include "cards/recognizedcard.h"
#include "cards/detectedcard.h"
#include "util.h"
#include <QDebug>
class RealCardExtractor
{
    QString removeBold(QString str);
public:
    RealCardExtractor();
    DetectedCard  getRealCard(const std::vector<DetectedCard>&,const RecognizedCard& card);
};

#endif // REALCARDEXTRACTOR_H
