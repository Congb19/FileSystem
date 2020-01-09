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
    else if(command=="cd"&&t.size()>=2) {
        cd(t[1]);
    }
    else if(command=="mkdir"&&t.size()>=2) {
        mkdir(t[1]);
    }
    else if(command=="rm"&&(t[1]=="-f"||t[1]=="-rf")) {
        rm(t[2]);
    }
    else if(command=="mv"&&t.size()>=3) {
        mv(t[1],t[2]);
    }
    else if(command=="cp"&&t.size()>=3) {
        cp(t[1],t[2]);
    }
    else if(command=="create"&&t.size()>=2) {
        string data;
        getline(cin, data);
        create(t[1], data);
    }
    else {
        cout<<"wrong command!"<<endl;
    }
    cout<<"now: "<<currdir->data.name<<endl;
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
    if (cmd=="cd") {
        cout << "cd [path] 改变当前目录" << endl;
    }
    if (cmd=="mkdir") {
        cout << "mkdir [name] 创建子目录：name" << endl;
    }
    if (cmd=="rm") {
        cout << "rm -rf/-f [name] 删除文件或文件夹：name" << endl;
    }
    if (cmd=="mv") {
        cout << "mv [old] [new] 将名为old的文件重命名为new" << endl;
    }
    if (cmd=="cp") {
        cout << "cp [path1] [path2] 将path1文件或文件夹拷贝到path2下" << endl;
    }
    if (cmd=="create") {
        cout << "create [name] 在当前文件夹下创建name文件并输入内容" << endl;
    }
}
void filesys::exit() {
    exit();
}
void filesys::ls() {
    file.show(currdir, 0);
}
bool filesys::cd(string path) {
    vector<string> t;
    string temp="";
    for (int i = 0; i < path.length(); ++i) {
        if(i==path.length()-1){
            temp+=path[i];
            t.push_back(temp);
            temp="";
            break;
        }
        if(path[i]=='/'){
            t.push_back(temp);
            temp="";
        }
        else {
            temp+=path[i];
        }
    }
    for (int j = 0; j < t.size(); ++j) {
        if (t[j]==".."){
            if(currdir->parent!= nullptr) {
                currdir=currdir->parent;
                currdirnames.pop_back();
            }
            else {
                return false;
            }
        }
        else {
            info te;
            te.name=t[j];
            node *p=file.find(currdir->child, te);
            if (currdir->child== nullptr) {
                return false;
            }
            else if(p!=currdir->child) {
                currdir=p;
                currdirnames.push_back(t[j]);
            }
            else if(currdir->child!= nullptr&& currdir->child->data.name==t[j]) {
                currdir=currdir->child;
                currdirnames.push_back(t[j]);
            }
            else{
                return false;
            }
        }
    }
    if(currdir->data.addr.begin!=-1){
        cout<<currdir->data.name<<": "<<disk1.read(currdir->data.addr.begin, currdir->data.addr.length)<<endl;
        currdir=currdir->parent;
        currdirnames.pop_back();
    }
    return true;
}
void filesys::mkdir(string name) {
    info t;
    t.name=name;

    if(currdir->child) {
        if(currdir->child!=file.find(currdir->child, t)) return;
        else if(currdir->child->data.name==name) return;
    }

    if (currdir->child== nullptr){
        file.insert_child(currdir, t);
    }
    else{
        node *p=currdir->child;
        file.insert_here(p, t);
    }
}
void filesys::rm(string name) {
    info t;
    t.name=name;
    node *p=file.find(currdir->child, t);
    if(p!=currdir->child) {
        file.delete_self(p);
    }
    else {
        if (currdir->child->data.name==name) {
            file.delete_self(p);
        }
    }
}
void filesys::mv(string old1, string new1) {
    info t;
    t.name=old1;
    node *p=file.find(currdir->child, t);
    if(p!= currdir->child) {
        p->data.name=new1;
    }
    else{
        if (currdir->child->data.name==old1) {
            currdir->child->data.name=new1;
        }
    }
}
node* filesys::finddir(string path) {
    node *res= nullptr;
    vector<string> t;
    string temp="";
    for (int i = 0; i < path.length(); ++i) {
        if(i==path.length()-1){
            temp+=path[i];
            t.push_back(temp);
            temp="";
            break;
        }
        if(path[i]=='/'){
            t.push_back(temp);
            temp="";
        }
        else {
            temp+=path[i];
        }
    }
    node *te=currdir;
    for (int j = 0; j < t.size(); ++j) {
        if (t[j]==".."){
            if(te->parent!= nullptr) {
                te=te->parent;
            }
            else {
                return res;
            }
        }
        else {
            info tem;
            tem.name=t[j];
            node *p=file.find(te->child, tem);
            if (te->child== nullptr) {
                return res;
            }
            else if(p!=te->child) {
                te=p;
            }
            else if(te->child!= nullptr&& te->child->data.name==t[j]) {
                te=te->child;
            }
            else{
                return res;
            }
        }
    }
    return te;
}
node* filesys::copychildren(node *origin) {
    info t;
    t=origin->data;
    node *res=new node(t);
    res->next=origin->next;
    res->child=origin->child;
    if (res->next != nullptr) {
        cout<<"rootnext, now origin = "<<origin->data.name<<endl;
        res->next=copychildren(origin->next);
    }
    if (res->child!= nullptr) {
        cout<<"rootchild, now origin = "<<origin->data.name<<endl;
        res->child=copychildren(origin->child);
    }
    return res;
}
node* filesys::copy(node *origin) {
    node *res;
    info t;
    t=origin->data;
    res=new node(t);
    res->child=origin->child;
    if (res->child!= nullptr) {
        cout<<"root1"<<endl;
        res->child=copychildren(origin->child);
    }
    return res;
}
void filesys::cp(string path1, string path2){
    node *p1, *p2;
    p1=finddir(path1);
    p2=finddir(path2);

    info t;
    t.name=p1->data.name;
    if(p2->child) {
        if(p2->child!=file.find(p2->child, t)) return;
        else if(currdir->child->data.name==p1->data.name) return;
    }

    node *temp=copy(p1);
    if(p1== nullptr||p2== nullptr) {
        return;
    }
    else {
        if(p2->child== nullptr) {
            file.insert_child(p2, temp);
        }
        else {
            file.insert_here(p2->child, temp);
        }
    }
}
void filesys::create(string name, string data) {
    info t;
    t.name=name;
    if(currdir->child) {
        if(currdir->child!=file.find(currdir->child, t)) return;
        else if(currdir->child->data.name==name) return;
    }
    addr ad=disk1.write(data);
    t.addr=ad;
    if(currdir->child== nullptr) {
        file.insert_child(currdir, t);
    }
    else{
        file.insert_here(currdir->child, t);
    }
}