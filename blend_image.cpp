#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img1=imread("circle.jpg",1);
	Mat img2(500,500,CV_8UC3,Scalar(0,0,0));
	Mat img3(500,500,CV_8UC3,Scalar(0,0,0));
	namedWindow("win",1);
	for(float i=0;i<=1;i+=0.05)
	{
		img3=i*img1+(1-i)*img2;
		imshow("win",img3);
		waitKey(200);
	}
}
