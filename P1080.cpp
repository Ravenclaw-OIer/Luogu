// Problem: P1080 [NOIP2012 提高组] 国王游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1080
// Written by RavenclawOIer on 10-08-2021

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int INF = 0x3f3f3f3f;
ttt inline T rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
  return x;
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
struct BigInteger {
  vector<int> num;
  BigInteger(int x) {
    while (x) {
      num.push_back(x % 10);
      x /= 10;
    }
    // cerr << "Constructor OK" << endl;
  }
  void allocate(int x) { num.resize(x); }
  BigInteger() {}
  BigInteger operator*(const int& rhs) {
    BigInteger ret;
    ret.allocate(num.size());
    // cerr << num.size() << endl;
    rep(i, num.size()) ret.num[i] = num[i] * rhs;
    // cerr << "OK" << endl;
    rep(i, num.size() - 1) {
      ret.num[i + 1] += ret.num[i] / 10;
      ret.num[i] %= 10;
    }
    // cerr << ret.num.size() << endl;
    while (ret.num[ret.num.size() - 1] >= 10) {
      // cerr << "It seems we need to deal with the last digit" << endl;
      ret.num.push_back(ret.num[ret.num.size() - 1] / 10);
      ret.num[ret.num.size() - 2] %= 10;
    }
    return ret;
  }
  BigInteger operator/(const int& rhs) {
    BigInteger ret;
    ret.allocate(num.size());
    int rem = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
      rem = rem * 10 + num[i];
      ret.num[i] = rem / rhs;
      rem %= rhs;
    }
    int i;
    for (i = ret.num.size() - 1; i >= 0; i--) {
      if (ret.num[i]) break;
    }
    ret.num.resize(i + 1);
    return ret;
  }
  bool operator<(const BigInteger& rhs) const {
    if (rhs.num.size() == num.size()) {
      // cerr << "Equal length, proceeding..." << endl;
      for (int i = num.size() - 1; i >= 0; i--) {
        if (rhs.num[i] != num[i]) {
          // cerr << "Differ: " << num[i] << ' ' << rhs.num[i] << endl;
          return num[i] < rhs.num[i];
        }
      }
      return false;
    } else
      return num.size() < rhs.num.size();
  }
};
ostream& operator<<(ostream& os, const BigInteger& x) {
  vector<int> y = x.num;
  reverse(y.begin(), y.end());
  rep(i, y.size()) os << y[i];
  return os;
}
pii a[200020];
int main() {
  int n;
  /* debug
  int x, y;
  cin >> x >> y;
  BigInteger X(x);
  cout << X * y << endl << X / y << endl;
  cout << X << endl;
  BigInteger Y(19);
  cout << (X < Y) << endl;
  //*/
  ///*
  rd(n);
  rep(i, n + 1) {
    int x, y;
    rd(x);
    rd(y);
    a[i] = (make_pair(x, y));
  }
  // cerr << "Input done" << endl;
  sort(a + 1, a + n + 1, [](const pii& lhs, const pii& rhs) {
    return lhs.first * lhs.second < rhs.first * rhs.second;
  });  // cerr << "Sorted!" << endl;
  BigInteger p(1), ans;
  // cerr << "OK" << endl;
  repn(i, n) {
    p = p * a[i - 1].first;
    BigInteger tmp;
    tmp = p / a[i].second;
    if (ans < tmp) ans = tmp;
  }
  cout << ans << endl;
  // */
}
