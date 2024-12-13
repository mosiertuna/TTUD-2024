
#include <bits/stdc++.h> 
using namespace std;
#define MAX 10000
int N,T,D;
int a[MAX];
int t[MAX];
int Time =0, goods=0,res =0;
void input(){
    cin >> N >> T >> D;
    for(int i=1; i<=N;i++){
        cin >> a[i];
    }
    for(int i =1;i<=N;i++){
        cin >>t[i];
    }
}
void solution(){
    if(res < goods){
        res=goods;
    }
}

void TRY (int k){
    if(Time +t[k] > T){
        solution();
        return;
    }
    goods+=a[k];
    for(int i=1;i<=D;i++){
        TRY(k+i);
    }
    goods-=a[k];
}
int main() 
{ 
    input();
    for(int i=1;i<=D;i++){
        Time =0;
        goods =0;
        TRY(i);
    }
    cout << res;

}