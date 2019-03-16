#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

Mat img(500,500,CV_8UC1,Scalar(255));

void callbackfunc(int event, int x,int y,int flag,void* a)
{
	
	if(event==EVENT_LBUTTONDOWN)
	{

	cout<<x;		
	/*for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			img.at<uchar>(x-2+i,y-2+j)=0;*/
	}
}

int main()
{
	
	namedWindow("win",1);
	//while(1)
	{
		
		setMouseCallback("win",callbackfunc,NULL);
			imshow("win",img);
		waitKey(0);
	}	
	return 0;
}
