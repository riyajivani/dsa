#include <iostream>
using namespace std;

class Node
{
    public:
    
    int key;
    int data;
    Node* next;

    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k,int d)
    {
        key=k;
        data=d;
    }
};

class Stack
{
    public:

    Node *top;
    
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }

    bool checkIfNodeExist(Node* n)
    {
        Node* temp=top;
        bool exist=false;

        while(temp!=NULL)
        {
            if(temp->key==n->key)
            {
                exist=true;
                break;
            }
            temp=temp->next;
        }

        return exist;
    }

    void push(Node* n)
    {
        if(top==NULL)
            top=n;
        else if(checkIfNodeExist(n))
            cout<<"Node already exist with this key value. Enter different key value."<<endl;
        else
        {
            Node* temp=top;
            top=n;
            n->next=temp;
            cout<<"Node pushed."<<endl;
        }
    }

    Node* pop()
    {
        Node* temp=NULL;
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return temp;
        }
        else
        {
            temp=top;
            top=top->next;
            return temp;
        }
    }

    Node* peek()
    {
        Node* temp=NULL;
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return temp;
        }
        else
        {
            return top;
        }
    }

    int count()
    {
        int count=0;
        Node* temp=top;

        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    void display()
        {
            cout<<"All values in the stack are : "<<endl;
            
            Node* temp=top;

            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")"<<"->"<<endl;
                temp=temp->next;
            }

            cout<<"Total number of nodes in the stack:"<<count()<<endl;
        }
};

int main()
{
    Stack s1;
    int option,key,data;

    do
    {
        cout<<"what operation do you want to perform ?(Select option number , Enter 0 to exit.)"<<endl;

        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. peek()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. clear screen"<<endl<<endl;

        cin>>option;

        Node* nn=new Node();

        switch(option)
        {

            case 0:
                {
                    break;
                }
            case 1:
                {
                    cout<<"Enter key and value of node to push in the stack"<<endl;
                    cin>>key;
                    cin>>data;
                    nn->key=key;
                    nn->data=data;
                    s1.push(nn);
                    break;
                }
            case 2:
                {
                    cout<<"pop function called - poped value:"<<s1.pop()<<endl;
                    nn=s1.pop();
                    cout<<"Top of stack is: ("<<nn->key<<","<<nn->data<<")"<<endl;
                    delete nn;
                    break;
                }
            case 3:
                {
                    if(s1.isEmpty())
                        cout<<"stack is empty"<<endl;
                    else   
                        cout<<"stack is not empty"<<endl;
                    break;
                }
            case 4:
                {
                    if(s1.isEmpty())
                        cout<<"stack is empty"<<endl;
                    else
                    {
                        cout<<"peek function called:"<<endl;
                        nn=s1.peek();
                        cout<<"Top of stack is: ("<<nn->key<<","<<nn->data<<")"<<endl;
                        break;
                    }
                }
            case 5:
                {
                    cout<<"count function called - Number of nodes in the stack are: "<<s1.count()<<endl;
                    break;
                }
            case 6:
                {
                    cout<<"display function called - "<<endl;
                    s1.display();
                    cout<<endl;
                    break;
                }
            case 7:
                {
                    system("cls");
                    break;
                }
            default:
                {
                    cout<<"enter proper option number: "<<endl;
                }
        }

    } while (option != 0);


    return 0;
}