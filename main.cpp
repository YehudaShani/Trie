#pragma once

#include<map>
#include<list>

#include "Node.h"
#include <cassert>


using namespace std;

void testNodeConstructor() {
    Node node;
    assert(node.getisEndOfSentence() == false);
    assert(node.getChildren().empty());
    assert(node.getFather() == nullptr);
    assert(node.getLocations().empty());
}

void testNodeParameterizedConstructor() {
    map<char, Node*> children;
    Node* father = new Node();
    list<int> locations = { 1, 2, 3 };

    Node node(true, children, father, locations);
    assert(node.getisEndOfSentence() == true);
    assert(node.getChildren() == children);
    assert(node.getFather() == father);
    assert(node.getLocations() == locations);
}

void testNodeGettersAndSetters() {
    Node node;
    node.setisEndOfSentence(true);
    assert(node.getisEndOfSentence() == true);

    map<char, Node*> children;
    Node* child = new Node();
    children['a'] = child;
    node.setChildren(children);
    assert(node.getChildren() == children);

    node.setChild('b', child);
    assert(node.getChild('b') == child);

    list<int> locations = { 1, 2, 3 };
    node.setLocations(locations);
    assert(node.getLocations() == locations);

    Node* father = new Node();
    node.setFather(father);
    assert(node.getFather() == father);
}

void testNodeAddLocation() {
    Node node;
    node.addLocation(1);
    node.addLocation(2);
    node.addLocation(3);
    list<int> locations = { 1, 2, 3 };
    assert(node.getLocations() == locations);
}

int main() {
    testNodeConstructor();
    testNodeParameterizedConstructor();
    testNodeGettersAndSetters();
    testNodeAddLocation();

    return 0;
}