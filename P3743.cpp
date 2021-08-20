// Problem: P3743 kotori的设备
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3743
// Written by RavenclawOIer on 08-20-2021

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
const double eps = 1e-6;
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
const int N = 100010;
double n, p, a[N], b[N];
bool check(double x) {
  double tot = 0;
  rep(i, n) {
    if (x > b[i] / a[i] + eps) {
      tot += a[i] * x - b[i];
    }
  }
  return tot < p * x;
}
int main() {
  rd(n);
  rd(p);
  double sum = 0;
  rep(i, n) {
    rd(a[i]);
    rd(b[i]);
    sum += a[i];
  }
  if (sum <= p) return !puts("-1");
  double L = 0, R = 1e12, ans = -1;
  while (L + eps < R) {
    double mid = (L + R) / 2;
    if (check(mid)) {
      ans = mid;
      L = mid;
    } else R = mid;
  }
  printf("%.12lf\n", L);
}
