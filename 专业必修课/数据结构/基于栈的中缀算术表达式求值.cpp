#include <iostream>
#include<cmath>
#include <iomanip>
#define MAXSIZE 1000
using namespace std;

char op[7] = { '+', '-', '*', '/', '(', ')', '=' };
 
typedef struct 
{
	char *base;
	char *top;
	int stacksize;
}SqStack1;
 
typedef struct 
{
	double *base;
	double *top;
	int stacksize;
}SqStack2;
 
int InitStack(SqStack1 &S)
{
 	S.base=new char[MAXSIZE];
	if(!S.base) 
	{
		return 0;
	}
 	S.top=S.base;
 	S.stacksize=MAXSIZE;
 	return 1;
}
 
int InitStack(SqStack2 &S)
{
 	S.base=new double[MAXSIZE];
	if(!S.base)
	{
		return 0;
	}
 	S.top=S.base;
 	S.stacksize=MAXSIZE;
 	return 1;
}
 
int Push(SqStack1 &S,char e)
{
	if(S.top-S.base==S.stacksize)
	{
		return 0;
	}
	*S.top=e;
	S.top++;
	return 1;
}
 
int Push(SqStack2 &S,double e)
{
	if(S.top-S.base==S.stacksize)
	{
		return 0;
	}
	*S.top=e;
	S.top++;
	return 1;
}
 
 
double GetTop(SqStack2 S)
{
	if(S.top!=S.base)
		return *(S.top-1);
}
 
char GetTop(SqStack1 S)
{
	if(S.top!=S.base)
		return *(S.top-1);
}
 
int Pop(SqStack1 &S,char &e)
{
	if(S.top==S.base)
	{
		return 0;
	}
	S.top--;
	e=*S.top;
	return 1;
}
 
int Pop(SqStack2 &S,double &e)
{
	if(S.top==S.base)
	{
		return 0;
	}
	S.top--;
	e=*S.top;
	return 1;
}
 
int In(char ch) {//判断ch是否为运算符
	for (int i = 0; i < 7; i++) 
	{
		if (ch == op[i]) {
			return 1;
		}
	}
	return 0;
}

char Precede(char c1, char c2)
{
	if((c1=='('&&c2==')')||(c1=='='&&c2=='=') )
		return '=';
	else
		if(((c1=='+'||c1=='-'||c1=='*'||c1=='/'||c1==')') && (c2=='+'||c2=='-'||c2==')'||c2=='='))||((c1=='*'||c1=='/'||c1==')')&&(c2=='*'||c2=='/')))
			return '>';
		else
			if(((c1=='('||c1=='=')&&c2!=')'&&c2!='=')|| ((c1=='+'||c1=='-')&&(c2=='*'||c2=='/'))||c1=='('||c2=='(') 
				return '<';
			else 
				cout<<c1<<" "<<c2<<"没有输出"<<endl; 
}

double Operate(double first, char theta, double second) {//计算两数运算结果
	switch (theta) 
	{
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		return first / second;
	}
	return 0;
}
 
double EvaluateExpression(char ch) {//算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈
	
	SqStack1 OPTR;
	SqStack2 OPND;
	
	char theta;
	double a, b;
	char x, top;
	InitStack(OPTR);
	InitStack(OPND); 
	Push(OPTR, '=');
	
	while (ch != '=' || (GetTop(OPTR) != '=')) //表达式没有扫描完毕或OPTR的栈顶元素不为“=”
	{
		char sign='+';
		if(ch=='-')
		{
			sign=ch;
		}
		
		if(!In(ch))//不是运算符则解析数字字符串然后进操作数栈
		{
			double m=0,n=0;
			while(ch!='.'&&ch>='0'&&ch<='9')
			{//解析整数部分
				m=m*10+(ch-48);
				cin >> ch;
			}
			
			if(ch=='.')//解析小数部分
				cin >> ch;
				
			int k=1;
			while(ch>='0'&&ch<='9')
			{
				n=n+(ch-48)*pow(10.0,-k);
				k++;
				cin>>ch;
			}
		
			if(sign=='-')
			{
				Push(OPND,-(m+n));
			}
			else
			{
				Push(OPND,m+n);
			}
		}//while 解析第一个数，整合整数部分和小数部分并将其压入栈 
		
		else//如果不是数，则比较运算符优先级 
		{
			switch (Precede(GetTop(OPTR), ch)) //比较OPTR的栈顶元素和ch的优先级
			{
				case '<'://还暂时不用对数栈运算 
					Push(OPTR, ch);
					cin >> ch; //当前字符ch压入OPTR栈，读入下一字符ch
					break;
				
				case '>'://弹出该运算符并弹出两个数，进行运算 
					Pop(OPTR, theta); //弹出OPTR栈顶的运算符
					Pop(OPND, b);
					Pop(OPND, a); //弹出OPND栈顶的两个运算数
					Push(OPND, Operate(a, theta, b)); //将运算结果压入OPND栈
					break;
				
				case '=': //OPTR的栈顶元素是“(”且ch是“)”，括号内容已经运算完毕，现在去括号 
					Pop(OPTR, x);
					cin >> ch; //弹出OPTR栈顶的“(”，读入下一字符ch
					break;
			}
		}	
	} 
	return GetTop(OPND); //OPND栈顶元素即为表达式求值结果
}

int main()
{
	while (1)
	{
		char ch;
		cin >> ch;
		if(ch=='=')break;
		double res = EvaluateExpression(ch);//表达式求值
		cout <<setiosflags(ios::fixed)<<setprecision(2)<< res <<endl;
	}
	return 0;
}