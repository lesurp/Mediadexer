#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include <QList>
#include <QObject>
#include <QVariant>
#include <memory>

#include "entities/searchnode.h"
#include "model/model.h"

class SearchController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString searchQuery READ searchQuery NOTIFY searchQueryChanged)
public:
  explicit SearchController(std::shared_ptr<Model> model,
                            QObject *parent = nullptr);
  QString searchQuery();

signals:
  void searchQueryChanged();

public slots:
  void onCategoryClicked(qint32 const, QString const);
  void onFormatterClicked(int const);

private:
  QList<SearchNode *> m_nodesList;
  std::shared_ptr<Model> model;
};

#endif // SEARCHCONTROLLER_H
