#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"

#include <iostream>

using namespace cv;

using namespace std;

 int bl=0;
int bh=255;    //100
int gl=0;      
int gh=255;    //70
int rl=0;     //85
int rh=255;
int th=190;

int main()

{

 //int i,j;

 //Mat img1(1,1,CV_8UC3,Scalar(0,0,0));

 VideoCapture vid(0);
//int Skip=0;
 Mat frame;
int ctr=0;
 
 while(1)

 {
   int flag=0;
  vid>>frame;
  medianBlur(frame,frame,3);
  for(int i=0;i<frame.rows;i++)
  {
    for(int j=0;j<frame.cols;j++)
    {
      if(!((frame.at<Vec3b>(i,j)[0]<=bh && frame.at<Vec3b>(i,j)[0] >=bl) && (frame.at<Vec3b>(i,j)[1]<=gh && frame.at<Vec3b>(i,j)[1] >=gl) && (frame.at<Vec3b>(i,j)[2]<=rh && frame.at<Vec3b>(i,j)[2] >=rl)))
      {
          frame.at<Vec3b>(i,j)={0,0,0};
      }
    }
  }
 
  Mat img1;
  cvtColor(frame,img1,CV_RGB2HSV);
  //for(i=0;i<=frame.cols;i++)
  vector<Mat> hsv_channels;
  split(img1, hsv_channels);
  Mat intensity=hsv_channels[2];

  for(int i=0;i<frame.rows;i++)
  {
    for(int j=0;j<frame.cols;j++)
    {
      if(intensity.at<uchar>(i,j)<=th)
      {
          intensity.at<uchar>(i,j)=0;
      }
    }
  }
 
   for(int r=0;r<frame.cols;r++) 
  {

   for(int s=0;s<=frame.rows;s++)

   {

    img1.at<Vec3b>(0,0)=frame.at<Vec3b>(s,r);

    frame.at<Vec3b>(s,frame.cols-r-1)=img1.at<Vec3b>(0,0);

   }

  }

  Mat element= getStructuringElement(MORPH_RECT,Size(5,5),Point(3,3));
  erode(intensity,intensity,element);
  dilate(intensity,intensity,element);

 
  vector<vector<Point> >contours;
  vector<Vec4i> hierarchy;
  findContours(intensity, contours, hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
 
   Mat drawing = Mat::zeros( intensity.size(), CV_8UC3 );
  //drawing = intensity;
  float area;
  for(int p=0;p<contours.size();p++)
  { area = contourArea(contours[0]);
   
    if(area>30.0)
    drawContours(drawing ,contours,p, Scalar(0,255,0),2, 8, hierarchy,0, Point());
 
 }
 
  Mat Black(drawing.size(),CV_8UC3,Scalar(0,0,0));
  for(int a=0;a<drawing.rows;a++)
{
  for(int b=0;b<drawing.cols;b++)
  {
   
    if(drawing.at<Vec3b>(a,b)[1]!=0)
      {flag=1;
      break;}
  }
}

  if(flag==1)
  {
    ctr++;
  }
  if(flag==0)
  {
    //Skip++;
    if(ctr!=0)
      cout<<50.0/((float)ctr)<<" ";
  }
  imshow("win",drawing);

  waitKey(10);

 }

 return 0;

}
