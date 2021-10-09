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
struct Point  {
  int x, y;
  Point(int x = 0, int y = 0): x(x), y(y) {}
  bool operator<(const Point& rhs) const { return x < rhs.x; }
} p[400040], b[400040];
int n;
inline double dist(Point p, Point q) {
  return sqrt((LL)(p.x - q.x) * (p.x - q.x) + (LL)(p.y - q.y) * (p.y - q.y));
}
double solve(int l, int r) {
  if (l == r) return 1e9;
  int mid = (l + r) >> 1;
  double d = 1e9;
  d = min(solve(l, mid), solve(mid + 1, r));
  double midx = p[mid].x;
  int cnt = 0;
  for (int i = l; i <= r; i++) {
    if (fabs(midx - p[i].x) < d) b[++cnt] = (p[i]);
  }
  sort(b + 1, b + cnt  + 1, [](const Point& x, const Point& y) {
    return x.y < y.y;
  });
  repn(i, cnt)
    for (int j = i + 1; j <= cnt; j++) {
      if (b[j].y - b[i].y >= d) break;
      chmin(d, dist(b[j], b[i]));
    }
  return d;
}
signed main() {
  rd(n);
  repn(i, n) {
    rd(p[i].x);
    rd(p[i].y);
  }
  sort(p + 1, p + n + 1);
  double ans = solve(1, n);
  printf("%.0lf", ans * ans);
}
