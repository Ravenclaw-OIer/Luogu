// Problem: P1024 [NOIP2001 提高组] 一元三次方程求解
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1024
// Written by RavenclawOIer on 08-15-2021

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
double a, b, c, d;
double f(double x) {
  return a * x * x * x + b * x * x + c * x + d;
}
const double eps = 1e-5;
int main() {
  cin >> a >> b >> c >> d;
  for (double x = -100; x <= 99; x++) {
   // cerr << f(x) << endl;
    if (f(x) == 0) cout << fixed << setprecision(2) << x << ' ';
    else if (f(x) * f(x + 1) < 0) {
  //    eprintf("Potential root in [%d, %d]\n", x, x + 1);
      double L = x, R = x + 1;
      while (R - L > eps) {
        double mid = (L + R) / 2;
        if (f(x) < 0) {
          if (f(mid) > 0) R = mid;
          else L = mid;
        } else {
          if (f(mid) < 0) R = mid;
          else L = mid;
        }
      }
      cout << fixed << setprecision(2) << L << ' ';
    }
  }
  
}
