#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char, int> m;
    int remove = 0;

    for(char c : a){
        m[c]++;
    }

    for(char c : b){
        m[c]--;
    }

    for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
        remove += abs(it->second);
    }

    
    return remove;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
