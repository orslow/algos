// binary serch and think
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n,l,w,h;
    cin >> n >> l >> w >> h;

    double lh=0, rh=max(l, max(w, h));

    for(int i=0; i<100000; i++) {
        double mid=(lh+rh)/2;
        if((ll)(l/mid)*(ll)(w/mid)*(ll)(h/mid)>=n) {
            lh=mid;
        } else {
            rh=mid;
        }
    }

    printf("%.10lf", lh);
}
