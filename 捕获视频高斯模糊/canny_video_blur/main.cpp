#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
	//1. ������ͷ������Ƶ
	VideoCapture capture(0);
	Mat edges;
	
	//ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;			      //����һ��Mat���������ڴ洢ÿһ֡ͼ��
		capture >> frame;	      //��ȡ��ǰ֡

		//����Ƶ��ȡ�꣬�˳�ѭ��
		if (frame.empty())
		{
			break;
		}
	//2. ��ͼ��תΪ�Ҷ�ͼ��
		cvtColor(frame, edges, CV_BGR2GRAY);   //��RGB��ɫͼתΪ�Ҷ�ͼ

	//3. ʹ��3*3�ں������루2*3+1=7��
		blur(edges,edges,Size(7,7));       //����ģ��

	//4. ����canny��Ե��Ⲣ��ʾ
		Canny(edges, edges, 0, 30, 3);
		imshow("��Ƶ��Ե���",edges);        //��ʾ���������ĵ�ǰ֡

		if (waitKey(30) >= 0)
			break;            //��ʱ30ms







	}


	return 0;
}