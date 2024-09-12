#include <iostream>

using namespace std;

string intToRoman(int num)
{
    string s;
    int count = 0, r;
    while (num != 0)
    {
        r = num % 10;
        num = num / 10;
        switch (count)
        {
        case 0:
            switch (r)
            {
            case 9:
                s.insert(0, "IX");
                break;
            case 8:
                s.insert(0, "VIII");
                break;
            case 7:
                s.insert(0, "VII");
                break;
            case 6:
                s.insert(0, "VI");
                break;
            case 5:
                s.insert(0, "V");
                break;
            case 4:
                s.insert(0, "IV");
                break;
            case 3:
                s.insert(0, "III");
                break;
            case 2:
                s.insert(0, "II");
                break;
            case 1:
                s.insert(0, "I");
                break;
            }
            break;
        case 1:
            switch (r)
            {
            case 9:
                s.insert(0, "XC");
                break;
            case 8:
                s.insert(0, "LXXX");
                break;
            case 7:
                s.insert(0, "LXX");
                break;
            case 6:
                s.insert(0, "LX");
                break;
            case 5:
                s.insert(0, "L");
                break;
            case 4:
                s.insert(0, "XL");
                break;
            case 3:
                s.insert(0, "XXX");
                break;
            case 2:
                s.insert(0, "XX");
                break;
            case 1:
                s.insert(0, "X");
            }
            break;
        case 2:
            switch (r)
            {
            case 9:
                s.insert(0, "CM");
                break;
            case 8:
                s.insert(0, "DCCC");
                break;
            case 7:
                s.insert(0, "DCC");
                break;
            case 6:
                s.insert(0, "DC");
                break;
            case 5:
                s.insert(0, "D");
                break;
            case 4:
                s.insert(0, "CD");
                break;
            case 3:
                s.insert(0, "CCC");
                break;
            case 2:
                s.insert(0, "CC");
                break;
            case 1:
                s.insert(0, "C");
                break;
            }
            break;
        case 3:
            switch (r)
            {
            case 3:
                s.insert(0, "MMM");
                break;
            case 2:
                s.insert(0, "MM");
                break;
            case 1:
                s.insert(0, "M");
                break;
            }
            break;
        }
        count++;
    }
    return s;
}

int main()
{
    string s = intToRoman(3749);
}