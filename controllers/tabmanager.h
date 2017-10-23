#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QObject>

#include "controllers/category_controller.h"

class TabManager : public QObject {
  Q_OBJECT
public:
  explicit TabManager(QObject *tabview, CategoryController *categoryController,
                      QObject *parent = nullptr);

signals:

public slots:
  void tabChanged(int);

private:
  QObject *tabView;
  CategoryController *categoryController;
};

#endif // TABMANAGER_H
