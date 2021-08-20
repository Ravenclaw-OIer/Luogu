// Problem: P2004 领地选择
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2004
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
const int N = 3100;
int a[N][N], sum[N][N], n, m, c;
int main() {
  rd(n);
  rd(m);
  rd(c);
  repn(i, n) repn(j, n) rd(a[i][j]);
  repn(i, n) repn(j, n) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
  int ans = -INF, x = -1, y = -1;
  for (int i = c; i <= n; i++)
    for (int j = c; j <= m; j++)
      if (ans < sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c]) {
        ans = sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c];
        x = i - c + 1, y = j - c + 1;
      }
  printf("%d %d\n", x, y);
}
