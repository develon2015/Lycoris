/*
    Copyright (c) 2018, RootHarold
    All rights reserved.

    Use of this source code is governed by an Apache license that can be found
    in the LICENSE file.
*/

#include "node.h"

Node::Node(uint32_t nodeNum, uint32_t nodeType) {
    this->nodeNum = nodeNum;
    this->nodeType = nodeType;
    value = 0;
    genomeMap = new std::map<Gen, Ome>();
}

Node::~Node() {
    delete genomeMap;
}

Node *Node::clone() {
    auto duplicate = new Node(nodeNum, nodeType);
    duplicate->bias = bias;

    for (auto iter = genomeMap->begin(); iter != genomeMap->end(); ++iter) {
        duplicate->genomeMap->insert(std::make_pair(iter->first, iter->second));
    }

    return duplicate;
}

void Node::initializeBias(float f) {
    this->bias = f;
}
