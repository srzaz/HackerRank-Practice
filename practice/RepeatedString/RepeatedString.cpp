#include <bits/stdc++.h>

using namespace std;

//Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    long counter = 0;
    //count instances in initial string
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'A')
            counter++;
    }

    //multiply by total substrings
    long times = n / s.length();
    counter = counter * times;

    //retrieve extra occurrences
    int remainder = n % s.length();
    if (remainder != 0)
    {
        for (int i = 0; i < remainder; i++)
        {
            if (s[i] == 'a' || s[i] == 'A')
                counter++;
        }
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
