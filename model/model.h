#ifndef MODEL_H
#define MODEL_H

#include "entities/category.h"
#include <QList>
#include <QSqlDatabase>

class Model {
public:
  Model();
  QList<QObject *> categories();
  void addCategory(QString const &);
  void updateCategory(qint32, QString const &);
  void deleteCategory(qint32);

  static QString categoryPlaceholder();

private:
  QSqlDatabase m_db;
};

#endif // MODEL_H
