#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img1=imread("joker.jpg",0);
	Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	namedWindow("win",1);
	int th=100;
	createTrackbar("legend","win",&th,255);
	
	while(1)
	{
	
	createTrackbar("legend","win",&th,255);
	for(int i=0;i<img1.rows;i++)
		for(int j=0;j<img1.cols;j++)
		{
			if(img1.at<uchar>(i,j)>=th)
				img2.at<uchar>(i,j)=255;
			else
				img2.at<uchar>(i,j)=0;
		}
		imshow("win",img2);
		char c=waitKey(1);
	}	
	return 0;
}
