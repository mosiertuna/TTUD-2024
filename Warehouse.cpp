#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define MAX_T 100

int N, T, D;
int a[MAX + 1];
int t[MAX + 1];
int dp[MAX + 1][MAX_T + 1]; // dp[i][j] là số hàng hóa tối đa có thể thu gom tại trạm i với thời gian j

void input() {
    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }
}

int main() {
    input();
    
    // Khởi tạo mảng dp
    memset(dp, 0, sizeof(dp));

    // Tính toán dp
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            // Không lấy hàng tại trạm i
            dp[i][j] = dp[i - 1][j];

            // Lấy hàng tại trạm i
            if (j >= t[i]) {
                for (int k = 1; k <= D; k++) {
                    if (i - k >= 1) {
                        dp[i][j] = max(dp[i][j], dp[i - k][j - t[i]] + a[i]);
                    }
                }
            }
        }
    }

    // Tìm giá trị tối đa trong dp
    int res = 0;
    for (int j = 0; j <= T; j++) {
        res = max(res, dp[N][j]);
    }

    cout << res << endl;
    return 0;
}
