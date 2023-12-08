#include <bits/stdc++.h>
#define name "contest"
#define int long long
const int N = 2e5 + 69;
using namespace std;
int n, q;
struct nodes
{
    int lazy, val;
};
nodes node[4 * N];
void down(int id, int l, int r)
{
    int t = node[id].lazy;
    int mid = (l + r) / 2;

    node[id * 2].lazy += t;
    node[id * 2].val += (mid - l + 1) * t; //node[id * 2].val = (mid - l + 1) * t;

    node[id * 2 + 1].lazy += t;
    node[id * 2 + 1].val += (r - mid) * t; //node[id * 2 + 1].val = (r - mid) * t;

    node[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u)
        return;
    if (u <= l && r <= v)
    {
        node[id].val += (r - l + 1) * val; //node[id].val = (r - l + 1) * val;
        node[id].lazy += val;
        return;
    }
    int mid = l + r >> 1;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    node[id].val = node[2 * id].val + node[2 * id + 1].val;
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
        return node[id].val;
    int mid = l + r >> 1;
    down(id, l, r);
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return get1 + get2;
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
    cin >> n >> q;
    while (q--)
    {
        int key;
        cin >> key;
        if (key == 0)
        {
            int u, v, c;
            cin >> u >> v >> c;
            update(1, 1, n, u, v, c);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << endl;
        }
    }
    return 0;
}