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

int TRY (int i , int k){
if(k >= n-1)if(check_solution){
	result++;
	return 0;
}

solution[k] = i;
for(int j = 1; j < n; j++){
	TRY(j,k+1);
}
return 0;
}






int main(){
cin >> n >> M;
for (int i = 0; i < n ; i++){
	cin >>  pt[i];
}
for(int i = 1; i < n; i++){
	TRY(i,0);
}

cout << result;
 

}