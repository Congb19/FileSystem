//
// Created by Congb on 2020/1/5.
//

#ifndef FILESYSTEM_DISK_H
#define FILESYSTEM_DISK_H

#include <iostream>
#include <cmath>
#include <vector>
#include "node.h"

#define DISK_SIZE 1000
#define BLOCK_SIZE 5

using namespace std;

struct block {
    string data;
    int size=BLOCK_SIZE;
    bool used=false;
};

class disk {
public:
    disk();
    ~disk();

    bool set(int start, int len, bool usage);
    bool use(int start, int len);
    bool free(int start, int len);
    int nearfit(int len);
    int bestfit(int len);

    addr write(string data);
    string read(int start, int len);


private:
    vector<block> datas;
    int frees;
};


#endif //FILESYSTEM_DISK_H
