#include <iostream>
#include <vector>

using namespace std;

int FindPivotIdx(vector<int>& arr, int startIdx, int endIdx)
{
    if (startIdx + 1 == endIdx)
    {
        if (arr[startIdx] > arr[endIdx])
            swap(arr[startIdx], arr[endIdx]);


        return endIdx;
    }

    int midIdx = (startIdx + endIdx) / 2;
    swap(arr[startIdx], arr[midIdx]);
    int pivot = arr[startIdx];
    int start = startIdx + 1;
    int end = endIdx;

    while (start <= end)
    {
        while (arr[start] < pivot && start < arr.size()) 
        {
            ++start;
        }

        while (arr[end] > pivot && end > 0)
        {
            --end;
        }

        if (start <= end)
            swap(arr[start], arr[end]);
    }

    arr[startIdx] = arr[end];
    arr[end] = pivot;

    return end;
}

void QuickSort(vector<int>& arr, int startIdx, int endIdx, int findIdx)
{
    if (startIdx < endIdx)
    {
        int pivotIdx = FindPivotIdx(arr, startIdx, endIdx);

        if (pivotIdx == findIdx)
            return;

        QuickSort(arr, startIdx, pivotIdx - 1, findIdx);
        QuickSort(arr, pivotIdx + 1, endIdx, findIdx);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, N - 1, K - 1);

    cout << A[K - 1];
}