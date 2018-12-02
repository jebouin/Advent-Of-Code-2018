#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#ifdef LOCAL
#define rall(x,a) for(x : a)
#define LL "%lld"
#else
#define rall(x,a) for(auto x : a)
#define LL "%I64d"
#define y0    oooo
#define y1    ooox
#define yn    ooxo
#define prev  ooxx
#define next  oxoo
#define read  oxox
#define tm    oxxo
#endif
#define rng(a) a.begin(), a.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int x = 0;
    vector<string> v;
    while(cin >> s) {
        v.pb(s);
        x = s.size();
    }
    for(s : v) {
        for(t : v) {
            string u;
            rep(i, 0, x - 1) {
                if(s[i] == t[i]) {
                    u += s[i];
                }
            }
            if(sz(u) == x - 1) {
                cout << u << endl;
                return 0;
            }
        }
    }
    return 0;
}
