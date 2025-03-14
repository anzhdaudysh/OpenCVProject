/**
 * @file ImageLoader.h
 * @brief Заголовочный файл для класса ImageLoader.
 */

 #pragma once
 
 #include <opencv2/opencv.hpp>
 #include <string>
 
 /**
  * @class ImageLoader
  * @brief Класс для загрузки изображений.
  *
  * Этот класс предоставляет методы для загрузки изображений из файлов.
  */
 class ImageLoader {
 public:
     /**
      * @brief Загружает изображение из файла.
      * @param path Путь к файлу изображения.
      * @return Загруженное изображение.
      * @throws std::runtime_error Если файл не существует или изображение не загружено.
      */
     cv::Mat loadImage(const std::string& path);
 
     /**
      * @brief Проверяет, существует ли файл.
      * @param path Путь к файлу.
      * @return true, если файл существует, иначе false.
      */
     bool fileExists(const std::string& path);
 };
 
