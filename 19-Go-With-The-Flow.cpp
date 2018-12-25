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

int reg[6], opr;
vector<string> ops;
vector<int> opa, opb, opc;

bool execute(string op, int a, int b, int c) {
    if(op == "addr") {
        reg[c] = reg[a] + reg[b];
    } else if(op == "addi") {
        reg[c] = reg[a] + b;
    } else if(op == "mulr") {
        reg[c] = reg[a] * reg[b];
    } else if(op == "muli") {
        reg[c] = reg[a] * b;
    } else if(op == "banr") {
        reg[c] = reg[a] & reg[b];
    } else if(op == "bani") {
        reg[c] = reg[a] & b;
    } else if(op == "borr") {
        reg[c] = reg[a] | reg[b];
    } else if(op == "bori") {
        reg[c] = reg[a] | b;
    } else if(op == "setr") {
        reg[c] = reg[a];
    } else if(op == "seti") {
        reg[c] = a;
    } else if(op == "gtir") {
        reg[c] = a > reg[b];
    } else if(op == "gtri") {
        reg[c] = reg[a] > b;
    } else if(op == "gtrr") {
        reg[c] = reg[a] > reg[b];
    } else if(op == "eqir") {
        reg[c] = a == reg[b];
    } else if(op == "eqri") {
        reg[c] = reg[a] == b;
    } else if(op == "eqrr") {
        reg[c] = reg[a] == reg[b];
    }
    return true;
}

//https://oeis.org/A000203
int run(int r3) {
    opr = 1;
    fill(reg, reg + 6, 0);
    while(reg[opr] < sz(ops)) {
        int pc = reg[opr];
        execute(ops[pc], opa[pc], opb[pc], opc[pc]);
        reg[opr]++;
        if(reg[3] == 920) {
            reg[3] = r3;
        }
        cout << reg[3] << endl;
    }
    return reg[0];
}

int solve(int x) {
    int ans = 0;
    for(int d = 1; d * d <= x; d++) {
        if(x % d == 0) {
            ans += d;
            if(x / d != d) {
                ans += x / d;
            }
        }
    }
    return ans;
}

signed main() {
    /*char c;
    while((c = getchar()) != EOF) {
        if(c != '#') {
            string s;
            cin >> s;
            ops.pb(c + s);
            opa.pb(readInt());
            opb.pb(readInt());
            opc.pb(readInt());
        }
    }*/
    cout << "Part 1: " << solve(920) << endl;
    cout << "Part 2: " << solve(10551320) << endl;
    return 0;
}
