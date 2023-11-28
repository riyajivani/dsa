#include <iostream>
using namespace std;

class CircularQueue
{
    private:

    int front;
    int rear;
    int itemcount;
    int arr[5];

    public:
        CircularQueue()
        {
            itemcount=0;
            front=-1;
            rear=-1;
            for(int i=0; i<5; i++)
            {
                arr[i]=0;
            }
        }

        bool isEmpty()
        {
            if(front==-1 && rear ==-1)
                return true;
            else 
                return false;
        }

        bool isFull()
        {
            if(((rear+1)%5)==front)  //------------change---------------//
                return true;
            else
                return false;
        }

        void Enqueue(int val)
        {
            if(isFull())
            {
                cout<<"Queue is FULL"<<endl;
                return;
            }
            else if(isEmpty())
            {
                rear=0;
                front=0;
                arr[rear]=val;
                itemcount++;
            }
            else
            {
                rear=(rear+1)%5;  //-----------change----------------//
                arr[rear]=val;
                itemcount++;
            }
        }

        int Dequeue()
        {
            int x;

            if(isEmpty())
            {
                cout<<"Queue is empty."<<endl;
                return 0;
            }
            else if(front==rear)
            {
                x=arr[front];
                arr[front]=0;
                rear=-1;
                front=-1;
                return x;
                itemcount--;
            }
            else
            {
                x=arr[front];
                arr[front]=0;
                front=(front+1)%5;   //--------------change--------------------//
                return x;
                itemcount--;
            }
        }

        int count()
        {
            return itemcount;
        }

         void display()
        {
            cout<<"All values in the queue are : "<<endl;
            for(int i=0; i<5; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    CircularQueue q1;
    int option,value;
    do
    {
        cout<<"what operation do you want to perform ?(Select option number , Enter 0 to exit.)"<<endl;

        cout<<"1. enqueue()"<<endl;
        cout<<"2. dequeue"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display"<<endl;
        cout<<"7. clear screen"<<endl<<endl;

        cin>>option;

        switch(option)
        {
            case 0:
                {
                    break;
                }
            case 1:
                {
                    cout<<"Enter an item to enqueue in the queue"<<endl;
                    cin>>value;
                    q1.Enqueue(value);
                    break;
                }
            case 2:
                {
                    cout<<"dequeue function called - dequeued value:"<<q1.Dequeue()<<endl;
                    break;
                }
            case 3:
                {
                    if(q1.isEmpty())
                        cout<<"queue is empty"<<endl;
                    else   
                        cout<<"queue is not empty"<<endl;
                    break;
                }
            case 4:
                {
                    if(q1.isFull())
                        cout<<"queue is full"<<endl;
                    else   
                        cout<<"queue is not full"<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"count function called - Number of item in the queue are: "<<q1.count()<<endl;
                    break;
                }
            case 6:
                {
                    cout<<"display function called - "<<endl;
                    q1.display();
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