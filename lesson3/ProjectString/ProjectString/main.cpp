# include <iostream>
#include<opencv2/opencv.hpp>
# include "highgui.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "BeginImage.h"
using namespace cv;
using namespace std;
/*函数名称：CaptureVideo()
*函数参数：无
*函数功能：读取并显示视频
*函数返回值：无
*/
void CaptureVideo()
{
	VideoCapture capture("1.avi");  // 读取视频，在定义的同时初始化
	while (1)  // 循环显示每一帧
	{
		Mat frame; //定义一个Mat变量，用于存储每一帧的图像
		capture >> frame;  // 读取当前帧
		imshow("读取视频", frame); // 显示当前帧
		waitKey(30);  // 延时30ms
	}

}
/*函数名称：CameraCapture()
*函数参数：无
*函数功能：从摄像头读取图像并显示
*函数返回值：无
*/
void CameraCapture()
{
	VideoCapture capture(0);  // 填0表示调用摄像头
	while (1)
	{
		Mat frame; // 定义Mat变量，用于存储每一帧的图像
		capture >> frame;  // 读取当前帧图像
		imshow("视频读取", frame);  // 显示当前帧
		waitKey(30);  // 延时30ms

	}
}
/*函数名称：TimeCanny()
*函数参数：无
*函数功能：从摄像头采集的图像利用Canny提取边缘
*函数返回值：无
*/
void TimeCanny()
{
	VideoCapture capture(0);
	Mat edges;
	while (1)
	{
		Mat frame; // 定义Mat变量，存储每一帧图像
		capture >> frame;  // 读取当前帧图像
		cvtColor(frame, edges, CV_BGR2GRAY);  // 颜色转换
		blur(edges, edges, Size(7, 7));  // 均值滤波
		Canny(edges, edges, 0, 30, 3);  //  边缘检测
		imshow("Canny之后的视频", edges);
		if (waitKey(30) >= 0)
			break;
	}
}


void  createAlpaMat(Mat& mat)
{
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			Vec4b& rgba = mat.at<Vec4b>(i, j);
			rgba[0] = UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);
			rgba[2] = saturate_cast<uchar>((float(mat.rows - j)) / ((float)mat.rows) * UCHAR_MAX);
			rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));

		}
	}
}

int main(int argc, char **argv)
{
	Mat mat(480, 640, CV_8UC4);
	createAlpaMat(mat);

	vector<int>compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	try {
		imwrite("透明Alpha值图.png", mat, compression_params);
		imshow("生成的PNG图", mat);
		fprintf(stdout, "图像转换为PNG数据保存完毕，可在工程目录下查看\n");
		waitKey(0);
	}
	catch (runtime_error& ex)
	{
		fprintf(stderr, "图像转换发生错误：%s\n", ex.what());
		return 1;
	}

	//	system("pause");
	return 0;

}
