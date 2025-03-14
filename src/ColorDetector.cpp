/**
 * @file ColorDetector.cpp
 * @brief Реализация методов класса ColorDetector.
 */

 #include "../include/ColorDetector.h"
 #include <iostream>
 
 /**
  * @brief Определяет средний цвет на изображении.
  * @param image Изображение, на котором нужно определить цвет.
  * @return Средний цвет в формате cv::Vec3b.
  * @throws std::runtime_error Если изображение пустое.
  */
 cv::Vec3b ColorDetector::detectColor(const cv::Mat& image) {
     if (image.empty()) {
         std::cerr << "Ошибка: изображение пустое!" << std::endl;
         return cv::Vec3b(0, 0, 0);
     }
 
     cv::Scalar meanColor = cv::mean(image);
     return cv::Vec3b(meanColor[0], meanColor[1], meanColor[2]);
 }