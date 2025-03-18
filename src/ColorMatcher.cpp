/**
 * @file ColorMatcher.cpp
 * @brief Реализация методов класса ColorMatcher.
 */

 #include "../include/ColorMatcher.h"
 #include <opencv2/opencv.hpp>
 
 /**
  * @brief Находит комплиментарный цвет для заданного цвета.
  * @param color Цвет в формате cv::Vec3b.
  * @return Комплиментарный цвет в формате cv::Vec3b.
  */
 cv::Vec3b ColorMatcher::getComplementaryColor(const cv::Vec3b& color) {

     cv::Mat bgrColor(1, 1, CV_8UC3, color);
     cv::Mat hsvColor;
     cv::cvtColor(bgrColor, hsvColor, cv::COLOR_BGR2HSV);
 

     uchar hue = hsvColor.at<cv::Vec3b>(0, 0)[0];
     uchar complementaryHue = (hue + 90) % 180; 
 

     cv::Vec3b complementaryHsv(complementaryHue, hsvColor.at<cv::Vec3b>(0, 0)[1], hsvColor.at<cv::Vec3b>(0, 0)[2]);

     cv::Mat complementaryHsvMat(1, 1, CV_8UC3, complementaryHsv);
     cv::Mat complementaryBgrMat;
     cv::cvtColor(complementaryHsvMat, complementaryBgrMat, cv::COLOR_HSV2BGR);

     return complementaryBgrMat.at<cv::Vec3b>(0, 0);
 }
 
 /**
  * @brief Находит комплиментарный цвет для заданного цвета.
  * @param color Цвет в формате cv::Scalar.
  * @return Комплиментарный цвет в формате cv::Scalar.
  */
 cv::Scalar ColorMatcher::getComplementaryColor(const cv::Scalar& color) {

     cv::Vec3b bgrColor(color[0], color[1], color[2]); 

     cv::Vec3b complementaryColor = getComplementaryColor(bgrColor);

     return cv::Scalar(complementaryColor[0], complementaryColor[1], complementaryColor[2]);
 }