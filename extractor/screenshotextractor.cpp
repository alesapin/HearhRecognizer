#include "screenshotextractor.h"

const double ScreenShotExtractor::UP_LEFT_X_PROP = 0.234375;
const double ScreenShotExtractor::UP_LEFT_Y_PROP = 0.5;
const double ScreenShotExtractor::CARD_RECT_W_PROP = 0.521;
const double ScreenShotExtractor::CARD_RECT_H_PROP = 0.5;
const int ScreenShotExtractor::THRESH_MIN = 100;
const int ScreenShotExtractor::THRESH_MAX = 255;
const double ScreenShotExtractor::CARD_LEFT_X_SHIFT_PROP = 0.028645;
const double ScreenShotExtractor::CARD_LEFT_Y_SHIFT_PROP = 0.041667;
const double ScreenShotExtractor::CARD_WIDTH_PROP = 0.182291;
const double ScreenShotExtractor::CARD_HEIGHT_PROP = 0.4125;
const double ScreenShotExtractor::POLY_AREA_PROP = 0.00075;
const double ScreenShotExtractor::RADIUS_PROP = 0.025;
std::vector<Circle> ScreenShotExtractor::getCirclesFromImage(const cv::Mat &img)
{
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat threshold_output;
    cv::threshold(img, threshold_output, THRESH_MIN, THRESH_MAX, cv::THRESH_BINARY );
    cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
    std::vector<std::vector<cv::Point> > contours_poly( contours.size() );
    std::vector<cv::Point2f>center( contours.size() );
    std::vector<float>radius( contours.size() );
    std::vector<Circle> circles;
    for( int i = 0; i < contours.size(); i++ ){
        if(cv::contourArea(contours[i]) > (int)(img.cols*img.rows*POLY_AREA_PROP +0.5)) {
            cv::approxPolyDP( cv::Mat(contours[i]), contours_poly[i], 3, true );
            cv::minEnclosingCircle( (cv::Mat)contours_poly[i], center[i], radius[i]);
            circles.push_back({center[i],radius[i]});
        }
     }
    return circles;
}

cv::Mat ScreenShotExtractor::getCardRectFromScreen(const cv::Mat &screen)
{
    cv::Rect r((int)(screen.cols*UP_LEFT_X_PROP+0.5),(int)(screen.rows*UP_LEFT_Y_PROP+0.5),
             (int)(screen.cols*CARD_RECT_W_PROP+0.5),(int)(screen.rows*CARD_RECT_H_PROP+0.5));
    return cv::Mat(screen,r);
}

ScreenShotExtractor::ScreenShotExtractor()
{
}

ImageCard ScreenShotExtractor::extractCardFromScreen(const cv::Mat &basicScreen)
{
    cv::Mat cardplace = getCardRectFromScreen(basicScreen);
    cv::Mat gray;
    cvtColor(cardplace,gray,CV_BGR2GRAY);
    gray = gray > 253;
    std::vector<Circle> circles = getCirclesFromImage(gray);
    int smallRadius = (int)(cardplace.cols*RADIUS_PROP+0.5) ;
    for(auto itr = circles.begin();itr!=circles.end();){
        if(itr->radius <= smallRadius || itr->radius >= smallRadius + 10){
            itr = circles.erase(itr);
        }else{
            itr++;
        }
    }
    std::sort(circles.begin(),circles.end());
    cv::Point2f manaplace;
    cv::Point2f hpplace;
    cv::Point2f attackplace;
    manaplace = circles[0].center;
    if(circles.size() > 1){
        attackplace = circles[1].center;
        hpplace = circles[2].center;
    }
    int xshift = (int)(basicScreen.cols * CARD_LEFT_X_SHIFT_PROP+0.5);
    int yshift = (int)(basicScreen.rows * CARD_LEFT_Y_SHIFT_PROP+0.5);
    int upX = manaplace.x - xshift;
    int upY  = manaplace.y - yshift;
    int width = xshift + (int)(basicScreen.cols*CARD_WIDTH_PROP + 0.5);
    int height = yshift +(int)(basicScreen.rows*CARD_HEIGHT_PROP + 0.5);
    if(upX < 0 ) upX = 0;
    if(upY < 0) upY = 0;
    if(width > cardplace.cols) width = cardplace.cols - 1;
    if(height > cardplace.rows) height = cardplace.rows - 1;
    cv::Point2f mana(manaplace.x-upX,manaplace.y-upY);
    cv::Point2f hp(hpplace.x-upX,hpplace.y-upY);
    cv::Point2f attack(attackplace.x-upX,attackplace.y-upY);

    cv::Rect cur(upX,upY,width,height);
    return ImageCard(cv::Mat(cardplace,cur),mana,hp,attack);
}
