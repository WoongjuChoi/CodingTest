#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;

    cin >> M >> N;
    vector<bool> numberArr(N + 1, true);
    int sqrtN = sqrt(N);

    numberArr[1] = false;
    for (int primeNumber = 2; primeNumber <= sqrtN; ++primeNumber)
    {
        if (numberArr[primeNumber] == false)
            continue;

        for (int j = primeNumber + primeNumber; j <= N; j += primeNumber)
        {
            numberArr[j] = false;
        }
    }

    for (int i = M; i <= N; ++i)
    {
        if (numberArr[i] == false)
            continue;

        cout << i << endl;
    }
}