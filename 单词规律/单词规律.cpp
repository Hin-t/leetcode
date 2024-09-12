#include <iostream>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> map;
    for (int i = 0; i < pattern.size(); i++)
    {
        int j = 0;
        string temp = "";
        while (j < s.size() && s[j] != ' ')
        {
            j++;
        }
        temp = s.substr(0, j);
        cout << temp << endl;
        if (map.find(pattern[i]) == map.end())
        {
            map[s[i]] = temp;
            cout << map[s[i]] << endl;
        }
        else
        {
            if (map[s[i]] != temp)
            {
                return false;
            }
        }
        s = s.substr(j + 1, s.size() - j - 1);
        cout << s << endl;
    }
    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    bool b = wordPattern(pattern, s);
}