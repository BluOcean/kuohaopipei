#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 20

typedef struct //˳��ջ�Ĵ���ṹ
{
    char *base;
    char *top;
    int stacksize;
} SqStack;

int InitStack(SqStack &S)//˳��ջ�ĳ�ʼ��
{
    S.base=new char [MAXSIZE];
    if(!S.base)
        exit(0);
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}

int Push(SqStack &S,char e)//��ջ
{
    if(S.top-S.base==S.stacksize)
        return 0;
    *S.top=e;
    S.top++;
    return 1;
}

char GetTop(SqStack &S)//ȡջ��Ԫ�أ�
{
    if(S.top!=S.base)
        return *(S.top-1);
}

int Pop(SqStack &S,char &e)//��ջ
{
    if(S.top==S.base)
        return 0;
    e=*--S.top;//�ȼ���S.top--;e=S.top;
    return 1;
}

//����ƥ��
int func1(SqStack S,char str[])
{
    char ch;
    char e;
    ch=*str++;
    while(ch)
    {
        switch(ch)
        {
        case '(':
            Push(S,ch);
            break;
        case '[':
            Push(S,ch);
            break;
        case '{':
            Push(S,ch);
            break;
        case ')':
            if(GetTop(S) == '(')
            {
                Pop(S,e);
            }
            else
            {
                return 0;
            }
            break;
        case ']':
            if(GetTop(S) == '[')
            {
                Pop(S,e);
            }
            else
            {
                return 0;
            }
            break;
        case '}':
            if(GetTop(S) == '{')
            {
                Pop(S,e);
            }
            else
            {
                return 0;
            }
            break;
        case '#':
            Push(S,ch);
            break;
        }
        ch=*str++;
    }

    if(GetTop(S) == '#')
    {
        if(S.top-1==S.base)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}

int main()
{
    int i;
    SqStack S;
    InitStack(S);
    string st;
    char str[20];

    cout<<"�����ַ�������#������"<<endl;
    cin>>str;

    for(i=0; i<10; i++)
    {
        if(st[i]=='\0')/*���Դ����Ԫ���Ƿ�Ϊ�գ�YES��ִ�и�ֵ��NO���˳�*/
            break;
        else
            str[i]=st[i];
    }

    if(func1(S,str))
    {
        cout<<"������ȷ"<<endl;
    }
    else
    {
        cout<<"�������"<<endl;
    }

    /*
    int e;
    cin>>e;
    Push(S,e);
    int d;
    d=GetTop(S);
    cout<<d<<endl;
    Pop(S,e);
    cout<<e<<endl;
    */
    return 0;
}
