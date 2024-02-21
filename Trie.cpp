#include "Trie.h"
#include <iostream>


Trie::Trie()
{
	root = new Node();
}
void Trie::insert(string word, int location)
{
    Node* current = root;
    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        auto children = current->getChildren();
        if (children.find(ch) == children.end())
        {
			current->setChild(ch, new Node());
        }
        current = current->getChild(ch);
    }

    current->setisEndOfSentence(true);
    current->addLocation(location);
}

list<int> Trie::search(string word)
{
	Node* endNode = findEndNode(word);
	int numberOfNodeVisits = 0;
	list<int> locations;
	if (endNode != nullptr)
	{
		endNode->findLocations(numberOfNodeVisits, locations);
	}
	
	cout << "Number of node visits: " << numberOfNodeVisits << endl;
	return locations;	
}

void Trie::remove(string word)
{
	Node* endNode = findEndNode(word);
	if (endNode != nullptr)
	{
		endNode->setisEndOfSentence(false);
	}
}


Node* Trie::findEndNode(string word)
{
	Node* current = root;
	for (int i = 0; i < word.length(); i++)
	{
		char ch = word[i];
		map<char, Node*> children = current->getChildren();
		if (children.find(ch) == children.end())
		{
			return nullptr;
		}
		current = children[ch];
	}
	return current;
}


Trie::~Trie()
{
	root->deleteAllChildren();
}
