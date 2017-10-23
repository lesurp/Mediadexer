#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include "entities/category.h"
#include "model/model.h"
//#include "entities/searchnode.h"
#include <QList>
#include <QObject>

class CategoryController : public QObject {
  // Q_PROPERTY(QList<SearchNode> SearchNodes MEMBER m_searchNodes)
  Q_OBJECT
  Q_PROPERTY(QVariant categories MEMBER m_categories NOTIFY categoriesChanged)
public:
  explicit CategoryController(QObject *parent = nullptr);

signals:
  void categoriesChanged();

public slots:
  void addCategory(const QString &);
  void updateCategory(qint32, QString const &);
  void deleteCategory(qint32);

private:
  // QList<SearchNode> m_searchNodes;
  QVariant m_categories;
  Model model;
};

#endif // SEARCHCONTROLLER_H
