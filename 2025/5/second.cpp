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

vector<pl> ranges;

void readRanges() {
  long long start, end;
  char dash;

  while (cin >> start >> dash >> end) {
    if (dash != '-') {
      break;
    }
    ranges.push_back({start, end});
  }
}

int main() {
  readRanges();
  sort(all(ranges));
  long long total = 0;
  long long currL = ranges[0].first;
  long long currR = ranges[0].second;

  for (auto [l, r] : ranges) {
    if (l <= currR) {
      currR = max(currR, r);
    } else {
      total += currR - currL + 1;
      currL = l;
      currR = r;
    }
  }

  total += currR - currL + 1;

  cout << "total = " << total << endl;

  return 0;
}