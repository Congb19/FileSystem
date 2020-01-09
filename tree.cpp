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
    p->parent=q->parent;
    while(q->next!=nullptr)
        q=q->next;
    q->next=p;
}

void tree::insert_child(node *q, info &t) {
    size++;
    node *p=new node(t);
    q->child=p;
    p->parent=q;
}

void tree::insert_here(node *q, node *t) {
    t->parent=q->parent;
    while(q->next!=nullptr)
        q=q->next;
    q->next=t;
}

void tree::insert_child(node *q, node *t) {
    q->child=t;
    t->parent=q;
}
node* tree::find(node *q, info &t) {
    node *p=q;
    while (p->next!=nullptr) {
        if(p->data.name!=t.name){
            p=p->next;
        }
        else break;
    }
    if(p->data.name!=t.name) return q;
    return p;
}

void tree::delete_child(node *q) {
    cout<<"del child"<<endl;
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
//    cout<<"del self"<<endl;
//    cout<<"p->parent->data.name: "<<p->parent->data.name<<endl;
//    cout<<"p->parent->child->data.name: "<<p->parent->child->data.name<<endl;
//    cout<<"p->data.name: "<<p->data.name<<endl;
    if (p->parent->child->data.name==p->data.name) {
//        cout<<"i am biggest!"<<endl;
        p->parent->child=p->next;
//        cout<<"now p.next is "<<p->next->data.name<<endl;
//        cout<<"now p->parent->child is "<<p->parent->child->data.name<<endl;
    }
    else {
//        cout<<"i am didi."<<endl;
        node *t=p->parent->child;
        while (t->next->data.name!=p->data.name){
            t=t->next;
        }
        t->next=p->next;
    }
    //delete_child(p);
//    delete(p);
}

void tree::show(node *q, int d) {
    node *p=q->child;
    if (p == nullptr) return;
    while (p!= nullptr) {
//        if (d != 0) {
//            cout << "|";
//        }
        for (int i = 0; i < d*2; i++) {
            cout << " ";
        }
        cout << "+--";
        cout << p->data.name << endl;
//        if(p->child== nullptr) cout << p->data.name << endl;
//        else cout << p->data.name << ", erzi is "<<p->child->data.name<<endl;
        show(p, d+1);
        p = p->next;
    }
}