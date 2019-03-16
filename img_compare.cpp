#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>

using namespace cv;

using namespace std;

int main() 
{
	int wsize=11;
	Mat left=imread("ambush_5_left.jpg",0);
	Mat right=imread("ambush_5_right.jpg",0);
	Mat Disparity(left.rows,left.cols,CV_8UC1,Scalar(0));
	Mat w1,w2,result;
	int maxdisp,disp;
	result.create( 1,left.cols-wsize+1,CV_32FC1);
	for(int i=(wsize-1)/2;i<left.rows-(wsize-1)/2;i++)
	{ 
  		for(int j=(wsize-1)/2;j<left.cols-(wsize-1)/2;j++)
  		{
    			w1=left(Range(i-(wsize-1)/2,wsize-1+i-(wsize-1)/2),Range(j-(wsize-1)/2,wsize-1+j-(wsize-1)/2)); //Window around selected pixel in left image
		    w2=right(Range(i-(wsize-1)/2,wsize-1+i-(wsize-1)/2),Range(0,left.cols-1));  //Checking region in right image
		    matchTemplate(w2, w1, result, CV_TM_SQDIFF_NORMED );    //SSD to find closest match
		    //normalize( result, result, 0, ,NORM_MINMAX,-1,Mat())
		    double minVal; double maxVal; Point minLoc; Point maxLoc;    
		    Point matchLoc;   //Point where location matches
		    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
		    matchLoc=minLoc;
		    disp=abs(i-matchLoc.x);
		    if (maxdisp<disp)
		      maxdisp=disp;
		    Disparity.at<uchar>(i,j)=255*((float)disp/(float)(l.cols-6));
		      
		}
	}
	namedWindow("W",WINDOW_NORMAL);
	imshow("W", Disparity);

	waitKey(0);
	return 0;

}



