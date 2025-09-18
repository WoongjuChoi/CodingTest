#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int startNode, vector<priority_queue<int, vector<int>, greater<int>>>& graph, vector<bool>& visitedDFS);
void BFS(int startNode, vector<priority_queue<int, vector<int>, greater<int>>>& graph, vector<bool>& visitedBFS);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<priority_queue<int, vector<int>, greater<int>>> graphDFS(N + 1);
    vector<priority_queue<int, vector<int>, greater<int>>> graphBFS(N + 1);
    int node1, node2;
    for (int i = 0; i < M; ++i)
    {
        cin >> node1 >> node2;
        graphDFS[node1].push(node2);
        graphDFS[node2].push(node1);
        graphBFS[node1].push(node2);
        graphBFS[node2].push(node1);
    }

    vector<bool> visitedDFS(N + 1, false);
    DFS(V, graphDFS, visitedDFS);
    cout << '\n';
    vector<bool> visitedBFS(N + 1, false);
    BFS(V, graphBFS, visitedBFS);
}

void DFS(int startNode, vector<priority_queue<int, vector<int>, greater<int>>>& graph, vector<bool>& visitedDFS)
{
    visitedDFS[startNode] = true;
    cout << startNode << ' ';

    while (graph[startNode].empty() == false)
    {
        if (visitedDFS[graph[startNode].top()] == false) 
        {
            DFS(graph[startNode].top(), graph, visitedDFS);
        }

        graph[startNode].pop();
    }
}

void BFS(int startNode, vector<priority_queue<int, vector<int>, greater<int>>>& graph, vector<bool>& visitedBFS)
{
    queue<int> bfs;
    bfs.push(startNode);

    while (bfs.empty() == false)
    {
        int visitNode = bfs.front();
        bfs.pop();

        if (visitedBFS[visitNode])
            continue;

        visitedBFS[visitNode] = true;
        cout << visitNode << ' ';

        while (graph[visitNode].empty() == false)
        {
            if (visitedBFS[graph[visitNode].top()] == false)
            {
                bfs.push(graph[visitNode].top());
            }

            graph[visitNode].pop();
        }
    }
}