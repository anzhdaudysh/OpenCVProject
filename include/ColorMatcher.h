/**
 * @file ColorMatcher.h
 * @brief Заголовочный файл для класса ColorMatcher.
 */

 #pragma once

 #include <opencv2/opencv.hpp>
 #include <vector>

 
 /**
  * @class ColorMatcher
  * @brief Класс для подбора сочетаний цветов.
  *
  * Этот класс предоставляет методы для нахождения комплиментарного цвета.
  */
 class ColorMatcher {
 public:
     /**
      * @brief Находит комплиментарный цвет для заданного цвета.
      * @param color Цвет в формате cv::Vec3b.
      * @return Комплиментарный цвет в формате cv::Vec3b.
      */
     static cv::Scalar getComplementaryColor(const cv::Scalar& color);
 
     /**
      * @brief Находит комплиментарный цвет для заданного цвета.
      * @param color Цвет в формате cv::Scalar.
      * @return Комплиментарный цвет в формате cv::Scalar.
      */
     static cv::Vec3b getComplementaryColor(const cv::Vec3b& color);
 };
 

