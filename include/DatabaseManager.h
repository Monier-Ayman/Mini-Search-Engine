#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <sqlite3.h>
#include <iostream>
#include <string>

class DatabaseManager{
private:
    sqlite3* db;

public:
    DatabaseManager(){
        if(sqlite3_open("search_engine.db", &db)){
            std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
            db = nullptr;
        } else {
            createTables();
        }
    }

    ~DatabaseManager(){
        if(db) sqlite3_close(db);
    }

    sqlite3* getDB() { return db; }

private:
    void createTables() {
        const char* createDocuments =
            "CREATE TABLE IF NOT EXISTS documents ("
            "name TEXT PRIMARY KEY);";

        const char* createWordIndex =
            "CREATE TABLE IF NOT EXISTS word_index ("
            "word TEXT COLLATE NOCASE,"   // <-- here is the change
            "doc_name TEXT,"
            "frequency INTEGER,"
            "PRIMARY KEY(word, doc_name));";

        const char* createSearchHistory =
            "CREATE TABLE IF NOT EXISTS search_history ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "query TEXT);";

        char* errMsg = nullptr;
        if(sqlite3_exec(db, createDocuments, 0, 0, &errMsg) != SQLITE_OK){
            std::cerr << "SQL error: " << errMsg << std::endl;
        }    

        if(sqlite3_exec(db, createWordIndex, 0, 0, &errMsg) != SQLITE_OK){
            std::cerr << "SQL error: " << errMsg << std::endl;
        }    

        if(sqlite3_exec(db, createSearchHistory, 0, 0, &errMsg) != SQLITE_OK){
            std::cerr << "SQL error: " << errMsg << std::endl;
        }    
    }
};

#endif
