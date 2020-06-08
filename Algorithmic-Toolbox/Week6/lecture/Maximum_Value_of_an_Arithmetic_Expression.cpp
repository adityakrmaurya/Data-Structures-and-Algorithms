#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

bool is_oper(char op) {
  return (op == '+' || op == '-' || op == '/' || op == '*');
}

ll evaluate(ll val1, char oper, ll val2) {
  if (oper == '+')
    return (val1 + val2);
  else if (oper == '-')
    return (val1 - val2);
  else if (oper == '/')
    return (val1 / val2);
  else if (oper == '*')
    return (val1 * val2);
  return -1e9;
}

pair<ll, ll> min_and_max(int i, int j, string &s, vector<vector<ll>> &M,
                           vector<vector<ll>> &m) {
  ll minimum = 1e9, maximum = -1e9;
  for (int k = i; k < j; k++) {
    if (is_oper(s[2 * k + 1])) {
      ll a = evaluate((M[i][k]), s[2 * k + 1], M[k + 1][j]);
      ll b = evaluate((M[i][k]), s[2 * k + 1], m[k + 1][j]);
      ll c = evaluate((m[i][k]), s[2 * k + 1], m[k + 1][j]);
      ll d = evaluate((m[i][k]), s[2 * k + 1], M[k + 1][j]);
      minimum = min(minimum, min(d, min(c, min(a, b))));
      maximum = max(maximum, max(d, max(c, max(a, b))));
    }
  }
  pair<ll, ll> Pair(minimum, maximum);
  return Pair;
}

ll parenthesis(string &str) {
  int n = (str.length() + 1) / 2;

  vector<vector<ll>> M(n, vector<ll>(n, 0));
  vector<vector<ll>> m(n, vector<ll>(n, 0));
  
  // s is the count for number of rows to fill in M and m
  // i is the relative position of element to fill from the diagonal
  // j is actual position from diagonal
  
  for (int i = 0; i < n; i++) {
    m[i][i] = stoll(str.substr(2 * i, 1));
    M[i][i] = stoll(str.substr(2 * i, 1));
  }
    

  for (int s = 0; s < n - 1; s++) {
    for (int i = 0; i < n - s - 1; i++) {
      int j = i + s + 1;
      pair<ll, ll> p = min_and_max(i, j, str, M, m);
      m[i][j] = p.first;
      M[i][j] = p.second;
    }
  }
  return M[0][n - 1];
}

int main(void) {
  string s;
  cin >> s;
  cout << parenthesis(s);
  return 0;
}
