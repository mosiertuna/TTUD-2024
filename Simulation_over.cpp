#include <bits/stdc++.h>
using namespace std;

int min_greater_equal(const set<int>& s, int x) {
    auto it = s.lower_bound(x);
    if (it == s.end()) return -1;
    return *it;
}

int min_greater(const set<int>& s, int x) {
    auto it = s.upper_bound(x);
    if (it == s.end()) return -1;
    return *it;
}

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    while (true) {
        string command;
        cin >> command;
        if (command == "#") break;
        if (command == "insert") {
            int x;
            cin >> x;
            s.insert(x);
        } else if (command == "remove") {
            int x;
            cin >> x;
            s.erase(x);
        } else if (command == "min_greater") {
            int x;
            cin >> x;
            int result = min_greater(s, x);
            if (result == -1) cout << "NULL" << endl;
            else cout << result << endl;
        } else if (command == "min_greater_equal") {
            int x;
            cin >> x;
            int result = min_greater_equal(s, x);
            if (result == -1) cout << "NULL" << endl;
            else cout << result << endl;
        }
    }

    return 0;
}