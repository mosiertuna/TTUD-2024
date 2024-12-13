#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int m;    // so giao vien
int n;     // so khoa hoc
vector<int> teach[MAX];
bool conflict[MAX][MAX];
int result;
int x[MAX];
int load[MAX];

void input(){
    cin >> m >> n;
    for(int t = 1; t <= m; t++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int c;    cin >> c;  teach[c].push_back(t);
        }
    }
    int K;
    for(int i = 1; i <= n; i++)
        for(int j =1 ; j <= n; j++)
            conflict[i][j] = false;
    cin >> K;
    for(int k =1 ; k <= K; k++){
        int i,j;  cin >> i >> j;
        conflict[i][j] = true;   conflict[j][i] = true;
    }
}

bool check(int t, int k ){
    for(int i=1; i <= k-1; i++){
        if(conflict[i][k] && x[i] == t) return false;
    }
    return true;
}

void  solution(){
    int maxLoad = 0;
    for(int i = 1; i <= m; i++){
        maxLoad = max(maxLoad, load[i]);
    }
    if(maxLoad < result) result = maxLoad;
}

void TRY(int k){
    for(int i = 0; i < teach[k].size(); i++){
        int t = teach[k][i];
        if(check(t,k)){
            x[k] = t;
            load[t] += 1;
            if(k == n) solution();
            else{
                if(load[t] < result) TRY(k+1);
            }
            load[t] -= 1;
        }
    }
}


int main() {
    input();
    for(int t = 1; t <= m; t++) load[t] = 0;
    result = 10000000;
    TRY(1); 
    cout << n << endl;
    for(int i = 1; i <= n; i++) cout << x[i] << " ";
    return 0;
}