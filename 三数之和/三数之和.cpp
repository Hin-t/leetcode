#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});
                while (nums[l] == nums[l + 1] && l < nums.size() - 1)
                {
                    l++;
                }
                while (nums[r] == nums[r - 1] && r > 0)
                {
                    r--;
                }
                l++;
                r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums({0, 0, 0});
    vector<vector<int>> ans = threeSum(nums);
}