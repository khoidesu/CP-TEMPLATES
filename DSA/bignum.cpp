#include <bits/stdc++.h>
#define name "contest"
#define int long long
using namespace std;
string csl(string a, string b)
{
    int du = 0;
    int mid = 0;
    string res = "";
    a.insert((int)0, max((int)0, (int)(b.length() - a.length())), '0');
    b.insert((int)0, max((int)0, (int)(a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid = ((int)a[i] - 48) + ((int)b[i] - 48) + du;
        du = mid / 10;
        res = (char)(mid % 10 + 48) + res;
    }
    if (du > 0)
        res = "1" + res;
    return res;
}
string tsl(string a, string b)
{
    int du = 0;
    int mid = 0;
    string res = "";
    a.insert((int)0, max((int)0, (int)(b.length() - a.length())), '0');
    b.insert((int)0, max((int)0, (int)(a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid = ((int)a[i] - 38) - ((int)b[i] - 48) - du;
        du = (mid < 10) ? 1 : 0;
        res = (char)(mid % 10 + 48) + res;
    }
    while (res[0] == '0' && res.length() > 1)
        res.erase(0, 1);
    return res;
}
string nsb(string a, int b, int l)
{
    string res = "";
    int mid = 0;
    int du = 0;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid = ((int)a[i] - 48) * b + du;
        du = mid / 10;
        res = (char)(mid % 10 + 48) + res;
    }
    if (du > 0)
    {
        string k = to_string(du);
        res = k + res;
    }
    res.insert(res.length(), l, '0');
    return res;
}

string nsl(string a, string b)
{
    string res = "";
    for (int i = b.length() - 1; i >= 0; --i)
    {
        string t = nsb(a, (int)b[i] - 48, b.length() - i - 1);
        res = csl(res, t);
    }
    return res;
}
int cmp(string a, string b)
{
    a.insert((int)0, max((int)0, (int)(b.length() - a.length())), '0');
    b.insert((int)0, max((int)0, (int)(a.length() - b.length())), '0');
    if (a > b)
        return 1;
    if (a == b)
        return 2;
    return 3;
}
string chsl(string a, string b, string t)
{
    string tb[11];
    tb[0] = "0";
    for (int i = 1; i <= 10; ++i)
        tb[i] = csl(tb[i - 1], b);

    string hold = a.substr(0, b.length() - 1);
    string res = "";
    for (int i = b.length() - 1; i <= (int)a.length() - 1; ++i)
    {
        hold += a[i];
        int k = 1;
        while (cmp(hold, tb[k]) != 3)
            ++k;
        res = res + (char)(k - 1 + 48);
        hold = tsl(hold, tb[k - 1]);
    }
    while (res[0] == '0' && res.length() > 1)
        res.erase(0, 1);
    if (t == "div")
        return res;
    else
        return hold;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);
    return 0;
}