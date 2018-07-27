project(OSGQt)
add_definitions(-D _SCL_SECURE_NO_WARNINGS)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(3RDPARTY_DIR "C:/3rdpart")
set(CMAKE_PREFIX ${3RDPARTY_DIR}/osgqt ${3RDPARTY_DIR}/gtest ${3RDPARTY_DIR}/boost)
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(OpenSceneGraph 3.0.0 REQUIRED osgDB osgGA osgUtil osgText osgViewer osgWidget)
find_package(osgqt)
#find_package(gtest)
find_package(Qt5OpenGL)
find_package(Qt5SerialPort)
find_package(Boost)
include_directories(
${PROJECT_SOURCE_DIR}/include
${OPENSCENEGRAPH_INCLUDE_DIRS}
${Qt5Widgets_INCLUDE_DIRS}
${OSGQT_INCLUDE_DIR}
${Qt5OpenGL_INCLUDE_DIRS}
${Boost_INCLUDE_DIR}
)

add_subdirectory(src)