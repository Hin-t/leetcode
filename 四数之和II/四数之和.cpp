#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int count = 0;
        int n = nums1.size();
        unordered_map<int, int> map;
        vector<int> set2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[-(nums1[i] + nums2[j])]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set2.push_back(nums3[i] + nums4[j]);
            }
        }
        for (int i = 0; i < set2.size(); i++) {
            if (map[set2[i]] != 0) {
                count += map[set2[i]];
            }
        }
        return count;
    }
};