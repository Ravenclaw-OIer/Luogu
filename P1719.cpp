// Problem: P1719 最大加权矩形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1719
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
const int N = 122;
int n, a[N][N], sum[N][N];
int main() {
  rd(n);
  repn(i, n) repn(j, n) rd(a[i][j]);
  repn(i, n) repn(j, n) sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  int ans = -INF;
  rep(x1, n + 1)  rep(y1, n + 1) for (int x2 = x1; x2 <= n; x2++) for (int y2 = y1; y2 <= n; y2++)
    chmax(ans, sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1]);
  printf("%d\n", ans);
}
