#ifndef SCREENSHOTEXTRACTOR_H
#define SCREENSHOTEXTRACTOR_H
#include <algorithm>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "cards/imagecard.h"
#include <vector>
struct Circle{
    cv::Point2f center;
    double radius;
    bool operator<(const Circle& o) const{
         cv::Point2f a= center;
         cv::Point2f b = o.center;
         double rad1 = radius;
        double rad2 = o.radius;
         double diff = std::abs(a.y - b.y);
         if( diff < (rad1+rad2)/6){
             return a.x < b.x;
         }else{
             return a.y<b.y;
         }
    }
};

class ScreenShotExtractor
{
    std::vector<Circle> getCirclesFromImage(const cv::Mat& img);
    cv::Mat getCardRectFromScreen(const cv::Mat& screen);
public:
    ScreenShotExtractor();
    ImageCard extractCardFromScreen(const cv::Mat& basicScreen);
    static const double UP_LEFT_X_PROP;
    static const double UP_LEFT_Y_PROP;
    static const double CARD_RECT_W_PROP;
    static const double CARD_RECT_H_PROP;
    static const int THRESH_MIN;
    static const int THRESH_MAX;
    static const double CARD_LEFT_X_SHIFT_PROP;
    static const double CARD_LEFT_Y_SHIFT_PROP;
    static const double CARD_WIDTH_PROP;
    static const double CARD_HEIGHT_PROP;
    static const double POLY_AREA_PROP;
    static const double RADIUS_PROP;
};

#endif // SCREENSHOTEXTRACTOR_H
