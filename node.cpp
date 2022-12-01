//
// Created by NY on 11/29/22.
//

#include "node.h"

Node::Node(string state, Node* parent, double path_cost) {
    this->state = state;
    this->parent = parent;
    this->pathCost = path_cost;
}

// overloaded constructor
Node::Node(string state) {
    this->state = state;
    this->parent = nullptr;
    this->pathCost = 0.0;
}

Node::Node () {
    this->parent = nullptr;
}

string Node::getState() const {
    return state;
}

Node* Node::getParent() {
    return parent;
}

double Node::getPathCost() const {
    return pathCost;
}

string Node::toString() {
    string node;
    if (this->parent != nullptr) {
        node = "Node {";
        node += "state=" + state;
        node += ", parent=" + parent->getState();
        node += ", path_cost=" + to_string(pathCost) + "}";
    } else {
        node = "Node { state=" + state + "}";
    }

    return node;
}

bool Node::operator== (const Node &other) const {
    return this->getState() == other.getState();
}


Path Node::path() {
    cout << "path called" << endl;
    vector<string> actions;
    double finalPathCost = this->getPathCost();

    actions.insert(actions.begin(), this->getState());
    Node *node = this->getParent();

    while (node != nullptr) {
        cout << node->getState() << endl;
        actions.insert(actions.begin(), node->getState());
        node = node->getParent();
    }

    cout << "done with path";
    return {actions, finalPathCost};
}
