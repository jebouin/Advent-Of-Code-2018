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

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const string CART = "v>^<";
vector<string> grid;

struct Cart {
    int x, y, d, dd;
    bool dead;
    Cart(int x, int y, int d) : x(x), y(y), d(d), dd(1), dead(false) {}
    bool move(vector<Cart>& carts) {
        int nx = x + DX[d];
        int ny = y + DY[d];
        char c = grid[ny][nx];
        if(c == '\\') {
            d ^= 1;
        } else if(c == '/') {
            d = ((d + 2) ^ 1) & 3;
        } else if(c == '+') {
            d = (d + dd + 4) & 3;
            dd--;
            if(dd < -1) dd = 1;
        }
        x = nx;
        y = ny;
        rall(c, carts) {
            if(c.x == x && c.y == y && !(c.d == d && c.dd == dd)) {
                c.dead = true;
                dead = true;
                return false;
            }
        }
        return true;
    }
};
vector<Cart> carts;

bool comp(const Cart& x, const Cart& y) {
    if(x.y < y.y) return true;
    if(x.y > y.y) return false;
    return x.x < y.x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while(getline(cin, line)) {
        grid.pb(line);
    }
    int n = sz(grid), m = sz(grid[0]);
    grid.pb(string(m + 2, ' '));
    grid.insert(grid.begin(), string(m + 2, ' '));
    rep(i, 1, n) {
        cout << grid[i];
        grid[i] = " " + grid[i] + " ";
        rep(j, 1, m) {
            char c = grid[i][j];
            int p = CART.find(c);
            if(p != string::npos) {
                Cart cart(j, i, p);
                carts.pb(cart);
                if(p & 1) grid[i][j] = '-';
                else grid[i][j] = '|';
            }
        }
    }
    while(1) {
        sort(rng(carts), comp);
        vector<Cart> nc;
        rall(c, carts) {
            if(!c.move(carts)) {
                cout << "PART 1: " << c.x - 1 << "," << c.y - 1 << endl;
            }
        }
        rall(c, carts) {
            if(!c.dead) {
                nc.pb(c);
            }
        }
        carts = nc;
        if(sz(carts) == 1) {
            cout << "PART 2: " << carts[0].x - 1 << "," << carts[0].y - 1 << endl;
            return 0;
        }   
    }
    return 0;
}
