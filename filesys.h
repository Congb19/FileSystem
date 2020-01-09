//
// Created by Congb on 2020/1/5.
//

#ifndef FILESYSTEM_FILESYS_H
#define FILESYSTEM_FILESYS_H

#include <iostream>
#include <string>
#include <vector>
#include "disk.h"
#include "node.h"
#include "tree.h"

using namespace std;

class filesys {
public:

    tree file;

    filesys();
    ~filesys();

    string cmd();
    string dirname();
    node* finddir(string path);
    node* copy(node *origin, node *oripa);
    node* copychildren(node *origin, node *oripa);
    void splitcmd(string cmd);
    void help(string cmd);
    void exit();
    void ls();
    bool cd(string path);
    void mkdir(string name);
    void rm(string name);
    void mv(string old1, string new1);
    void cp(string path1, string path2);
    void create(string name, string data);

    void go();

    disk disk1;
private:
    node *currdir;
    vector<string> currdirnames;
};


#endif //FILESYSTEM_FILESYS_H
