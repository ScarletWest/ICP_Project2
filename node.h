//
// Created by NY on 11/29/22.
//

#ifndef ICP_PROJECT2_NODE_H
#define ICP_PROJECT2_NODE_H


/**
 * this file defines operations for the Node class
 * operations include constructor and accessor methods,
 * compareTo, equals, and solutionPath methods
 *
 * @author Richard Quayson
 */


#include <iostream>
#include <string>
#include "Path.h"
#include <vector>
using namespace std;



/**
 * the node class extends Comparable to enable the sorting of Node objects
 */
class Node {

private:
    /**
     * instance variables
     */
    string state;
    Node* parent;
    double pathCost;

public:
/**
 * Constructor:
 * Build and initialise the objects of the Node class
 *
 * @param state AirportID
 * @param parent node object of the calling object
 * @param action AirportID
 * @param path_cost distance between the state of the calling Node and this node's state
 */
    Node(string state, Node *parent, double path_cost);

// overloaded constructor
    Node(string state);

    Node ();

/**
 * returns the state of this node object
 * @return this.state
 */
    string getState() const;

/**
 * returns the parent node of this node object
 * @return this.parent
 */
    Node * getParent();
/**
 * returns the path cost of this node object
 * @return this.pathCost
 */
    double getPathCost() const;


/**
 * returns the string representation of a node class
 * @return string representation of the f
 */
    string toString();

/**
 * checks if two node objects are equal
 * returns true if the two nodes have the same state
 * @param o the node to compare calling node object with
 * @return boolean
 */
    bool operator== (Node other) const;


/**
 * returns the Solution of a given node
 * a Solution consists of the state sequence from the
 * initial state to the goal state of a given problem
 * @return Solution
 */
    Path path();

///**
// * returns an int based on whether a node has a greater, equal or lower
// * past cost than the node it is being compared with
// * @param node the node to compare calling node object with
// * @return int (1,-1,0)
// */
//    int compareTo(Node node) {
//        return Double.compare(this.getPathCost(), node.getPathCost());
//    }

    bool equals(Node *n);
};


#endif //ICP_PROJECT2_NODE_H
