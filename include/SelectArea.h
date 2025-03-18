/**
 * @file SelectArea.h
 * @brief Заголовочный файл для класса SelectArea.
 */

 #pragma once

 #include <opencv2/opencv.hpp>
 #include <functional>
 
 /**
  * @class SelectArea
  * @brief Класс для выбора области на изображении с помощью мыши.
  *
  * Этот класс предоставляет функциональность для выбора прямоугольной области на изображении
  * с помощью мыши и вызова callback-функции после завершения выбора.
  */
 class SelectArea {
    public:
        /**
         * @brief Конструктор класса SelectArea.
         * 
         * @param windowName Название окна, в котором будет происходить выбор области.
         */
        explicit SelectArea(const std::string& windowName);
    
        /**
         * @brief Устанавливает callback-функцию, которая будет вызвана после выбора области.
         * 
         * @param callback Функция, принимающая cv::Rect (выбранная область) и cv::Mat (изображение).
         */
        void setCallback(const std::function<void(const cv::Rect&, const cv::Mat&)>& callback);
    
        /**
         * @brief Запускает процесс выбора области на изображении.
         * 
         * @param image Изображение, на котором будет происходить выбор области.
         */
        void start(const cv::Mat& image);
    
        /**
         * @brief Отображает квадратное изображение с заданным цветом.
         * 
         * @param color Цвет для отображения.
         * @param windowName Название окна.
         */
        static void showColorSquare(const cv::Scalar& color, const std::string& windowName = "Complementary Color");
    
    private:
        std::string _windowName; ///< Название окна.
        cv::Point _startPoint;   ///< Начальная точка выбора области.
        cv::Point _endPoint;     ///< Конечная точка выбора области.
        bool _selecting;         ///< Флаг, указывающий, что идет процесс выбора области.
        cv::Mat _image;          ///< Изображение для отображения.
        std::function<void(const cv::Rect&, const cv::Mat&)> _callback; ///< Callback-функция.
    
        /**
         * @brief Обработчик событий мыши.
         * 
         * @param event Тип события мыши.
         * @param x Координата X курсора мыши.
         * @param y Координата Y курсора мыши.
         * @param flags Флаги события мыши.
         * @param userdata Пользовательские данные (не используются).
         */
        static void onMouse(int event, int x, int y, int flags, void* userdata);
    };