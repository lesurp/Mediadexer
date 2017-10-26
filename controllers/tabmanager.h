#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QObject>

#include "controllers/category_controller.h"
#include "controllers/searchcontroller.h"

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
  SearchController *searchController;
};

#endif // TABMANAGER_H
