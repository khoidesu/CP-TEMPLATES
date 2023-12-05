#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

struct Edge
{
    int a, b, w;
    int idx;
};

// for edges
Edge edges[N + 1];

// for dsu
int _par[N + 1];

// for temp graph
vector<pair<int, int>> adj[N + 1];

// for result
int res[N + 1];

// for bridges
int in[N + 1], low[N + 1], timer;
bool vis[N + 1];

bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int a)
{
    if (_par[a] == a)
        return a;

    return _par[a] = find(_par[a]);
}

void dfs(int node, int edgeNumber)
{
    vis[node] = true;
    in[node] = low[node] = timer++;

    for (pair<int, int> e : adj[node])
    {
        if (e.second == edgeNumber)
            continue;

        if (vis[e.first] == true)
        {
            low[node] = min(low[node], in[e.first]);
        }
        else
        {
            dfs(e.first, e.second);
            low[node] = min(low[node], low[e.first]);
        }
    }

    if (edgeNumber != 0)
    {
        if (in[node] == low[node])
            res[edgeNumber] = 2;
    }
}

void addEdge(int a, int b, int idx)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    res[idx] = 1;
    adj[a].push_back({b, idx});
    adj[b].push_back({a, idx});
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    // clearing the graph
    adj[a].clear();
    adj[b].clear();
    vis[a] = vis[b] = false;

    // merge
    if (a == b)
        return;
    _par[a] = b;
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

    for (int i = 1; i <= n; i++)
        _par[i] = i;

    for (int i = 1; i <= m; i++)
        cin >> edges[i].a >> edges[i].b >> edges[i].w, edges[i].idx = i;

    sort(edges + 1, edges + m + 1, comp);

    int i = 1;

    for (; i <= m;)
    {

        int j;
        for (j = i; edges[i].w == edges[j].w; j++)
            addEdge(edges[j].a, edges[j].b, edges[j].idx);

        timer = 0;
        for (j = i; edges[i].w == edges[j].w; j++)
        {
            int p = find(edges[j].a);
            if (vis[p] == false)
                dfs(p, 0);
        }

        for (j = i; edges[i].w == edges[j].w; j++)
            merge(edges[j].a, edges[j].b);

        i = j;
    }

    for (int i = 1; i <= m; i++)
    {
        if (res[i] == 0)
            cout << "none\n";
        else if (res[i] == 1)
            cout << "at least one\n";
        else
            cout << "any\n";
    }
}