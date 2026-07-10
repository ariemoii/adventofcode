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

  const bool operator<(const Point other) {
    if (x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }

  const bool operator==(const Point other) {
    return x == other.x && y == other.y;
  }

  friend ostream& operator<<(ostream& stream, const Point& p) {
    return stream << '(' << p.x << ' ' << p.y << ')';
  }
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

//check if p is on segment a1a2
bool onSegment(Point a1, Point a2, Point p) {
  return (p.x <= max(a1.x, a2.x) &&
          p.x >= min(a1.x, a2.x) &&
          p.y <= max(a1.y, a2.y) &&
          p.y >= min(a1.y, a2.y)); 
}

ll calcArea(Point a, Point b) {
  return (abs(a.x - b.x) + 1) * (abs(a.y - b.y) + 1);
}

// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {

  Point v1 = {q.x - p.x, q.y - p.y};
  Point v2 = {r.x - q.x, r.y - q.y};

  long long val = 1LL * v1.x * v2.y - 1LL * v1.y *v2.x;

  // collinear
  if (val == 0) return 0;

  // clock or counterclock wise
  // 1 for clockwise, 2 for counterclockwise
  return (val > 0) ? 1 : 2;
}

bool lineIntersectsLine(Point a1, Point a2, Point b1, Point b2) {
  if ((a1 == b1 && a2 == b2) ||
    (a1 == b2 && a2 == b1)) {
    // we have the same line segments

    return false;
  }

  int o1 = orientation(a1, a2, b1);
  int o2 = orientation(a1, a2, b2);
  int o3 = orientation(b1, b2, a1);
  int o4 = orientation(b1, b2, a2);

  //general case
  if (o1 != o2 && o3 != o4) {
    return true;
  }

  return false;
}

bool pointInsidePolygon(Point p, vector<Point>& polygon) {
  bool inside = false;
  int n = polygon.size();

  for (int i = 0, j = n - 1; i < n; j = i++) {
    Point a = polygon[i];
    Point b = polygon[j];

    if (orientation(a, b, p) == 0 && onSegment(a, b, p)) {
        return true;
    }

    bool crosses = ((a.y > p.y) != (b.y > p.y)) &&
                   (p.x < (b.x - a.x) * (p.y - a.y) / 
                           (double)(b.y - a.y) + a.x);

    if (crosses) {
      inside = !inside;
    }
  }

  return inside;
}

bool intersectsAnyLine(Point p1, Point p2, vector<Point>& polygon) {
  for (int i = 0; i < polygon.size()-1; ++i) {
    if (lineIntersectsLine(p1, p2, polygon[i], polygon[i+1])) {
      return true;
    }
  }

  if (lineIntersectsLine(p1, p2, polygon[0], polygon[polygon.size()-1])) {
    return true;
  }
  
  return false;
}

void calcAllAreas() {
  rep(i, 0, redBoxes.size()) {
    rep(j, i + 1, redBoxes.size()) {
      Point p1 = redBoxes[i];
      Point p2 = redBoxes[j];
      Point p3 = {p1.x, p2.y};
      Point p4 = {p2.x, p1.y};

      //first, check if the center is inside
      Point center = {
        (p1.x + p2.x) / 2,
        (p1.y + p2.y) / 2
      };

      if (!pointInsidePolygon(center, redBoxes)) {
        break;
      }

      if (intersectsAnyLine(p1, p3, redBoxes) ||
          intersectsAnyLine(p1, p4, redBoxes) ||
          intersectsAnyLine(p2, p3, redBoxes) ||
          intersectsAnyLine(p2, p4, redBoxes)) continue;

      areas.push_back(calcArea(p1, p2));
    }
  }
}

int main() {
  readBoxes();
  calcAllAreas();
  // cout << *max_element(all(areas)) << endl;
  cout << "num areas = " << areas.size() << endl;
  return 0;
}