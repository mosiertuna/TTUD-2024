#include <bits/stdc++.h>
using namespace std;
#define MAX 23
int n,k;
int c[MAX][MAX];
stack <int> path;

int result = 0;

bool check(){
    if(path.size() < 2){
        return true;
    }
return false;
}










int main(){
    cin >> n >> k ;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> c[i][j];
        }
    }
    
    


return 0;
}