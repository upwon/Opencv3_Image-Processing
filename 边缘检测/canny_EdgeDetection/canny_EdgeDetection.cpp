// canny_EdgeDetection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>      //opencv highgui模块头文件
#include<opencv2/imgproc/imgproc.hpp>	   //opencv图像处理头文件

using namespace cv;
int main()
{
	//1.载入图像
	Mat srcImage = imread("./1.jpg");

	//显示图片
	imshow("原图", srcImage);

	Mat dstImage, edge, grayImage;   //参数定义

	//2.创建于src同类型和大小的矩阵（dst）
	dstImage.create(srcImage.size(), srcImage.type());

	//3. 将原图像转换为灰度图像
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//4 使用3*3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//5. 使用canny算子
	Canny(edge, edge ,3, 9, 3);

	//6. 显示效果图
	imshow("canny边缘检测", edge);

	waitKey(0);
	return 0;
}

