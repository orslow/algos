// dirty code - refactoring needed 
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int ans, n;

int fd[505][505];

void lt(int x, int y) {

    int blown=0;

    int bl=fd[x][y-1]*1/100;
    if(x-1>0) {
        fd[x-1][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n) {
        fd[x+1][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y-1]*2/100;
    if(x-2>0 && y-1>0) {
        fd[x-2][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+2<=n && y-1>0) {
        fd[x+2][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y-1]*7/100;
    if(x-1>0 && y-1>0) {
        fd[x-1][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n && y-1>0) {
        fd[x+1][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y-1]*10/100;
    if(x-1>0 && y-2>0) {
        fd[x-1][y-2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n && y-2>0) {
        fd[x+1][y-2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y-1]*5/100;
    if(y-3>0) {
        fd[x][y-3]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y-1]*55/100;
    if(y-2>0) {
        // fd[x][y-2]+=bl;
        fd[x][y-2]+=(fd[x][y-1]-blown);
    } else {
        ans+=(fd[x][y-1]-blown);
    }

    fd[x][y-1]=0;
}

void ut(int x, int y) {

    int blown=0;

    int bl=fd[x-1][y]*1/100;
    if(y-1>0) {
        fd[x][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n) {
        fd[x][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x-1][y]*2/100;
    if(y-2>0 && x-1>0) {
        fd[x-1][y-2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+2<=n && x-1>0) {
        fd[x-1][y+2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x-1][y]*7/100;
    if(y-1>0 && x-1>0) {
        fd[x-1][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n && x-1>0) {
        fd[x-1][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x-1][y]*10/100;
    if(y-1>0 && x-2>0) {
        fd[x-2][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n && x-2>0) {
        fd[x-2][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x-1][y]*5/100;
    if(x-3>0) {
        fd[x-3][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x-1][y]*55/100;
    if(x-2>0) {
        // fd[x-2][y]+=bl;
        fd[x-2][y]+=(fd[x-1][y]-blown);
    } else {
        // ans+=bl;
        ans+=(fd[x-1][y]-blown);
    }
    
    fd[x-1][y]=0;
}


void rt(int x, int y) {

    int blown=0;

    int bl=fd[x][y+1]*1/100;
    if(x-1>0) {
        fd[x-1][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n) {
        fd[x+1][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y+1]*2/100;
    if(x-2>0 && y+1<=n) {
        fd[x-2][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+2<=n && y+1<=n) {
        fd[x+2][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y+1]*7/100;
    if(x-1>0 && y+1<=n) {
        fd[x-1][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n && y+1<=n) {
        fd[x+1][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y+1]*10/100;
    if(x-1>0 && y+2<=n) {
        fd[x-1][y+2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(x+1<=n && y+2<=n) {
        fd[x+1][y+2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y+1]*5/100;
    if(y+3<=n) {
        fd[x][y+3]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x][y+1]*55/100;
    if(y+2<=n) {
        // fd[x][y+2]+=bl;
        fd[x][y+2]+=(fd[x][y+1]-blown);
    } else {
        // ans+=bl;
        ans+=(fd[x][y+1]-blown);
    }
    
    fd[x][y+1]=0;
}

void dt(int x, int y) {

    int blown=0;

    int bl=fd[x+1][y]*1/100;
    if(y-1>0) {
        fd[x][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n) {
        fd[x][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x+1][y]*2/100;
    if(y-2>0 && x+1<=n) {
        fd[x+1][y-2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+2<=n && x+1<=n) {
        fd[x+1][y+2]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x+1][y]*7/100;
    if(y-1>0 && x+1<=n) {
        fd[x+1][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n && x+1<=n) {
        fd[x+1][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x+1][y]*10/100;
    if(y-1>0 && x+2<=n) {
        fd[x+2][y-1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;
    if(y+1<=n && x+2<=n) {
        fd[x+2][y+1]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x+1][y]*5/100;
    if(x+3<=n) {
        fd[x+3][y]+=bl;
    } else {
        ans+=bl;
    }
    blown+=bl;

    bl=fd[x+1][y]*55/100;
    if(x+2<=n) {
        // fd[x+2][y]+=bl;
        fd[x+2][y]+=(fd[x+1][y]-blown);
    } else {
        // ans+=bl;
        ans+=(fd[x+1][y]-blown);
    }

    fd[x+1][y]=0;
    
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int fir=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> fd[i][j];
            fir+=fd[i][j];
        }
    }

    int cx=n/2+1, cy=n/2+1, ma=1;
    while(1) {

        if(cx==1) ma--;

        for(int i=0; i<ma; i++) {
            lt(cx, cy);
            cy-=1;
        }

        if(cx==1 && cy==1) break;

        for(int i=0; i<ma; i++) {
            dt(cx, cy);
            cx++;
        }

        ma++;

        for(int i=0; i<ma; i++) {
            rt(cx, cy);
            cy++;
        }

        for(int i=0; i<ma; i++) {
            ut(cx, cy);
            cx--;
        }

        ma++;
    }

    /*
    int la=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << fd[i][j] << ' ';
            la+=fd[i][j];
        }
        cout << '\n';
    }
    cout << fir << ' ' << la << '\n' << fir-la << '\n';
    */


    cout << ans << '\n';

}
