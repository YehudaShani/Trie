#pragma once
#include "Node.h"
#include <string>
#include <list>

using namespace std;

class Trie {
private:
	Node* root;
public:
	Trie();
	Node* findEndNode(string word);
	void insert(string word, int location);
	list<int> search(string word);
	void remove(string word);

	~Trie();
};