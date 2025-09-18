#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<bool> visitCheck;

void DFS(int node, const vector<vector<int>>& graph)
{
	cout << node << " ";
	visitCheck[node] = true;

	for (int i = 0; i < graph[node].size(); ++i)
	{
		if (visitCheck[graph[node][i]])
			continue;

		DFS(graph[node][i], graph);
	}
}

void BFS(int node, const vector<vector<int>>& graph)
{
	queue<int> visitQueue;

	visitQueue.push(node);

	while (visitQueue.empty() == false)
	{
		int curNode = visitQueue.front();
		visitQueue.pop();

		if (visitCheck[curNode])
			continue;

		cout << curNode << " ";
		visitCheck[curNode] = true;

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			if (visitCheck[graph[curNode][i]])
				continue;

			visitQueue.push(graph[curNode][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	int V = 0;

	cin >> N;
	cin >> M;
	cin >> V;

	visitCheck.resize(N + 1, false);

	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int start, end;
		cin >> start >> end;

		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	fill(visitCheck.begin(), visitCheck.end(), false);

	DFS(V, graph);
	cout << endl;

	fill(visitCheck.begin(), visitCheck.end(), false);

	BFS(V, graph);
}