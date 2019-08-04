# include <iostream>
#include<opencv2/opencv.hpp>
# include "highgui.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "BeginImage.h"
using namespace cv;
using namespace std;
/*�������ƣ�CaptureVideo()
*������������
*�������ܣ���ȡ����ʾ��Ƶ
*��������ֵ����
*/
void CaptureVideo()
{
	VideoCapture capture("1.avi");  // ��ȡ��Ƶ���ڶ����ͬʱ��ʼ��
	while (1)  // ѭ����ʾÿһ֡
	{
		Mat frame; //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  // ��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame); // ��ʾ��ǰ֡
		waitKey(30);  // ��ʱ30ms
	}

}
/*�������ƣ�CameraCapture()
*������������
*�������ܣ�������ͷ��ȡͼ����ʾ
*��������ֵ����
*/
void CameraCapture()
{
	VideoCapture capture(0);  // ��0��ʾ��������ͷ
	while (1)
	{
		Mat frame; // ����Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  // ��ȡ��ǰ֡ͼ��
		imshow("��Ƶ��ȡ", frame);  // ��ʾ��ǰ֡
		waitKey(30);  // ��ʱ30ms

	}
}
/*�������ƣ�TimeCanny()
*������������
*�������ܣ�������ͷ�ɼ���ͼ������Canny��ȡ��Ե
*��������ֵ����
*/
void TimeCanny()
{
	VideoCapture capture(0);
	Mat edges;
	while (1)
	{
		Mat frame; // ����Mat�������洢ÿһ֡ͼ��
		capture >> frame;  // ��ȡ��ǰ֡ͼ��
		cvtColor(frame, edges, CV_BGR2GRAY);  // ��ɫת��
		blur(edges, edges, Size(7, 7));  // ��ֵ�˲�
		Canny(edges, edges, 0, 30, 3);  //  ��Ե���
		imshow("Canny֮�����Ƶ", edges);
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
		imwrite("͸��Alphaֵͼ.png", mat, compression_params);
		imshow("���ɵ�PNGͼ", mat);
		fprintf(stdout, "ͼ��ת��ΪPNG���ݱ�����ϣ����ڹ���Ŀ¼�²鿴\n");
		waitKey(0);
	}
	catch (runtime_error& ex)
	{
		fprintf(stderr, "ͼ��ת����������%s\n", ex.what());
		return 1;
	}

	//	system("pause");
	return 0;

}
