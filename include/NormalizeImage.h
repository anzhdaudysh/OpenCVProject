/**
 * @file NormalizeImage.h
 * @brief Заголовочный файл для класса NormalizeImage.
 */

 #pragma once

 #include <opencv2/opencv.hpp>
 #include <string>
 
 /**
  * @class NormalizeImage
  * @brief Класс для нормализации изображений и работы с цветами.
  *
  * Этот класс предоставляет методы для нормализации изображений (удаления теней и засветов)
  * и вычисления среднего цвета в области изображения.
  */
 class NormalizeImage {
 public:
     /**
      * @brief Нормализует изображение, удаляя тени и засветы.
      * 
      * @param inputImage Входное изображение в формате BGR.
      * @return cv::Mat Нормализованное изображение.
      */
     static cv::Mat normalizeImage(const cv::Mat& inputImage);
 
     /**
      * @brief Вычисляет средний цвет в заданной области изображения.
      * 
      * @param image Изображение.
      * @param region Область изображения.
      * @return Средний цвет в формате cv::Scalar.
      * @throws std::runtime_error Если область выходит за пределы изображения.
      */
     static cv::Scalar calculateAverageColor(const cv::Mat& image, const cv::Rect& region);
 };