#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct ComparePairBySecond
{
    bool operator() (const pair<int, int>& a, const pair<int, int> b) 
    {
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 1; i <= E; ++i)
    {
        int startNode, endNode, weight;
        cin >> startNode >> endNode >> weight;
        graph[startNode].emplace_back(make_pair(endNode, weight));
    }

    vector<int> shortestRoute(V + 1);
    fill(shortestRoute.begin(), shortestRoute.end(), INT_MAX);
    shortestRoute[K] = 0;

    vector<bool> visited(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairBySecond> visitQueue;
    visitQueue.emplace(make_pair(K, 0));

    while (visitQueue.empty() == false)
    {
        pair<int, int> curNode = visitQueue.top();
        visitQueue.pop();

        if (visited[curNode.first])
            continue;

        visited[curNode.first] = true;

        for (int i = 0; i < graph[curNode.first].size(); ++i)
        {
            int nextNode = graph[curNode.first][i].first;
            int edgeWeight = graph[curNode.first][i].second;

            shortestRoute[nextNode] = min(shortestRoute[nextNode], shortestRoute[curNode.first] + edgeWeight);
            visitQueue.emplace(make_pair(nextNode, shortestRoute[nextNode]));
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (shortestRoute[i] == INT_MAX)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << shortestRoute[i] << '\n';
        }
    }
}