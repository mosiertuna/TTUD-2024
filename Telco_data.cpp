#include <bits/stdc++.h> 
using namespace std;


bool checkPhone(string s){
    if(s.length() != 10) return false;
    for(int i=0; i<s.length(); i++) if(s[i] < '0' && s[i] > '9') return false;
return true;
}

int number_calls(map<string,string> phone_number, string phone){
    int count = 0;
    for(map <string, string> :: iterator arr = phone_number.begin(); arr != phone_number.end();arr++){
        if((*arr).first == phone) count++;
    }
    return count;
}

int total_calls(map<string,string> phone_number){
    return phone_number.size();
}

string total_time_call_of_phone(map<string, string> phone_number, map<string, string> time, string phone) {
    int total_time = 0;
    



    

    return to_string(total_time);
}




int main(){
map<string, string> phone_number;
vector<string> date;
map<string, string> time_call;

phone_number.insert(pair<string, string>("1111212s", "1234567890"));
date.push_back("2021-12-12");
time_call.insert(pair<string, string>("11:20:23", "12:00:00"));

phone_number.insert(pair<string, string>("1111213sw12", "123456790"));
date.push_back("2021-12-12");
time_call.insert(pair<string, string>("11:24:23", "12:00:00"));




for(map <string, string> :: iterator arr = phone_number.begin(); arr != phone_number.end();arr++){
    cout << checkPhone((*arr).first) << endl;
    cout << checkPhone((*arr).second) << endl;
}


for(map <string, string> :: iterator arr = phone_number.begin(); arr != phone_number.end();arr++){
    cout << number_calls(phone_number, (*arr).first) << endl;
}

cout << total_calls(phone_number) << endl;

cout << total_time_call_of_phone(phone_number, time_call, "1111212s") << endl;



return 0;
}