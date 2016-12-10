CONFIG(debug, debug|release) {
    OPENCV_HOME = /usr/local/opencv/2.4.13/Debug
} else {
    OPENCV_HOME = /usr/local/opencv/2.4.13/Release
}

INCLUDEPATH += $$OPENCV_HOME/include
LIBS += -L$$OPENCV_HOME/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
