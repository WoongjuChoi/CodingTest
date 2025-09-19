#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> buildTime(N + 1, 0);
    vector<int> indegree(N + 1, 0);
    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        cin >> buildTime[i];
        result[i] = buildTime[i];

        while (true)
        {
            int temp;
            cin >> temp;

            if (temp == -1)
                break;

            graph[temp].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> indegreeQueue;
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
            indegreeQueue.push(i);
    }

    while (indegreeQueue.empty() == false)
    {
        int curBuilding = indegreeQueue.front();
        indegreeQueue.pop();

        for (int linkedBuilding : graph[curBuilding])
        {
            indegree[linkedBuilding]--;

            result[linkedBuilding] = max(result[linkedBuilding], result[curBuilding] + buildTime[linkedBuilding]);
            
            if (indegree[linkedBuilding] == 0)
                indegreeQueue.push(linkedBuilding);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << result[i] << '\n';
    }
}