
#include <iostream>
using namespace std;

class node
{
    public:

    int key;
    int data;
    node* next;

    node()
    {
        key=0;
        data=0;
        next=NULL;
    }

    node(int k,int d)
    {
        key=k;
        data=d;
    }
};

class CircularQueue
{
    public:

    node* front;
    node* rear;

    CircularQueue()
    {
        front=NULL;
        rear=NULL;
    }

    bool isEmpty()
    {
        if(front == NULL && rear == NULL)
            return true;
        else
            return false;
    }

    bool CheckIfNodeExist(node* n)
    {
        node* temp=front;
        bool exist=false;

        do
        {
            if(temp->key==n->key)
            {
                exist=true;
                break;
            }
            temp=temp->next;
        }while(temp!=front);

        return exist;
    }

    void Enqueue(node* n)
    {
        if(isEmpty())
        {
            front=n;
            rear=n;
            cout<<"node enqueued sucessfully."<<endl;
        }
        else if(CheckIfNodeExist(n))
        {
            cout<<"node already exist with this key value - enter different key value."<<endl;
        }
        else
        {
            rear->next=n;
            rear=n;
            n->next=front;
            cout<<"node enqueued sucessfully"<<endl;
        }
    }

    node* Dequeue()
    {
        node* temp=NULL;

        if(isEmpty())
        {
            cout<<"stack underflow."<<endl;
            return NULL;
        }
        else
        {
            if(front==rear)
            {
                temp=front;
                front=NULL;
                rear=NULL;
                return temp;
            }

            else
            {
                temp=front;
                front=front->next;
                rear->next=front;
                return temp;
            }
        }
    }

    int count()
    {
        int count=0;
        node* temp=front;

        do
        {
            count++;
            temp=temp->next;
        }while(temp!=front);

        return count;
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"queue is empty."<<endl;
        }
        else{
            cout<<"all values in the queue are:"<<endl;
            node* temp=front;

            do
            {
                cout<<"("<<temp->key<<","<<temp->data<<")"<<"->";
                temp=temp->next;
            }while(temp!=front);
            cout<<"("<<temp->key<<","<<temp->data<<")";
            cout<<endl;
        }
    }

};

int main()
{
    CircularQueue q;
    int option,key,data;

    do
    {
        cout<<"what operation do you want to perform ?(Select option number , Enter 0 to exit.)"<<endl;

        cout<<"1. enqueue()"<<endl;
        cout<<"2. dequeue"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. count()"<<endl;
        cout<<"5. display()"<<endl;
        cout<<"6. clear screen"<<endl<<endl;

        cin>>option;

        node* nn=new node();

        switch(option)
        {
            case 0:
                {
                    break;
                }
            case 1:
                {
                    cout<<"Enter key and value of node to enqueue in the queue"<<endl;
                    cin>>key;
                    cin>>data;
                    nn->key=key;
                    nn->data=data;
                    q.Enqueue(nn);
                    break;
                }
            case 2:
                {
                    cout<<"dequeue function called - "<<endl;
                    nn=q.Dequeue();
                    cout<<"dequeued value: ("<<nn-key<<","<<nn->data<<")"<<endl;
                    delete nn;
                    cout<<endl;
                    break;
                }
            case 3:
                {
                    if(q.isEmpty())
                        cout<<"queue is empty"<<endl;
                    else   
                        cout<<"queue is not empty"<<endl;
                    break;
                }
            case 4:
                {
                    cout<<"count function called - Number of item in the queue are: "<<q.count()<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"display function called - "<<endl;
                    q.display();
                    cout<<endl;
                    break;
                }
            case 6:
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