//
// Created by Congb on 2020/1/5.
//

#ifndef FILESYSTEM_TREE_H
#define FILESYSTEM_TREE_H

#include <iostream>
#include <string>
#include <vector>

#include "node.h"
#include "disk.h"

using namespace std;

class tree {
public:

    tree();
    ~tree();

    node *root;
    int size;

    void insert_here(node *p, info &t);
    void insert_child(node *p, info &t);
    node* find(node *p, info &t);
    void delete_child(node *p);
    void delete_self(node *p);
    void show(node *p, int d);
private:

};


#endif //FILESYSTEM_TREE_H
