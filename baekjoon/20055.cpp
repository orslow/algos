// simulation practice
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

pair<int,int> cv[203];

int n,k;

void move1() {
    int v=cv[n*2].first, r=cv[n*2].second;
    for(int i=n*2; i>=2; i--) {
        cv[i].first=cv[i-1].first;
        cv[i].second=cv[i-1].second;
    }
    if(cv[n].second==1) {
        cv[n].second=0;
    }
    cv[1].first=v; cv[1].second=r;
}

void move2() {
    for(int i=n; i>=2; i--) {
        if(cv[i].second==0 && cv[i].first>0 && cv[i-1].second==1) {
            cv[i].second=1;
            cv[i].first-=1;
            cv[i-1].second=0;
        }
    }
    if(cv[n].second==1) {
        cv[n].second=0;
    }
    if(cv[1].first>0) {
        cv[1].second=1;
        cv[1].first-=1;
    }
}

bool check() {
    int cnt=0;
    for(int i=1; i<=n*2; i++) {
        if(cv[i].first==0) {
            cnt++;
        }
    }

    if(cnt>=k) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for(int i=1; i<=n*2; i++) {
        cin >> cv[i].first;
    }

    int ans=0;
    while(1) {
        move1();
        move2();
        if(check()) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans+1;
}

