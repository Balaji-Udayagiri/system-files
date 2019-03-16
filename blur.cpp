#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	namedWindow("happy1",1);
	namedWindow("happy2",1);
	namedWindow("happy3",1);
	double kernel1[3][3];	
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
   			kernel1[i][j]=1.0/9.0;
	double kernel3[3][3]={-1,0,1,-1,0,1,-1,0,1};                                                   //{1/16.0,1/8.0,1/16.0,1/8.0,1/4.0,1/8.0,1/16.0,1/8.0,1/16.0};
	double kernel2[3][3]={-1,-1,-1,0,0,0,1,1,1};
	Mat img1=imread("joker.jpg",0);
	Mat img2(img1.rows+2,img1.cols+2,CV_8UC1,Scalar(0));
	for (int i=0;i<img1.rows;i++)
		for (int j=0;j<img1.cols;j++)
			img2.at<uchar>(i+1,j+1)=img1.at<uchar>(i,j);
	Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Mat img4(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	for(int i=1;i<=img1.rows;i++)
		for(int j=1;j<=img1.cols;j++)
		{
			
			int l,m;
			for(l=0;l<3;l++)
				for(m=0;m<3;m++)
				img3.at<uchar>(i-1,j-1)+=kernel1[l][m]*img2.at<uchar>(i-1+l,j-1+m);

		}
	for(int i=1;i<=img1.rows;i++)
		for(int j=1;j<=img1.cols;j++)
		{
			
			int l,m;
			for(l=0;l<3;l++)
				for(m=0;m<3;m++)
				img4.at<uchar>(i-1,j-1)+=kernel3[l][m]*img2.at<uchar>(i-1+l,j-1+m);

		}
	

    	imshow("happy1",img3);
	imshow("happy2",img4);
	imshow("happy3",img2);
	waitKey(0);
	return 0;
     
}










/*img3.at<uchar>(i-1,j-1)=kernel[0][0]*img2.at<uchar>(i-1,j-1)+kernel[0][1]*img2.at<uchar>(i-1,j)+kernel[0][2]*img2.at<uchar>(i-1,j+1)+kernel[1][0]*img2.at<uchar>(i,j-1)+kernel[1][1]*img2.at<uchar>(i,j)+kernel[1][2]*img2.at<uchar>(i,j+1)+kernel[2][0]*img2.at<uchar>(i+1,j-1)+kernel[2][1]*img2.at<uchar>(i+1,j)+kernel[2][2]*img2.at<uchar>(i+1,j+1);*/
