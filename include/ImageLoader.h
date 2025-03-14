#pragma once

#include <opencv2/opencv.hpp>
#include <string>

class ImageLoader {
public:
    // Загружает изображение по указанному пути
    cv::Mat loadImage(const std::string& path);

    // Проверяет, существует ли файл
    bool fileExists(const std::string& path);
};
