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

const int N = 11111;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
bool grid[N][N];
int dist[N][N];

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

set<pair<pair<int, int>, int> > memo;
void build(const string& s, int x, int y, int& i) {
    pair<pair<int, int>, int> key(make_pair(x, y), i);
    if(memo.find(key) != memo.end()) return;
    memo.insert(key);
    if(s[i] == '$') return;
    else if(s[i] == '^') i++;
    else if(s[i] == 'W') grid[x][--y] = true, grid[x][--y] = true, i++;
    else if(s[i] == 'E') grid[x][++y] = true, grid[x][++y] = true, i++;
    else if(s[i] == 'N') grid[--x][y] = true, grid[--x][y] = true, i++;
    else if(s[i] == 'S') grid[++x][y] = true, grid[++x][y] = true, i++;
    else if(s[i] == '(') {
        do {
            build(s, x, y, ++i);
        } while(s[i] == '|');
        assert(s[i] == ')');
        ++i;
    }
    build(s, x, y, i);
}

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 0, N - 1) {
        fill(dist[i], dist[i] + N, INT_MAX);
    }
    string s;
    cin >> s;
    int x = N / 2, y = N / 2, i = 1;
    grid[x][y] = true;
    build(s, x, y, i);
    queue<pair<int, int> > q;
    dist[x][y] = 0;
    q.push(make_pair(x, y));
    int ans = 0, ans2 = 0;
    while(sz(q)) {
        pair<int, int> pos = q.front();
        int di = dist[pos.first][pos.second];
        ans = max(ans, di / 2);
        q.pop();
        rep(d, 0, 3) {
            int nx = pos.first + DX[d];
            int ny = pos.second + DY[d];
            if(grid[nx][ny] && dist[nx][ny] > di + 1) {
                dist[nx][ny] = di + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            ans2 += dist[i][j] < INT_MAX && dist[i][j] / 2 >= 1000 && (i + j) % 2 == 0;
        }
    }
    cout << "Part 1: " << ans << endl;
    cout << "Part 2: " << ans2 << endl;
    return 0;
}
