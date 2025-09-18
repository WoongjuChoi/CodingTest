#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(string expression, char delimiter)
{
    vector<string> result;
    stringstream ss(expression);
    string splitData;
    while (getline(ss, splitData, delimiter))
    {
        result.push_back(splitData);
    }

    return result;
}

int Sum(string expression)
{
    int result = 0;
    vector<string> numArr = Split(expression, '+');
    for (int i = 0; i < numArr.size(); ++i)
    {
        result += stoi(numArr[i]);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression;
    cin >> expression;

    vector<string> splitArr = Split(expression, '-');
    int result = Sum(splitArr[0]);
    for (int i = 1; i < splitArr.size(); ++i)
    {
        result -= Sum(splitArr[i]);
    }

    cout << result;
}