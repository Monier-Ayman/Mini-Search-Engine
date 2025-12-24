#ifndef DOCNODE_H
#define DOCNODE_H

#include <string>

class DocNode {
public:
    std::string docName;
    int frequency;
    DocNode* next;

    DocNode(const std::string &name) {
        docName= name;
        frequency= 1;
        next= nullptr;
    }
};

#endif
