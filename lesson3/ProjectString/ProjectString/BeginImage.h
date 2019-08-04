#pragma once
#ifndef BEGINIMAGE_H
#define BEGINIMAGE_H

# include <iostream>
#include<opencv2/opencv.hpp>
# include "highgui.h"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

/*函数名称：ErodePicture()
*函数参数：无
*函数功能：显示main目录的1.jpg，并对其做腐蚀操作
*函数返回值：无
*/
void ErodePicture()
{
	Mat srcImage = imread("1.jpg");
	imshow("原图片显示", srcImage);  // 显示原图
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));  // 返回指定形状和尺寸的结构元素（内核矩阵）
	Mat dstImage;
	erode(srcImage, dstImage, element);  // 腐蚀操作
	imshow("腐蚀操作后的效果图", dstImage);
	waitKey(0);
}
/*函数名称：BlurPictrue()
*函数参数：无
*函数功能：对图片进行均值模糊
*函数返回值：无
*/
void BlurPictrue()
{
	Mat srcImage = imread("1.jpg");  // 载入原图
	imshow("原图显示", srcImage);
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));  // 进行均值滤波
	imshow("均值滤波效果图 ", dstImage);
	waitKey(0);
}
/*函数名称：CannyImage()
*函数参数：无
*函数功能：对输入图像进行边缘提取
*函数返回值：无
*/
void CannyImage()
{
	Mat scrImage = imread("1.jpg");
	imshow("显示原图", scrImage);
	Mat dstImage, edge, grayImage;  // 参数定义
	dstImage.create(scrImage.size(), scrImage.type());  // 创建于scr同类型和大小的矩阵
	cvtColor(scrImage, grayImage, COLOR_BGR2GRAY);  // 将原图像转换为灰度图像
	blur(grayImage, edge, Size(3, 3));  // 使用（3，3）内核降噪
	Canny(edge, edge, 3, 9, 3);  // 调用Canny算子提取边缘
	imshow("效果图", edge);
	waitKey(0);


}
#endif
