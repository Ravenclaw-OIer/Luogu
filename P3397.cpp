// Problem: P3397 地毯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3397
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
const int N = 1010;
int n, m;
int a[N][N], b[N][N];
int main() {
  rd(n); rd(m);
  repn(i, m) {
    int x1, y1, x2, y2;
    rd(x1); rd(y1); rd(x2); rd(y2);
    for (int x = x1; x <= x2; x++) {
      a[x][y1]++;
      a[x][y2 + 1]--;
    }
  }
  repn(i, n) {
    repn(j, n) {
      b[i][j] = b[i][j - 1] + a[i][j];
      printf("%d ", b[i][j]);
    }
    puts("");
  }
}
