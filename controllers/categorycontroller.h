#ifndef CATEGORYCONTROLLER_H
#define CATEGORYCONTROLLER_H

#include <QObject>
#include <QVariant>
#include <memory>

#include "entities/category.h"
#include "model/model.h"

class CategoryController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariant categories MEMBER m_categories NOTIFY categoriesChanged)
public:
  explicit CategoryController(std::shared_ptr<Model> model,
                              QObject *parent = nullptr);

signals:
  void categoriesChanged();

public slots:
  void onAddCategory(QString const &);
  void onUpdateCategory(qint32, QString const &);
  void onDeleteCategory(qint32);

private:
  QVariant m_categories;
  std::shared_ptr<Model> model;
};

#endif // CATEGORYCONTROLLER_H
