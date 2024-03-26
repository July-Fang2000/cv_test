#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace cv;

// 边缘检测
// void lineDetect(Mat frame, Mat &result)
// {
//     Canny(frame, result, 50, 200, 3);
// }

// 感兴趣区域
void roiSelect(Mat frame, Mat &result)
{
    result = Mat(frame.size(), CV_8UC1);
    Mat mask = Mat::zeros(frame.size(), CV_8UC1);
    Point PointArray[4];
    PointArray[0] = Point(300, mask.rows);
    PointArray[1] = Point(500, 200);
    PointArray[2] = Point(700, 200);
    PointArray[3] = Point(900, mask.rows);
    fillConvexPoly(mask, PointArray, 4, Scalar(255));
    bitwise_and(mask, frame, result);

    // 用于观测ROI区域
    // result.setTo(Scalar(255, 255, 255), ~mask);
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
void simulate(Mat frame, Mat &result, vector<Vec4i> &lines)
{
    result = Mat::zeros(frame.size(), CV_8UC3);
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4i L = lines[i];
        line(result, Point(L[0], L[1]), Point(L[2], L[3]), Scalar(0, 0, 255), 3, LINE_AA);
    }
}

// 图像混合
void mixLines(Mat frame1, Mat frame2, Mat &result)
{
    result = Mat(frame1.size(), CV_8UC3);
    addWeighted(frame1, 1, frame2, 2, 0.0, result);
}