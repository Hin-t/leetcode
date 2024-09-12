#include <iostream>

using namespace std;

int romanToInt(string s)
{
    int sum = 0;
    int i = 0;
    while (i < s.size())
    {
        if (s.substr(i, 1) == "IV")
        {
            sum += 4;
            i++;
        }
        else if (s.substr(i, 1) == "IX")
        {
            sum += 9;
            i++;
        }
        else if (s.substr(i, 1) == "XL")
        {
            sum += 40;
            i++;
        }
        else if (s.substr(i, 1) == "XC")
        {
            sum += 90;
            i++;
        }
        else if (s.substr(i, 1) == "CD")
        {
            sum += 400;
            i++;
        }
        else if (s.substr(i, 1) == "CM")
        {
            sum += 900;
            i++;
        }
        else if (s[i] == 'I')
        {
            sum += 1;
        }
        else if (s[i] == 'V')
        {
            sum += 5;
        }
        else if (s[i] == 'X')
        {
            sum += 10;
        }
        else if (s[i] == 'L')
        {
            sum += 50;
        }
        else if (s[i] == 'C')
        {
            sum += 100;
        }
        else if (s[i] == 'D')
        {
            sum += 500;
        }
        else if (s[i] == 'M')
        {
            sum += 1000;
        }
        i++;
    }
    return sum;
}

int main()
{
    int a = romanToInt("MCMXCIV");
}