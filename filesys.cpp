//
// Created by Congb on 2020/1/5.
//

#include "filesys.h"
filesys::filesys() {
    currdir=file.root;
}
filesys::~filesys() {

}
string filesys::cmd() {
    string t;
    cout<<dirname();
    cout<<">";
    getline(cin, t);
    return t;
}
string filesys::dirname() {
    string t="C:\\";
    for (int i = 0; i < currdirnames.size(); ++i) {
        t+=currdirnames[i];
        t+="\\";
    }
    return t;
}

void filesys::go() {
    while (1) {
        splitcmd(cmd());
    }
}
void filesys::splitcmd(string cmd) {
    vector<string> t;
    string temp="";
    for (int i = 0; i < cmd.length(); ++i) {
        if(i==cmd.length()-1){
            temp+=cmd[i];
            t.push_back(temp);
            temp="";
            break;
        }
        if(cmd[i]==' '){
            t.push_back(temp);
            temp="";
        }
        else {
            temp+=cmd[i];
        }
    }
    string command = t[0];
    if (t.size()==2&&t[1]=="?") {
        help(command);
    }
    else if(command=="help") {
        help("all");
    }
    else if(command=="ls") {
        ls();
    }
    else if(command=="exit") {
        exit();
    }
}




void filesys::help(string cmd) {
    if(cmd=="all") {
        cout << "exit 退出" << endl;
        cout << "ls 显示文件目录" << endl;
        cout << "cd [path] 改变当前目录" << endl;
        cout << "mkdir [name] 创建子目录：name" << endl;
        cout << "rm -rf/-f [name] 删除文件或文件夹：name" << endl;
        cout << "mv [old] [new] 将名为old的文件重命名为new" << endl;
        cout << "cp [path1] [path2] 将path1文件或文件夹拷贝到path2下" << endl;
        cout << "create [name] 在当前文件夹下创建name文件并输入内容" << endl;
    }
    if (cmd=="ls") {
        cout << "ls 显示文件目录" << endl;
    }
    if (cmd=="exit") {
        cout << "exit 退出" << endl;
    }
}
void filesys::ls() {

}
void filesys::exit() {

}