#include <iostream>
#include <vector>

using namespace std;

int Find(int node, vector<int>& set)
{
    if (set[node] != node)
    {
        set[node] = Find(set[node], set);
    }
        
    return set[node];
}

void Union(int node1, int node2, vector<int>& set)
{
    set[Find(node2, set)] = Find(node1, set);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> n >> m;

    vector<int> set(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        set[i] = i;
    }

    int input, node1, node2;
    for (int i = 0; i < m; ++i)
    {
         cin >> input >> node1 >> node2;

        if (input == 0)
        {
            Union(node1, node2, set);
        }
        else if (input == 1)
        {
            if (Find(node1, set) == Find(node2, set))
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}