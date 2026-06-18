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

struct problem {
  vector<long long> numbers;
  char operation;
};

vector<problem> problems;

void readProblems() {
  long long number;
  int next = 0;
  while (cin >> number) {
    next %= 1000; // number of problems
    problems[next].numbers.push_back(number);
    next++;
  }
  cin.clear();
  next = 0;
  char op;
  while (cin >> op) {
    next %= 1000;
    if (op == '*' || op == '+') {
      problems[next].operation = op;
      next++;
    }
  }
}

int main() {
  problems.resize(1000);
  readProblems();
  long long total = 0;

  for (problem i : problems) {
    if (i.operation == '+') {
      for (auto num : i.numbers) {
        total += num;
      }
    } else {
      long long prod = 1;
      for (auto num : i.numbers) {
        prod *= num;
      }
      total += prod;
    }
  }

  cout << "total = " << total << endl;
  return 0;
}