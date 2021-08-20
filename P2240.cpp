// Problem: P2240 【深基12.例1】部分背包问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2240
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
const int N = 1020;
int n, t;
struct S {
  double m, v;
} s[N];
int main() {
  rd(n);
  rd(t);
  repn(i, n) {
    rd(s[i].m);
    rd(s[i].v);
  }
  sort(s + 1, s + n + 1, [](const S& a, const S& b) {
    double value1 = a.v / a.m;
    double value2 = b.v / b.m;
    return value1 > value2;
  });
  double ans = 0;
  repn(i, n) {
 //   cerr << t << endl;
    if (t > s[i].m) {
      t -= s[i].m;
      ans += s[i].v;
    } else {
      ans += (s[i].v / s[i].m) * t;
      break;
    }
  }
  printf("%.2lf\n", ans);
}
