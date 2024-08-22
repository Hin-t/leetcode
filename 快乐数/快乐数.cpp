#include<iostream>
#include<unordered_map>
using namespace std;

int sqSum(int x) {
        int sum = 0;
        while (x != 0) {
            sum += x % 10 * x % 10;
            x = x / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, int> map;
        int sum = sqSum(n);
        while (sum != 1) {
            if (map[sum] != 0) {
                cout<<map[sum];
                return false;
            } else {
                map[sum] = 1;
                sum = sqSum(sum);
            }
        }
        return true;
    }

    int main(){
        bool b = isHappy(19);
    }