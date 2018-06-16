#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

namespace Geometry2D {
    const double EPS = 1e-10;
    double add(double a, double b) {
        if (abs(a + b) < Geometry2D::EPS * (abs(a) + abs(b))) return 0;
        return a + b;
    }
    int sgn(double a, double b = 0.0) {// sign function
        return a < b - EPS ? -1 : a > b + EPS ? 1 : 0;
    }

    struct Point {//二次元座標
        double x, y;
        Point() {}
        Point(double _x, double _y) : x(_x), y(_y) {}
        const Geometry2D::Point operator+ (const Geometry2D::Point p) {
            return Point(Geometry2D::add(this->x, p.x), Geometry2D::add(this->y, p.y));
        }
        const Geometry2D::Point operator- (const Geometry2D::Point p) {
            return Point(Geometry2D::add(this->x, -p.x), Geometry2D::add(this->y, -p.y));
        }
        const Geometry2D::Point operator* (double d) {
            return Point(this->x * d, this->y * d);
        }
    };

    struct Line {
        Geometry2D::Point a, b, dis;
        Line() {}
        Line(const Geometry2D::Point &_a, const Geometry2D::Point &_b) : a(_a), b(_b), dis(b - a) {}
        double distSquare() { //距離の二乗
            return (this->a.x - this->b.x) * (this->a.x - this->b.x) + (this->a.y - this->b.y) * (this->a.y - this->b.y);
        }
        double distance() {
            return sqrt(this->distSquare());
        }
    };

    double naiseki(const Geometry2D::Point &p1, const Geometry2D::Point &p2) {
        return Geometry2D::add(p1.x * p2.x, p1.y * p2.y);
    }
    double gaiseki(const Geometry2D::Point &p1, const Geometry2D::Point &p2) {
        return Geometry2D::add(p1.x * p2.y, -p1.y * p2.x);
    }
    Point intersection(Geometry2D::Line &l1, Geometry2D::Line &l2) {//p1-p2とq1-q2の交点
        auto buf = (l1.b - l1.a);
        return l1.a + buf * (gaiseki(l2.b - l2.a, l2.a - l1.a) / gaiseki(l2.b - l2.a, l1.b - l1.a));
    }
    bool on_seg(Geometry2D::Point &p, Geometry2D::Line &l) {//線分l上にこの点pがあるか
        return Geometry2D::sgn(Geometry2D::gaiseki((l.a - p), (l.b - p))) == 0 && Geometry2D::naiseki(l.a - p, l.b - p) <= 0;
    }
    bool isIntersect(Geometry2D::Line &l1, Geometry2D::Line &l2) { // l1とl2が交差してるか
        Point intersect = intersection(l1, l2);
        return on_seg(intersect, l1) && on_seg(intersect, l2);
    }

    struct Circle {//円
        double r;//半径
        Point center;//中心座標
        Circle() {}
        Circle(double _x, double _y, double _r) : r(_r), center(_x, _y) {}
        Circle(const Point &_p, double _r) : r(_r), center(_p) {}
        bool inside(Point &p) {//円内部に居るか(円周含まない)
            return Geometry2D::sgn(Geometry2D::add(Geometry2D::Line(p, this->center).distSquare(), -(this->r * this->r))) == -1;
        }
        bool on_seg(Point &p) {//円周上に居るか
            return Geometry2D::sgn(Geometry2D::add(Geometry2D::Line(p, this->center).distSquare(), -(this->r * this->r))) == 0;
        }
        double square() {
            return this->r * this->r * acos(-1.0);
        }
    };
};
using namespace Geometry2D;

Line l[2][4];

int nx[] = {-100, -100, 100, 100};
int ny[] = {-100, 100, 100, -100};

int main(void) {
    REP(i, 2) {
        Point p[4];
        REP(j, 4) {
            cin >> p[j].x >> p[j].y;
        }
        REP(j, 4) {
            l[i][j] = Line(p[j], p[(j + 1) % 4]);
        }
    }
    REP(i, 4) {
        REP(j, 4) {
            if (isIntersect(l[0][i], l[1][j])) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    REP(i, 2) {
        REP(j, 4) {
            bool f1 = true;
            REP(k, 4) {//100とか-100とか決める
                Line l1(l[i][j].a, Point(nx[k], ny[k]));
                bool f2 = false;
                REP(m, 4) {//外の正方形の線
                    f2 |= isIntersect(l1, l[(i + 1) % 2][m]);
                }
                f1 &= f2;
            }
            if (f1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}
