#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include <QObject>
#include <QVariant>

#include "entities/category.h"
#include "model/model.h"

class CategoryController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariant categories MEMBER m_categories NOTIFY categoriesChanged)
public:
  explicit CategoryController(QObject *parent = nullptr);

signals:
  void categoriesChanged();

public slots:
  void addCategory(QString const &);
  void updateCategory(qint32, QString const &);
  void deleteCategory(qint32);

private:
  QVariant m_categories;
  Model model;
};

#endif // SEARCHCONTROLLER_H
