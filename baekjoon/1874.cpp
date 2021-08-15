#include <bits/stdc++.h>

using namespace std;

int nums[100001];
int ord[100001];

bool vis[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;

    /*
    int maxi=0, mini=100005;
    for(int i=0; i<n; i++) {
        cin >> k;
        if(k > maxi) {
            maxi=k;
            mini=k;
        }
        else if(k < mini) {
            mini = k;
        }

        if(k > mini && k < maxi) {
            cout << "NO" << '\n';
            return 0;
        }
        nums[i]=k;
    }
    */

    int bf=0;
    for(int i=0; i<n; i++) {
        cin >> k;
        vis[k]=1;

        for(int j=k+1; j<bf; j++) {
            if (vis[j] == 0) {
                cout << "NO" << '\n';
                return 0;
            }
        }
        bf=k;
        nums[i]=k;
    }

    stack<int> stk;
    for(int i=0; i<n; i++) {
        ord[i]=i+1;
    }

    int idx=0;
    for(int i=0; i<n; i++) {
        if(stk.size()==0) {
            while(idx!=n && ord[idx]!=nums[i]) {
                stk.push(ord[idx++]);
                cout << '+' << '\n';
            }
            stk.push(ord[idx++]);
            cout << '+' << '\n';
            cout << '-' << '\n';
            stk.pop();
        } else {
            if(stk.top()==nums[i]) {
                cout << '-' << '\n';
                stk.pop();
            } else {
                while(idx!=n && ord[idx]!=nums[i]) {
                    stk.push(ord[idx++]);
                    cout << '+' << '\n';
                }
                stk.push(ord[idx++]);
                cout << '+' << '\n';
                cout << '-' << '\n';
                stk.pop();
            }
        }
    }

    return 0;
}



