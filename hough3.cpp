#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
 {
 int x,y,r,th,flag=0;
 Mat img=imread("squarecan.jpg",0);
 Mat img2(900,400,CV_8UC1,Scalar(0));
 Mat img3;
 for(x=0;x<img.rows;x++)
  {
  for(y=0;y<img.cols;y++)
   {
   if(img.at<uchar>(x,y)>250)
    {
    for(th=0;th<180;th+=1)
     {
     r=y*cos(th*(CV_PI/180))+x*sin(th*(CV_PI/180));
     img2.at<uchar>(r+500,th)+=5;
     }
    }
   }
  }
 namedWindow("Win",0);
 imwrite("ht.jpg",img2);
 imshow("Win",img2);
 waitKey(0); 
 return 0;
 } 
