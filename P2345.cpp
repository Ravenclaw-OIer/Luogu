/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n;
struct Cow {
  int x, v;
  bool operator<(const Cow& rhs) const {
    return x < rhs.x;
  }
  Cow(int x = 0, int v = 0): x(x), v(v) {}
};
Cow cow[20010], b[20010]; 
int sum[20020], suf[20020], ans;
 main() {
  rd(n);
  repn(i, n) {
    rd(cow[i].v);
    rd(cow[i].x);
  }
  sort(cow + 1, cow + 1 + n, [](const Cow a, const Cow b) {
    return a.v < b.v;
  });
  repn(i, n) repn(j, i - 1) ans += cow[i].v * abs(cow[i].x - cow[j].x);
  printf("%lld\n", ans);
}
