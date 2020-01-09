//
// Created by Congb on 2020/1/5.
//

#ifndef FILESYSTEM_NODE_H
#define FILESYSTEM_NODE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct addr {
    int begin=-1;
    int length;
};
struct info {
    string name;
    addr addr;
};

class node {
public:

    node();
    ~node();
    node(const info &data);
    node(const info &data, node *parent, node *child, node *next);

    node *parent;
    node *child;
    node *next;
    info data;

private:

};


#endif //FILESYSTEM_NODE_H
