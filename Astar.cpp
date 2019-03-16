#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include<math.h>
#include <queue>

using namespace cv;
using namespace std;

Mat img=imread("Test2.png",1); 

int ctr1 = 0;
int ctr2 = 0;


struct Node
{
	int x;
	int y;
	float f;
	float g;
	float h;
};

Node dest,start;
bool closedlist[img.cols][img.rows] = {0};
priority_queue <Node> openlist;

for(int p=0; p<img.rows; p++)
{
	for(int q=0; q<img.cols; q++)
	{
		if(img.at<Vec3b>(p,q)[0] = 0 && img.at<Vec3b>(p,q)[0] = 255 && img.at<Vec3b>(p,q)[0] = 0)
	    {
	    	start.x+=p;
	    	start.y+=q;
	        ctr1 +=1;
	    }
	    
	    if(img.at<Vec3b>(p,q)[0] = 0 && img.at<Vec3b>(p,q)[0] = 0 && img.at<Vec3b>(p,q)[0] = 255)
	    {
	    	dest.x+=p;
	    	dest.y+=q;
	        ctr2 +=1;
	    }

	}
}
start.x/=ctr1;
start.y/=ctr1;
dest.x/=ctr2;
dest.y/=ctr2;


struct compare{
bool operator()(const Node & a, const Node & b)
    {
        if(a.f == b.f)
        {
            return a.h > b.h;
        }
        else
        {
            return a.f > b.f;
        }
}
};

void ffunc (Node *p, Node *q)
{
	p->h = ( (abs(dest->x - p->x)>abs(dest->y - p->y)) ? (dest.x-p.x) : (dest.y-p.y) )
    if (abs(p->x - q->x)==1 && abs(p->y - q->y)==1)
    	p->g = sqrt(2.0);
    else
    	p->g = 1.0;
    p->f = g + h;
}

bool isdest(Node* p)
{
 	return (((p->x == dest->x)&&(p->y == dest->y)) ? true ? false);
}

bool isvalid(int i, int j)
{
	flag = 0;
	if((i<0 || i>img.cols)||(j<0 || j>img.cols))
    {
    	for(int k=0; k<3; k++)
    	{
    		if(img.at<Vec3b>(i,j)[k]!=0)
    			{
    				flag = 1;
    				break;
    			}
    	}
        if(flag==1)
        return false;
        else 
        return true;	
    }
    return false;
}

void sucessorgen(int i, int j, Node *p)
{
    Node q;
    q.x = i + p->x;
    q.y = i + p->y;
	if(isvalid(q.x,q.y))
	{
	
		if(!isdest(&q))
		{	
			if(closedlist[q.x][q.y])
			return;
			
			ffunc (&q,p);
			openlist.push(q);
    	    
            
    	}
    }
    else 
    return;
}

int main()
{
	start.g=0.0;
    openlist.push(start);
 
	while (!openlist.empty())
	{
		Node q = openlist.front()
		img.at<Vec3b>(q.x,q.y)={0,0,255};
        openlist.pop();
        sucessorgen(1,0,&q);
        sucessorgen(0,1,&q);
        sucessorgen(-1,0,&q);
        sucessorgen(0,-1,&q);
        sucessorgen(1,-1,&q);
        sucessorgen(-1,1,&q);
        sucessorgen(-1,-1,&q);
        sucessorgen(1,1,&q);
        closedlist[q.x][q.y] = 1;
	
		
	}
	namedWindow("win",0);
	imshow("win",img);
	waitKey(0);

	return 0;
}
