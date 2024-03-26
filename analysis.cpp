#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "include/searchLines.h"

using namespace std;
using namespace cv;

void drawLines(Mat frame_original, Mat frame, Mat &result)
{
    Mat lineFrame, roiFrame, simuFrame;
    vector<Vec4i> lines;

    // 边缘检测
    // lineFrame = Mat(frame_original.size(), CV_8UC1);
    // lineDetect(frame, lineFrame);

    // 感兴趣区域
    roiSelect(frame, roiFrame);

    // 霍夫变换
    transform(roiFrame, lines);

    // 轨道线拟合
    simulate(roiFrame, simuFrame, lines);

    // 图像混合
    mixLines(frame_original, simuFrame, result);

    // Check if frames are empty before displaying

    // if (!frame_original.empty())
    //     imshow("Original Frame", frame_original);
    // else
    //     cerr << "Error: Original frame is empty!" << endl;

    // if (!lineFrame.empty())
    // {
    //     imshow("Line Frame", lineFrame);
    // }
    // else
    //     cerr << "Error: Line frame is empty!" << endl;

    // if (!roiFrame.empty())
    //     imshow("ROI Frame", roiFrame);
    // else
    //     cerr << "Error: ROI frame is empty!" << endl;

    // if (!simuFrame.empty())
    //     imshow("Simu Frame", simuFrame);
    // else
    //     cerr << "Error: Simulation frame is empty!" << endl;

    // if (!result.empty())
    //     imshow("Result Frame", result);
    // else
    //     cerr << "Error: Result frame is empty!" << endl;
}
