#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat img1=imread("canned.jpg",0);

void callbackfunc(int event,int x,int y,int flag, void* b)
{
	int a=0;
	float r=0.0;
	Mat img((int)sqrt((img1.rows)*(img1.rows)+(img1.cols)*(img1.cols)),180,CV_8UC1,Scalar(255));
	namedWindow("win2",1);
	if(event==EVENT_RBUTTONDOWN)
		{
		for(a=0;a<180;a++)
			{
				r=x*cos((float)a*3.14/180)+y*sin((float)a*3.14/180);
				int r1=(int)r; 
				img.at<uchar>(r1,a)=0;
			}
		imshow("win2",img);
		}
}


	
	

int main()
{
	namedWindow("win",1);
	
	
	setMouseCallback("win",callbackfunc,NULL);
		
	imshow("win",img1);
	
	waitKey(0);
	return 0;
}
