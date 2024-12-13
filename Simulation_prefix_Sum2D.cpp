#include <bits/stdc++.h>
using namespace std;
#define MAX  1001
int n,m;
int a[MAX][MAX];
int q;
int res[MAX][MAX] = {0};

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            res[i][j] = res[i][j-1] + a[i][j];
        }
    }
}

void solution(int r1, int c1,int r2, int c2){
    int sum = 0;
    for(int i=r1;i<=r2;i++){
        sum += res[i][c2] - res[i][c1-1];
    }
    cout << sum << endl;
}

int main(){
    input();
    cin >> q;
    for(int i = 1; i <= q; i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        solution(r1,c1,r2,c2);
    }
return 0;
}
