#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
// input: number of queries, two integers denoting the 2d array queries,
// where the first subelement is the query type, and the second is the number to insert or delete
// There are three different query types: 1, 2, 3 
// Query 1 inserts the second element in a data structure
// Query 2 deletes the second element
// Query 3 checks if any integer is present whose frequency is exactly z
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> m;
    map<int, int> other_m;
    vector<int> output;

    for(int i = 0; i < queries.size(); i++){
        if(queries[i][0] == 1){
            if(!m[queries[i][1]]){
                m[queries[i][1]] = 1;
                other_m[1] = 1;
            }
            else{
             m[queries[i][1]] += 1;
             other_m[queries[i][1]] -= 1;
            }
        }
        else if(queries[i][0] == 2){
            if(m[queries[i][1]] > 0){
                other_m[m[queries[i][1]]] -= 1;
                m[queries[i][1]] -= 1;
                other_m[m[queries[i][1]]] += 1;
            }
        }
        else if(queries[i][0] == 3){
            int freq = queries[i][1];
            if(other_m[freq] > 0){
                output.push_back(1);
            } 
            else{
                output.push_back(0);
            }
        }
    }

return output;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
