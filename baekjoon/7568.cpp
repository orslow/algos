// easy simulation
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int weight;
    int height;
    int rank;
} person;

person p[59];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> p[i].weight >> p[i].height;
    }

    int r;

    for(int i=0; i<n; i++) {
        r=1;
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if(p[i].weight < p[j].weight && p[i].height < p[j].height)
                    r++;
            }
        }
        cout << r << ' ';
    }
}
