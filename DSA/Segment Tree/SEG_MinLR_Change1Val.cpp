#include <bits/stdc++.h>
#define name "contest"
#define int long long
const int N = 2e5 + 69;
using namespace std;

int n, q;
int a[N];
int tree[4 * N];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

void update(int id, int l, int r, int x, int val)
{
    if (x < l || x > r)
        return;
    if (l == r)
    {
        tree[id] = val; //tree[id] += val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, x, val);
    update(2 * id + 1, mid + 1, r, x, val);
    tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return (int)1e9;
    if (l >= u && r <= v)
        return tree[id];
    int mid = l + r >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return min(get1, get2);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        int k, u, v;
        cin >> k >> u >> v;
        if (k == 0)
            update(1, 1, n, u, v);
        else
            cout << get(1, 1, n, u, v) << endl;
    }
    return 0;
}