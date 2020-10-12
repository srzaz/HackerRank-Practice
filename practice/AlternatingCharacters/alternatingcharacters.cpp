#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    char prev;
    char curr;
    int deletions = 0;
    int i = 0; 

    for(int j = 1; j < s.length(); j++){
        curr = s[j];
        prev = s[i];
        if(prev == curr){
            deletions++;
        }
        i++;    
    }
    
    return deletions;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
