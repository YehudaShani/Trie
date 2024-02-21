#pragma once

#include<map>
#include<list>
#include<string>

using namespace std;

class Node {
private:
	bool isEndOfSentence;
	map<char, Node*> children;
	list<int> locations;
	Node* father;

public:
	Node();
	Node(bool isEndOfSentence, map<char, Node*> children, Node* father, list<int> locations);
	bool getisEndOfSentence();
	void setisEndOfSentence(bool isEndOfSentence);
	map<char, Node*>& getChildren();
	void setChildren(map<char, Node*> children);
	Node* getChild(char c);
	void setChild(char c, Node* node);
	list<int> getLocations();
	void setLocations(list<int> locations);
	void addLocation(int location);
	Node* getFather();
	void setFather(Node* father);
	void deleteAllChildren();
	void findLocations(int& numberOfVisits, list<int>& result);



	~Node();
};