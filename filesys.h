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
    void splitcmd(string cmd);

    void help(string cmd);
    void ls();
    void exit();

    void go();

private:
    node *currdir;
    vector<string> currdirnames;
    disk disk;
};


#endif //FILESYSTEM_FILESYS_H
