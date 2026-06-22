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

int main() {
  readManifold();

  long long total = 0;

  rep(i, 1, manifold.size()) {
    rep(j, 0, manifold[i].size()) {

      if (manifold[i - 1][j] == 'S' || manifold[i - 1][j] == '|') {
        if (manifold[i][j] == '^') {
          bool tr = false;
          if (j > 0) {
            tr = true;
            manifold[i][j - 1] = '|';
          }
          if (j < manifold[i].length()) {
            tr = true;
            manifold[i][j + 1] = '|';
          }
          if (tr)
            total++;
        } else {
          // if there is an S or beam above it
          manifold[i][j] = '|';
        }
      }
    }
  }

  cout << total << endl;

  return 0;
}