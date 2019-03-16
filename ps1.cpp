#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	namedWindow("cam",0);
	VideoCapture colour_detector(0);
`	Mat frame;

	while(1)
	{
		colour_detector>>frame;	
		if(frame.empty())
			break;
		for(int i=0;i<frame.rows;i++)
			for(int j=0;j<frame.cols;j++)
			{
				frames.at<Vec3b>[0]=0;
				frames.at<Vec3b>[1]=0;

				if(frames.at<Vec3b>[2]>150)
				{
				frames.at<Vec3b>[2]=255;
				}				}
				else
				frames.at<Vec3b>[2]=0;
		Mat canny_img;
		Canny(frame,canny_img,15,50,3);
			
		findContours(canyy_img,0,)
	}
}

