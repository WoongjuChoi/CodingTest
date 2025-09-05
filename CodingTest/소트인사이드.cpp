#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    vector<int> arr(N.size());
    for (int i = 0; i < N.size(); ++i)
    {
        arr[i] = stoi(N.substr(i, 1));
    }

    int maxIdx = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }

        cout << arr[maxIdx];

        int temp = arr[maxIdx];
        arr[maxIdx] = arr[i];
        arr[i] = temp;

        maxIdx = i + 1;
    }
}