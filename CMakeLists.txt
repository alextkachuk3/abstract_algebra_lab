# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("algebra_lab")

add_executable (algebra "main.cpp" )

# Включите подпроекты.
add_subdirectory ("algebra_lab")
