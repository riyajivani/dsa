#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
    if(c=='+'|| c=='-'|| c=='*'|| c=='/'|| c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}

string InfixToPrefix(stack<char> s,string infix)
{
    string prefix;
    reverse(infix.begin(),infix.end());

        for(int i=0;i<infix.length();i++)
        {
            if(infix[i]=='(')
                infix[i]=')';
            else if(infix[i]==')')
                infix[i]='(';
        }

        for(int i=0; i<infix.length(); i++)    
        {
            if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
            {
                prefix+=infix[i];
            }

            else if(infix[i] == '(')
            {
                s.push(infix[i]);
            }

            else if(infix[i] == ')')
            {
                while(((s.top()!='(')) && !s.empty())
                {
                    char temp=s.top();
                    prefix+=temp;
                    s.pop();
                }

                if(s.top()=='(')
                {
                    s.pop();
                }
            }

            else if(isOperator(infix[i]))
            {
                if(s.empty())
                {
                    s.push(infix[i]);
                }
                else
                {
                    if(precedence(infix[i])>precedence(s.top()))
                    {
                        s.push(infix[i]);
                    }

                    else if((infix[i]==precedence(s.top())) && (infix[i]=='^'))
                    {
                        while (precedence(infix[i])==precedence(s.top()) && infix[i]=='^')
                        {
                            prefix+=s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }

                    else if((infix[i]==precedence(s.top())))
                    {
                        s.push(infix[i]);
                    }

                    else
                    {
                        while((!s.empty()) && (precedence(infix[i])<precedence(s.top())))
                        {
                            prefix+=s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }
                }
            }
        }

    while(!s.empty())
    {
        prefix+=s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main()
{
    string infix_exp,prefix_exp;

    cout<<"Enter a Infix expression:"<<endl;
    cin>>infix_exp;
    stack <char> s;  //provided by stl
    cout<<"INFIX EXPRESSION:"<<infix_exp<<endl;
    prefix_exp = InfixToPrefix(s,infix_exp);
    cout<<endl<<"PREFIX EXPRESSION: "<<endl<<prefix_exp<<endl;

    return 0;
}