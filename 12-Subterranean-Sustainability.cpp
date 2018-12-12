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
typedef long long ll;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int gens = 400;
    string s;
    cin >> s >> s >> s;
    cout << s << endl;
    s = string(gens, '.') + s + string(gens, '.');
    string line;
    vector<pair<string, char> > rules;
    while(getline(cin, line)) {
        stringstream ss(line);
        string r, a, c;
        ss >> r >> a >> c;
        rules.pb(make_pair(r, c[0]));
    }
    vector<int> sums;
    rep(g, 1, gens) {
        string t(sz(s), '.');
        rep(i, 0, sz(s) - 1) {
            rall(p, rules) {
                bool match = true;
                rep(j, 0, 4) {
                    int ii = i + j - 2;
                    char c = ii < 0 ? '.' : (ii >= sz(s) ? '.' : s[ii]);
                    if(p.first[j] != c) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    t[i] = p.second;
                    break;
                }
            }
        }
        s = t;
        int ans = 0;
        rep(i, 0, sz(s) - 1) {
            if(s[i] == '#') {
                ans += i - gens;
            }
        }
        cout << g << " " << ans << endl;
        sums.pb(ans);
    }
    ll gens2 = 50000000000;
    ll ds = sums[gens - 1] - sums[gens - 2];
    ll ans = sums.back() + ds * (gens2 - gens);
    cout << ans << endl;
    return 0;
}
