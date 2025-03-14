#include "../include/ImageProcessor.h"

cv::Scalar ImageProcessor::calculateAverageColor(const cv::Mat& image, const cv::Rect& region) {
    // Проверяем, что область находится в пределах изображения
    if (region.x < 0 || region.y < 0 || region.width <= 0 || region.height <= 0 ||
        region.x + region.width > image.cols || region.y + region.height > image.rows) {
        std::cerr << "Ошибка: область выходит за пределы изображения!" << std::endl;
        return cv::Scalar();
    }

    // Вырезаем область из изображения
    cv::Mat roi = image(region);

    // Вычисляем средний цвет в области
    cv::Scalar avgColor = cv::mean(roi);

    return avgColor;
}