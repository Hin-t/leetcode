/* 
    题目描述：给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{

    vector<vector<int>> matrix(n, vector<int>(n));
    int up = 0, down = n, left = 0, right = n;
    int num = 1;
    int i = 0, j = 0;
    while (num <= n * n)
    {
        while (j < right)
        {
            matrix[i][j] = num;
            j++;
            num++;
        }
        up = up + 1;
        j--;
        i++;
        while (i < down)
        {
            matrix[i][j] = num;
            i++;
            num++;
        }
        right = right - 1;
        i--;
        j--;
        while (j >= left)
        {
            matrix[i][j] = num;
            j--;
            num++;
        }
        down = down - 1;
        j++;
        i--;
        while (i >= up)
        {
            matrix[i][j] = num;
            i--;
            num++;
        }
        left = left + 1;
        i++;
        j++;
    }
    return matrix;
}

int main()
{
    vector<vector<int>> res(3, vector<int>(3));
    res = generateMatrix(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}