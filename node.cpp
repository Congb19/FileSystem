//
// Created by Congb on 2020/1/5.
//

#include "node.h"

node::node() {

}
node::~node() {

}
node::node(const info &d, node *p, node *c, node *n) {
    data=d;
    parent=p;
    child=c;
    next=n;
}
node::node(const info &d) {
    data=d;
    parent=nullptr;
    child=nullptr;
    next=nullptr;
}