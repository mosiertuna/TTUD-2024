#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int n;
int a[MAX];
int d;
int s[MAX][2];
int prefix[MAX];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> d;
    for (int i = 1; i <= d; i++){
        cin >> s[i][0] >> s[i][1];
    }
    for(int  i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
}

void prefix_sum(int l, int r){
    cout << prefix[r] - prefix[l - 1] << endl;
}


int main(){
    input();
    for (int i = 1; i <= d; i++){
        prefix_sum(s[i][0], s[i][1]);
    }

return 0;
}