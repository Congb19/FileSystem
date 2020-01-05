//
// Created by Congb on 2020/1/5.
//

#include "disk.h"

disk::disk() {
    block end;
    end.used=true;
    datas.resize(DISK_SIZE+1);
    datas[DISK_SIZE]=end;
    //init
    for (int i = 0; i < DISK_SIZE; ++i) {
        block t;
        datas[i] = t;
    }
}
disk::~disk() {

}

bool disk::set(int start, int len, bool usage) {
    if (start < 0 || start > DISK_SIZE) {
        return false;
    }
    for (int i = start; i < start + len; i++) {
        datas[i].used = usage;
    }
    return true;
}
bool disk::use(int start, int len) {
    bool flag = set(start, len, true);
    return flag;
}
bool disk::free(int start, int len) {
    bool flag = set(start, len, false);
    return flag;
}
addr disk::write(string s) {
    addr res;
    int len=datas.size(), blocks;
    blocks=(int)(len/BLOCK_SIZE);
    res.length=blocks;
    int index=0;
    //
    for (int i = 0; i < blocks; ++i) {
        string t;
        if(len-index>=BLOCK_SIZE) {
            t=s.substr(index, BLOCK_SIZE);
        }
        else {
            t=s.substr(index);
        }
        index+=BLOCK_SIZE;
        datas[i].data=t;
    }
    res.begin=index;
    return res;
}
string disk::read(int start, int len) {
    string res="";
    for (int i = 0; i < start+len; ++i) {
        if(datas[i].used==true) res+=datas[i].data;
    }
    return res;
}