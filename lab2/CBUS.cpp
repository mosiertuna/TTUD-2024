#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int N;                              // Số khách 
int cap;                            // Số ghế ngồi trong xe bus
int A[2*MAX+1][2*MAX+1];            // Ma trận chi phí di chuyển C[i][j]
int x[2*MAX + 1];                                               
int appear[2*MAX + 1];
int load;
int expense;
int best_expense;
int cmin;

// Nhập giá trị vào 
void input(){
    cin >> N >> cap;
    cmin = 1000000;
    for(int i = 0; i <= 2*N;  i++){
        for(int j= 0; j <= 2*N; j++){
            cin >> A[i][j];
            if(i != j && cmin > A[i][j]) cmin = A[i][j];   //Tìm chi phí nhỏ nhất giữa 2 điểm bất kỳ
        }
    }
}


int Check(int v){
    if(appear[v] == 1) return 0;           // Điểm đã xuất hiện

    if(v >N){                              // Kiếm tra điểm đích hay điểm xuất phát
        if(!appear[v-N]) return 0;         // Điểm xuất chưa tới
    }
    else{
        if(load + 1 > cap) return 0;        // Kiếm tra xe có chứa thêm được ko
    }
    return 1;
}

bool Back_track(int v)

void solution(){
    if(expense + A[x[2*N]][0] < best_expense){
        best_expense = expense + A[x[2*N]][0];
    }
}

void TRY(int k){
    for(int v = 1; v <=2*N; v++){
        if(Check(v)){
            x[k] = v;                                         // lưu hành trình hiện tại
            expense += A[x[k-1]][x[k]];                        // lưu chi phí
            if(v <= N) load += 1; else load += -1;              // cập nhật số ghế
            appear[v] = 1;                                        // cập nhật sự suất hiện 
            if(k == 2*N) solution();                               // kiếm tra giải pháp (nếu đã đến điểm kết thúc)
            else{
                if(expense + (2*N+1-k)*cmin < best_expense)         
                    TRY(k+1);
            }
            if(v <= N) load -= 1; else load -= -1;
            appear[v] = 0;
            expense -= A[x[k-1]][x[k]];
        }
    }
}

void solve(){
    load = 0;
    expense = 0;
    best_expense = 1000000;
    for(int i = 1; i <= 2*N; i++) appear[i] = 0;
    x[0] = 0;
    TRY(1);
    printf("%d",best_expense);
}




int main(){
    input();
    solve();
    cout << cmin;
  return 0;
}