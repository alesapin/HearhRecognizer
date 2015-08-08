#include "Main.h"
#include "dbconnector/dbconnector.h"

#include <QApplication>
#include <QDebug>
#include "cards/imagecard.h"
#include "extractor/imageextractor.h"
#include "extractor/textextractor.h"
#include "extractor/realcardextractor.h"
#include "cards/card.h"
#include "cards/recognizedcard.h"
#include "util.h"
#include "mongo/bson/bsonobj.h"

int main(int argc, char *argv[])
{

    ImageCard img("croc.png");
    img.saveDescription("","descr.png");
    img.saveHealth("","health.png");
    ImageExtractor extr;
    TextExtractor textExtr;
    RealCardExtractor realExtr;
    Card card = extr.getExtractedCard(img);
    RecognizedCard crd = textExtr.getExtractedCard(card);
    qDebug() << crd.getMana();
    qDebug() << crd.getAttack();
    qDebug() << crd.getHealth();
    DBConnector db(QString("localhost"));
    db.connect();
    std::vector<DetectedCard> result = db.getCardsByStats(crd.getMana(),crd.getHealth(),crd.getAttack());
    DetectedCard real = realExtr.getRealCard(result,crd);
    qDebug() << real.getName();
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
