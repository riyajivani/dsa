#include<iostream>
using namespace std;

class impliment;

class node
{
    int data;
    node* link;

    public:
    
    friend class impliment;

    node(int ele)
    {
        data=ele;
        link=NULL;
    }
};

class impliment
{
    node* first;

    public:

    impliment(){first=NULL;}

    node* Add(int ele)
    {
        node* nn=new node(ele);

        if(first==NULL)
        {
            first=nn;
            return first;
        }

        else
        {
            node* temp=first;
            while(temp->link!=NULL)
                temp=temp->link;

            temp->link=nn;

            return first;
        }
    }

    node* display(node* first)
    {
        node* temp=new node(0);
        temp=first;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }

        cout<<endl;

        return first;
    }

    node* Insert_after(int ele,int se,node* first)
    {
        if(first==NULL)
        {
            cout<<"Linklist doesn't exist"<<endl;
        }

        else
        {
            node* nn=new node(ele);
            node* temp=first;

                while(temp->data!=se)
                    temp=temp->link;

                if(temp->link!=NULL)
                {
                    nn->link=temp->link;
                    temp->link=nn;
                }

                else
                {
                    temp->link=nn;
                    nn->link=NULL;
                }
        }

        return first;
    }

    node* Insert_before(int se,int ele,node *first)
    {
        node* nn=new node(ele);
        node* temp=first;

        if(first==NULL)
        {
            cout<<"linklist doesn't exist."<<endl;
            return first;
        }

        else if(temp->link->data==se)
        {
            nn->link=temp->link;
            temp->link=nn;
            return first;
        }

        else
        {
            while (temp->link->link->data!=se)
                temp=temp->link;

            nn->link=temp->link->link;
            temp->link->link=nn;

            return first;
        }
    }

    node* Delete_before(int se,node *first)
    {
        node* temp=new node(0);
        temp=first;

        if(first==NULL)
        {
            cout<<"linklist doesn't exist."<<endl;
            return first;
        }

        else if(first->link->data==se)
        {
            first=first->link;
            delete temp;
            return first;
        }

        else
        {
            while(temp->link->link->data!=se)
                temp=temp->link;

                node* temp1=new node(0);

                temp1=temp->link;
                temp->link=temp->link->link;

                delete temp1;
                return first;
        }
    }

    node* Delete_after(int se,node* first)
    {
        node* temp=new node(0);
        temp=first;

        if(first==NULL)
        {
            cout<<"linklist doesn't exist"<<endl;
            return first;
        }

        else
        {
            while(temp->data!=se)
                temp=temp->link;

            if(temp->link==NULL)
                cout<<"this is the last element of linklist"<<endl;

            else
            {
                node* temp1=new node(0);
                temp1=temp->link;

                temp->link=temp->link->link;
                delete temp1;
            }

            return first;
        }
    }

};

int main()
{
    int n,no;
    impliment ll;
    node* ptr;

    do
    {
        cout<<"1. add element in linklist."<<endl;
        cout<<"2. insert after."<<endl;
        cout<<"3. insert before."<<endl;
        cout<<"4. delete after."<<endl;
        cout<<"5. delete before."<<endl;
        cout<<"6. display."<<endl;
        cout<<"7. exit."<<endl;

        cout<<"select option: ";
        cin>>n;

        switch(n)
        {
            case 1: {
                        int ele;

                        cout<<"enter no. of total elements you want to enter: "; 
                        cin>>no;

                        cout<<"enter element: ";

                        for(int i=1; i<=no; i++)
                        {
                            cin>>ele;
                            ptr = ll.Add(ele);
                        }

                        break;
                    }
                
            case 2: {
                        int se,ele;
                        cout<<"enter element you want to add and after which you want to add: ";
                        cin>>ele>>se;
                        ptr=ll.Insert_after(ele,se,ptr);
                        break;
                    }

            case 3: {
                        int se,ele;
                        cout<<"enter element you want to add and before which you want to add: ";
                        cin>>ele>>se;
                        ptr=ll.Insert_before(se,ele,ptr);
                        break;
                    }

            case 4: {
                        int se;
                        cout<<"enter element after which you want to delete: ";
                        cin>>se;
                        ptr=ll.Delete_after(se,ptr);
                        break;
                    }

            case 5: {
                        int se;
                        cout<<"enter element before which you want to delete: ";
                        cin>>se;
                        ptr=ll.Delete_before(se,ptr);
                        break;
                    }
            
            case 6:
                {
                    ptr=ll.display(ptr);
                    break;
                }
        }

    } while (n!=7);
    return 0;
}