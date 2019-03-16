#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int th=128;

void onmove(int a,void* b)
{
	Mat img=imread("circle2.png",0);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));        
	Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));        
	Mat img4(img.rows,img.cols,CV_8UC1,Scalar(0));

	int kernel1[3][3]={-1,-1,-1,0,0,0,1,1,1}, kernel2[3][3]={-1,0,1,-1,0,1,-1,0,1};
	
	for (int i=1;i<img.rows-1;i++)
		for (int j=1;j<img.cols-1;j++)
			for (int l=0;l<3;l++)
				for (int m=0;m<3;m++)			
					img2.at<uchar>(i,j)+=kernel1[l][m]*img.at<uchar>(i-1+l,j-1+m);

	for (int i=1;i<img.rows-1;i++)
		for (int j=1;j<img.cols-1;j++)
			for (int l=0;l<3;l++)
				for (int m=0;m<3;m++)			
					img3.at<uchar>(i,j)+=kernel2[l][m]*img.at<uchar>(i-1+l,j-1+m);
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			img4.at<uchar>(i,j)=sqrt((img2.at<uchar>(i,j))*(img2.at<uchar>(i,j))+(img3.at<uchar>(i,j))*(img3.at<uchar>(i,j)));
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			if(img4.at<uchar>(i,j)>th)
				img4.at<uchar>(i,j)=255;
			else
				img4.at<uchar>(i,j)=0;
	imshow("win",img4);
}

int main()
{
	
	namedWindow("win",1);
	createTrackbar("tracky","win",&th,255,onmove);
	waitKey(0);

	return 0;
}
