#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int total[1000];
 
int del(int total[1000],int location1,int totalnum)
{
	int i ;
	for(i = location1; i < totalnum; i++)//遍历顺序表 计数
	{
		total[i] = total[i+1];
	}
	return 0;
}

int Joseph(int total[1000], double location, double totalnum, double deletenum)
{
	int count = 0;
	int totalnum1 = totalnum;
	int location1 = location-1;
	for(count = 0; count < totalnum; count++)
	{
		if(location1 > totalnum1 - 1)
		{
			location1 = location1 % totalnum1;
		}
		for(int j = 1; j <deletenum; j++)
		{
			location1++;
		}
		if(location1 > totalnum1 - 1)
	    {
	    	location1 %= totalnum1; 
		}
	    cout << total[location1] << " " << "->";
		del(total, location1, totalnum);
		totalnum1--;
	}
	return 0;
}


int main()
{
	double totalnum, deletenum, location;
	
	//输入各个参数
	cout << "请输入总人数 Totalnum: ";
	cin >> totalnum;
	
	int flag = 1;
	while(flag)
	{
		if(totalnum > 0)
		{
			flag = 0;
		}
		else if(flag)
		{
			cout << "输入数据违规，请重新输入 Totalnum: " << endl; 
			cin >> totalnum;
		}
	}
	
	cout << "请输入开始的位置 Location: ";
	cin >> location;
	
	flag = 1;
	while(flag)
	{
		if( location > 0 && location <= totalnum) 
		{
			flag = 0;
	    }
		else if(flag)
		{
			cout << "输入数据违规，请重新输入 Location: "; 
			cin >> location ;
		} 
	}
	
	cout << "请输入想要删除的序数 Deletenum: ";
	cin >> deletenum;
	
	flag = 1;
	while(flag)
	{
		if( deletenum > 0 && deletenum <= totalnum) 
		{
			flag = 0;
		}
		else if(flag)
		{
			cout << "输入数据违规，请重新输入 Deletenum: "; 
			cin >> deletenum;
		} 
	}

	for(int i = 0; i < totalnum;i++)//构造顺序表
	{
		total[i] = i + 1;
	}
	
	Joseph(total,location,totalnum,deletenum); //函数主体
} 
