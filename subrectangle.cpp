#include <bits/stdc++.h>
using namespace std;

int largestHistogramArea(const vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int area_with_top;
    int i = 0;

    while (i < heights.size()) {
        // Nếu stack rỗng hoặc chiều cao hiện tại lớn hơn chiều cao đỉnh stack
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area_with_top);
        }
    }

    return max_area;
}

int maxRectangleArea(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0);
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Cập nhật chiều cao
            height[j] = (matrix[i][j] == 1) ? height[j] + 1 : 0;
        }
        // Tính diện tích lớn nhất cho hàng hiện tại
        max_area = max(max_area, largestHistogramArea(height));
    }

    return max_area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << maxRectangleArea(matrix) << endl;

    return 0;
}
