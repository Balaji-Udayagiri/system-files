#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

void nokku (int a,void* b)
{
	for(int i=0;i<img1.rows;i++)
		for(int j=0;j<img1.cols;j++)
	{
		if(img1.at<uchar>(j,i)>th)
			img2.at<uchar>(j,i)=255;
		else
			img2.at<uchar>(j,i)=0;
	}
   imshow ("win",img2);
}

int main()
{
	Mat img1=imread("joker.jpg",1);
	Mat img2(img1.rows,img1.cols,CV_8UC3,Scalar(0,0,0));
	namedWindow("win",1);
	int th=100;
	createTrackbar("colcola","win",&th,255,nokku);
	createTrackbar("pepsi","win",&th,255,nokku);
	createTrackbar("balayya babu","win",&th,255,nokku);
	for(int i=0;i<img1.rows;i++)
	for(int j=0;j<img1.cols;j++)
	{
		if(img1.at<uchar>(j,i)>th)
			img2.at<uchar>(j,i)=255;
		else
			img2.at<uchar>(j,i)=0;
	}
	
        waitKey (0);
	return 0;
}
