#include "../include/ColorDetector.h"

cv::Vec3b ColorDetector::detectColor(const cv::Mat& image) {
    if (image.empty()) {
        std::cerr << "Ошибка: изображение пустое!" << std::endl;
        return cv::Vec3b(0, 0, 0);
    }

    // Вычисляем средний цвет
    cv::Scalar meanColor = cv::mean(image);
    return cv::Vec3b(meanColor[0], meanColor[1], meanColor[2]);
}