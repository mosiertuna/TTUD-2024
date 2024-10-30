#include <bits/stdc++.h>
using namespace std;

#define max 100
int n, k;
int c[2 * max + 1][2 * max + 1]; // Ma trận khoảng cách
int expense; // Chi phí hiện tại
int b_expense; // Chi phí tốt nhất
int cmin; // Khoảng cách nhỏ nhất
int x[2 * max + 1]; // Lưu hành trình
int optimize[2 * max + 1]; // Lưu hành trình tối ưu
int appear[2 * max + 1]; // Kiểm tra sự xuất hiện của hành khách
int load; // Số lượng hành khách hiện có trên xe

void input() {
    cin >> n >> k;
    cmin = 10000;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
}

bool Check(int v) {
    if (appear[v] == 1) return false; // Nếu hành khách đã được chọn
    if (v > n) {
        if (appear[v - n] == 0) return false; // Nếu chưa trả khách
    } else {
        if (load + 1 > k) return false; // Nếu vượt quá số chỗ ngồi
    }
    return true;
}

void solution() {
    if (expense + c[x[2 * n]][0] < b_expense) {
        b_expense = expense + c[x[2 * n]][0]; // Cập nhật chi phí tốt nhất
        for (int i = 1; i <= 2 * n; i++) optimize[i] = x[i]; // Lưu hành trình tối ưu
    }
}

void TRY(int l) {
    for (int v = 1; v <= 2 * n; v++) {
        if (Check(v)) {
            x[l] = v; // Lưu hành trình hiện tại
            expense += c[x[l - 1]][x[l]]; // Cập nhật chi phí
            load += (v <= n) ? 1 : -1; // Cập nhật số ghế
            appear[v] = 1; // Đánh dấu hành khách đã xuất hiện

            if (l == 2 * n) {
                solution(); // Kiểm tra giải pháp
            } else {
                // Kiểm tra xem có thể tiếp tục tìm kiếm không
                if (expense + (2 * n + 1 - l) * cmin < b_expense) {
                    TRY(l + 1);
                }
            }

            // Quay lại trạng thái trước đó
            load += (v <= n) ? -1 : 1;
            appear[v] = 0;
            expense -= c[x[l - 1]][x[l]];
        }
    }
}

int main() {
    input();
    b_expense = 1000000; // Khởi tạo chi phí tốt nhất
    expense = 0; // Khởi tạo chi phí hiện tại
    load = 0; // Khởi tạo số ghế
    memset(appear, 0, sizeof(appear)); // Đánh dấu tất cả hành khách chưa xuất hiện
    x[0] = 0; // Điểm xuất phát

    TRY(1); // Bắt đầu tìm kiếm
    cout << n << endl; // In chi phí tốt nhất
    for (int i = 1; i <= 2 * n; i++) {
        cout << optimize[i] << " "; // In hành trình tối ưu
    }
    cout << endl;

    return 0;
}
