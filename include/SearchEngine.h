#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "WordNode.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

class SearchEngine{
private:
    WordNode* root;

    // ---------------- Tokenize ----------------
    std::vector<std::string> tokenize(const std::string& text){
        std::stringstream ss(text);
        std::string word;
        std::vector<std::string> tokens;

        while(ss >> word){
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
            tokens.push_back(word);
        }

        return tokens;
    }

    // ---------------- Insert Word into BST ----------------
    WordNode* insertWord(WordNode* node, const std::string& word, const std::string& docName) {
        if(!node){
            WordNode* newNode= new WordNode(word);
            newNode->docList= new DocNode(docName);
            return newNode;
        }

        if(word < node->word){
            node->left= insertWord(node->left, word, docName);
        } 
        else if(word > node->word){
            node->right = insertWord(node->right, word, docName);
        } 
        else{
            DocNode* temp= node->docList;
            while(temp){
                if(temp->docName == docName){
                    temp->frequency++;
                    return node;
                }
                if(!temp->next){ 
                    break;
                }    
                temp= temp->next;
            }

            temp->next= new DocNode(docName);
        }

        return node;
    }

    // ---------------- Search Word ----------------
    DocNode* searchWord(WordNode* node, const std::string& word) {
        if(!node){ 
            return nullptr;
        }    
        if(word == node->word){ 
            return node->docList;
        }    
        if(word < node->word){ 
            return searchWord(node->left, word);
        }

        return searchWord(node->right, word);
    }

    // ---------------- Print Documents ----------------
    void printDocList(DocNode* head) {
        if(!head){
            std::cout<< "No documents found.\n";
            return;
        }

        std::vector<std::pair<std::string,int>> results;
        DocNode* temp= head;
        while(temp){
            results.push_back({temp->docName, temp->frequency});
            temp= temp->next;
        }

        std::sort(results.begin(), results.end(), [](auto &a, auto &b){ return a.second > b.second; });
        for(auto &res : results){
            std::cout<< res.first<<" - Frequency: "<< res.second<<std::endl;
        }
    }

public:
    SearchEngine() {
        root= nullptr;
    }

    void buildIndexFromUserInput() {
        int numDocs;
        std::cout<< "Enter number of documents: ";
        std::cin>> numDocs;
        std::cin.ignore();

        std::vector<std::string> documents(numDocs);
        for(int i=0 ; i<numDocs ; i++){
            std::cout<< "\nEnter text for Document "<< i+1<< ":\n";
            std::getline(std::cin, documents[i]);
        }

        for(int i=0 ; i<numDocs ; i++){
            std::vector<std::string> words = tokenize(documents[i]);
            for(auto &word : words){
                root= insertWord(root, word, "Document " + std::to_string(i+1));
            }
        }
    }

    void searchAndPrint(const std::string& query) {
        std::string q= query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        DocNode* result= searchWord(root, q);
        printDocList(result);
    }
};

#endif
