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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<string> lines;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    sort(rng(lines));
    int curId, last;
    map<int, vector<int> > times;
    rall(line, lines) {
        string day, time;
        stringstream ss(line);
        ss >> day >> time;
        int mi = 0;
        if(time[0] == '0' && time[1] == '0') {
            mi = (time[3] - '0') * 10 + time[4] - '0';
        }
        string word;
        ss >> word;
        if(word == "Guard") {
            string idstr;
            ss >> idstr;
            ss.clear();
            ss.str(idstr.substr(1));
            ss >> curId;
            if(times.find(curId) == times.end()) {
                times[curId] = vector<int>(60);
            }
        } else if(word == "wakes") {
            for(int t = last; t <= mi; t++) {
                times[curId][t]++;
            }
        } else if(word == "falls") {
            last = mi;
        }
    }
    int maxi = 0, best, bm;
    for(p : times) {
        rep(t, 0, 59) {
            int x = p.se[t];
            if(x > maxi) {
                maxi = x;
                best = p.fi;
                bm = t;
            }
        }
    }
    cout << best * bm << endl;
    return 0;
}
