#pragma once

#include "Node.h"

Node::Node() {
	
	isEndOfSentence = false;
}

Node::Node(bool isEndOfSentence, map<char, Node*> children, Node* father, list<int> locations)
{
	this->isEndOfSentence = isEndOfSentence;
	this->children = children;
	this->father = father;
	this->locations = locations;
}

bool Node::getisEndOfSentence() {
	return isEndOfSentence;
}

void Node::setisEndOfSentence(bool isEndOfSentence) {
	this->isEndOfSentence = isEndOfSentence;
}

map<char, Node*>& Node::getChildren() {
	return children;
}

Node* Node::getChild(char c) {
	if (children.find(c) == children.end()) {
		return nullptr;
	}
	return children[c];
}

void Node::setChild(char c, Node* node) {
	children[c] = node;
}

list<int> Node::getLocations() {
	return locations;
}

void Node::setLocations(list<int> locations) {
	this->locations = locations;
}

void Node::addLocation(int location) {
	locations.push_back(location);
}

Node* Node::getFather() {
	return father;
}

void Node::setFather(Node* father) {
	this->father = father;
}

Node::~Node()
{
	
}

void Node::setChildren(map<char, Node*> children) {
	this->children = children;
}

void Node::deleteAllChildren() {
	for (auto it = children.begin(); it != children.end(); it++) {
		it->second->deleteAllChildren();
	}
	delete this;
}

void Node::findLocations(int& numberOfVisits, list<int>& result)
{
    if (result.size() >= 3) {
        return;
    }
    
    // Increment the number of visits
    numberOfVisits++;
    
    // Visit the children nodes in preorder fashion
    for (auto it = children.begin(); it != children.end(); it++) {
        Node* child = it->second;
        child->findLocations(numberOfVisits, result);
        if (result.size() >= 3) {
            break;
        }
    }
    
    // If the current node is the end of a word, add its locations to the result
    if (isEndOfSentence) {
        for (auto it = locations.begin(); it != locations.end(); it++) {
            result.push_back(*it);
        }
    }
    
    // Remove all results after the first 3
    while (result.size() > 3) {
        result.pop_back();
    }
    
}

