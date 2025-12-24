#include <iostream>
#include "SearchEngine.h"

int main(){
    std::cout<< "=== MINI SEARCH ENGINE ===\n";

    SearchEngine engine;
    engine.buildIndexFromUserInput();

    std::string query;
    while(true){
        std::cout<< "\nEnter word to search (or 'exit' to quit): ";

        std::getline(std::cin, query);
        if(query=="exit"){ 
            break;
        }
            
        engine.searchAndPrint(query);
    }

    return 0;
}

