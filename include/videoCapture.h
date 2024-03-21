#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void readAndDisplayVideo(const std::string &filename, cv::VideoCapture &cap, double &fps);
void createWindow(cv::VideoCapture &cap);
void releaseCap(cv::VideoCapture &cap);

#endif // VIDEOCAPTURE_H
