//
// Created by NY on 11/29/22.
//

#include "node.h"

Node::Node(int state, Node parent, double path_cost) {
    this->state = state;
    this->parent = &parent;
    this->pathCost = path_cost;
}

// overloaded constructor
Node::Node(int state) {
    this->state = state;
    this->parent = nullptr;
    this->pathCost = 0.0;
}

Node::Node (void) {
    this->parent = nullptr;
}

int Node::getState() const {
    return state;
}

Node * Node::getParent() {
    return parent;
}

double Node::getPathCost() const {
    return pathCost;
}

string Node::toString() {
    string node;
    if (this->parent != nullptr) {
        node = "Node {";
        node += "state=" + to_string(state);
        node += ", parent=" + to_string(parent->getState());
        node += ", path_cost=" + to_string(pathCost) + "}";
    } else {
        node = "Node { state=" + to_string(state) + "}";
    }

    return node;
}

bool Node::operator== (Node &other) const {
    return this->state == other.state;
}

//bool Node::equals(Node *n) {
//    if (n == this) return true;
//    if (!(instanceof<Node>(n))) {
//        return false;
//    }
//    Node node = *dynamic_cast<Node>(*n);
//    return this->getState() == node.getState();
//}

//Solution Node::solutionPath() {
//    vector<int> stateSequence;
//    double totalPathCost = this->getPathCost();
//
//    stateSequence.insert(stateSequence.begin(), this->getState());
//    Node *node = this->getParent();
//
//    while (node != nullptr) {
//        stateSequence.insert(stateSequence.begin(), node->getState());
//        node = node->getParent();
//
//    }
//
//    return {stateSequence, totalPathCost};
//}
