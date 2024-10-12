#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int arr[MAXN];
int segTree[4 * MAXN];

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
    }
}

// Function to query the segment tree
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return INT_MAX;
    }
    if (l <= start && end <= r) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int leftQuery = query(2 * node, start, mid, l, r);
    int rightQuery = query(2 * node + 1, mid + 1, end, l, r);
    return min(leftQuery, rightQuery);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    int m;
    cin >> m;
    long long sumQ = 0;

    while (m--) {
        int l, r;
        cin >> l >> r;
        sumQ += query(1, 0, n - 1, l, r);
    }

    cout << sumQ << endl;
    return 0;
}