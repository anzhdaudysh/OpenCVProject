#include "../include/ColorMatcher.h"
#include <opencv2/opencv.hpp>

// Преобразует цвет в дополнительный (complementary color)
cv::Vec3b ColorMatcher::getComplementaryColor(const cv::Vec3b& color) {
    // Преобразуем цвет из BGR в HSV
    cv::Mat bgrColor(1, 1, CV_8UC3, color);
    cv::Mat hsvColor;
    cv::cvtColor(bgrColor, hsvColor, cv::COLOR_BGR2HSV);

    // Получаем значение оттенка (Hue)
    uchar hue = hsvColor.at<cv::Vec3b>(0, 0)[0];

    // Вычисляем дополнительный оттенок (Hue + 180°)
    uchar complementaryHue = (hue + 90) % 180; // OpenCV использует диапазон Hue 0-179

    // Создаем дополнительный цвет в HSV
    cv::Vec3b complementaryHsv(complementaryHue, hsvColor.at<cv::Vec3b>(0, 0)[1], hsvColor.at<cv::Vec3b>(0, 0)[2]);

    // Преобразуем обратно в BGR
    cv::Mat complementaryHsvMat(1, 1, CV_8UC3, complementaryHsv);
    cv::Mat complementaryBgrMat;
    cv::cvtColor(complementaryHsvMat, complementaryBgrMat, cv::COLOR_HSV2BGR);

    // Возвращаем дополнительный цвет
    return complementaryBgrMat.at<cv::Vec3b>(0, 0);
}

// Новый метод для работы с cv::Scalar
cv::Scalar ColorMatcher::getComplementaryColor(const cv::Scalar& color) {
    // Преобразуем cv::Scalar в cv::Vec3b
    cv::Vec3b bgrColor(color[0], color[1], color[2]); // B, G, R

    // Получаем комплиментарный цвет
    cv::Vec3b complementaryColor = getComplementaryColor(bgrColor);

    // Преобразуем результат обратно в cv::Scalar
    return cv::Scalar(complementaryColor[0], complementaryColor[1], complementaryColor[2]);
}