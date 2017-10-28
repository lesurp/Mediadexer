#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <QObject>
#include <QString>

enum NodeType {
  CategoryPlaceholder,
  Category,
  Operator,
};

class SearchNode : public QObject {
  Q_OBJECT
public:
  enum Operator {
    Add,
    Or,
    OpenParen,
    CloseParen,
    Equal,
    Different,
    Placeholder,
  };
  Q_ENUM(Operator)

  explicit SearchNode(QObject *parent = nullptr);
  explicit SearchNode(Operator const, QObject *parent = nullptr);
  explicit SearchNode(qint32 const, QString const &, QObject *parent = nullptr);
  QString getDisplayedString() const;
  QString getQueryString() const;

private:
  NodeType nodeType;
  QString displayedString;
  QString queryString;
};

Q_DECLARE_METATYPE(SearchNode::Operator)

#endif // SEARCHNODE_H
