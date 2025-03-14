/**
 * @file ImageProcessor.cpp
 * @brief Реализация методов класса ImageProcessor.
 */

 #include "../include/ImageProcessor.h"

 /**
  * @brief Вычисляет средний цвет в заданной области изображения.
  * @param image Изображение.
  * @param region Область изображения.
  * @return Средний цвет в формате cv::Scalar.
  * @throws std::runtime_error Если область выходит за пределы изображения.
  */
 cv::Scalar ImageProcessor::calculateAverageColor(const cv::Mat& image, const cv::Rect& region) {
    
     if (region.x < 0 || region.y < 0 || region.width <= 0 || region.height <= 0 ||
         region.x + region.width > image.cols || region.y + region.height > image.rows) {
         std::cerr << "Ошибка: область выходит за пределы изображения!" << std::endl;
         return cv::Scalar();
     }
 
     cv::Mat roi = image(region);
 
     cv::Scalar avgColor = cv::mean(roi);
 
     return avgColor;
 }

