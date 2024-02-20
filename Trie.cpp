#include "Trie.h"

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
		if (children[ch] == NULL)
		{
			children[ch] = new Node();
		}
		current = children[ch];
	}

	current->setisEndOfSentence(true);
	current->addLocation(location);
}
