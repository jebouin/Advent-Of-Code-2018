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
#define int long long
typedef long long ll;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    list<int> mar;
    mar.push_back(0);
    list<int>::iterator it = mar.begin();
    vector<int> sc(n, 0);
    rep(i, 0, m - 1) {
        int elf = i % n;
        if((i + 1) % 23 == 0) {
            sc[elf] += i + 1;
            rep(j, 1, 8) {
                if(it == mar.begin()) it = mar.end();
                --it;
            }
            sc[elf] += *it;
            mar.erase(it++);
            if(it == mar.end()) it = mar.begin();
            ++it;
        } else {
            if(mar.size() <= 1) {
                it = mar.begin();
                ++it;
            } else {
                if(it == mar.end()) it = mar.begin();
                ++it;
            }
            mar.insert(it, i + 1);
        }
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        ans = max(ans, sc[i]);
    }
    cout << ans << endl;
    return 0;
}
