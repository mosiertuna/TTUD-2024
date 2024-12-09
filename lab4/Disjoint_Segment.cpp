#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int n;
pair<int,int> a[MAX];

bool cmp (pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        cin >> a[i].second;
    }
}



void solve() {
    int res = 0;        // result
    int last = -1;      // the end point of last chosen segment
    sort(a+1, a+n, cmp);
    for (int i=1; i<=n; i++)
    if (a[i].first > last) {   // not overlap
        res ++;
        last = a[i].second;
    }
    cout << res << endl;
}
int main() {
    input();
    solve();
    return 0;
}
