#include <bits/stdc++.h>
/** -----CAM THUAT----- **/
// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,fma")
using namespace std;

/** -----BASIC MACROES----- **/
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define sqr(x) ((x) * (x))
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back

/** -----BIT CONTROLS----- **/
template <class T>
int getbit(T s, int i) { return (s >> i) & 1; }
template <class T>
T onbit(T s, int i) { return s | (T(1) << i); }
template <class T>
T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T>
int cntbit(T s) { return __builtin_popcount(s); }

/** -----I/O FILE----- **/
#define file(name, dot)                     \
	if (fopen(name ".inp", "r"))            \
	{                                       \
		freopen(name ".inp", "r", stdin);   \
		freopen(name "." dot, "w", stdout); \
	}                                       \
	else if (fopen("input.txt", "r"))       \
	{                                       \
		freopen("input.txt", "r", stdin);   \
		freopen("output.txt", "w", stdout); \
	}

/** -----CONST VALUES----- **/
const int MOD = 1e9 + 7;
/** -----EXTENSIVE FUNCTIONS----- **/
int muti(int a, int b) { return (1LL * a * b) % MOD; }
int Pow(int x, int y)
{
	int res = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
			res = muti(res, x);
		x = muti(x, x);
	}
	return res;
}
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
	X eps = 1e-9;
	if (x > y + eps)
	{
		x = y;
		return true;
	}
	else
		return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
	X eps = 1e-9;
	if (x + eps < y)
	{
		x = y;
		return true;
	}
	else
		return false;
}
/* Author: khoidesu */
/** -----IDEAS-----
	-------------------------- **/

/** -----GLOBAL VARIABLES----- **/
const int maxn = 2e5 + 50;
const int INF = 1e9;
/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
}
void Solve()
{
}

/** -----MAIN FUNCTION----- **/
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	file("TASK", "out");
	auto TIME1 = chrono::steady_clock::now();
	int T = 1;
	// cin >> T;
	while (T--)
	{
		VarInput();
		Solve();
	}
	auto TIME2 = chrono::steady_clock::now();
	auto DIFF = TIME2 - TIME1;
	cerr << "Time: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s";
	return 0;
}
