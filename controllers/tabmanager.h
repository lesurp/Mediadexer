#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QObject>

#include "controllers/categorycontroller.h"
#include "controllers/searchcontroller.h"

class TabManager : public QObject {
  Q_OBJECT
public:
  explicit TabManager(QObject *tabview, CategoryController *categoryController,
                      SearchController *searchController,
                      QObject *parent = nullptr);

signals:

public slots:
  void onTabChanged(int);

private:
  QObject *tabView;
  CategoryController *categoryController;
  SearchController *searchController;
};

#endif // TABMANAGER_H
