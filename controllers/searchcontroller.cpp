#include "searchcontroller.h"

SearchController::SearchController(QObject *parent) : QObject(parent) {}

void SearchController::categoryClicked(qint32 const categoryId) {
  m_nodesList.append(new SearchNode(categoryId));
  m_nodes = QVariant::fromValue(m_nodesList);
  emit nodesChanged();
}

void SearchController::formatterClicked(SearchNode::NodeType const nodeType) {
  m_nodesList.append(new SearchNode(nodeType));
  m_nodes = QVariant::fromValue(m_nodesList);
  emit nodesChanged();
}
