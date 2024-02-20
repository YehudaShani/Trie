#pragma once
#include "Node.h"
#include <string>

using namespace std;

class Trie {
private:
	Node* root;
public:
	Trie();
	void insert(string word, int location);
};