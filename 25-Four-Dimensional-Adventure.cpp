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
int x[N], y[N], z[N], w[N], c[N], cnt[N];
int n = 1006;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        x[i] = readInt(), y[i] = readInt(), z[i] = readInt(), w[i] = readInt();
        c[i] = i;
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if(c[i] == c[j]) continue;
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]) + abs(w[i] - w[j]);
            if(d > 3) continue;
            int from = c[j], to = c[i];
            rep(k, 1, n) {
                if(c[k] == from) {
                    c[k] = to;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        if(cnt[c[i]] == 0) {
            ans++;
        }
        cnt[c[i]]++;
    }
    cout << ans << endl;
    return 0;
}
