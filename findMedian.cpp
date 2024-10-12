#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Gộp hai mảng lại
        for(int i = 0; i < nums2.size(); i++)
            nums1.push_back(nums2[i]);
        
        // Sắp xếp mảng đã gộp
        sort(nums1.begin(), nums1.end());
        
        // Tính trung vị
        int n = nums1.size();
        if (n % 2 == 0) {
            return (nums1[n/2 - 1] + nums1[n/2]) / 2.0;
        } else {
            return nums1[n/2];
        }
    }

    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (true) {
            if (i == n1) return nums2[j + k - 1];
            if (j == n2) return nums1[i + k - 1];
            if (k == 1) return min(nums1[i], nums2[j]);

            int new_i = min(i + k/2 - 1, n1 - 1);
            int new_j = min(j + k/2 - 1, n2 - 1);
            if (nums1[new_i] <= nums2[new_j]) {
                k -= new_i - i + 1;
                i = new_i + 1;
            } else {
                k -= new_j - j + 1;
                j = new_j + 1;
            }
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3,6,8,11,34,4,5,7,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    vector<int> nums2 = {2,4,6,7,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    int kth = sol.findKthElement(nums1, nums2, 2);
    cout << kth << endl;
    cout << median << endl;
    return 0;
}