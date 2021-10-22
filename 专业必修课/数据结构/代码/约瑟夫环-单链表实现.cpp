//
//  约瑟夫环-单链表实现.cpp
//  Josephu
//
//  Created by 邵柏豪 on 2020/11/19.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct LNode{
    int num;
    struct LNode *next;
}LNode;
typedef LNode *Linklist;

void Create(Linklist &L, int totalnum)//构造链表
{
    Linklist p, q;
    p = L;
    int m = 1;
    for(int i = 0; i < totalnum; i++)
    {
        q = new LNode;
        q->num = m;
        q->next = NULL;
        p->next = q;
        p = q;
        m++;
    }
    p->next = L->next;
}

void Josephu(Linklist &L, int location, int totalnum, int deletenum)
{
    Linklist p, q;
    p = L;
    
    for(int i = 0; p->next != NULL && i < location - 1; i++)//遍历链表-计数 考虑程序健壮性
    {
        p = p->next;
    }
    
    for(int j = 0; j < totalnum; j++)//约瑟夫环主体
    {
        for(int k = 0; k < deletenum - 1; k++)//跳过
        {
            p = p->next;
        }
        cout << p->next->num << " -> ";
        q = p->next;//被除去的人
        p->next = q->next;//指针传递到再下一人
        delete q;
    }
}

int main(int argc, const char * argv[]) {
    //设置一个头节点
    Linklist L;
    L = new LNode;
    int totalnum, deletenum, location;
    
    //输入各个参数
    cout << "请输入总人数 Totalnum: ";
    cin >> totalnum;
    
    int flag = 1;
    while(flag)
    {
        if( totalnum > 0)
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

    //函数主体
    Create(L, totalnum);
    Josephu(L, location, totalnum, deletenum);
    
    return 0;
}

