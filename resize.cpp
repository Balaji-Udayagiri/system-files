#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;
int x=1;
void onmove(int a, void* b)
{
	Mat img1=imread("fruits.jpg",0);
	
	Mat img2(6*img1.rows,6*img1.cols,CV_8UC1,Scalar(0));
	
	for(int i=0;i<=x*(img1.rows-1);i++)
		for(int j=0;j<=x*(img1.rows-1);j++)
			img2.at<uchar>(i,j)=img1.at<uchar>(i/x,j/x);
	imshow("win",img2);
}
int main()
{
	namedWindow("win",1);
	createTrackbar("scale_factor","win",&x,6,onmove);	
	waitKey(0);
	return 0;
}
