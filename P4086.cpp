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
const int N = 100100;
int a[N], n, sufsum[N], sufmin[N];
double res[N];
int main() {
  rd(n);
  repn(i, n) rd(a[i]);
  sufmin[n + 1] = 0x3f3f3f3f;
  for (int i = n; i >= 1; i--) {
    sufsum[i] = a[i] + sufsum[i + 1];
    sufmin[i] = min(a[i], sufmin[i + 1]);
  }

  // printf("done!\n");
  double ans = -1;
  repn(k, n - 2) {
//  cerr << sufsum[k + 1] << ' ' << sufmin[k + 1] << endl;
    res[k] = (sufsum[k + 1] - sufmin[k + 1] ) / (double)(n - k - 1);
    chmax(ans, res[k]);
  }
 // repn(k, n - 2) cerr << res[k] << ' '; cerr << endl;
  repn(k, n - 2) if (res[k] == ans) printf("%d\n", k);
}