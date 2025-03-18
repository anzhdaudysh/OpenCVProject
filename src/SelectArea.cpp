/**
 * @file SelectArea.cpp
 * @brief Реализация методов класса SelectArea.
 */

 #include "../include/SelectArea.h"
 #include <iostream>
 
 SelectArea::SelectArea(const std::string& windowName)
 : _windowName(windowName), _selecting(false) {}

void SelectArea::setCallback(const std::function<void(const cv::Rect&, const cv::Mat&)>& callback) {
 _callback = callback;
}

void SelectArea::start(const cv::Mat& image) {
 _image = image.clone();
 cv::namedWindow(_windowName);
 cv::imshow(_windowName, _image);
 cv::setMouseCallback(_windowName, onMouse, this);
 cv::waitKey(0);
 cv::destroyAllWindows();
}

void SelectArea::showColorSquare(const cv::Scalar& color, const std::string& windowName) {
 int size = 300; // Размер изображения
 cv::Mat colorSquare(size, size, CV_8UC3, color); // Создаем изображение
 cv::imshow(windowName, colorSquare); // Отображаем изображение
 cv::waitKey(0); // Ждем нажатия клавиши
}

void SelectArea::onMouse(int event, int x, int y, int flags, void* userdata) {
 SelectArea* self = static_cast<SelectArea*>(userdata);

 if (event == cv::EVENT_LBUTTONDOWN) {
     self->_startPoint = cv::Point(x, y);
     self->_endPoint = self->_startPoint;
     self->_selecting = true;
 } else if (event == cv::EVENT_MOUSEMOVE && self->_selecting) {
     self->_endPoint = cv::Point(x, y);
     cv::Mat displayImage = self->_image.clone();
     cv::rectangle(displayImage, self->_startPoint, self->_endPoint, cv::Scalar(0, 255, 0), 2);
     cv::imshow(self->_windowName, displayImage);
 } else if (event == cv::EVENT_LBUTTONUP) {
     self->_endPoint = cv::Point(x, y);
     self->_selecting = false;

     if (self->_startPoint.x < 0 || self->_startPoint.y < 0 ||
         self->_endPoint.x > self->_image.cols || self->_endPoint.y > self->_image.rows) {
         std::cerr << "Ошибка: область выходит за пределы изображения!" << std::endl;
         return;
     }

     cv::Rect region(self->_startPoint, self->_endPoint);
     if (self->_callback) {
         self->_callback(region, self->_image);
     }
 }
}