#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums1 = {1, 3,6,8,11,34,4,5,7,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    Solution sol;
    vector<int> result = sol.twoSum(nums1, 9);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

return 0;
}
