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

const int N = 1111;
int cnt[N][N];
int ok[N];
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n = 1000;
    string line;
    int id = 0;
    while(getline(cin, line)) {
        id++;
        ok[id] = true;
        stringstream ss(line);
        int id, x, y, w, h;
        char c;
        ss >> c >> id >> c >> x >> c >> y >> c >> w >> c >> h;
        for(int i = x; i < x + w; i++) {
            for(int j = y; j < y + h; j++) {
                if(cnt[i][j] > 0) {
                    ok[cnt[i][j]] = false;
                    ok[id] = false;
                } else {
                    cnt[i][j] = id;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= id; i++) {
        if(ok[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
