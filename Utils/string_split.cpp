//
// Created by lichao15 on 2016/9/20.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string, string);

int test_split() {
    string line = "1234,1,,wetwe";
    vector<string> res = split(line, ",,");
    vector<string>::iterator iter;
    for (iter = res.begin(); iter != res.end(); ++iter)
        cout << ":" << *iter << endl;
}

vector<string> split(string str, string delim) {
    vector<string> result;
    str += delim;
    size_t first = 0;
    size_t index = str.find(delim, first);
    do {
        result.push_back(str.substr(first, index - first));
        first = index + delim.size();
        index = str.find(delim, first);
    } while (index < str.size());
    return result;
}