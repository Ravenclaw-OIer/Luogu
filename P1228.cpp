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

void dfs(int n, int sx, int sy, int x, int y) {
  if (!n) return;
  int l = 1 << (n - 1);
  if (x < sx + l && y < sy + l) {
    printf("%d %d 1\n", sx + l, sy + l);
    dfs(n - 1, sx, sy, x, y);
    dfs(n - 1, sx + l, sy, sx + l, sy + l - 1);
    dfs(n - 1, sx + l, sy + l, sx + l, sy + l);
    dfs(n - 1, sx, sy + l, sx + l - 1, sy + l);
  } else if (x < sx + l) {
    printf("%d %d 2\n", sx + l, sy + l - 1);
    dfs(n - 1, sx, sy, sx + l - 1, sy + l - 1);
    dfs(n - 1, sx + l, sy, sx + l, sy + l - 1);
    dfs(n - 1, sx + l, sy + l, sx + l, sy + l);
    dfs(n - 1, sx, sy + l, x, y);
  } else if (y < sy + l) {
    printf("%d %d 3\n", sx + l  - 1, sy + l);
    dfs(n - 1, sx, sy, sx + l - 1, sy + l - 1);
    dfs(n - 1, sx + l, sy, x, y);
    dfs(n - 1, sx + l, sy + l, sx + l, sy + l);
    dfs(n - 1, sx, sy + l, sx + l - 1, sy + l);
  } else {
    printf("%d %d 4\n", sx + l - 1, sy + l - 1);
    dfs(n - 1, sx, sy, sx + l - 1, sy + l - 1);
    dfs(n - 1, sx + l, sy, sx + l, sy + l - 1);
    dfs(n - 1, sx + l, sy + l, x, y);
    dfs(n - 1, sx, sy + l, sx + l - 1, sy + l);
  }
}
int main() {
  int n, x, y;
  rd(n); rd(x); rd(y);
  dfs(n, 1, 1, x, y);
}
