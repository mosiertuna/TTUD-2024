#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> arr;
    string s;

  while (true) {
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            arr.push(x);
        } else if (s == "POP") {
            if (arr.empty()) {
                cout << "NULL" << endl; 
            } else {
                cout << arr.top() << endl;
                arr.pop(); 
            }
        } else if (s == "#")break;
        
    }

    return 0;
}
