#include <bits/stdc++.h>
using namespace std;

void find_paths(vector<vector<int>> &paths, vector<int> &path, vector<int> parent[], int n, int u)
{
    if (u == -1)
    {
        paths.push_back(path);
        return;
    }
    for (int par : parent[u])
    {
        path.push_back(u);
        find_paths(paths, path, parent,
                   n, par);
        path.pop_back();
    }
}

void bfs(vector<int> adj[], vector<int> parent[], int n, int start)
{
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(start);
    parent[start] = {-1};
    dist[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1)
            {
                parent[v].push_back(u);
            }
        }
    }
}

void print_paths(vector<int> adj[], int n, int start, int end)
{
    vector<vector<int>> paths;
    vector<int> path;
    vector<int> parent[n + 1];

    bfs(adj, parent, n, start);

    find_paths(paths, path, parent, n, end);

    for (auto v : paths)
    {
        reverse(v.begin(), v.end());
        for (int u : v)
            cout << u << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("contest.inp", "r", stdin);
    freopen("contest.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src = 1;
    int dest = 5;

    // Function Call
    print_paths(adj, n, src, dest);

    return 0;
}