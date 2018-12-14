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
    vector<int> v;
    v.pb(3);
    v.pb(7);
    int a = 0, b = 1;
    string s;
    cin >> s;
    rep(i, 0, 30000000) {
        int sum = v[a] + v[b];
        vector<int> nv;
        if(!sum) {
            v.pb(0);
        } else {
            while(sum) {
                nv.pb(sum % 10);
                sum /= 10;
            }
            reverse(rng(nv));
            v.insert(v.end(), rng(nv));
        }
        a = (a + 1 + v[a]) % sz(v);
        b = (b + 1 + v[b]) % sz(v);
    }
    rep(i, 0, sz(v) - sz(s) + 1) {
        bool ok = true;
        rep(j, 0, sz(s) - 1) {
            if(s[j] - '0' != v[i + j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
