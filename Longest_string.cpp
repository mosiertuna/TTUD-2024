#include <bits/stdc++.h>
using namespace std;

// Hàm xây dựng cây segment
void buildSegmentTree(const vector<int>& a, vector<int>& segTree, int node, int start, int end) {
    if (start == end) {
        segTree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(a, segTree, 2 * node + 1, start, mid);
        buildSegmentTree(a, segTree, 2 * node + 2, mid + 1, end);
        segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
    }
}

// Hàm truy vấn giá trị nhỏ nhất trong khoảng [left, right]
int querySegmentTree(const vector<int>& segTree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return INT_MAX;
    }
    if (left <= start && end <= right) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int min_left = querySegmentTree(segTree, 2 * node + 1, start, mid, left, right);
    int min_right = querySegmentTree(segTree, 2 * node + 2, mid + 1, end, left, right);
    return min(min_left, min_right); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Nhập mảng a
    }

    //khởi tạo cây segment
    vector<int> segTree(4 * n);
    buildSegmentTree(a, segTree, 0, 0, n - 1); // Xây dựng cây segment

    int m;
    cin >> m;   // Nhập số lượng truy vấn
    long long Q = 0; // Biến để lưu tổng
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j; // Nhập các chỉ số i, j
        Q += querySegmentTree(segTree, 0, 0, n - 1, i, j); // Truy vấn và cộng vào tổng
    }

    cout << Q << endl; // Xuất tổng Q
    return 0;
}
