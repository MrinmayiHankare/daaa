#include<iostream>
#include<math.h>
using namespace std;
class bag
{
	public:
	int id;
	double w;
	double p;
	double r;
	double ratio()
	{
		return r=p/w;
	}
	double fraction;
	
	void sort(bag a[],int n);
	void sack(bag a[],int n,double capacity);
};
void bag::sort(bag a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].r<a[j+1].r)
			{
				bag temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp; 
			}
		}
	}
}
void bag::sack(bag a[],int n,double capacity)
{
	double TW=0,TP=0;
	int i=0;
	while(1)
	{
		if(TW<capacity)
		{
			if(a[i].w<=(capacity-TW))
			{
				a[i].fraction=1;
				TW+=a[i].w;
				TP+=a[i].p;
			}
			else if(a[i].w>(capacity-TW))
			{
				a[i].fraction=(capacity-TW)/a[i].w;
				TW+=a[i].fraction*a[i].w;
				TP+=a[i].fraction*a[i].p;
			}
		}
		else
		{
			break;
		}
		i++;
	}
	cout<<"total profit="<<TP<<"\n";
}
int main()
{
	int n;
	double capacity;
	cout<<"enter no. of obj=";
	cin>>n;
	cout<<"enter capacity=";
	cin>>capacity;
	bag b;
	bag obj[n];
	for(int i=0;i<n;i++)
	{
		obj[i].id=i+1;
		cout<<"enter weight of obj"<<i+1<<"=";
		cin>>obj[i].w;
		cout<<"enter profit of obj"<<i+1<<"=";
		cin>>obj[i].p;
		obj[i].ratio();
	}
	cout<<"displaying table:\n";
	cout<<"id\t"<<"weight\t"<<"profit\t"<<"ratio\t"<<"fraction\n";
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].id<<"\t"<<obj[i].w<<"\t"<<obj[i].p<<"\t"<<obj[i].r<<"\t"<<obj[i].fraction<<"\n";
	}
	cout<<"displaying table after sorting:\n";
	cout<<"id\t"<<"weight\t"<<"profit\t"<<"ratio\t"<<"fraction\n";
	b.sort(obj,n);
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].id<<"\t"<<obj[i].w<<"\t"<<obj[i].p<<"\t"<<obj[i].r<<"\t"<<obj[i].fraction<<"\n";
	}
	b.sack(obj,n,capacity);
	return 0;
}

/*
output

mrinmayi@mrinmayi-VirtualBox:~$ cd daa
mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ g.cpp
mrinmayi@mrinmayi-VirtualBox:~/daa$ ./a.out
enter no. of objects=7
enter capacity=15
enter weight of obj1=2
enter profit of obj1=10
enter weight of obj2=3
enter profit of obj2=5
enter weight of obj3=5
enter profit of obj3=15
enter weight of obj4=7
enter profit of obj4=7
enter weight of obj5=1
enter profit of obj5=6
enter weight of obj6=4
enter profit of obj6=18
enter weight of obj7=1
enter profit of obj7=3

id	weight	profit	ratio	fraction
1	2	10	5	0
2	3	5	1.66667	2.122e-314
3	5	15	3	6.9487e-310
4	7	7	1	1.36389e+253
5	1	6	6	6.95331e-310
6	4	18	4.5	6.95331e-310
7	1	3	3	6.95331e-310

after sorting

id	weight	profit	ratio	fraction
5	1	6	6	6.95331e-310
1	2	10	5	0
6	4	18	4.5	6.95331e-310
3	5	15	3	6.9487e-310
7	1	3	3	6.95331e-310
2	3	5	1.66667	2.122e-314
4	7	7	1	1.36389e+253
total profit=55.3333


mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ g.cpp
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
displaying table:
id	weight	profit	ratio	fraction
1	1	2	2	6.91721e-310
2	3	4	1.33333	9.25264e-122
3	5	6	1.2	6.95296e-310
4	7	8	1.14286	6.95296e-310
5	9	1	0.111111	6.95296e-310
displaying table after sorting:
id	weight	profit	ratio	fraction
1	1	2	2	6.91721e-310
2	3	4	1.33333	9.25264e-122
3	5	6	1.2	6.95296e-310
4	7	8	1.14286	6.95296e-310
5	9	1	0.111111	6.95296e-310
total profit=13.1429

*/






















