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

const int N = 2222;
string grid[N];
int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;

void printGrid() {
    const int d = 3;
    //rep(i, max(miny - d, 0), min(maxy + d, N - 1)) {
        //rep(j, max(minx - d, 0), min(maxx + d, N - 1)) {
    rep(i, 0, 500) {
        rep(j, 490, 600) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool flow(int i, int j) {
    cout << i << " " << j << endl;
    if(i >= N - 2 || i < 0 || j < 2 || j >= N - 2) {
        return false;
    }
    grid[i][j] = 'o';
    bool ok = true;
    if(grid[i + 1][j] == ' ') {
        ok &= flow(i + 1, j);
    } else if(grid[i + 1][j] == 'o') {
        ok = false;
    }
    if(ok) {
        if(grid[i][j - 1] == ' ') {
            ok &= flow(i, j - 1);
        }
        if(grid[i][j + 1] == ' ') {
            ok &= flow(i, j + 1);
        }
    }
    if(ok) {
        grid[i][j] = 'O';
    } else {
        int k = j + 1;
        while(grid[i][k] == 'O') {
            grid[i][k] = 'o';
            k++;
        }
        k = j - 1;
        while(grid[i][k] == 'O') {
            grid[i][k] = 'o';
            k--;
        }
    }
    return ok;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    rep(i, 0, N - 1) {
        grid[i] = string(N, ' ');
    }
    while(1) {
        char c = getchar();
        if(c == EOF) break;
        if(c == 'x') {
            int x = readInt(), y1 = readInt(), y2 = readInt();
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y1);
            maxy = max(maxy, y2);
            rep(y, y1, y2) {
                grid[y][x] = '#';
            }
        } else {
            int y = readInt(), x1 = readInt(), x2 = readInt();
            minx = min(minx, x1);
            maxx = max(maxx, x2);
            miny = min(miny, y);
            maxy = max(maxy, y);
            rep(x, x1, x2) {
                grid[y][x] = '#';
            }
        }
    }
    cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
    flow(0, 500);
    int total = 0, retained = 0;
    printGrid();
    rep(i, miny, maxy) {
        rep(j, 0, N - 1) {
            total += grid[i][j] == 'O' || grid[i][j] == 'o';
            retained += grid[i][j] == 'O';
        }
    }
    cout << "total: " << total << "\tretained: " << retained << endl;
    return 0;
}
