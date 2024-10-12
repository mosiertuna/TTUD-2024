#include <bits/stdc++.h> 
using namespace std;
#define MAX 20

int n, M, result = 0;
int solution[MAX], pt[MAX];

bool check_solution (){
int count = 0;
	for(int i = 0; i < n ; i++){
		count += solution[i] * pt[i];
	}
	if(count != M) return false;
return true;
}

int Back_track(int k){
	int count = 0;
	for(int i = 0; i < k ; i++){
		count += solution[i] * pt[i];
	}
	if(count > M) return 1;
return 0;
}

void TRY (int k){
if(k == n){
	if(check_solution())result ++;
	return;
}
if(Back_track(k)) return;


for(int j = 1; j <= M; j++){
	solution[k] = j;
	TRY (k+1);
}
return;
}


int main(){
cin >> n >> M;
for (int i = 0; i < n ; i++){
	cin >>  pt[i];
}
TRY(0);

cout << result;
 

}