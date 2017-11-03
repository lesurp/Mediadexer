#include "filterbuilder.h"

#include "entities/searchnode.h"

FilterBuilder::FilterBuilder() : {}

bool FilterBuilder::isValidQuery(const QList<SearchNode *> &nodes,
                                 QString &outputString) {
  state = States::FirstNode;
  output = outputString;
  SearchNode *previousNode = nullptr;
  SearchNode *currentNode;
  // SearchNode::NodeType expectedNextNode
  int bracketCount = 0;

  for (SearchNode const *node : nodes) {
    if (!nextState(node))
      return false;
  }

  if (sate != States::ValidQuery) {
    output = "Your query is invalid. Please check your syntax";
    return false;
  }

  return true;
}

bool FilterBuilder::nextState(const SearchNode *nextNode) {}
