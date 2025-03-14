#pragma once

#include <opencv2/opencv.hpp>
#include <string>

class ImageProcessor {
public:
    static cv::Scalar calculateAverageColor(const cv::Mat& image, const cv::Rect& region);
};
