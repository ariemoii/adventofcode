#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpl vector<pl>
#define vpi vector<pi>
#define vld vector<ld>
#define vvpi vector<vpi>
#define in(el, cont) (cont.find(el) != cont.end()) // sets/maps
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define inf(T) numeric_limits<T>::max()

constexpr int INF = INT_MAX;
constexpr ll LLINF = LONG_LONG_MAX;

struct Point {
  long long x, y;
};

vector<Point> redBoxes;

vl areas;

void readBoxes() {
  int x, y;
  while (1) {
    if (!(cin >> x)) {
      break;
    }
    getchar();
    cin >> y;
    redBoxes.push_back({x, y});
  }
}

void printBoxes() {
  for (auto b : redBoxes) {
    cout << b.x << ' ' << b.y << endl;
  }
}

ll calcArea(Point a, Point b) {
  return (abs(a.x - b.x) + 1) * (abs(a.y - b.y) + 1);
}

void calcAllAreas() {
  rep(i, 0, redBoxes.size()) {
    rep(j, i + 1, redBoxes.size()) {
      areas.push_back(calcArea(redBoxes[i], redBoxes[j]));
    }
  }
}

int main() {
  readBoxes();
  calcAllAreas();
  cout << *max_element(all(areas)) << endl;
  return 0;
}