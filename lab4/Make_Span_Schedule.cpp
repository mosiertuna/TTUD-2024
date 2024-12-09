#include <bits/stdc++.h>
using namespace std;

void earliest_completion_time(int n, int m, vector<int>& durations, vector<pair<int, int>>& constraints) {
    // Tạo đồ thị và mảng độ vào
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> completion_time(n + 1, 0);

    // Thêm các cạnh vào đồ thị
    for (const auto& constraint : constraints) {
        int i = constraint.first;
        int j = constraint.second;
        graph[i].push_back(j);
        in_degree[j]++;
    }

    // Khởi tạo hàng đợi cho các nhiệm vụ có độ vào bằng 0
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            completion_time[i] = durations[i - 1]; // Thời gian hoàn thành của nhiệm vụ i
        }
    }

    // Thực hiện Topological Sort
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            in_degree[neighbor]--;
            // Cập nhật thời gian hoàn thành cho nhiệm vụ láng giềng
            completion_time[neighbor] = max(completion_time[neighbor], completion_time[current] + durations[neighbor - 1]);
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Thời gian hoàn thành sớm nhất của dự án
    int result = *max_element(completion_time.begin(), completion_time.end());
    cout << result << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> durations(n);
    
    for (int i = 0; i < n; i++) {
        cin >> durations[i];
    }

    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; i++) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    earliest_completion_time(n, m, durations, constraints);
    return 0;
}