#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n;
vector<int> a(MAX);

void merge(int l,int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for(int i = 0; i<n1; i++) L[i] = a[l+i];
    for(int i = 0; i<n2; i++) R[i] = a[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int l,in r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}


int main(){
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    
    
return 0;
}