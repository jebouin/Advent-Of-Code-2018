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

const int DX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int N = 55;
string grid[N], grid2[N];

void readGrid() {
    rep(i, 1, 50) {
        string line;
        cin >> line;
        grid[i] = " " + line + " ";
        grid2[i] = string(52, '.');
    }
}

void printGrid() {
    rep(i, 1, 50) {
        cout << grid[i].substr(1, 50) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    readGrid();
    //1e9 - 8000 = 0 [28]
    rep(o, 1, 8000) {
        rep(i, 1, 50) {
            rep(j, 1, 50) {
                grid2[i][j] = grid[i][j];
                int tree = 0, lumb = 0;
                rep(d, 0, 7) {
                    int ii = i + DX[d];
                    int jj = j + DY[d];
                    tree += grid[ii][jj] == '|';
                    lumb += grid[ii][jj] == '#';
                }
                if(grid[i][j] == '.' && tree >= 3) {
                    grid2[i][j] = '|';
                } else if(grid[i][j] == '|' && lumb >= 3) {
                    grid2[i][j] = '#';
                } else if(grid[i][j] == '#' && !(tree >= 1 && lumb >= 1)) {
                    grid2[i][j] = '.';
                }
            }
        }
        rep(i, 1, 50) {
            grid[i] = grid2[i];
        }
        int x = 0, y = 0;
        rep(i, 1, 50) {
            rep(j, 1, 50) {
                x += grid[i][j] == '|';
                y += grid[i][j] == '#';
            }
        }
        cout << o << " " << x * y << endl;
    }
    return 0;
}
