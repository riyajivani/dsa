#include <iostream>
#include <stack>
using namespace std;

class Impliment;

class Node{

    int data;
    Node* next;

    public:

    friend class Impliment;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class Impliment
{
    Node* head;

    public:

    Impliment()
    {
        head=NULL;
    }

    Node* create(int ele)
    {
        Node* nn=new Node(ele);

        if(head == NULL)
        {
            head=nn;
        }

        else
        {
            Node* temp=new Node(0);
            temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=nn;
        }

        return head;
    }

    Node* display(Node* hed,int no)
    {
        Node* temp=new Node(0);
        temp=hed;

        while(no!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
            no--;
        }

        cout<<endl;

        return hed;
    }

    Node* Reverse_stack(Node* hed,int no)
    {
        
        stack <int> stc;
        Node* temp=new Node(0);
        temp=hed;
        
        while(temp!=NULL)
        {
            stc.push(temp->data);
            temp=temp->next;
        }

        temp=hed;
       
        while(no!=0)
        {
            temp->data=stc.top();
            stc.pop();
            temp=temp->next;
            no--;
        }
        
        return hed;
    }
};

int main()
{
    int n,no;
    Node*ptr=new Node(0);
    Impliment s;

    do
    {
        cout<<"1.enter element in linklist."<<endl;
        cout<<"2.reverse linklist."<<endl;
        cout<<"3.display linklist"<<endl;
        cout<<"4.quit"<<endl;
        label:
        cout<<"choose option: ";
        cin>>n;

        switch (n)
        {
            case 1:
                {
                    int ele;

                    cout<<"enter no. of total elements you want to enter: "; 
                    cin>>no;

                    cout<<"enter element: ";

                    for(int i=1; i<=no; i++)
                    {
                        cin>>ele;
                        ptr = s.create(ele);
                    }

                    break;
                }
            
            case 2:
                {
                    ptr=s.Reverse_stack(ptr,no);
                    break;
                }

            case 3:
                {
                    ptr=s.display(ptr,no);
                    break;
                }

            case 4:
                {
                    break;
                }

            default:
                {   
                        cout<<"choose correct option."<<endl;
                        goto label;
                    
                }

        }

    }while(n!=4);

    return 0;
}