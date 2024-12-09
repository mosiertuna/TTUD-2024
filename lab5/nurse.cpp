#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int countWorkingPlans(int N, int K1, int K2) {
    // dp[i] sẽ lưu số kế hoạch làm việc có thể cho i ngày
    std::vector<long long> dp(N + 1, 0);
    
    // Có một kế hoạch làm việc trống cho 0 ngày
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        // Xem xét các khoảng thời gian làm việc từ K1 đến K2
        for (int length = K1; length <= K2; ++length) {
            if (i - length >= 0) {
                // Nếu có thể làm việc length ngày, cộng số kế hoạch cho i - length
                dp[i] = (dp[i] + dp[i - length]) % MOD;
            }
        }

        // Thêm vào kế hoạch không làm việc hôm nay
        if (i > 1) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD; // Nghỉ 1 ngày
        }
    }

    return dp[N];
}

int main() {
    int N, K1, K2;
    std::cin >> N >> K1 >> K2;

    int result = countWorkingPlans(N, K1, K2);
    std::cout << result << std::endl;

    return 0;
}