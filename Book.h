#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "Trie.h"
using namespace std;

class Book {
private:
    string content;
    // TODO: Add a trie attribute
    Trie* trie;
    void processContent();

public:
    Book(const string& filepath);
    string extractSentence(int location);
    void searchAndPrint(const string& query);
    void censorQuery(const string& query);

};
