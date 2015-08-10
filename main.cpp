#include "screencontroller/controller.h"
#include "dbconnector/dbconnector.h"
#include <QPixmap>
#include <QApplication>
#include <QDebug>
#include <QScreen>
#include "cards/imagecard.h"
#include "extractor/imageextractor.h"
#include "extractor/textextractor.h"
#include "extractor/realcardextractor.h"
#include "extractor/screenshotextractor.h"
#include "cards/card.h"
#include "cards/recognizedcard.h"
#include "util.h"
#include "mongo/bson/bsonobj.h"
#include <QFile>
#include <locale.h>
int main(int argc, char *argv[])
{

//    cv::Mat basicImage=cv::imread("nocard.png",1);
//    ScreenShotExtractor scr;
//    ImageCard img = scr.extractCardFromScreen(basicImage);
//    if(!img.isEmpty()){
//        img.saveDescription("","descr.png");
//        img.saveHealth("","health.png");
//        img.saveAttack("","attack.png");
//        img.saveMana("","mana.png");
//        ImageExtractor extr;
//        TextExtractor textExtr;
//        RealCardExtractor realExtr;
//        Card card = extr.getExtractedCard(scr.extractCardFromScreen(basicImage));
//        RecognizedCard crd = textExtr.getExtractedCard(card);

//        DBConnector db(QString("localhost"));
//        db.connect();
//        std::vector<DetectedCard> result = db.getCardsByStats(crd.getMana(),crd.getHealth(),crd.getAttack());
//        DetectedCard real = realExtr.getRealCard(result,crd);
//        qDebug() << real.getName();
//    }
    QApplication a(argc, argv);
    Controller w;
//    QScreen *screen = QGuiApplication::primaryScreen();
//    if (screen){
//        QPixmap originalPixmap = screen->grabWindow(0);
//        QFile file("screen.png");
//        file.open(QIODevice::WriteOnly);
//        originalPixmap.save(&file, "PNG");
//    }
    w.show();

    return a.exec();
}
