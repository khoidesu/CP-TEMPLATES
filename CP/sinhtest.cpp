#include <bits/stdc++.h>
using namespace std;
const string NAME = "TASK";
const int N = 1e5 + 1;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rand     rd
#define fi       first
#define se       second
#define pb       push_back
#define all(x)   x.begin(),x.end()
#define sz(x)    x.size()

typedef pair<int,int>     pii;
typedef vector<int>       vi;
typedef vector<pii>       vii;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return abs((l + rd() * 1LL * rd() % (h - l + 1)));
}

/*=Random Function============================================================*/
vi  random_array(int n,int L,int R) {   //random array of size n in range [L,R]
    vi  a(n);
    for(int i = 0 ; i < n ; ++i)
        a[i] = Rand(L,R);
    return  a;
}
vi  random_permutation(int n) {   //random permutation of size n
    vi  a(n);
    for(int i = 0 ; i < n ; ++i)
        a[i] = i + 1;
    random_shuffle(all(a));
    return  a;
}
vii random_tree(int n) {   //random tree with n vertices
    vi  x = random_permutation(n);
    vii E;
    for(int i = 2 ; i <= n ; ++i)
        E.pb(pii(i,Rand(1,i - 1)));
    for(int i = 0 ; i < n - 1 ; ++i)    {
        pii &e = E[i];
        e.fi = x[e.fi - 1]; e.se = x[e.se - 1];
    }
    return  E;
}
vii random_graph(int n) {   //random graph with n vertices
    vii E = random_tree(n);
    map<pii,int> mp;
    for(int i = 0 ; i < n - 1 ; ++i)    {
        if(E[i].fi > E[i].se)
            swap(E[i].fi,E[i].se);
        mp[E[i]]++;
    }
    int m = min((n - 1) * (n - 2) / 2,N + N - 1 - n);
    while(m--)  {
        int x, y;
        while(1)    {
            y = Rand(1,n); x = Rand(1,y - 1);
            if(!mp.count(pii(x,y)))    break;
        }
        E.pb(pii(x,y));
        mp[pii(x,y)]++;
    }
    random_shuffle(all(E));
    return  E;
}

void SINHTEST(ofstream &cout) {
}

main() {
    srand(time(NULL));
    ofstream inp((NAME + ".inp").c_str());
    SINHTEST(inp);
}