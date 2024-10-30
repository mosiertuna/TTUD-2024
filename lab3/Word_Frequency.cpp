#include <bits/stdc++.h>
using namespace std;

string sanitize_word(string arr){
    string clean;
    for(char a : arr){
        if(isalnum(a)){
            clean += a;
        }
    }
return clean;
}

int main(){
    string text;
    map <string, int> word_count;
    
    getline(cin, text);
    istringtream stream(text);
    string word;

    while(stream >> word){
        string sanitize_word = sanitize_word(word);
        if(!sanitize_word.empty())
    }




}