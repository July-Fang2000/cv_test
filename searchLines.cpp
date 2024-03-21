#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace cv;

// 边缘检测参数

// 边缘检测
void lineDetect(Mat frame, Mat result)
{
    Canny(frame, result, 50, 200, 3);
}

// 感兴趣区域
void roiSelect(Mat frame, Mat &result)
{
    Mat mask = Mat::zeros(frame.size(), CV_8UC1);
    Point PointArray[4];
    PointArray[0] = Point(0, mask.rows);
    PointArray[1] = Point(400, 330);
    PointArray[2] = Point(570, 330);
    PointArray[3] = Point(mask.cols, mask.rows);
    fillConvexPoly(mask, PointArray, 4, Scalar(255));
    bitwise_and(mask, frame, result);
}

// 霍夫变换
void transform(Mat frame, vector<Vec4i> &lines)
{
    int rho = 1;
    double theta = CV_PI / 180;
    int threshold = 30;
    int min_line_len = 3;
    int max_line_gap = 10;
    HoughLinesP(frame, lines, rho, theta, threshold, min_line_len, max_line_gap);
}

// 轨道线拟合
void simulate(Mat &result, vector<Vec4i> &lines)
{
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4i L = lines[i];
        line(result, Point(L[0], L[1]), Point(L[2], L[3]), Scalar(0, 0, 255), 3, LINE_AA);
    }
}

// 图像混合
void mixLines(Mat frame1, Mat frame2, Mat &result)
{
    // Convert frame_original to CV_8UC3 if it's not already in that format
    if (frame1.type() != CV_8UC3)
    {
        cv::cvtColor(frame1, frame1, cv::COLOR_BGR2RGB);
    }

    // Convert simuFrame to CV_8UC3 if it's not already in that format
    if (frame2.type() != CV_8UC3)
    {
        cv::cvtColor(frame2, frame2, cv::COLOR_BGR2RGB);
    }

    addWeighted(frame1, 1, frame2, 2, 0.0, result);
}