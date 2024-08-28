#include <iostream>

using namespace std;

// 傻瓜方法
// bool repeatedSubstringPattern(string s)
// {
//     string substr = "";
//     int k = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == substr[k])
//         {
//             k++;
//             k = k % substr.size();
//         }
//         else
//         {
//             i = i - k;
//             substr += s[i];
//             k = 0;
//         }
//     }
//     if (substr.size() == s.size() || k != 0 ||
//         s.size() % substr.size() != 0)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }

// 聪明蛋方法
bool repeatedSubstringPattern(string s)
{
    return (s + s).find(s, 1) != s.size();
}
int main()
{
    string s = "abaababaab";
    bool b = repeatedSubstringPattern(s);
    cout << b;
}