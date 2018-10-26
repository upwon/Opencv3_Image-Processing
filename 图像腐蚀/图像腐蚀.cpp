// 图像腐蚀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//OpenCV实现最基本的形态学运算之--图像腐蚀
//windows 64bit+vs2017+opencv3.4.3

#include <iostream>
#include<opencv2/highgui/highgui.hpp>      //opencv highgui模块头文件
#include<opencv2/imgproc/imgproc.hpp>	   //opencv图像处理头文件


using namespace cv;                        //包含cv命名空间


int main()
{
	//载入图片
	Mat srcImage = imread("./1.jpg");

	//显示图片
	imshow("原图",srcImage);
	
	//腐蚀
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage,dstImage,element);

	//显示效果图
	imshow("腐蚀操作",dstImage);
	waitKey(0);


	return 0;



}

