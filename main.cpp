//
// Created by Congb on 2020/1/5.
//

#include <iostream>
#include <cmath>
#include <string>

#include "tree.h"
#include "disk.h"
#include "filesys.h"


using namespace std;

int main() {
    disk disk1;
    filesys filesys1;
    tree testtree;

    addr i = disk1.write("123");

    info info,info2, info3, info4, info5, info6, info7;
    info={"file1", 0, i};

    testtree.show(testtree.root, 0);
    cout << "Hello, World!" << endl;
    system("pause");
    return 0;
}