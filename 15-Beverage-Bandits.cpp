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

class Unit;

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};
vector<string> input, grid;
vector<Unit> units;

class Unit {
    private:
        int x, y, att, hp;
        bool g, dead;

    public:
        Unit(int x, int y, bool g, int hp = 200, int att = 3) : x(x), y(y), g(g), hp(hp), att(att), dead(false) {
            
        }
        
        bool operator == (const Unit& other) {
            return getPos() == other.getPos();
        }

        bool operator < (const Unit& other) {
            return make_pair(x, y) < make_pair(other.x, other.y);
        }

        void printHP(ostream& stream) const {
            stream << getTypeChar() << "(" << hp << ")";
        }

        pair<int, int> getPos() const {
            return make_pair(x, y);
        }

        int getHP() const {
            return hp;
        }

        char getTypeChar() const {
            return g ? 'G' : 'E';
        }

        void move(pair<int, int> pos) {
            x = pos.first;
            y = pos.second;
        }

        void hit(Unit& other) {
            other.hp -= att;
            if(other.hp <= 0) {
                other.dead = true;
            }
        }

        bool isDead() {
            return dead;
        }
};

ostream& operator << (ostream& stream, const Unit& u) {
    u.printHP(stream);
    return stream;
}

int n, m;

void readGrid() {
    input.clear();
    string line;
    while(cin >> line) {
        input.pb(line);
        m = sz(line);
    }
    n = sz(input);
}

void parseGrid(int att) {
    grid.clear();
    units.clear();
    rep(i, 0, n - 1) {
        string line = input[i];
        rep(j, 0, m - 1) {
            if(line[j] == '.') {
                line[j] = ' ';
            } else if(line[j] != '#') {
                if(line[j] == 'G') {
                    units.pb(Unit(i, j, true));
                } else {
                    units.pb(Unit(i, j, false, 200, att));
                }
                line[j] = ' ';
            }
        }
        grid.pb(line);
    }
}

void printGrid() {
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            char c = grid[i][j];
            rall(u, units) {
                if(make_pair(i, j) == u.getPos() && !u.isDead()) {
                    c = u.getTypeChar();
                    break;
                }
            }
            cout << c;
        }
        cout << " ";
        rall(u, units) {
            if(u.getPos().first == i && !u.isDead()) {
                cout << u << ", ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isFree(pair<int, int> pos) {
    if(grid[pos.first][pos.second] != ' ') {
        return false;
    }
    rall(u, units) {
        if(!u.isDead() && u.getPos() == pos) {
            return false;
        }
    }
    return true;
}

vector<vector<int> > bfs(pair<int, int> from, pair<int, int> to) {
    vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
    dist[from.first][from.second] = 0;
    queue<pair<int, int> > q;
    q.push(from);
    while(sz(q)) {
        pair<int, int> pos = q.front();
        int cd = dist[pos.first][pos.second];
        q.pop();
        rep(d, 0, 3) {
            pair<int, int> poss(pos.first + DX[d], pos.second + DY[d]);
            int& nd = dist[poss.first][poss.second];
            if((poss == to || isFree(poss)) && cd + 1 < nd) {
                nd = cd + 1;
                q.push(poss);
            }
        }
    }
    return dist;
}

set<pair<int, int> > getRanges(Unit& from) {
    set<pair<int, int> > ans;
    rall(other, units) {
        if(from.getTypeChar() == other.getTypeChar() || other.isDead()) continue;
        rep(d, 0, 3) {
            pair<int, int> pos(other.getPos().first + DX[d], other.getPos().second + DY[d]);
            if(isFree(pos) || pos == from.getPos()) {
                ans.insert(pos);
            }
        }
    }
    return ans;
}

int getElfCount() {
    int ans = 0;
    rall(unit, units) {
        if(unit.getTypeChar() == 'E' && !unit.isDead()) ans++;
    }
    return ans;
}

bool gameEnded() {
    set<char> sc;
    rall(unit, units) {
        if(unit.isDead()) continue;
        sc.insert(unit.getTypeChar());
    }
    return sz(sc) == 1;
}

pair<bool, int> getOutcome(int att) {
    parseGrid(att);
    sort(rng(units));
    int elves = getElfCount();
    rep(o, 1, 500) {
        cout << "TURN " << o << " " << endl;
        rall(unit, units) {
            if(gameEnded()) {
                int code = 0;
                rall(unit, units) {
                    if(unit.isDead()) continue;
                    code += unit.getHP();
                }
                cout << "Total HP: " << code << endl;
                code *= o - 1;
                return make_pair(getElfCount() == elves, code);
            }
            if(unit.isDead()) continue;
            set<pair<int, int> > ranges = getRanges(unit);
            bool inRange = false;
            rall(p, ranges) {
                if(p == unit.getPos()) {
                    inRange = true;
                    break;
                }
            }
            if(!inRange) {
                set<pair<int, pair<int, int> > > reachable;
                rall(p, ranges) {
                    vector<vector<int> > dist = bfs(p, unit.getPos());
                    int d = dist[unit.getPos().first][unit.getPos().second];
                    if(d < INT_MAX) {
                        reachable.insert(make_pair(d, p));
                    }
                }
                if(sz(reachable)) {
                    pair<int, int> target = reachable.begin()->second;
                    vector<vector<int> > dist = bfs(target, unit.getPos());
                    set<pair<int, pair<int, int> > > movePoss;
                    rep(d, 0, 3) {
                        pair<int, int> poss(unit.getPos().first + DX[d], unit.getPos().second + DY[d]);
                        int di = dist[poss.first][poss.second];
                        if(di < INT_MAX) {
                            movePoss.insert(make_pair(di, poss));
                        }
                    }
                    pair<int, int> movePos = movePoss.begin()->second;
                    unit.move(movePos);
                }
            }
            set<pair<int, pair<int, int> > > targets;
            rall(other, units) {
                if(other.isDead()) continue;
                if(other.getTypeChar() != unit.getTypeChar() && abs(unit.getPos().first - other.getPos().first) + abs(unit.getPos().second - other.getPos().second) == 1) {
                    targets.insert(make_pair(other.getHP(), other.getPos()));
                }
            }
            if(sz(targets)) {
                pair<int, int> target = targets.begin()->second;
                rall(other, units) {
                    if(other.getPos() == target) {
                        unit.hit(other);
                    }
                }
            }
        }
        vector<Unit> sunits(units);
        units.clear();
        rall(unit, sunits) {
            if(!unit.isDead()) {
                units.pb(unit);
            }
        }
        sort(rng(units));
        printGrid();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    readGrid();
    rep(att, 4, 100) {
        pair<bool, int> outcome = getOutcome(att);
        cout << att << " " << outcome.first << " " << outcome.second << endl;
        if(outcome.first) return 0;
    }
    return 0;
}
