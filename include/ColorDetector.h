#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/opencv.hpp>

class ColorDetector {
public:
    // Определяет средний цвет на изображении
    cv::Vec3b detectColor(const cv::Mat& image);
};

#endif