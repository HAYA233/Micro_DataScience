#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;

bool Find(string Peo_DNA, string Vir_DNA, int i) 
{
	int len_Peo = Peo_DNA.length();
	int len_Vir = Vir_DNA.length();
	int num = 0, j = 0;
	
	for (j = 0; j<2*len_Vir && i+j<len_Peo; j++) 
	{
		if (Peo_DNA[i+j] == Vir_DNA[j]) 
		{
			num++;
		}
		else
		{
			num = 0;
		}
		if (num == len_Vir) 
		{
			return true;
		}
	}
	return false;
}

int main() {
	string Peo_DNA, Vir_DNA;
	while (true) 
	{
		cout << "请输入病毒和人的DNA序列：";
		cin >> Vir_DNA >> Peo_DNA;
		
		int len_Vir = Vir_DNA.length();
		int len_Peo = Peo_DNA.length();
		
		if (Vir_DNA == "0" && Peo_DNA == "0") 
		{
			cout << "OVER" << endl;
			break;
		}
		if (!len_Vir || !len_Peo) 
		{
			cout << "空数据集无效" << endl;
			continue;
		}
		if (len_Vir >= len_Peo) 
		{
			cout << "ERROR 人的DNA应长于病毒" << endl;
			continue;
		}
		
		int i;
		for (i = 0; i < len_Vir - 1; i++) 
		{
			Peo_DNA = " " + Peo_DNA;
		}
		
		len_Peo = len_Peo + len_Vir - 1;
		
		for (i = 0; i < len_Peo - len_Vir; i++) 
		{
			if (Find(Peo_DNA, Vir_DNA, i)) 
			{
				cout << "YES" << endl;
				break;
			}
		}
		if (i >= len_Peo - len_Vir) 
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
