#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(100005);

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void solve(){
    long long max_even_sum = LLONG_MIN;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += a[i];
        if (current_sum % 2 == 0) {
            max_even_sum = max(max_even_sum, current_sum);
        }
        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    if (max_even_sum == LLONG_MIN) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << max_even_sum << endl;
    }
}


int main(){
    input();
    solve();
    return 0;
}