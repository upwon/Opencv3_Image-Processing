// BlurredImage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// windows 64模糊bit+vs2017+opencv3.4.3
// 均值滤波--图像

#include "pch.h"
#include <iostream>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>      //opencv highgui模块头文件
#include<opencv2/imgproc/imgproc.hpp>	   //opencv图像处理头文件


using namespace cv;                        //包含cv命名空间


int main()
{
	//载入图片
	Mat srcImage = imread("./2.jpeg");

	//显示图片
	imshow("原图", srcImage);

	//均值滤波
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));    //blur函数进行均值滤波操作

	//显示效果图
	imshow("均值滤波操作", dstImage);        //imshow显示
	waitKey(0);                            //waitKey函数等待按键按下，以便于窗口一直显示


	return 0;



}
