#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <QObject>
#include <QString>

class SearchNode : public QObject {
  Q_OBJECT
public:
  enum NodeType {
    Plus,
    Minus,
    And,
    Or,
    OpenParen,
    CloseParen,
    Equal,
    Different,
    Category,
  };
  Q_ENUM(NodeType)

  explicit SearchNode(QObject *parent = nullptr);
  explicit SearchNode(NodeType const, QObject *parent = nullptr);
  explicit SearchNode(qint32 const, QString const &, QObject *parent = nullptr);
  QString getDisplayedString() const;
  QString getQueryString() const;

private:
  NodeType nodeType;
  QString displayedString;
  qint32 categoryId;
};

Q_DECLARE_METATYPE(SearchNode::NodeType)

#endif // SEARCHNODE_H
