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

#define NUM_PROBLEMS 1000

struct problem {
  vector<long long> numbers;
  char operation;
};

vector<problem> problems;
vector<string> input;

void readProblemsAsString() {
  int next = 0;

  char ch = '1';
  while (1) {
    ch = getchar();
    if (ch == '+' || ch == '*') {
      break;
    }
    if (ch == '\n') {
      next++;
      continue;
    }

    input[next].push_back(ch);
  }

  // read as Strings
  // char ch = '1';
  // while (ch != '+' && ch != '*') {
  //   ch = getchar();
  //   next %= NUM_PROBLEMS;
  //   if (ch == ' ' || ch == '\n') {
  //     if (isdigit(cin.peek())) {
  //       asString[next].push_back(' ');
  //       next++;
  //     }
  //     continue;
  //   }

  //   if (ch == '+' || ch == '*') {
  //     break;
  //   }

  //   asString[next].push_back(ch);
  // }

  cin.putback(ch);

  // read operations
  cin.clear();
  next = 0;
  char op;
  while (cin >> op) {
    next %= NUM_PROBLEMS;
    if (op == '*' || op == '+') {
      problems[next].operation = op;
      next++;
    }
  }
}

void transpose(vector<string> &a) {
  int n = a.size();
  if (n == 0)
    return;

  int m = 0;
  for (auto &row : a)
    m = max(m, (int)row.size());

  for (auto &row : a)
    row.resize(m, ' ');

  vector<string> t(m, string(n, ' '));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      t[j][i] = a[i][j];
    }
  }

  a = move(t);
}

void readAsProblem(vector<string> &input) {
  int next = 0;
  for (auto &i : input) {
    stringstream ss(i);
    long long num = -1;
    ss >> num;
    if (num == -1) {
      next++;
      continue;
    }
    problems[next].numbers.push_back(num);
  }
}

int main() {
  problems.resize(NUM_PROBLEMS);
  input.resize(NUM_PROBLEMS);

  readProblemsAsString();
  transpose(input);
  readAsProblem(input);

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