#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include<cmath>
using namespace cv;
using namespace std;
 
int main()
{
 int n=0,k,s,s1,c;
Mat img1=imread("88.jpg",0);
for(int i=0;i<img1.rows;i++)
 img1.at<uchar>(i,0)=0;
for(int i=0;i<img1.rows;i++)
 img1.at<uchar>(i,img1.cols-1)=0;
for(int j=0;j<img1.cols;j++)
 img1.at<uchar>(0,j)=0;
for(int j=0;j<img1.cols;j++)
 img1.at<uchar>(img1.rows-1,j)=0;
Mat src(img1.rows,img1.cols,CV_8UC1,Scalar(0));

 dilate(img1,src,Mat());
    
    Mat dst, cdst;
    Canny(src, cdst, 50, 200, 3);
    //cvtColor(dst, cdst, CV_GRAY2BGR);
    int t1;
Mat temp(cdst.size(), CV_8UC3);
//namedWindow("win",WINDOW_AUTOSIZE);

vector<Vec4i> lines;


    HoughLinesP(cdst, lines, 1, CV_PI/180, 100, 50, 180 );
   for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        // draw the lines
        line( temp, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 3, CV_AA);
    }
  
    waitKey(1);
   
    
    
Vec4i l1 = lines[0];
s=(l1[0]-l1[2])/(l1[1]-l1[3]);
vector<int> slope;
slope.push_back(s);
n++;

for(size_t i=1;i<lines.size();i++)
{
Vec4i l1 = lines[i];

s=(l1[0]-l1[2])/(l1[1]-l1[3]);
s1=(int)(atan(s)*180/3.14);
c=0;
for(k=0;k<n;k++)
{

if(abs(s1-slope[k])<20)
{

c++;
break;

}

}

if(c==0)
{

slope.push_back(s1);
n++;

}


}

cout<<n-1;
 
//imshow("win",temp);
//namedWindow("wino",WINDOW_AUTOSIZE);
//imshow("wino",cdst);
 waitKey(0);
return 0;
}
