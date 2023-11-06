#include<iostream>
#include<math.h>
using namespace std;
class item
{
	public :
	int w;
	int p;
};
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
void sort(item a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].w>a[j+1].w)
			{
				item temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
void sack(int n,int c,item a[])
{
	int maxprofit[n+1][c+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<c+1;j++)
		{
			if(i==0||j==0)
			{
				maxprofit[i][j]=0;
			}
			else
			{
				maxprofit[i][j]= max(maxprofit[i-1][j], (maxprofit[i-1][j-a[i-1].w]+a[i-1].p));
					      // max(maxprofit[i-1][j], (maxprofit[i-1][j-a[i-1].w]+a[i-1].p));
									
			}
		}
	}
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<c+1;j++)
		{
			cout<<maxprofit[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,c;
	cout<<"enter no. of obj=";
	cin>>n;
	cout<<"enter capacity=";
	cin>>c;
	item a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter weight of obj"<<i+1<<"=";
		cin>>a[i].w;
		cout<<"enter profit of obj"<<i+1<<"=";
		cin>>a[i].p;
		
	}
	sort(a,n);
	sack(n,c,a);
	return 0;
}
/*
output:

mrinmayi@mrinmayi-VirtualBox:~$ cd daa
mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ d.cpp
mrinmayi@mrinmayi-VirtualBox:~/daa$ ./a.out
enter no. of objects=5
enter knapsack capacity=7
enter weight of object1=2
enter profit of object1=15
enter weight of object2=4
enter profit of object2=14
enter weight of object3=1
enter profit of object3=10
enter weight of object4=3
enter profit of object4=45
enter weight of object5=4
enter profit of object5=30
0 0 0 0 0 0 0 0 
0 10 10 10 10 10 10 10 
0 15 15 25 25 25 25 25 
0 55 55 45 60 60 70 70 
0 55 55 45 60 69 70 70 
0 90 100 100 60 85 85 75 

mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ d.cpp
mrinmayi@mrinmayi-VirtualBox:~/daa$ ./a.out
enter no. of obj=5
enter capacity=10
enter weight of obj1=1
enter profit of obj1=2
enter weight of obj2=3
enter profit of obj2=4
enter weight of obj3=5
enter profit of obj3=6
enter weight of obj4=7
enter profit of obj4=8
enter weight of obj5=9
enter profit of obj5=1
0 0 0 0 0 0 0 0 0 0 0 
0 2 2 2 2 2 2 2 2 2 2 
0 4 4 4 6 6 6 6 6 6 6 
0 8 8 8 8 6 10 10 10 12 12 
0 14 14 14 14 14 14 10 16 16 16 
0 14 14 14 14 14 14 13 16 16 16 
*/


