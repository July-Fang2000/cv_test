#ifndef SEARCH_LINES_H
#define SEARCH_LINES_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// void lineDetect(Mat frame, Mat &result);
void roiSelect(Mat frame, Mat &result);
void transform(Mat frame, vector<Vec4i> &lines);
void simulate(Mat frame, Mat &result, vector<Vec4i> &lines);
void mixLines(Mat frame1, Mat frame2, Mat &result);

#endif // SEARCH_LINES_H
