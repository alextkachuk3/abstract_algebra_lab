# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("algebra_lab")
# find_package(GMP REQUIRED)
# include_directories(${GOBJECT_INCLUDE_DIR})
# target_link_libraries(${PROJECT_NAME} "D:/Programs/ProgrammingEnvironment/Librares/gmp-6.1.1/lib/libgmp.a")
# Включите подпроекты.
add_subdirectory ("algebra_lab")
# target_link_libraries(ExecutableName ${GOBJECT_LIBRARIES})