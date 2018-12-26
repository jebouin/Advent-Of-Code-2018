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

const int N = 1111;
int x[N], y[N], z[N], r[N];
int n = 1000;

int f(int px, int py, int pz) {
    int ans = 0;
    rep(i, 1, n) {
        int dx = x[i] - px;
        int dy = y[i] - py;
        int dz = z[i] - pz;
        int dist = abs(dx) + abs(dy) + abs(dz);
        ans += dist <= r[i];
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int br = -1, bi;
    int maxx = INT_MIN, minx = INT_MAX;
    rep(i, 1, n) {
        x[i] = readInt();
        y[i] = readInt();
        z[i] = readInt();
        r[i] = readInt();
        if(r[i] > br) {
            br = r[i];
            bi = i;
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        int dx = x[i] - x[bi];
        int dy = y[i] - y[bi];
        int dz = z[i] - z[bi];
        int dist = abs(dx) + abs(dy) + abs(dz);
        ans += dist <= br;
    }
    cout << "Part 1: " << ans << endl;

    int cx = 0, cy = 0, cz = 0, d = 100000000;
    int m = d * 10;
    int maxi, bx, by, bz, bd;
    while(d) {
        maxi = -1;
        for(int i = cx - m; i <= cx + m; i += d) {
            for(int j = cy - m; j <= cy + m; j += d) {
                for(int k = cz - m; k <= cz + m; k += d) {
                    int cnt = f(i, j, k);
                    if(cnt > maxi) {
                        maxi = cnt;
                        bx = i, by = j, bz = k;
                        bd = abs(i) + abs(j) + abs(k);
                    } else if(cnt == maxi && abs(i) + abs(j) + abs(k) < bd) {
                        bx = i, by = j, bz = k;
                        bd = abs(i) + abs(j) + abs(k);
                    }
                }
            }
        }
        cx = bx, cy = by, cz = bz;
        d /= 10;
        m /= 10;
    }
    cout << "Part 2: " << abs(bx) + abs(by) + abs(bz) << endl;
    return 0;
}
