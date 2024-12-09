#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long merge_and_count(vector<int>& arr, vector<int>& temp_arr, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[k++] = arr[i++];
        } else {
            // There are mid - i inversions, because all remaining elements in the left subarray
            // (arr[i], arr[i+1], ..., arr[mid]) are greater than arr[j]
            inv_count += (mid - i + 1);
            inv_count %= MOD; // Take modulo
            temp_arr[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp_arr[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp_arr[k++] = arr[j++];
    }

    // Copy the sorted subarray into Original array
    for (i = left; i <= right; i++) {
        arr[i] = temp_arr[i];
    }

    return inv_count;
}

long long merge_sort_and_count(std::vector<int>& arr, std::vector<int>& temp_arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += merge_sort_and_count(arr, temp_arr, left, mid);
        inv_count %= MOD; // Take modulo
        inv_count += merge_sort_and_count(arr, temp_arr, mid + 1, right);
        inv_count %= MOD; // Take modulo
        inv_count += merge_and_count(arr, temp_arr, left, mid, right);
        inv_count %= MOD; // Take modulo
    }
    cout << inv_count << endl;
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp_arr(n);
    long long result = merge_sort_and_count(arr, temp_arr, 0, n - 1);
    
    cout << result << endl;
    return 0;
}
