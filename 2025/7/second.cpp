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

vector<string> manifold;

void readManifold() {
  string line;
  while (getline(cin, line)) {
    manifold.push_back(line);
  }
}

long long memo[1000][1000];

ll solve(int y, int x) {
  if (y >= manifold.size()) {
    return 1; // weve reached the end of a line
  }

  if (memo[y][x] != -1) {
    // weve already calculated this
    return memo[y][x];
  }

  char c = manifold[y][x];

  if (c == '.' || c == 'S') {
    return memo[y][x] = solve(y + 1, x);
  }

  if (c == '^') {
    return memo[y][x] = (solve(y, x + 1) + solve(y, x - 1));
  }

  cerr << "not supp to happen" << endl;
  return 0;
}

int main() {
  readManifold();

  memset(memo, -1, sizeof(memo));

  ll total = 0;

  rep(i, 0, manifold[0].size()) {
    if (manifold[0][i] == 'S') {
      total = solve(0, i);
      break;
    }
  }

  cout << total << endl;

  return 0;
}