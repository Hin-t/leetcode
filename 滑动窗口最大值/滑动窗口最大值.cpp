#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     priority_queue<pair<int, int>> pq;
//     for (int i = 0; i < k; i++)
//     {
//         pq.emplace(nums[i], i);
//     }
//     vector<int> res;
//     res.push_back(pq.top().first);
//     for (int i = k; i < n; i++)
//     {
//         pq.emplace(nums[i], i);
//         while (pq.top().second < i - k + 1)
//         {
//             pq.pop();
//         }
//         res.push_back(pq.top().first);
//     }
//     return res;
// }

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vector<int> res;
    res.push_back(nums[dq.front()]);
    for (int i = k; i < n; i++)
    {
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        while (dq.front() < i - k + 1)
        {
            dq.pop_front();
        }
        res.push_back(nums[dq.front()]);
    }
    return res;
}

int main()
{
    vector<int> a({9, 10, 9, -7, -4, -8, 2, -6});
    vector<int> res = maxSlidingWindow(a, 5);
}