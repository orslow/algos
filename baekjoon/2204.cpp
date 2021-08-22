#include <bits/stdc++.h>

using namespace std;

int main() {

    while(true) {
        int n;
        cin >> n;
        if(!n) return 0;

        string w;
        vector <pair<string, string> > words;
        while(n--) {
            cin >> w;
            string md="";
            for(auto& c: w) md+=tolower(c);
            words.push_back({md, w});
        }

        sort(words.begin(), words.end());

        cout << words[0].second << '\n';
    }
}

