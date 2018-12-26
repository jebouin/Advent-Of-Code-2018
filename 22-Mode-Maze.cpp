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
#define int long long
typedef long long ll;
using namespace std;

ll readInt() {
	char c;
	bool start = false, neg = false;
	ll ans = 0;
	while(1) {
		c = getchar();
		if((c < '0' || c > '9') && c != '-' && !start) {
			continue;
		}
		if((c < '0' || c > '9') && c != '-' && start){
			break;
		}
		if(start) {
            ans *= 10;
        }
		start = true;
		if(c == '-') {
            neg = true;
        } else {
            ans += c - '0';
        }
	}
    return neg ? -ans : ans;
}

const int N = 1111, D = 7305, X = 13, Y = 734, MOD = 20183;
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, -1, 0, 1};
int val[N][N], dist[N][N][3];

inline bool canMoveTo(int x, int y, int gear) {
    return val[x][y] != gear;
}

signed main() {
    int ans = 0;
    rep(x, 0, N - 1) {
        rep(y, 0, N - 1) {
            if(x > 0 && y > 0) {
                val[x][y] = val[x - 1][y] * val[x][y - 1];
            } else if(x > 0) {
                val[x][0] = x * 16807;
            } else if(y > 0) {
                val[0][y] = y * 48271;
            }
            if(x == X && y == Y) {
                val[x][y] = 0;
            }
            val[x][y] = (val[x][y] + D) % MOD;
            ans += val[x][y] % 3;
            fill(dist[x][y], dist[x][y] + 3, INT_MAX);
        }
    }
    dist[0][0][1] = 0;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 1));
    while(sz(q)) {
        pair<pair<int, int>, int> pos = q.front();
        q.pop();
        int di = dist[pos.fi.fi][pos.fi.se][pos.se];
        rep(d, 0, 3) {
            int x = pos.fi.fi + DX[d], y = pos.fi.se + DY[d];
            if(x < 0 || y < 0 || x >= N || y >= N || val[x][y] % 3 == pos.se) continue;
            if(dist[x][y][pos.se] > di + 1) {
                dist[x][y][pos.se] = di + 1;
                q.push(make_pair(make_pair(x, y), pos.se));
            }
        }
        rep(nt, 0, 2) {
            int x = pos.fi.fi, y = pos.fi.se;
            if(nt == pos.se || val[x][y] % 3 == nt) continue;
            if(dist[x][y][nt] > dist[x][y][pos.se] + 7) {
                dist[x][y][nt] = dist[x][y][pos.se] + 7;
                q.push(make_pair(make_pair(x, y), nt));
            }
        }
    }
    cout << "Part 1: " << ans << endl;
    cout << "Part 2: " << dist[X][Y][1] << endl;
    return 0;
}
