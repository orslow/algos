// basic trie - practice
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool il;

char ss[10003][11];

struct Trie {
    bool finish;
    Trie *next[10];

    Trie() : finish(0) {
        for(int i=0; i<10; i++) {
            next[i]=NULL;
        }
    }

    ~Trie() {
        for(int i=0; i<10; i++) {
            if(next[i]) delete next[i];
        }
    }

    void insert(const char* c) {
        if(*c == '\0') {
            finish=1;
        }
        else {
            int t=*c-48;
            if(next[t]==NULL) {
                next[t]=new Trie();
            }
            next[t]->insert(c+1);
        }
    }

    bool check(const char* c) {
        if(*c == '\0') {
            return false;
        }
        if(finish==1)
            return true;
        int t=*c-48;
        if(next[t]==NULL) {
            return false;
        }
        return next[t]->check(c+1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    cin >> t;

    while(t--) {
        cin >> n;

        Trie *root = new Trie();
        il=1;

        for(int i=0; i<n; i++) {
            cin >> ss[i];
            root->insert(ss[i]);
        }
        for(int i=0; i<n; i++) {
            if(root->check(ss[i])) {
                il=0;
                break;
            }
        }
        if(il) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        delete root;
    }
}
