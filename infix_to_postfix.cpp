#include<iostream>
#include<stack>
using namespace std;
int isp(char y)
{
    if(y=='(' || y=='#')
    {
        return 8;
    }/*
    else if(y=="||")
    {
        return 7;
    }
    else if(y=="&&")
    {
        return 6;
    }
    else if(y=="==" || y=="!=")
    {
        return 5;
    }
    else if(y=="<" || y=="<=" || y==">" || y==">=")
    {
        return 4;
    }*/
    else if(y=='+' || y=='-')
    {
        return 2;
    }
    else if(y=='*' || y=='/' || y=='%')
    {
        return 1;
    }
}
int icp(char y)
{
    if(y=='#')
    {
        return 8;
    }
    else if(y=='(')
    {
        return 0;
    }
   /* else if(y=="||")
    {
        return 7;
    }
    else if(y=="&&")
    {
        return 6;
    }
    else if(y=="==" || y=="!=")
    {
        return 5;
    }
    else if(y=="<" || y=="<=" || y==">" || y==">=")
    {
        return 4;
    }*/
    else if(y=='+' || y=='-')
    {
        return 2;
    }
    else if(y=='*' || y=='/' || y=='%')
    {
        return 1;
    }
}
char nextToken(string e)
{
    static int i=0;
    return e[i++];
}
void postfix(string e)
{
    stack <char> s;
    char y;

    s.push('#');
    for( char x=nextToken(e);x!='#';x=nextToken(e))
    {
        if((x>='A' && x<='Z' ) || (x>='a' && x<='z'))
        {
            cout<<x;
        }
        else if(x==')')
        {
            for(y=s.top(),s.pop();y!='(';y=s.top(),s.pop())
            {
                cout<<y;
                //s.pop();
            }
        }
        else
        {
            for(y=s.top(),s.pop();isp(y)<=icp(x);y=s.top(),s.pop())
            {
                cout<<y;
                //s.pop();
            }
            s.push(y);
            s.push(x);
        }
    }
    while(!s.empty())
    {
        y=s.top();
        s.pop();
        cout<<y;
    }
}

int main()
{
    string s;
    cout<<"enter the expression: "<<endl;
    cin>>s;
    postfix(s);
    return 0;
}
