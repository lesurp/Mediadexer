#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include <QList>
#include <QObject>
#include <QVariant>

#include "entities/searchnode.h"
#include "model/model.h"

class SearchController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariant nodes MEMBER m_nodes NOTIFY nodesChanged)
public:
  explicit SearchController(QObject *parent = nullptr);

signals:
  void nodesChanged();

public slots:
  void categoryClicked(qint32 const);
  void formatterClicked(SearchNode::NodeType const);

private:
  QVariant m_nodes;
  QList<QObject *> m_nodesList;
  Model model;
};

#endif // SEARCHCONTROLLER_H
