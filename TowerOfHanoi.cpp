#include<iostream>
#define MAX 3
using namespace std;

class Source{
public:
    int sarr[MAX];
    int tos = -1;
};

void push(Source &s, int element){
    s.tos++;
    //cout << "tos in push " << s.tos << " "; 
    s.sarr[s.tos] = element;
    //cout << "value in push " << s.sarr[s.tos] << endl;
}

int pop(Source &s){
    int y;
    //cout << s.tos << " "; 
    y = s.sarr[s.tos];
    //cout << "value " << y << " ";
    s.tos--;
    //cout << s.tos << endl ;
    return y;
}

void ToH(int n, Source &s, Source &a, Source &d){
    if(n == 1){
        int y = pop(s);
        push(d, y);
    }
    else{
        ToH(n - 1, s, d, a);
        int y = pop(s);
        push(d, y);
        ToH(n - 1, a, s, d);
    }
}

int main(){
    Source so;
    Source au;
    Source dest;
    int cnt = MAX;
    
    while(so.tos < MAX - 1){
        push(so, cnt);
        cnt--;
    }
    
    for(int i = 0; i < MAX; i++)
        cout << so.sarr[i] << " ";
        
    cout << endl;
    
    ToH(MAX, so, au, dest);
    
    cout << "after ToH" << endl;
    
    for(int i = 0; i < MAX; i++)
        cout << dest.sarr[i] << " ";
    return 0;
}