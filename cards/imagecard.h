#ifndef IMAGECARD_H
#define IMAGECARD_H
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc.hpp"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
class ImageCard
{
    cv::Mat mana;
    cv::Mat attack;
    cv::Mat health;
    cv::Mat crdclass;
    cv::Mat description;
    cv::Mat basicImage;
    cv::Mat markedImage;
    std::size_t rows;
    std::size_t cols;
    cv::Mat cutRect(std::size_t x,std::size_t y,std::size_t width,std::size_t height);
    void drawRedRect(std::size_t x,std::size_t y,std::size_t width,std::size_t height);
    void splitCard();
    void markCard();
    void turnToBw();
public:
    ImageCard(std::string path);
    ImageCard(cv::Mat image);
    cv::Mat getMana() const;
    void setMana(const cv::Mat &value);
    cv::Mat getAttack() const;
    void setAttack(const cv::Mat &value);
    cv::Mat getHealth() const;
    void setHealth(const cv::Mat &value);
    cv::Mat getCrdclass() const;
    void setCrdclass(const cv::Mat &value);
    cv::Mat getDescription() const;
    void setDescription(const cv::Mat &value);
    cv::Mat getBasicImage() const;
    void setBasicImage(const cv::Mat &value);
    cv::Mat getMarkedImage() const;
    void setMarkedImage(const cv::Mat &value);
    std::size_t getRows() const;
    void setRows(const std::size_t &value);
    std::size_t getCols() const;
    void setCols(const std::size_t &value);
    void processCard();

    void saveImage(std::string path, std::string name);
    void saveMarkedImage(std::string path,std::string name);
    void saveMana(std::string path,std::string name);
    void saveHealth(std::string path,std::string name);
    void saveAttack(std::string path,std::string name);
    void saveDescription(std::string path,std::string name);
    void saveCardClass(std::string path,std::string name);
    static const std::size_t STAT_HEIGHT;
    static const std::size_t STAT_WIDTH;
    static const std::size_t CLASS_HEIGHT;
    static const std::size_t CLASS_WIDTH;
    static const std::size_t DESCR_HEIGHT;
    static const std::size_t DESCR_WIDTH;
};

#endif // IMAGECARD_H
