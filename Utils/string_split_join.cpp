#include <string>
#include <vector>
#include <io.h>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> stringSplit(string, string);

string stringJoin(vector<string>, string);

int main() {
    string line = "abc,12,de,45";
    vector<string> res = stringSplit(line, ",");
    vector<string>::iterator iter;
    for (iter = res.begin(); iter != res.end(); ++iter)
        cout << ":" << *iter << endl;
    line = stringJoin(res, " ");
    cout << line;

}

vector<string> stringSplit(string str, string delim) {
    vector<string> result;
    if (str.size() > 0) {
        str += delim;
        size_t first = 0;
        size_t index = str.find(delim, first);
        do {
            result.push_back(str.substr(first, index - first));
            first = index + delim.size();
            index = str.find(delim, first);
        } while (index < str.size());
    }
    return result;
}

string stringJoin(vector<string> vstr, string delim) {
    string result;
    vector<string>::iterator iter;
    for (iter = vstr.begin(); iter != vstr.end(); ++iter) {
        if (iter == vstr.end() - 1)
            result += *iter;
        else
            result += *iter + delim;
    }
    return result;
}