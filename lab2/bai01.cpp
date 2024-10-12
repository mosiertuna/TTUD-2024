#include <bits/stdc++.h> 
using namespace std;


bool checkPhone(string s){
    if(s.length() != 10) return false;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9') return false;
    }
    
return true;
}


int main(){
map<string, string> phone_number;
phone_number.insert(pair<string, string>("1111212s", "1234567890"));
phone_number.insert(pair<string, string>("1111213sw12", "123456790"));

for(it = phone_number.begin(); it != phone_number.end();it++){
    cout << checkPhone((*it).first) << endl;
    cout << checkPhone((*it).second) << endl;
}

return 0;
}
