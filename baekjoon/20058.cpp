// simulation practice (gold 4)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int n;

int so1[65][65];
int so2[65][65];
bool so3[65][65];

bool vis[65][65];

int mx[4]={0, 1, 0 ,-1};
int my[4]={1, 0, -1, 0};

void rot(int x, int y, int k) {
    int i2=0, j2=k-1;
    for(int i=x; i<x+k; i++) {
        for(int j=y; j<y+k; j++) {
            so2[i2][j2]=so1[i][j];
            i2++;
        }
        j2--;
        i2=0;
    }

    i2=0;
    j2=0;
    for(int i=x; i<x+k; i++) {
        for(int j=y; j<y+k; j++) {
            so1[i][j]=so2[i2][j2];
            j2++;
        }
        i2++;
        j2=0;
    }

    /*
    for(int i=x; i<x+k; i++) {
        for(int j=y; j<y+k; j++) {
            cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            cout << so2[i][j] << ' ';
        }
        cout << '\n';
    }
    */
}

void boq(int k) {
    k=(int)pow(2,k);
    int x=0, y;
    int n1=n, n2=n;
    while(n1>0) {
        n1-=k;
        y=0;
        while(n2>0) {
            rot(x, y, k);
            y+=k;
            n2-=k;
        }
        x+=k;
        n2=n;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q, l, cx, cy;
    cin >> n >> q;

    n=(int)pow(2, n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
        }
    }

    while(q--) {
        cin >> l;
        if(l!=0) boq(l);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                so3[i][j]=0;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                int an=0;
                for(int k=0; k<4; k++) {
                    cx=i+mx[k]; cy=j+my[k];

                    if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
                    if(so1[cx][cy]>0) an++;
                }
                if(an<3 && so1[i][j]>0) so3[i][j]=true;
            }
        }

        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(so3[i][j]==true) so1[i][j]--;
                ans+=so1[i][j];
            }
        }
    }

    int mar=0, cur;
    pair<int, int> tmq;
    int qx, qy;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(so1[i][j]==0) continue;

            queue <pair<int ,int>> qu;
            qu.push({i, j});
            vis[i][j]=1;
            cur=1;
            while(!qu.empty()) {
                tmq=qu.front();qu.pop();
                qx=tmq.first; qy=tmq.second;

                for(int k=0; k<4; k++) {
                    cx=qx+mx[k]; cy=qy+my[k];

                    if(cx<0 || cy<0 || cx>=n || cy>=n) continue;

                    if(vis[cx][cy]==0 && so1[cx][cy]>0) {
                        cur++;
                        qu.push({cx, cy});
                        vis[cx][cy]=1;
                    }
                }
            }
            if(cur>mar) mar=cur;
        }
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans+=so1[i][j];
        }
    }

    cout << ans << '\n' << mar;


}

