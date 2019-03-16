#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;



int main()
{
	int thr,thb,thg;
	Mat img1=imread("Test2.png",1);
	Mat img2(img1.rows,img1.cols,CV_8UC3,Scalar(0,0,0));
	namedWindow("win",0);
	createTrackbar("red","win",&thr,255);
	createTrackbar("blue","win",&thb,255);
	createTrackbar("green","win",&thg,255);
	
	while(1)
	{
		for(int i=0;i<img1.rows;i++)
			for(int j=0;j<img1.cols;j++)
			{	
			

				if(img1.at<Vec3b>(i,j)[0]>thb)
					img2.at<Vec3b>(i,j)[0]=img1.at<Vec3b>(i,j)[0];
				else
					img2.at<Vec3b>(i,j)[0]=0;

				if(img1.at<Vec3b>(i,j)[1]>thg)
						img2.at<Vec3b>(i,j)[1]=img1.at<Vec3b>(i,j)[1];
				else
					img2.at<Vec3b>(i,j)[1]=0;
				if(img1.at<Vec3b>(i,j)[2]>thr)
					img2.at<Vec3b>(i,j)[2]=img1.at<Vec3b>(i,j)[2];
				else
					img2.at<Vec3b>(i,j)[2]=0;
			}
		imshow("win",img2);
		waitKey(1);
	}
}
