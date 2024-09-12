#include <iostream>
#include <vector>
using namespace std;

void backtrack(int i, vector<int> nums, vector<int> &visited,
               vector<int> &arr, vector<vector<int>> &arrs)
{
    visited[i] = 1;
    arr.push_back(nums[i]);
    bool isAllVisited = true;
    for (auto i : visited)
    {
        if (i == 0)
        {
            isAllVisited = false;
            break;
        }
    }
    if (isAllVisited)
    {
        arrs.push_back(arr);
    }
    else
    {
        for (int k = 0; k < nums.size(); k++)
        {
            if (visited[k] == 0)
            {
                backtrack(k, nums, visited, arr, arrs);
            }
        }
    }

    visited[i] = 0;
    arr.pop_back();
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> arr;

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> visited(nums.size(), 0);
        backtrack(i, nums, visited, arr, res);
    }
    return res;
}

int main()
{
    vector<int> test({1,2,3});
    vector<vector<int>> res = permute(test);
}