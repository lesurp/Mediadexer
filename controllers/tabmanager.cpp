#include "tabmanager.h"
#include <QDebug>
#include <QQmlApplicationEngine>

enum TabIndexes {
  SEARCH = 0,
  BROWSE = 1,
  CATEGORIES = 2,
};

TabManager::TabManager(QObject *tabView, CategoryController *categoryController,
                       QObject *parent)
    : tabView(tabView), categoryController(categoryController),
      QObject(parent) {}

void TabManager::tabChanged(int tabIndex) {
  switch (tabIndex) {
  case CATEGORIES:
    auto categoryTab = tabView->findChild<QObject *>("categoryTab");
    QObject::connect(categoryTab, SIGNAL(addCategory(QString)),
                     categoryController, SLOT(addCategory(QString)));
    QObject::connect(categoryTab, SIGNAL(updateCategory(qint32, QString)),
                     categoryController, SLOT(updateCategory(qint32, QString)));
    QObject::connect(categoryTab, SIGNAL(deleteCategory(qint32)),
                     categoryController, SLOT(deleteCategory(qint32)));
    break;
  }
}
