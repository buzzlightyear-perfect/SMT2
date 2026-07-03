#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Tree.h"

int main(){
    Tree T;
    T.root = nullptr;

    string File = "materi-strukdat/tree/family.txt";
    loadFile(T.root, File);
    printTree(T.root, 0);
    getchar();
    getchar();
};

123