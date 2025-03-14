/**
 * @file ImageProcessor.h
 * @brief Заголовочный файл для класса ImageProcessor.
 */

 #pragma once

#include <opencv2/opencv.hpp>
#include <string>
 
 /**
  * @class ImageProcessor
  * @brief Класс для обработки изображений.
  *
  * Этот класс предоставляет методы для обработки изображений, включая вычисление среднего цвета в области.
  */
 class ImageProcessor {
 public:
     /**
      * @brief Вычисляет средний цвет в заданной области изображения.
      * @param image Изображение.
      * @param region Область изображения.
      * @return Средний цвет в формате cv::Scalar.
      * @throws std::runtime_error Если область выходит за пределы изображения.
      */
     static cv::Scalar calculateAverageColor(const cv::Mat& image, const cv::Rect& region);
 };
 
