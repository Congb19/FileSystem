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
    tree tree1;

    cout<<"init"<<endl;
//    addr i = disk1.write("123");
//    disk1.write("000000");
//    addr j = disk1.write("456");
//
    addr i{1,2};
    info info1, info2, info3, info4;
    info1={"file1", 0, i};
//    info4={"file4", 0};

    cout<<"add"<<endl;
    filesys1.file.insert_child(filesys1.file.root, info1);


    filesys1.file.show(filesys1.file.root, 0);

    cout << "Hello, World!" << endl;
    filesys1.go();

    system("pause");
    return 0;
}