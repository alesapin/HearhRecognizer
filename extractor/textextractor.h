#ifndef TEXTEXTRACTOR_H
#define TEXTEXTRACTOR_H
#include "cards/recognizedcard.h"
#include "cards/card.h"
#include <vector>
#include "util.h"
#include <QDebug>
class TextExtractor
{
    QString correctClass(QString cls);
    std::size_t recognizeMana(QString m);
    std::size_t recognizeHealth(QString h);
    std::size_t recognizeAttack(QString a);
    QString correctDescription(QString descr);
    std::vector<QString> getMechanics(QString descr);
public:
    TextExtractor();
    RecognizedCard getExtractedCard(const Card& c);
    static std::vector<QString> CLASSES;
    static std::vector<QString> MECHANICS;
};

#endif // TEXTEXTRACTOR_H
