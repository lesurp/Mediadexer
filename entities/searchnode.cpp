#include "searchnode.h"

SearchNode::SearchNode(QObject *parent) : QObject(parent) {}

SearchNode::SearchNode(SearchNode::NodeType const nodeType, QObject *parent)
    : QObject(parent), m_nodeType(nodeType) {}

SearchNode::SearchNode(qint32 const id, QObject *parent)
    : QObject(parent), m_nodeType(SearchNode::NodeType::Category),
      m_categoryId(id) {}

SearchNode::operator QString() const {
  switch (m_nodeType) {
  case SearchNode::NodeType::AddOperator:
    return " ADD ";
  case SearchNode::NodeType::OrOperator:
    return " OR ";
  case SearchNode::NodeType::OpenParenthesis:
    return "(";
  case SearchNode::NodeType::CloseParenthesis:
    return ")";
  case SearchNode::NodeType::Category:
    return QString::number(m_categoryId);
  }
}
