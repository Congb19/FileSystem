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
        cout << "exit �˳�" << endl;
        cout << "ls ��ʾ�ļ�Ŀ¼" << endl;
        cout << "cd [path] �ı䵱ǰĿ¼" << endl;
        cout << "mkdir [name] ������Ŀ¼��name" << endl;
        cout << "rm -rf/-f [name] ɾ���ļ����ļ��У�name" << endl;
        cout << "mv [old] [new] ����Ϊold���ļ�������Ϊnew" << endl;
        cout << "cp [path1] [path2] ��path1�ļ����ļ��п�����path2��" << endl;
        cout << "create [name] �ڵ�ǰ�ļ����´���name�ļ�����������" << endl;
    }
    if (cmd=="ls") {
        cout << "ls ��ʾ�ļ�Ŀ¼" << endl;
    }
    if (cmd=="exit") {
        cout << "exit �˳�" << endl;
    }
}
void filesys::ls() {

}
void filesys::exit() {

}