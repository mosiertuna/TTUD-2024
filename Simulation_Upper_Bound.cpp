#include <bits/stdc++.h>

using namespace std;

// Tìm giá trị bên trái lớn hơn giá trị x, nếu không có trả về -1
int upper_bound(int a[], int n, int x) {
    int l = 0, r = n - 1;
    if (a[0] > x) return a[0];
    if (a[n - 1] <= x) return -1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] > x && (mid == 0 || a[mid - 1] <= x)) return a[mid];
        else if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return a[l];
}




int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while(true){
        string s;
        cin >> s;
        if (s == "#") break;
        if (s == "next") {
            int x;
            cin >> x;
            int result = upper_bound(a, n, x);
            cout << result << endl;
        }
    }

    return 0;
}