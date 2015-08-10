#include "controller.h"

const QString Controller::LOG_PATH = "game.log";
void Controller::writeToLog(QString name)
{
    (*stream) << name + '\n';
}

cv::Mat Controller::QImageToCvMat(const QImage &inImage, bool inCloneImageData)
{
    switch ( inImage.format() )
         {
            // 8-bit, 4 channel
            case QImage::Format_RGB32:
            {
               cv::Mat  mat( inImage.height(), inImage.width(), CV_8UC4, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine() );

               return (inCloneImageData ? mat.clone() : mat);
            }

            // 8-bit, 3 channel
            case QImage::Format_RGB888:
            {
               if ( !inCloneImageData )
                  qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";

               QImage   swapped = inImage.rgbSwapped();

               return cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
            }

            // 8-bit, 1 channel
            case QImage::Format_Indexed8:
            {
               cv::Mat  mat( inImage.height(), inImage.width(), CV_8UC1, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine() );

               return (inCloneImageData ? mat.clone() : mat);
            }

            default:
               qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
               break;
         }

         return cv::Mat();
}

void Controller::takeScreenshot()
{
    QImage image = screen->grabWindow(0).toImage();
    cv::Mat mat = QImageToCvMat(image,true);
    cv::imwrite("scrn.png",mat);
    ImageCard img = firstStage->extractCardFromScreen(mat);
    if(!img.isEmpty()){
         Card card = secondStage->getExtractedCard(img);
         RecognizedCard crd = thirdStage->getExtractedCard(card);
         std::vector<DetectedCard> result = connector->getCardsByStats(crd.getMana(),crd.getHealth(),crd.getAttack());
         DetectedCard real = fourthStage->getRealCard(result,crd);
         qDebug() << real.getName();
         writeToLog(real.getName());
         std::string name = real.getName().toStdString()+".png";
         img.saveImage("game",name);
         img.saveAttack("game","attack)"+std::to_string(crd.getAttack())+name);
         img.saveHealth("game","health)"+std::to_string(crd.getHealth())+name);
         img.saveMana("game","mana)"+std::to_string(crd.getMana())+name);
         img.saveDescription("game","descr)"+crd.getDescription().toStdString()+name);

    }
}

Controller::Controller()
{
    timer = new QTimer();
    int screenNum = 0;
    screen = QGuiApplication::primaryScreen();
    log = new QFile(LOG_PATH);
    connect(timer,SIGNAL(timeout()),this,SLOT(takeScreenshot()));
    log->open(QIODevice::WriteOnly |  QIODevice::Text);
    firstStage = new ScreenShotExtractor();
    secondStage = new ImageExtractor();
    thirdStage = new TextExtractor();
    fourthStage = new RealCardExtractor();
    connector = new DBConnector(QString("localhost"));
    connector->connect();
    stream = new QTextStream(log);
    sleep(5);
    timer->start(500);
}

Controller::~Controller()
{
    stream->flush();
    delete stream;
}
