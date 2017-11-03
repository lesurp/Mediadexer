#include "tabmanager.h"
#include "entities/searchnode.h"
#include <QDebug>
#include <QQmlApplicationEngine>

enum TabIndexes {
  SEARCH = 0,
  BROWSE = 1,
  CATEGORIES = 2,
};

TabManager::TabManager(QObject *tabView, CategoryController *categoryController,
                       SearchController *searchController, QObject *parent)
    : QObject(parent), tabView(tabView), categoryController(categoryController),
      searchController(searchController) {
  onTabChanged(0);
}

void TabManager::onTabChanged(int tabIndex) {
  switch (tabIndex) {
  case SEARCH: {
    auto searchTab = tabView->findChild<QObject *>("searchTab");
    QObject::connect(searchTab, SIGNAL(categoryClicked(qint32, QString)),
                     searchController,
                     SLOT(onCategoryClicked(qint32, QString)));
    QObject::connect(searchTab, SIGNAL(formatterClicked(int)), searchController,
                     SLOT(onFormatterClicked(int)));
  } break;
  case CATEGORIES: {
    auto categoryTab = tabView->findChild<QObject *>("categoryTab");
    QObject::connect(categoryTab, SIGNAL(addCategory(QString)),
                     categoryController, SLOT(onAddCategory(QString)));
    QObject::connect(categoryTab, SIGNAL(updateCategory(qint32, QString)),
                     categoryController,
                     SLOT(onUpdateCategory(qint32, QString)));
    QObject::connect(categoryTab, SIGNAL(deleteCategory(qint32)),
                     categoryController, SLOT(onDeleteCategory(qint32)));
    break;
  }
  }
}
