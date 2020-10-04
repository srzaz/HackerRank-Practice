#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long max_long = -99999999;

// Complete the arrayManipulation function below.
// Starting with a 1-indexed array of zeros
// and a list of operations, for each operation
//  add a value to each of the array element between
//  two given indices, inclusive. Once all operations have
//  been performed, return the maximum value in the array.

/* NAIVE Solution O(nm) time
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> max_value(n+1);

    for(long i = 0; i < queries.size(); i++){
        long a = queries[i][0];
        long b = queries[i][1];
        long k = queries[i][2];

        while(a <= b){
            max_value[a] += k;
            if(max_value[a] > max_long){
                max_long = max_value[a];
            }
            a++;
        }
    }

    return max_long;

}
*/
//OPTIMAL Solution O(n+m) time

long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> max_value(n + 2);

    for (long i = 0; i < queries.size(); i++)
    {
        long a = queries[i][0];
        long b = queries[i][1];
        long k = queries[i][2];

        max_value[a] += k;
        max_value[b + 1] -= k;
    }

    long sum = 0;
    for(int i = 0; i < max_value.size(); i++){
        sum += max_value[i];
        if(sum > max_long){
            max_long = sum;
        }
    }

    return max_long;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++)
    {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
