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

using namespace std;

class filesys {
public:
    filesys();
private:
    node *currdir;
    vector<string> currdirname;
};


#endif //FILESYSTEM_FILESYS_H
