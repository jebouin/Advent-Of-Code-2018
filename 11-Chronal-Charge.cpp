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

int sum[301][301];

signed main() {
    int bx, by, bs, best = INT_MIN;
    for(int y = 1; y <= 300; y++) {
        for(int x = 1; x <= 300; x++) {
            int id = x + 10;
            int p = id * y;
            p += 1718;
            p *= id;
            p = (p / 100) % 10;
            p -= 5;
            sum[y][x] = p + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
        }
    }
    for(int s = 1; s <= 300; s++) {
        for(int y = s; y <= 300; y++) {
            for(int x = s; x <= 300; x++) {
                int total = sum[y][x] - sum[y - s][x] - sum[y][x - s] + sum[y - s][x - s];
                if(total > best) {
                    best = total;
                    bx = x;
                    by = y;
                    bs = s;
                }
            }
        }
    }
    cout << bx - bs + 1 << "," << by - bs + 1 << "," << bs << endl;
    return 0;
}
