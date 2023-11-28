#include<iostream>
#include<queue>
using namespace std;

class graph
{
    int n;
    int array[10][10];
    int visit[10];

    public:

    graph()
    {
        for(int i=0; i<10; i++)
        {
            visit[i]=0;
        }

        cout<<"enter the number of vertices:"<<endl;
        cin>>n;

        char ch;

        do
        {
            cout<<endl<<"enter edge"<<endl;
            int a,b;
            cin>>a>>b;

            array[a][b]=1;
            array[b][a]=1;

            cout<<"press # for stop and * for continue"<<endl;
            cin>>ch;
        }while(ch!='#');
        
        cout<<endl<<"adjacency matrix"<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(array[i][j]!=1)
                    array[i][j]=0;

                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int v)
    {
        for (int  i = 0; i < n; i++)
        {
            visit[i] = 0;
        }
        
        int v2;
        queue<int> q;
        q.push(v);
        visit[v] = 1;

        while(!q.empty())
        {
            v2 = q.front();
            q.pop();
            cout <<v2<< " ";
            for(int i=0;i<n; i++)
            {
                if(array[v2][i]==1 && visit[i] == 0)
                {
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
        for (int  i = 0; i < n; i++)
        {
            visit[i] = 0;
        }
        
    }

    void dfs(int v)
    {
        cout << v << " ";
        visit[v] = 1;

        for(int i=0; i<n ; i++)
        {
            if(array[v][i] ==  1 && visit[i] == 0)
            {
                dfs(i);
            }
        }
    }
};


int main()
{
    graph g;

    cout<<"dfs traversal"<<endl;
    g.dfs(0);
    cout<<endl;
    cout<<"bfs traversal"<<endl;
    g.bfs(0);
    cout<<endl;

    return 0;
}