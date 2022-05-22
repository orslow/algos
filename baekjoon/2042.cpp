// segment tree exercise
#include <bits/stdc++.h>

using namespace std;

long long so1[2000004];

int n;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) so1[i] = so1[i<<1] + so1[i<<1|1];
}

void modify(int p, long long value) {  // set value at position p
  for (so1[p += n] = value; p > 1; p >>= 1) {
      so1[p>>1] = so1[p] + so1[p^1]; // p^1 equals to p+1 if p is even, and p-1 if p is odd.
  }
}

long long query(int l, int r) {  // sum on interval [l, r)
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += so1[l++];
    if (r&1) res += so1[--r];
  }
  return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,k;
    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        cin >> so1[n+i];
    }

    build();

    long long a,b,c;
    for(int i=0; i<m+k; i++) {
        cin >> a >> b >> c;

        if(a==1) {
            modify(b-1, c);
        } else {
            cout << query(b-1, c) << '\n';
        }
    }
}
