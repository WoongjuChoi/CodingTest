#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BinarySearch(long long num, const vector<long long>& numArr)
{
    int start = 0;
    int end = numArr.size() - 1;
    int targetIdx;

    while (start < end)
    {
        targetIdx = (start + end) / 2;

        if (numArr[targetIdx] == num)
        {
            cout << 1 << '\n';
            return;
        }
        else if (numArr[targetIdx] > num)
        {
            end = targetIdx - 1;
        }
        else if (numArr[targetIdx] < num)
        {
            start = targetIdx + 1;
        }
    }

    if (numArr[start] == num)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long long> numArr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> numArr[i];
    }

    sort(numArr.begin(), numArr.end());

    int M;
    cin >> M;

    long long num;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        BinarySearch(num, numArr);
    }
}