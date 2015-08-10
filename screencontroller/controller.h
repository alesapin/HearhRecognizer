#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QTimer>
#include <QFile>
#include <QScreen>
#include <QApplication>
#include "extractor/screenshotextractor.h"
#include "extractor/imageextractor.h"
#include "extractor/textextractor.h"
#include "extractor/realcardextractor.h"
#include "cards/imagecard.h"
#include "cards/card.h"
#include "cards/recognizedcard.h"
#include "cards/detectedcard.h"
#include "dbconnector/dbconnector.h"
#include <QTextStream>
#include "unistd.h"
class Controller: public QWidget
{
    Q_OBJECT
    QTimer * timer;
    int screenNum;
    QScreen* screen;
    ScreenShotExtractor* firstStage;
    ImageExtractor* secondStage;
    TextExtractor* thirdStage;
    RealCardExtractor* fourthStage;
    QFile* log;
    QTextStream* stream;
    DBConnector* connector;
    void writeToLog(QString name);
    cv::Mat QImageToCvMat(const QImage &inImage, bool inCloneImageData = true);
public slots:
    void takeScreenshot();
public:
    Controller();
    ~Controller();
    static const QString LOG_PATH;
};

#endif // CONTROLLER_H
