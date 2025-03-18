/**
 * @file ImageLoader.cpp
 * @brief Реализация методов класса ImageLoader.
 */

 #include "../include/ImageLoader.h"
 #include <iostream>
 #include <fstream>
 
 /**
  * @brief Проверяет, существует ли файл.
  * @param path Путь к файлу.
  * @return true, если файл существует, иначе false.
  */
 bool ImageLoader::fileExists(const std::string& path) {
     std::ifstream file(path);
     return file.good();
 }
 
 /**
  * @brief Загружает изображение из файла.
  * @param path Путь к файлу изображения.
  * @return Загруженное изображение.
  * @throws std::runtime_error Если файл не существует или изображение не загружено.
  */
 cv::Mat ImageLoader::loadImage(const std::string& path) {
     if (!fileExists(path)) {
         std::cerr << "Ошибка: файл " << path << " не существует!" << std::endl;
         return cv::Mat(); 
     }
 
     cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
     if (image.empty()) {
         std::cerr << "Ошибка: не удалось загрузить изображение!" << std::endl;
     }
 

    //  cv::GaussianBlur(image, image, cv::Size(5, 5), 0);
    //  cv::medianBlur(image, image, 5);
 

     double gamma = 1.5;
     cv::Mat lookupTable(1, 256, CV_8U);
     uchar* p = lookupTable.ptr();
     for (int i = 0; i < 256; ++i) {
         p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
     }
     cv::LUT(image, lookupTable, image);
 
     return image;
 }