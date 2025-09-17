#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(int node, vector<bool>& visited, vector<list<int>>& graph);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<bool> visited(N + 1, false);
    vector<list<int>> graph(N + 1);
    for (int i = 1; i <= M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int result = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i])
            continue;

        DFS(i, visited, graph);
        ++result;
    }

    cout << result;
}

void DFS(int node, vector<bool>& visited, vector<list<int>>& graph)
{
    visited[node] = true;

    while (graph[node].empty() == false)
    {
        if (visited[graph[node].front()] == false) 
        {
            DFS(graph[node].front(), visited, graph);
        }

        graph[node].pop_front();
    }
}