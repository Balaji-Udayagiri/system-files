#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
 src = imread("66.jpg",1);
dst = Mat.zeros(src.rows, src.cols, cv.CV_8UC3);
cvtColor(src, src, cv.COLOR_RGBA2GRAY, 0);
threshold(src, src, 177, 200, cv.THRESH_BINARY);
contours = new cv.MatVector();
hierarchy = new cv.Mat();
line = new cv.Mat();
findContours(src, contours, hierarchy, cv.RETR_CCOMP, cv.CHAIN_APPROX_SIMPLE);
let cnt = contours.get(0);
// You can try more different parameters
fitLine(cnt, line, DIST_L2, 0, 0.01, 0.01);
contoursColor = new Scalar(255, 255, 255);
lineColor = new Scalar(255, 0, 0);
drawContours(dst, contours, 0, contoursColor, 1, 8, hierarchy, 100);
vx = line.data32F[0];
vy = line.data32F[1];
x = line.data32F[2];
y = line.data32F[3];
lefty = Math.round((-x * vy / vx) + y);
righty = Math.round(((src.cols - x) * vy / vx) + y);
point1 = new cv.Point(src.cols - 1, righty);
point2 = new cv.Point(0, lefty);
line(dst, point1, point2, lineColor, 2, cv.LINE_AA, 0);
imshow("canvasOutput", dst);
//delete(); dst.delete(); contours.delete(); hierarchy.delete(); line.delete(); cnt.delete();

}
