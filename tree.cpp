//
// Created by Congb on 2020/1/5.
//

#include "tree.h"

tree::tree() {
    size=0;
    root = new node;
    root->child=nullptr;
    root->parent=nullptr;
}
tree::~tree() {
    delete_self(root);
}

void tree::insert_here(node *q, info &t) {
    size++;
    node *p=new node(t);
    q->next=p;
    p->parent=q->parent;
}

void tree::insert_child(node *q, info &t) {
    size++;
    node *p=new node(t);
    q->child=p;
    p->parent=q;
}

node* tree::find(node *q, info &t) {
    node *p=q;
    while (p->next!=nullptr && p->next->data.name != t.name) {
        p=p->next;
    }
    return p;
}

void tree::delete_child(node *q) {
    node *p=q->child;
    vector<node*> t;
    while (p!=nullptr) {
        t.push_back(p);
        delete_child(p->child);
        p=p->next;
    }
    while (!t.empty()){
        delete(t.back());
        t.pop_back();
    }
}

void tree::delete_self(node *p) {
    if (p->parent->child==p) {
        p->parent->child=p->next;
    }
    else {
        node *t=find(p->parent->child, p->data);
        t->next=p->next;
    }
    delete_child(p);
    delete(p);
}

void tree::show(node *q, int d) {
    node *p=q->child;
    if (d > 1) return;
    if (p == nullptr) return;
    while (p!= nullptr) {
        if (d != 0) {
            cout << "|";
        }
        for (int i = 0; i < d*2; i++) {
            cout << " ";
        }
//        if (p->next == nullptr) {
//            cout << "+-";
//        }
//        else {
//            cout << "+-";
//        }
        cout << "+-";
        cout << p->data.name << endl;
        show(p, d+1);
        p = p->next;
    }
}