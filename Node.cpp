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

map<char, Node*> Node::getChildren() {
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

void Node::setChildren(map<char, Node*> children) {
	this->children = children;
}

