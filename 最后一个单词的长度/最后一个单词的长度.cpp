#include <iostream>
using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0;
    int n = s.size() - 1;
    while (n >= 0)
    {
        if (s[n] == ' ')
        {
            s = s.substr(0, n - 1);
            n--;
        }
        else
        {
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main()
{
    string s = "a ";
    int a = lengthOfLastWord(s);
}