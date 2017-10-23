#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>
#include <qqmlcontext.h>

#include "controllers/category_controller.h"
#include "controllers/tabmanager.h"
#include "entities/category.h"
#include "model/model.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  auto context = engine.rootContext();

  qmlRegisterType<Category>("mediadexer.Category", 1, 0, "Category");

  CategoryController categoryController;
  context->setContextProperty("CategoryController", &categoryController);

  engine.load(QUrl(QLatin1String("qrc:/views/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  auto tabView = engine.rootObjects().first()->findChild<QObject *>("tab_view");
  TabManager tabManager(tabView, &categoryController);

  QObject::connect(tabView, SIGNAL(onCurrentIndexChanged(int)), &tabManager,
                   SLOT(tabChanged(int)));
  return app.exec();
}
