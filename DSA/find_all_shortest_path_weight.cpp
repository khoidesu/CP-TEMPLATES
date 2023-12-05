#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void find_paths(vector<vector<pii>> &paths, vector<pii> &path, vector<pii> parent[], int n, int u, int w)
{
    if (u == -1)
    {
        paths.push_back(path);
        return;
    }
    for (auto [par, w] : parent[u])
    {
        path.push_back({u, w});
        find_paths(paths, path, parent,
                   n, par, w);
        path.pop_back();
    }
}

void bfs(vector<pii> adj[], vector<pii> parent[], int n, int start)
{
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(start);
    parent[start].push_back({-1, 0});
    dist[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push(v);
                parent[v].clear();
                parent[v].push_back({u, w});
            }
            else if (dist[v] == dist[u] + w)
            {
                parent[v].push_back({u, w});
            }
        }
    }
}

void print_paths(vector<pii> adj[], int n, int start, int end)
{
    vector<vector<pii>> paths;
    vector<pii> path;
    vector<pii> parent[n + 1];

    bfs(adj, parent, n, start);

    find_paths(paths, path, parent, n, end, 0);

    for (auto v : paths)
    {
        reverse(v.begin(), v.end());
        for (auto [u, w] : v)
            cout << u << "(" << w << ") ";
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
    vector<pii> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int src = 1;
    int dest = 5;

    // Function Call
    print_paths(adj, n, src, dest);

    return 0;
}