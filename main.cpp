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
    filesys filesys1;

    filesys1.disk1.write("asdfasfdsfsdaf");
    addr i{1,2};
    info info1={"root"},
        info2={"file2"},
        info3={"file3"},
        info4={"file4"},
        info5={"file5"},
        info6={"file6"},
        info7={"file7"},
        info8={"file8"},
        info9={"file9"},
        info10={"file10"}
    ;

    filesys1.file.insert_child(filesys1.file.root, info1);

    filesys1.file.insert_child(filesys1.file.root->child, info2);
    filesys1.file.insert_here(filesys1.file.root->child->child, info3);
    filesys1.file.insert_here(filesys1.file.root->child->child, info4);
    filesys1.file.insert_here(filesys1.file.root->child->child, info8);

    filesys1.file.insert_child(filesys1.file.root->child->child->next->next, info5);
    filesys1.file.insert_here(filesys1.file.root->child->child->next->next->child, info6);
    filesys1.file.insert_child(filesys1.file.root->child->child->next->next->child->next, info9);
    filesys1.file.insert_here(filesys1.file.root->child->child->next->next->child, info7);



    filesys1.file.show(filesys1.file.root, 0);

//    cout << filesys1.file.root->child->child->next->data.name << endl;

    cout << "Hello, World!" << endl;

    filesys1.go();

    system("pause");
    return 0;
}