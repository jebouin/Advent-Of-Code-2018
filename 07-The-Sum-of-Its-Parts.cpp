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

const int N = 33;
vector<int> graph[N];
int dp[N];
bool has[N];
int indeg[N];
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n = 26;
    string line;
    vector<string> lines;
    rep(i, 1, 101) {
        getline(cin, line);
        lines.push_back(line.substr(1));
    }
    sort(rng(lines));
    rall(line, lines) {
        int from = 0, to = 0;
        rall(c, line) {
            if(toupper(c) == c && isalpha(c)) {
                if(from) {
                    to = c - 'A' + 1;
                } else {
                    from = c - 'A' + 1;
                }
            }
        }
        has[from] = true;
        has[to] = true;
        graph[from].pb(to);
        indeg[to]++;
    }
    priority_queue<int> q;
    rep(i, 1, n) {
        if(!has[i]) continue;
        if(!indeg[i]) {
            q.push(100 - i);
        }
    }
    string ans;
    while(q.size()) {
        int u = 100 - q.top();
        q.pop();
        rall(x, graph[u]) {
            indeg[x]--;
            if(!indeg[x]) {
                q.push(100 - x);
            }
        }
        ans += 'A' + u - 1;
    }
    rall(c, ans) {
        int u = c - 'A' + 1;
        int t = u + 60;
        rall(v, graph[u]) {
            dp[v] = max(dp[v], dp[u] + t);
        }
    }
    int maxi = 0;
    rep(u, 1, n) {
        if(has[u]) {
            maxi = max(maxi, dp[u] + 60 + u);
        }
    }
    cout << maxi << endl;
    return 0;
}
