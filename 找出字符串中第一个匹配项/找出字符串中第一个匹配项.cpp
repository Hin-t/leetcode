#include <iostream>
#include <vector>
using namespace std;

// int strStr(string haystack, string needle)
// {
//     int k = 0, count = 0;
//     for (int i = 0; i < haystack.size(); i++)
//     {
//         count = 0;
//         k = 0;
//         while (k < needle.size() && haystack[i + k] == needle[k])
//         {
//             k++;
//             count++;
//         }
//         if (count == needle.size())
//         {
//             return i;
//         }
//     }
//     return -1;
// }

/*
    shit一样的KMP算法
 */

void Next(vector<int>& next, string s) {
        if (s.size() == 1) {
            next[0] = -1;
            return;
        }
        if (s.size() == 2) {
            next[0] = -1;
            next[1] = 0;
            return;
        }
        if (s.size() > 2) {
            next[0] = -1;
            next[1] = 0;
            int k = 0;
            for (int i = 2; i < s.size(); i++) {
                if (s[i - 1] == s[next[i - 1]]) {
                    next[i] = next[i - 1] + 1;
                } else {
                    next[i] = 0;
                    k = i - 1;
                    while (next[k] != 0) {
                        k = next[k];
                        if (s[i - 1] == s[next[k]]) {
                            next[i] = next[k] + 1;
                            break;
                        }
                    }
                }
            }
        }
    }
int strStr(string haystack, string needle)
{
    vector<int> next(needle.size());
    Next(next, needle);
    int i = 0, k = 0;
    while (i < haystack.size() && k < needle.size())
    {
        if (k < needle.size() && haystack[i] == needle[k])
        {
            i++;
            k++;
        }
        else
        {
            if (next[k] == -1)
            {
                k = 0;
                i++;
            }
            else
            {
                k = next[k];
            }
        }
        if (k == needle.size())
        {
            return i - needle.size();
        }
    }
    return -1;
}

int main()
{
    string h = "sadbutsad";
    string n = "aabaaac";
    int a = strStr(h, n);
    cout<<a;
}