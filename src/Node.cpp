#include "Node.h"

/**
 * Constructor of class Node
 * @param node_id
 * @param p_degree
 * @param p_radian
 * @param hotel
 */
Node:: Node(int node_id, Point p_degree, Point p_radian, string hotel) : node_id(node_id), p_degree(p_degree), p_radian(p_radian), hotel(hotel), num_cli(0){}

/**
 * Returns the Point in degrees
 */
Point Node:: getPointDegree() const{return p_degree;}
/**
 * Modifies the Point in degrees
 * @param p_degree new p_degree
 */
void Node:: setPointDegree(Point p_degree){this->p_degree = p_degree;}

/**
 * Returns the Point in radians
 */
Point Node:: getPointRadian() const{return p_radian;}
/**
 * Modifies the Point in radians
 * @param p_radian new p_radian
 */
void Node:: setPointRadian(Point p_radian){this->p_radian = p_radian;}

/**
 * Returns the node id
 */
int Node:: getNodeId() const {return node_id;}
/**
 * Modifies the node id
 * @param nodeId new node_id
 */
void Node:: setNodeId(int nodeId){this->node_id = nodeId;}

/**
 * Returns the hotel name
 */
string Node:: getHotelName() const {return this->hotel;}
/**
 * Modifies the hotel name
 * @param new hotel name
 */
void Node:: setHotelName(string hotel) {this->hotel = hotel;}
