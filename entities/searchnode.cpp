#include "searchnode.h"
#include "model/model.h"

QString const SearchNode::categoryPlaceholder = Model::categoryPlaceholder();

SearchNode::SearchNode(QObject *parent) : QObject(parent) {}

SearchNode::SearchNode(Operator const op, QObject *parent)
    : QObject(parent), nodeType(NodeType::Operator) {
  switch (op) {
  case Operator::Add:
    displayedString = " <font color='#c05050'><b>AND</b></font> ";
    queryString = " ADD ";
    break;
  case Operator::Or:
    displayedString = " <font color='#c05050'><b>OR</b></font> ";
    queryString = " OR ";
    break;
  case Operator::OpenParen:
    displayedString = "<font color='#f0eaea'>(</font>";
    queryString = "(";
    break;
  case Operator::CloseParen:
    displayedString = "<font color='#f0eaea'>)</font>";
    queryString = ")";
    break;
  case Operator::Equal:
    displayedString = " <font color='#f0eaea'>=</font> ";
    queryString = " = ";
    break;
  case Operator::Different:
    displayedString = " <font color='#f0eaea'>≠</font> ";
    queryString = " != ";
    break;
  case Operator::Placeholder:
    displayedString = " _category_ ";
    nodeType = NodeType::CategoryPlaceholder;
    break;
  }
}

SearchNode::SearchNode(qint32 const id, QString const &name, QObject *parent)
    : QObject(parent), nodeType(NodeType::Category),
      displayedString(" " + name + " "), queryString(QString::number(id)) {}

QString SearchNode::getDisplayedString() const { return displayedString; }
QString SearchNode::getQueryString() const { return queryString; }
