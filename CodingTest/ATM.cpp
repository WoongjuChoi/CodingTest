#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> time(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> time[i];
    }

    for (int idx = 1; idx < N; ++idx)
    {
        int insertIdx = idx;
        for (int j = idx - 1; j >= 0; --j)
        {
            if (time[j] > time[idx])
            {
                insertIdx = j;
            }
        }

        int insertValue = time[idx];
        for (int k = idx; k > insertIdx; --k)
        {
            time[k] = time[k - 1];
        }

        time[insertIdx] = insertValue;
    }

    vector<int> sumArr(N);
    sumArr[0] = time[0];
    for (int i = 1; i < N; ++i)
    {
        sumArr[i] = sumArr[i - 1] + time[i];
    }

    cout << accumulate(sumArr.begin(), sumArr.end(), 0);
}