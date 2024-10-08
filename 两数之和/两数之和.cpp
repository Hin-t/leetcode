#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] != 0) {
                res.push_back(i);
                res.push_back(map[nums[i]] - 1);
            } else {
                map[target - nums[i]] = i + 1;
            }
        }
        return res;
    }
};