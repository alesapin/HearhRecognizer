#include "imagecard.h"

const std::size_t ImageCard::STAT_HEIGHT = 150;
const std::size_t ImageCard::STAT_WIDTH = 100;
const std::size_t ImageCard::CLASS_HEIGHT = 50;
const std::size_t ImageCard::CLASS_WIDTH = 100;
const std::size_t ImageCard::DESCR_HEIGHT = 80;
const std::size_t ImageCard::DESCR_WIDTH = 200;



cv::Mat ImageCard::getMana() const
{
    return mana;
}

void ImageCard::setMana(const cv::Mat &value)
{
    mana = value;
}

cv::Mat ImageCard::getAttack() const
{
    return attack;
}

void ImageCard::setAttack(const cv::Mat &value)
{
    attack = value;
}

cv::Mat ImageCard::getHealth() const
{
    return health;
}

void ImageCard::setHealth(const cv::Mat &value)
{
    health = value;
}

cv::Mat ImageCard::getCrdclass() const
{
    return crdclass;
}

void ImageCard::setCrdclass(const cv::Mat &value)
{
    crdclass = value;
}

cv::Mat ImageCard::getDescription() const
{
    return description;
}

void ImageCard::setDescription(const cv::Mat &value)
{
    description = value;
}

cv::Mat ImageCard::getBasicImage() const
{
    return basicImage;
}

void ImageCard::setBasicImage(const cv::Mat &value)
{
    basicImage = value;
}

cv::Mat ImageCard::getMarkedImage() const
{
    return markedImage;
}

void ImageCard::setMarkedImage(const cv::Mat &value)
{
    markedImage = value;
}

std::size_t ImageCard::getRows() const
{
    return rows;
}

void ImageCard::setRows(const std::size_t &value)
{
    rows = value;
}

std::size_t ImageCard::getCols() const
{
    return cols;
}

void ImageCard::setCols(const std::size_t &value)
{
    cols = value;
}

void ImageCard::processCard()
{
    splitCard();
    markCard();
    turnToBw();
}

void ImageCard::splitCard()
{
    mana = cutRect(0,0,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    attack = cutRect(0,rows-150,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    health = cutRect(cols-100,rows-150,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    crdclass = cutRect(100,rows-80,ImageCard::CLASS_WIDTH,ImageCard::CLASS_HEIGHT);
    description = cutRect(50,rows-160,ImageCard::DESCR_WIDTH,ImageCard::DESCR_HEIGHT);
}

void ImageCard::markCard()
{
    drawRedRect(0,0,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    drawRedRect(0,rows-150,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    drawRedRect(cols-100,rows-150,ImageCard::STAT_WIDTH,ImageCard::STAT_HEIGHT);
    drawRedRect(100,rows-80,ImageCard::CLASS_WIDTH,ImageCard::CLASS_HEIGHT);
    drawRedRect(50,rows-160,ImageCard::DESCR_WIDTH,ImageCard::DESCR_HEIGHT);
}

void ImageCard::turnToBw()
{
    cvtColor(mana,mana,CV_BGR2GRAY);
    cvtColor(attack,attack,CV_BGR2GRAY);
    cvtColor(health,health,CV_BGR2GRAY);
    cvtColor(crdclass,crdclass,CV_BGR2GRAY);
    cvtColor(description,description,CV_BGR2GRAY);
    mana = mana > 250;
    attack = attack > 250;
    health = health > 250;
    crdclass = crdclass > 230;
    description = (cv::Scalar::all(255) - description) > 200;
}


void ImageCard::saveImage(std::string path,std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,basicImage);
}

void ImageCard::saveMarkedImage(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,markedImage);
}

void ImageCard::saveMana(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,mana);
}

void ImageCard::saveHealth(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,health);
}

void ImageCard::saveAttack(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,attack);
}
void ImageCard::saveDescription(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,description);
}

void ImageCard::saveCardClass(std::string path, std::string name)
{
    if(path != ""){
        path += "/";
    }
    cv::imwrite(path+name,crdclass);
}

cv::Mat ImageCard::cutRect(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
{
    return cv::Mat(basicImage,cv::Rect(x,y,width,height));
}

void ImageCard::drawRedRect(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
{
        cv::rectangle(markedImage,cv::Rect(x,y,width,height),cv::Scalar(0,0,255),2,8);
}

ImageCard::ImageCard(std::string path)
{
    basicImage = cv::imread(path, 1 );
    markedImage = basicImage.clone();
    cols = basicImage.cols;
    rows = basicImage.rows;
    processCard();
}

ImageCard::ImageCard(cv::Mat image)
{
    basicImage = image;
    markedImage = basicImage.clone();
    cols = basicImage.cols;
    rows = basicImage.rows;
    processCard();
}
