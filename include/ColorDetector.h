/**
 * @file ColorDetector.h
 * @brief Заголовочный файл для класса ColorDetector.
 */

 #pragma once
 
 #include <opencv2/opencv.hpp>
 
 /**
  * @class ColorDetector
  * @brief Класс для определения цвета на изображении.
  *
  * Этот класс предоставляет методы для определения среднего цвета на изображении.
  */
 class ColorDetector {
 public:
     /**
      * @brief Определяет средний цвет на изображении.
      * @param image Изображение, на котором нужно определить цвет.
      * @return Средний цвет в формате cv::Vec3b.
      * @throws std::runtime_error Если изображение пустое.
      */
     cv::Vec3b detectColor(const cv::Mat& image);
 };
 