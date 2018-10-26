#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
	//1. 从摄像头读入视频
	VideoCapture capture(0);
	Mat edges;
	
	//循环显示每一帧
	while (1)
	{
		Mat frame;			      //定义一个Mat变量，用于存储每一帧图像
		capture >> frame;	      //读取当前帧

		//若视频读取完，退出循环
		if (frame.empty())
		{
			break;
		}
	//2. 将图像转为灰度图像
		cvtColor(frame, edges, CV_BGR2GRAY);   //将RGB彩色图转为灰度图

	//3. 使用3*3内核来降噪（2*3+1=7）
		blur(edges,edges,Size(7,7));       //进行模糊

	//4. 进行canny边缘检测并显示
		Canny(edges, edges, 0, 30, 3);
		imshow("视频边缘检测",edges);        //显示经过处理后的当前帧

		if (waitKey(30) >= 0)
			break;            //延时30ms







	}


	return 0;
}