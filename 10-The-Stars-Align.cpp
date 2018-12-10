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

int read() {
    char r;
    bool start = false, neg = false;
    int x = 0;
    while(true) {
        r = getchar();
        if((r - '0' < 0 || r - '0' > 9) && r != '-') {
            if(start) break;
            continue;
        }
        if(start) {
            x *= 10;
        }
        start = true;
        if(r == '-') {
            neg = true;
        } else {
            x += r - '0';
        }
    }
    return neg ? -x : x;
}

const int N = 500;
int x[N], y[N], vx[N], vy[N];
int n = 357;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 1, n) {
        x[i] = read();
        y[i] = read();
        vx[i] = read();
        vy[i] = read();
    }
    rep(k, 1, 1000000) {
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        rep(i, 1, n) {
            x[i] += vx[i];
            y[i] += vy[i];
            minx = min(minx, x[i]);
            miny = min(miny, y[i]);
            maxx = max(maxx, x[i]);
            maxy = max(maxy, y[i]);
        }
        int dx = maxx - minx + 1;
        int dy = maxy - miny + 1;
        if(dx < 100 && dy < 100) {
            cout << k << endl;
            vector<string> grid(dy, string(dx, ' '));
            for(int k = 1; k <= n; k++) {
                int xx = x[k] - minx, yy = y[k] - miny;
                grid[yy][xx] = '#';
            }
            rall(s, grid) {
                cout << s << endl;
            }
        }
    }
    return 0;
}
