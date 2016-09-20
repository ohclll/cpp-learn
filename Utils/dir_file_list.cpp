//
// Created by lichao15 on 2016/9/20.
//

#include <string>
#include <vector>
#include <io.h>
#include <iostream>
#include <fstream>

using namespace std;

void getFiles(const string &, vector<string> &);

int dir_file_list() {
    string prefix = "E:\\data\\bot\\train\\";
    vector<string> imgnames;
    getFiles(prefix, imgnames);
    ofstream outf("E:\\data\\bot\\t.txt", ios::out);
    for (int i = 0; i < imgnames.size(); ++i) {
        outf << imgnames[i] << endl;
    }
    outf.close();
    ifstream inf("E:\\data\\bot\\t.txt", ios::in);
    vector<pair<string, string>> path_name;
    string line;
    size_t pos;
    while (getline(inf, line)) {
        pos = line.find_last_of("\\");
        path_name.push_back(make_pair(line.substr(0, pos), line.substr(pos + 1)));
    }
    vector<pair<string, string>>::iterator iter;
    for (iter = path_name.begin(); iter != path_name.end(); iter++) {
        cout << (*iter).first << "\t" << (*iter).second << endl;
    }
}

void getFiles(const string &path, vector<string> &files) {
    intptr_t hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("*").c_str(), &fileinfo)) != -1) {
        do {
            if ((fileinfo.attrib & _A_SUBDIR)) {
                if (strcmp(fileinfo.name, ".") != 0 & strcmp(fileinfo.name, "..") != 0) {
                    getFiles(p.assign(path).append(fileinfo.name).append("\\"), files);
                }
            }
            else {
                files.push_back(p.assign(path).append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}
