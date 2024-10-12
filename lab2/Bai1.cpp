#include <bits/stdc++.h> 
using namespace std;

int Search(vector<int> a, int x){
    int l = 0;
    int r = a.size() - 1;
    int mid = l + (r - l) / 2;
    int result;    // là số lớn hơn x nếu có, nếu không thì trả về -1
    while(l <= r){
        mid = l + (r - l) / 2;
        if(a[mid] > x){
            result = a[mid];
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(result == x)return -1;
}


int main(){
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    string s;
    int arr;
    while(1){
        cin >> s;
        if(s == "#")break;
        if(s == "next"){
            cin >> arr;
            int result = Search(a,arr);
            cout << result << endl;
        }
    }


return 0;
}