cmake_minimum_required(VERSION 3.10)
project(ClothingColorDetector)

# Указываем стандарт C++ (например, C++17)
set(CMAKE_CXX_STANDARD 17)

# Добавляем OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Добавляем исходные файлы
set(SOURCES
    src/ImageLoader.cpp
    src/ImageProcessor.cpp
    src/ColorDetector.cpp
    src/ColorMatcher.cpp
    src/main.cpp
)

# Создаем исполняемый файл
add_executable(ClothingColorDetector ${SOURCES})

# Линкуем OpenCV
target_link_libraries(ClothingColorDetector ${OpenCV_LIBS})