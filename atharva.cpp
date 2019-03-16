#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>
#include <queue>

using namespace cv;
using namespace std;

Mat img=imread("Test2.png",1);
int path[10000][2];
float ctr1 = 0.0;
float ctr2 = 0.0;
float sx=0.0, sy=0.0;
float dx=0.0, dy=0.0;

struct Node
{
    int x;
    int y;
    float f;
    float g;
    float h;
};

struct comparee{
bool operator()(const Node & a, const Node & b)
    {
    return a.f > b.f;
}
};

Node dest, start;
bool closedlist[600][1000] = {0};
priority_queue<Node, vector<Node>, comparee> openlist;

void sdcalc()
{
int l,m;
for(l=0; l<img.rows; l++)
{
        for(m=0; m<img.cols; m++)
    {
        if((img.at<Vec3b>(l,m)[0] == 0 && img.at<Vec3b>(l,m)[1] == 255) && img.at<Vec3b>(l,m)[2] == 0)
        {
            sx+=l;
            sy+=m;
            ctr1 += 1.0;
        }
       
        if((img.at<Vec3b>(l,m)[0] == 0 && img.at<Vec3b>(l,m)[1] == 0) && img.at<Vec3b>(l,m)[2] == 255)
        {
            dx+=l;
            dy+=m;
            ctr2 += 1.0;
        }

    }
}

start.x = (sx)/(ctr1);
start.y = (sy)/(ctr1);
dest.x = (dx)/(ctr2);
dest.y = (dy)/(ctr2);
}


void ffunc (Node *p, Node *q)
{
    p->h = ( (abs(dest.x - p->x)>abs(dest.y - p->y)) ? (dest.x-p->x) : (dest.y-p->y) );
    if (abs(p->x - q->x)==1 && abs(p->y - q->y)==1)
        p->g = sqrt(2.0);
    else
        p->g = 1.0;
    p->f = p->g + p->h;
}

bool isdest(Node* p)
{
     return (((p->x == dest.x)&&(p->y == dest.y)) ? true : false);
}

bool isvalid(int i, int j)
{
    if((i>0 && i<img.cols)&&(j>0 && j<img.cols))
    {
       
            if((img.at<Vec3b>(i,j)[0]==255) && (img.at<Vec3b>(i,j)[1]==255) &&img.at<Vec3b>(i,j)[2]==255)
                {
                 return false;
               
                        }
           
      
        return true;   
    }
    return false;
}

void sucessorgen(int i, int j, Node *p)
{
   
    Node q;
        ffunc (&q,p);
        if(isvalid(q.x,q.y))
    {
   
         q.x = i + p->x;
         q.y = j + p->y;
        if(!isdest(&q))
        {   
            if(closedlist[q.x][q.y])
            return;
           
            openlist.push(q);
                }
             else
             return;
        }
   
}

int main()
{
    sdcalc();
    start.f = 0.0;
    start.g = 0.0;
    start.h = 0.0;
    openlist.push(start);
        int ctr=0;
        while (!openlist.empty())
    {
       
                Node q = openlist.top();
        img.at<Vec3b>(q.x,q.y)[0] =0;
                img.at<Vec3b>(q.x,q.y)[1] =0;
                img.at<Vec3b>(q.x,q.y)[2] =255;
        openlist.pop();
        path[ctr][0] = q.x;
        path[ctr][1] = q.y;
        sucessorgen(1,0,&q);
        sucessorgen(0,1,&q);
        sucessorgen(-1,0,&q);
        sucessorgen(0,-1,&q);
        sucessorgen(1,-1,&q);
        sucessorgen(-1,1,&q);
        sucessorgen(-1,-1,&q);
        sucessorgen(1,1,&q);
        closedlist[q.x][q.y] = 1;   
        ctr++;
        }
cout<<isvalid(dest.x,dest.y);
namedWindow("IMAGE",WINDOW_NORMAL);
imshow("IMAGE",img);
/*for(int i=0; i<ctr; i++)
cout<<path[i].x<<" "<<path[i].y<<endl; */
waitKey(0);
return 0;
}


