//基于哈夫曼树的数据压缩方法
#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include<memory.h>
using namespace std;

typedef struct{
	char c;
	int weight;
	int lchild, rchild, parent;
}HuffmanNode, *HuffmanTree;

typedef struct {
	char ch;
	char *pHC;
}HuffCodeNode;
typedef HuffCodeNode *HuffmanCode;

void Select(HuffmanTree &HT, int index, int &s1, int &s2)
{
	int i;
	for (i = 1; i <= index; i++)
	{
		if (HT[i].parent == 0)
		{
			break;
		}
	}
	
	s1 = i;
	for (int j = s1 + 1; j <= index; j++)
	{
		if (HT[j].parent == 0 && HT[j].weight < HT[s1].weight)
		{
			s1 = j;
		}
	}
	
	int k;
	for (k = 1; k <= index; k++)
	{
		if (HT[k].parent == 0 && k != s1)
		{
			break;
		}
	}
	s2 = k;
	for (int j = s2 + 1; j <= index; j++)
	{
		if (HT[j].parent == 0 && HT[j].weight < HT[s2].weight&&j != s1)
		{
			s2 = j;
		}
	}
}

int CreateHuffmanTree(HuffmanTree& HT, string str)
{
	map<char,int> mymap;
	for(int i=0;i<str.length();i++)
	{
		if(mymap.find(str[i]) != mymap.end())
		{
			mymap[str[i]]++;
		}
		else
		{
			mymap[str[i]] = 1;
		}
	}
	for(auto it=mymap.begin();it!=mymap.end();it++)
	{
		cout<<it->first<<":"<<it->second<<" ";
	}
	cout<<endl;
	int n = mymap.size();
	HT=new HuffmanNode[2*n];
	for(int i=0;i<2*n;i++)
	{
		HT[i].c='\0';
		HT[i].weight=0;
		HT[i].lchild=HT[i].rchild=0;
		HT[i].parent=0;
	}
	map<char,int>::iterator it=mymap.begin();
	for(int i=1; i<=n,it!=mymap.end();i++,it++)
	{
		HT[i].c=it->first;
		HT[i].weight=it->second;
	}
	for(int i=n+1;i<2*n;i++)
	{
		int s1,s2;
		Select(HT, i-1, s1, s2);
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[s2].parent=i;
		HT[s1].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	return n;
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
	HC = new HuffCodeNode[n + 1];
	char *dc = new char[n];
	dc[n - 1] = '\0';
	int start;
	for (int i = 1; i <= n; i++)
	{
		HC[i].ch = HT[i].c;
		start = n - 1;
		int c = i, f = HT[c].parent;
		while (f)
		{
			if (HT[f].lchild == c)
			{
				dc[--start] = '0';
			}
			else
			{
				dc[--start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		int m = n - start;
		HC[i].pHC = new char[m];
		memcpy(HC[i].pHC, dc + start, m);
	}
}

void HuffmanPrintInfo(HuffmanTree& HT, int n)
{
	for (int i = 1; i < 2 * n; i++)
	{
		cout << i <<' '<< HT[i].weight << ' ' << HT[i].parent<< ' ' << HT[i].lchild << ' ' << HT[i].rchild <<endl;
	}
}

void HuffmanCodePrint(HuffmanCode &HC, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << HC[i].ch<<":"<<HC[i].pHC <<" ";
	}
	cout<<endl;
}

string EncodeStr(HuffmanCode &HC, string str, int n)
{
	string res="";
	for(int i=0;i<str.length();i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str[i]==HC[j].ch)
			{
				res+=HC[j].pHC;
				break;
			}
		}
	}
	return res;
}

string DeCodeStr(HuffmanTree HT, int n, string code)
{
	string res = "";
	char ch;
	int start = 0;
	int i = 0;
	while ((ch=code[i++])!='\0')
	{
		if (ch == '0')
		{
			start = HT[2 * n - 1].lchild;
		}
		else if (ch == '1')
		{
			start = HT[2 * n - 1].rchild;
		}
		
		while (HT[start].lchild != 0)
		{
			if ((ch = code[i++]) == '\0')
			{
				return res;
			}
			if (ch == '0')
			{
				start = HT[start].lchild;
			}
			else if (ch == '1')
			{
				start = HT[start].rchild;
			}
		}
		res += HT[start].c;
	}
	return res;
}

int main()
{
	string str;
	cin >> str;
	while (str != "0")
	{
		HuffmanTree HT;
		HuffmanCode HC;
		int n = CreateHuffmanTree(HT, str);
		CreateHuffmanCode(HT, HC, n);
		HuffmanPrintInfo(HT, n);
		HuffmanCodePrint(HC, n);
		string encode = EncodeStr(HC, str, n);
		cout << encode << endl;
		string decode = DeCodeStr(HT, n, encode);
		cout << decode << endl;
		cin >> str;
	}
	return 0;
}