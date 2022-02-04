#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumPasses' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER m
 *  2. LONG_INTEGER w
 *  3. LONG_INTEGER p
 *  4. LONG_INTEGER n
 */

long minimumPasses(long m, long w, long p, long n) {
    long candies=0;
    long passes=0;
    long tempM,tempW,buy,curent=0;
    while(curent<n){
        candies+=(m*w);
        curent=candies;
        tempM = m;
        tempW = w;
        buy = candies/p;
        if (buy>0){
            if(m >= w+buy){
                tempW+=buy;
            }else if(w >= m+buy){
                tempM+=buy;
            }else{
                tempW = (m+w+buy)/2;
                tempM = (m+w+buy)-tempW;
            }
            if(((n-candies)/(m*w))>((n-(candies-buy*p))/(tempW*tempM))){
                m=tempM;
                w=tempW;
                candies=candies-(buy*p);
            }
        }
        
        
        
        
        
        

        passes++;
    }
    return passes;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long m = stol(first_multiple_input[0]);

    long w = stol(first_multiple_input[1]);

    long p = stol(first_multiple_input[2]);

    long n = stol(first_multiple_input[3]);

    long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

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
