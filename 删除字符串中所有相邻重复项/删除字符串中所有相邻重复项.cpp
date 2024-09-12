#include <iostream>
#include <deque>
using namespace std;

string removeDuplicates(string s)
{
    string res;
    deque<char> dq;
    for (int i = 0; i < s.size(); i++)
    {
        dq.push_back(s[i]);
        while (i < s.size()-1 &&!dq.empty()&& dq.back() == s[i+1])
        {
            dq.pop_back();
            i++;
        }
    }
    while (!dq.empty())
    {
        res += dq.front();
        dq.pop_front();
    }
    return res;
}
int main()
{
    string s = "abbaca";
    string res = removeDuplicates(s);
    cout << res;
}