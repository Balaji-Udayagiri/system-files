#include<iostream>
#include<math.h>
using namespace std;

typedef struct Data
{
	float x;
	float y;
}data;
data centroid (data A[],int n)
{
 	data sum;
	data avg;
	sum.x=0;
	sum.y=0;
	for(int i=0;i<10;i++)
		{
			sum.x+=A[i].x;
			sum.y+=A[i].y;
		}
	avg.x=sum.x/n;
	avg.y=sum.y/n;
	return avg;
}
float distance(data a,data b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int isPresent(data var,data arr[])
{
	for(int i=0;i<10;i++)
		if(arr[i].x==var.x&&arr[i].y==var.y)
			return 1;
 	return 0;
}
int main()
{
data info[10];
info[0].x=2;
info[0].y=6;
info[1].x=3;
info[1].y=4;
info[2].x=3;
info[2].y=8;
info[3].x=4;
info[3].y=7;
info[4].x=6;
info[4].y=2;
info[5].x=6;
info[5].y=4;
info[6].x=7;
info[6].y=3;
info[7].x=7;
info[7].y=4;
info[8].x=8;
info[8].y=5;
info[9].x=7;
info[9].y=6;

int flag =1;

data arr1;
int n1=0;

data arr2;
int n2=0;

for(int i=0;i<10;i++)
 	{
		arr1[i].x=0;
		arr1[i].y=0;	
	}

for(int i=0;i<10;i++)
 	{
		arr2[i].x=0;
		arr2[i].y=0;	
	}

arr1[1].x=3;
arr1[1].y=4;
n1++;

arr2[7].x=7;
arr2[7].y=4;
n2++;

while(flag)
{
	flag=0;
	for(int i=0;i<10;i++)
	{
		if(distance(centroid(arr1,n1),info[i])<distance(centroid(arr2,n2),info[i]))
		{
			if(isPresent(info[i],arr2))
			{	
				arr2[i].x=0;
				arr2[i].y=0;
				n2--;
				flag=1;
			}	
			if(isPresent(info[i],arr1))
			{
				flag=0
				continue;
			}
			
			else
			{
					arr1[i]=info[i];
					n1++;
					flag=1;
			}
		}

		else
		{
			if(isPresent(info[i],arr1))
			{	
				arr1[i].x=0;
				arr1[i].y=0;
				n1--;
				flag=1;
			}	
			if(isPresent(info[i],arr2))
			{
				flag=0;
				continue;
			}
			else
			{
					arr2[i]=info[i];
					n2++;
					flag=1;
			}
				
		}	
				
	}
}

for(int i=0;i<10;i++)
{
	if(arr1[i]!=0)
	cout<<i<<endl;
}


return 0;
}



