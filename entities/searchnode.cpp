#include "searchnode.h"
#include "model/model.h"

QString const CATEGORY_PLACEHOLDER = Model::categoryPlaceholder();

SearchNode::SearchNode(QObject *parent) : QObject(parent) {}

SearchNode::SearchNode(NodeType const nodeType, QObject *parent)
    : QObject(parent), nodeType(nodeType) {
  switch (nodeType) {
  case NodeType::Plus:
    displayedString = " <font color='#c05050'><b>+</b></font> ";
    break;
  case NodeType::Minus:
    displayedString = " <font color='#c05050'><b>-</b></font> ";
    break;
  case NodeType::And:
    displayedString = " <font color='#c05050'><b>AND</b></font> ";
    break;
  case NodeType::Or:
    displayedString = " <font color='#c05050'><b>OR</b></font> ";
    break;
  case NodeType::OpenParen:
    displayedString = "<font color='#f0eaea'>(</font>";
    break;
  case NodeType::CloseParen:
    displayedString = "<font color='#f0eaea'>)</font>";
    break;
  case NodeType::Equal:
    displayedString = " <font color='#f0eaea'>=</font> ";
    break;
  case NodeType::Different:
    displayedString = " <font color='#f0eaea'>≠</font> ";
    break;
  case NodeType::Category:
    throw "Wrong constructor for SearchNode - got Category without the said "
          "category";
    break;
  }
}

SearchNode::SearchNode(qint32 const id, QString const &name, QObject *parent)
    : QObject(parent), nodeType(NodeType::Category),
      displayedString(" " + name + " "), categoryId(id) {}

QString SearchNode::getDisplayedString() const { return displayedString; }
