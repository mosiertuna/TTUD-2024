#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n;
vector<pair<int, int>> jobs; 
map<int,bool> days;
int result = 0;



void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        jobs.push_back({u, v}); 
    }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second;
}



void solution(){
    sort(jobs.begin(), jobs.end(), cmp);

    for (auto job : jobs) {
        int deadline = job.first;
        int money = job.second;


        for (int d = deadline; d > 0; d--) {
            if (!days[d]) { 
                days[d] = true; // Đánh dấu ngày đã được chọn
                result += money; 
                break; 
            }
        }
    }
    
}

int main() {
    input();
    solution();
    cout << result << endl; // In ra tổng số tiền nhận được
    return 0;
}
