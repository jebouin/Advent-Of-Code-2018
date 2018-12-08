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

struct Node {
    vector<Node*> children;
    vector<int> meta;
    int sum;

    int read() {
        int cnt, mc;
        sum = 0;
        cin >> cnt >> mc;
        rep(i, 1, cnt) {
            children.pb(new Node());
            sum += children.back()->read();
        }
        rep(i, 1, mc) {
            int x;
            cin >> x;
            meta.pb(x);
            sum += x;
        }
        return sum;
    }

    int getVal() {
        if(children.empty()) {
            return sum;
        }
        int ans = 0;
        rall(x, meta) {
            if(x >= 1 && x <= children.size()) {
                ans += children[x - 1]->getVal();
            }
        }
        return ans;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Node root;
    int ans = root.read();
    cout << ans << endl;
    ans = root.getVal();
    cout << ans << endl;
    return 0;
}
