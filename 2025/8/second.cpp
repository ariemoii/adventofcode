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

struct UnionFind {
  vector<int> par, rank, size;
  int c;
  UnionFind(int n): par(n), rank(n, 0), size(n, 1), c(n) {
    for (int i = 0; i < n; i++) par[i] = i;
  }

  int find(int i) {
    return (par[i] == i) ? i : (par[i] = find(par[i]));
  }

  bool same(int i, int j) {
    return find(i) == find(j);
  }

  int getSize(int i) {
    return size[find(i)];
  }

  int count() {
    return c;
  }

  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    --c;
    if (rank[i] > rank[j]) swap(i, j);
    par[i] = j;
    size[j] += size[i];
    if (rank[i] == rank[j]) ++rank[j];
    return j;
  }
};

struct box {
  int x, y, z;
  int id;
};

struct connection {
  int boxID1, boxID2;
  ll length;

  const bool operator<(const connection& other) const {
    return length < other.length;
  }
};

vector<box> boxes;

vector<connection> connections;

istream& readBox(istream& in) {
  box b;
  char comma;

  if (in >> b.x >> comma >> b.y >> comma >> b.z) {
    b.id = boxes.size();
    boxes.push_back(b);
  }

  return in;
}

void readBoxes() {
  while (readBox(cin));
}

ll calcDist(box a, box b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  ll dz = a.z - b.z;
  return dx*dx + dy*dy + dz*dz;
}

void fillConnections() {
  for (int i = 0; i < boxes.size(); i++) {
    for (int j = i+1; j < boxes.size(); j++) {
      connection c = {boxes[i].id, boxes[j].id, 0};
      c.length = calcDist(boxes[i], boxes[j]);
      connections.push_back(c);
    }
  }

  sort(connections.begin(), connections.end());
}

int main() { 
  readBoxes();
  fillConnections();

  UnionFind uf(boxes.size());

  connection last;

  for (int i = 0; i < connections.size(); i++) {
    if (!uf.same(connections[i].boxID1, connections[i].boxID2)) {
      uf.merge(connections[i].boxID1, connections[i].boxID2);
      last = connections[i];
    }
  }

  ll total = 1;

  cout << "answer = " << boxes[last.boxID1].x * boxes[last.boxID2].x << endl;

  return 0; 
}