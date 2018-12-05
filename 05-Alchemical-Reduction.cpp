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

inline bool isp(char c, char cc) {
    return c != cc && toupper(c) == toupper(cc);
}

int react(string s) {
    string st;
    rall(c, s) {
        st += c;
        while(st.size() >= 2 && isp(st[st.size() - 1], st[st.size() - 2])) {
            st.erase(st.begin() + st.size() - 1);
            st.erase(st.begin() + st.size() - 1);
        }
    }
    return st.size();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int mini = INT_MAX;
    rep(i, 0, 25) {
        string ss;
        rall(c, s) {
            if(c != 'a' + i && c != 'A' + i) {
                ss += c;
            }
        }
        int cur = react(ss);
        if(cur < mini) {
            mini = cur;
        }
    }
    cout << mini << endl;
    return 0;
}
