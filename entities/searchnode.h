#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <QObject>
#include <QString>

class SearchNode : public QObject {
  Q_OBJECT
  Q_PROPERTY(qint32 categoryId MEMBER m_categoryId)
  Q_PROPERTY(NodeType nodeType MEMBER m_nodeType)
  Q_ENUMS(NodeType)
public:
  enum NodeType {
    OpenParenthesis,
    CloseParenthesis,
    Category,
    AddOperator,
    OrOperator,
  };

  explicit SearchNode(QObject *parent = nullptr);
  explicit SearchNode(SearchNode::NodeType const, QObject *parent = nullptr);
  explicit SearchNode(qint32 const, QObject *parent = nullptr);
  operator QString() const;

protected:
  NodeType m_nodeType;
  qint32 m_categoryId;
};

#endif // SEARCHNODE_H
