#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc , char ** argv)
{
	int r ;
	Mat circle(500,500,CV_8UC3,Scalar(0,0,0));

	cout << "Enter the radius of circle (must be less than "<<circle.rows/2<<" )"<<endl;
	cin >> r ;
	
	for(int i=0;i<circle.rows;i++)
	{
		for(int j=0;j<circle.cols;j++)
		{
			if(norm(Point(i,j)-Point(250,250))<r)
			{
				circle.at<Vec3b>(i,j)[0]=0;
				circle.at<Vec3b>(i,j)[1]=255;
				circle.at<Vec3b>(i,j)[2]=0;
			}
		}
	}
	namedWindow("circle",CV_WINDOW_NORMAL);
	imshow("circle",circle);
	imwrite("circle.jpg",circle);
	waitKey(0);
}