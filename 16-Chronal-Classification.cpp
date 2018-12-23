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

int reg[4], reg1[4], reg2[4];
bool isra[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
bool isrb[16] = {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1};

inline bool isr(int a) {
    return a >= 0 && a <= 3;
}

bool execute(int op, int a, int b, int c) {
    if(!isr(c)) return false;
    bool aa = isr(a), bb = isr(b);
    if(isra[op] && !aa) return false;
    if(isrb[op] && !bb) return false;
    if(op == 0) {
        reg[c] = reg[a] + reg[b];
    } else if(op == 1) {
        reg[c] = reg[a] + b;
    } else if(op == 2) {
        reg[c] = reg[a] * reg[b];
    } else if(op == 3) {
        reg[c] = reg[a] * b;
    } else if(op == 4) {
        reg[c] = reg[a] & reg[b];
    } else if(op == 5) {
        reg[c] = reg[a] & b;
    } else if(op == 6) {
        reg[c] = reg[a] | reg[b];
    } else if(op == 7) {
        reg[c] = reg[a] | b;
    } else if(op == 8) {
        reg[c] = reg[a];
    } else if(op == 9) {
        reg[c] = a;
    } else if(op == 10) {
        reg[c] = a > reg[b];
    } else if(op == 11) {
        reg[c] = reg[a] > b;
    } else if(op == 12) {
        reg[c] = reg[a] > reg[b];
    } else if(op == 13) {
        reg[c] = a == reg[b];
    } else if(op == 14) {
        reg[c] = reg[a] == b;
    } else if(op == 15) {
        reg[c] = reg[a] == reg[b];
    }
    return true;
}

vector<int> readPermutation() {
    vector<set<int> > poss;
    rep(i, 0, 15) {
        set<int> st;
        rep(j, 0, 15) st.insert(j);
        poss.pb(st);
    }
    rep(j, 1, 797) {
        rep(i, 0, 3) {
            reg1[i] = readInt();
        }
        int op = readInt(), a = readInt(), b = readInt(), c = readInt();
        rep(i, 0, 3) {
            reg2[i] = readInt();
        }
        set<int> st;
        rep(o, 0, 15) {
            copy(reg1, reg1 + 4, reg);
            if(execute(o, a, b, c)) {
                bool ok = true;
                rep(i, 0, 3) {
                    if(reg[i] != reg2[i]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    st.insert(o);
                }
            }
        }
        set<int> un;
        rall(x, st) {
            if(poss[op].find(x) != poss[op].end()) {
                un.insert(x);
            }
        }
        poss[op] = un;
    }
    bool change = true;
    while(change) {
        change = false;
        rep(o, 0, 15) {
            if(sz(poss[o]) == 1) {
                rep(oo, 0, 15) {
                    if(oo == o) continue;
                    poss[oo].erase(*(poss[o].begin()));
                }
            } else {
                change = true;
            }
        }
    }
    vector<int> ans;
    rep(o, 0, 15) {
        cout << o << " " << sz(poss[o]) << endl;
        assert(sz(poss[o]) == 1);
        ans.pb(*(poss[o].begin()));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> perm = readPermutation();
    fill(reg, reg + 4, 0);
    while(1) {
        int op = readInt(), a = readInt(), b = readInt(), c = readInt();
        execute(perm[op], a, b, c);
        cout << reg[0] << endl;
    }
    return 0;
}
