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
int x[N], y[N];
int k;

vector<int> solve(int n) {
    vector<int> ans(k + 1);
    for(int i = -n / 2; i <= n / 2; i++) {
        for(int j = -n / 2; j <= n / 2; j++) {
            int mini = INT_MAX, best = -1;
            for(int l = 1; l <= k; l++) {
                int cd = abs(i - x[l]) + abs(j - y[l]);
                if(cd < mini) {
                    mini = cd;
                    best = l;
                }
            }
            ans[best]++;
        }
    }
    return ans;
}

int solve2(int n) {
    int ans = 0;
    for(int i = -n / 2; i <= n / 2; i++) {
        for(int j = -n / 2; j <= n / 2; j++) {
            int sum = 0;
            for(int l = 1; l <= k; l++) {
                int cd = abs(i - x[l]) + abs(j - y[l]);
                sum += cd;
            }
            ans += sum < 10000;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char c;
    while(cin >> x[k + 1] >> c >> y[k + 1]) {
        k++;
    }
    vector<int> cnt = solve(800), cntt = solve(1000);
    int maxi = 0;
    for(int i = 1; i <= k; i++) {
        if(cnt[i] == cntt[i] && cnt[i] > maxi) {
            cout << i << " " << cnt[i] << endl;
            maxi = cnt[i];
        }
    }
    cout << maxi << endl;
    cout << solve2(1000) << endl;
    return 0;
}
