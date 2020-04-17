#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphEdge::GraphEdge(int id) { _id = id; }

void GraphEdge::SetChildNode(GraphNode *childNode) { _childNode = childNode; }

void GraphEdge::SetParentNode(GraphNode *parentNode) {
  _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token) { _keywords.push_back(token); }

GraphEdge::GraphEdge(GraphEdge &&source) noexcept {
  std::cout << "GraphEdge Move Constructor" << std::endl;

  _childNode = source._childNode;
  _parentNode = source._parentNode;
  _id = source._id;
  _keywords = std::move(source._keywords);

  source._childNode = nullptr;
  source._parentNode = nullptr;
  source._id = 0;
}
