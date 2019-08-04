#pragma once
#ifndef BEGINIMAGE_H
#define BEGINIMAGE_H

# include <iostream>
#include<opencv2/opencv.hpp>
# include "highgui.h"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

/*�������ƣ�ErodePicture()
*������������
*�������ܣ���ʾmainĿ¼��1.jpg������������ʴ����
*��������ֵ����
*/
void ErodePicture()
{
	Mat srcImage = imread("1.jpg");
	imshow("ԭͼƬ��ʾ", srcImage);  // ��ʾԭͼ
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));  // ����ָ����״�ͳߴ�ĽṹԪ�أ��ں˾���
	Mat dstImage;
	erode(srcImage, dstImage, element);  // ��ʴ����
	imshow("��ʴ�������Ч��ͼ", dstImage);
	waitKey(0);
}
/*�������ƣ�BlurPictrue()
*������������
*�������ܣ���ͼƬ���о�ֵģ��
*��������ֵ����
*/
void BlurPictrue()
{
	Mat srcImage = imread("1.jpg");  // ����ԭͼ
	imshow("ԭͼ��ʾ", srcImage);
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));  // ���о�ֵ�˲�
	imshow("��ֵ�˲�Ч��ͼ ", dstImage);
	waitKey(0);
}
/*�������ƣ�CannyImage()
*������������
*�������ܣ�������ͼ����б�Ե��ȡ
*��������ֵ����
*/
void CannyImage()
{
	Mat scrImage = imread("1.jpg");
	imshow("��ʾԭͼ", scrImage);
	Mat dstImage, edge, grayImage;  // ��������
	dstImage.create(scrImage.size(), scrImage.type());  // ������scrͬ���ͺʹ�С�ľ���
	cvtColor(scrImage, grayImage, COLOR_BGR2GRAY);  // ��ԭͼ��ת��Ϊ�Ҷ�ͼ��
	blur(grayImage, edge, Size(3, 3));  // ʹ�ã�3��3���ں˽���
	Canny(edge, edge, 3, 9, 3);  // ����Canny������ȡ��Ե
	imshow("Ч��ͼ", edge);
	waitKey(0);


}
#endif
