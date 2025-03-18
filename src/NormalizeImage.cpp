/**
 * @file NormalizeImage.cpp
 * @brief Реализация методов класса NormalizeImage.
 */

#include "../include/NormalizeImage.h"
#include <iostream>
#include <stdexcept>
 
 cv::Mat NormalizeImage::normalizeImage(const cv::Mat& inputImage) {
     // Преобразуем изображение в grayscale для работы с яркостью
     cv::Mat grayImage;
     cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
 
     // Применяем размытие для уменьшения шума
     cv::Mat blurredImage;
     cv::GaussianBlur(grayImage, blurredImage, cv::Size(15, 15), 0);
 
     // Вычисляем разницу между оригинальным и размытым изображением
     cv::Mat diffImage;
     cv::absdiff(grayImage, blurredImage, diffImage);
 
     // Инвертируем разницу, чтобы выделить тени и засветы
     cv::Mat invertedDiff;
     cv::bitwise_not(diffImage, invertedDiff);
 
     // Нормализуем изображение
     cv::Mat normalizedImage;
     cv::normalize(invertedDiff, normalizedImage, 0, 255, cv::NORM_MINMAX);
 
     // Применяем пороговую обработку для выделения теней и засветов
     cv::Mat thresholdImage;
     cv::threshold(normalizedImage, thresholdImage, 200, 255, cv::THRESH_BINARY);
 
     // Убираем тени и засветы из оригинального изображения
     cv::Mat resultImage;
     cv::inpaint(inputImage, thresholdImage, resultImage, 3, cv::INPAINT_TELEA);
 
     return resultImage;
 }
 
 cv::Scalar NormalizeImage::calculateAverageColor(const cv::Mat& image, const cv::Rect& region) {
     // Проверяем, что область находится в пределах изображения
     if (region.x < 0 || region.y < 0 ||
         region.x + region.width > image.cols ||
         region.y + region.height > image.rows) {
         throw std::runtime_error("Область выходит за пределы изображения!");
     }
 
     // Вычисляем среднее значение для каждого канала (B, G, R) в области
     cv::Mat roi = image(region);
     cv::Scalar avgColor = cv::mean(roi);
     return avgColor;
 }