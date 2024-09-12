#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) {
        int count = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[count]) {
                count++;
            }
        }
        if (count == s.size()) {
            return true;
        }
        return false;
    }

int main()
{
    string s = "axc";
    string t = "ahbgdc";
    bool b = isSubsequence(s, t);
}