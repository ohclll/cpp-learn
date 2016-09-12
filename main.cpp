#include <string>
#include <vector>
#include <io.h>
#include <iostream>

using namespace std;

void getFiles(const string&,vector<string>&);
int main() {
    string prefix="E:\\data\\bot\\image\\";
    vector<string> imgnames;
    getFiles(prefix,imgnames);
    cout<<imgnames.size()<<endl;
}

void getFiles(const string& path,vector<string>& files){
    intptr_t hFile=0;
    struct _finddata_t fileinfo;
    string p;
    if((hFile=_findfirst(p.assign(path).append("*").c_str(),&fileinfo))!=-1){
        do{
            if((fileinfo.attrib & _A_SUBDIR)){
                if(strcmp(fileinfo.name,".")!=0 & strcmp(fileinfo.name,"..")!=0){
                    getFiles(p.assign(path).append(fileinfo.name).append("\\"),files);
                }
            }
            else{
                files.push_back(p.assign(path).append(fileinfo.name));
            }
        }while (_findnext(hFile,&fileinfo)==0);
        _findclose(hFile);
    }
}
