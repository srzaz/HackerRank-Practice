#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
// Find the number of pairs of substrings of the string
// that are anagrams of eachothers

//O(n^3) complexity
int sherlockAndAnagrams(string s) {
    //initialize map to hold pairs
    map<string, int> m;

    //initialize size of string
    int len = (int)s.size();

    //loop through every possible combination of substring
    for(int i = 0; i < len; i++){
        for(int j = 1; i + j -1 < len; j++){
            //get the substring from point i to j
            string t = s.substr(i, j);
            // sort it because order doesnt matter, only occurrences of letters. (third for-loop)
            sort(t.begin(), t.end());
            //add each combination into map
            m[t]++;
        }
    }

    long long ans = 0;
    //iterate through combination counter
    for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
        //n(n-1)/2 for distinct pairs
        ans += (long long)(it->second) * (it->second - 1)/2;
    }
    
    return ans;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
