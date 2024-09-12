#include <iostream>
#include <stack>
#include<sstream>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> num;
    int temp, op1, op2, value;
    for (int i = 0; i < tokens.size(); i++)
    {
        temp = 0, op1 = 0, op2 = 0;
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
            tokens[i] != "/")
        {
            stringstream(tokens[i]) >> value;
            num.push(value);
        }
        else if (!num.empty() && tokens[i] == "+")
        {
            op1 = num.top();
            num.pop();
            op2 = num.top();
            num.pop();
            temp = op2 + op1;
            num.push(temp);
        }
        else if (!num.empty() && tokens[i] == "-")
        {
            op1 = num.top();
            num.pop();
            op2 = num.top();
            num.pop();
            temp = op2 - op1;
            num.push(temp);
        }
        else if (!num.empty() && tokens[i] == "*")
        {
            op1 = num.top();
            num.pop();
            op2 = num.top();
            num.pop();
            temp = op2 * op1;
            num.push(temp);
        }
        else if (!num.empty() && tokens[i] == "+")
        {
            op1 = num.top();
            num.pop();
            op2 = num.top();
            num.pop();
            temp = op2 / op1;
            num.push(temp);
        }
    }
    return num.top();
}

int main(){
    vector<string> tokens({"4","13","5","/","+"});
    int x = evalRPN(tokens);
}