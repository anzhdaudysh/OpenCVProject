#include "../include/ImageLoader.h"
#include <iostream>
#include <fstream>

// Проверка существования файла
bool ImageLoader::fileExists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

// Загрузка изображения
cv::Mat ImageLoader::loadImage(const std::string& path) {
    if (!fileExists(path)) {
        std::cerr << "Ошибка: файл " << path << " не существует!" << std::endl;
        return cv::Mat(); // Возвращаем пустое изображение
    }

    cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Ошибка: не удалось загрузить изображение!" << std::endl;
    }

    return image;
}

// cv::Mat ImageLoader::loadImage(const std::string& path) {
//     std::cout << "Загружаем изображение: " << path << std::endl; // Добавлено для отладки
//     if (!fileExists(path)) {
//         std::cerr << "Ошибка: файл " << path << " не существует!" << std::endl;
//         return cv::Mat(); // Возвращаем пустое изображение
//     }



//     cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
//     if (image.empty()) {
//         std::cerr << "Ошибка: не удалось загрузить изображение!" << std::endl;
//     }

//     return image;
// }