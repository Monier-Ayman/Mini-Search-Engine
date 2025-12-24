#ifndef WORDNODE_H
#define WORDNODE_H

#include "DocNode.h"
#include <string>

class WordNode {
public:
    std::string word;
    DocNode* docList;
    WordNode* left;
    WordNode* right;

    WordNode(const std::string &w) {
        word= w;
        docList= nullptr;
        left= right= nullptr;
    }
};

#endif
