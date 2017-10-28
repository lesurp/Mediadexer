#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>
#include <memory>
#include <qqmlcontext.h>

#include "controllers/categorycontroller.h"
#include "controllers/searchcontroller.h"
#include "controllers/tabmanager.h"
#include "entities/category.h"
#include "entities/searchnode.h"
#include "model/model.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  auto context = engine.rootContext();

  auto model = std::make_shared<Model>(Model());
  SearchController searchController(model);
  CategoryController categoryController(model);
  context->setContextProperty("CategoryController", &categoryController);
  context->setContextProperty("SearchController", &searchController);

  qmlRegisterType<SearchNode>("mediadexer.searchnode", 1, 0, "SearchNode");
  engine.load(QUrl(QLatin1String("qrc:/views/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  auto tabView = engine.rootObjects().first()->findChild<QObject *>("tab_view");
  TabManager tabManager(tabView, &categoryController, &searchController);

  QObject::connect(tabView, SIGNAL(onCurrentIndexChanged(int)), &tabManager,
                   SLOT(onTabChanged(int)));
  return app.exec();
}
