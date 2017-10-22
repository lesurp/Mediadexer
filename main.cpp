#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>
#include <qqmlcontext.h>

#include "controllers/category_controller.h"
#include "entities/category.h"
#include "model/model.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  qmlRegisterType<Category>("mediadexer.category", 1, 0, "Category");

  CategoryController categoryController;

  auto context = engine.rootContext();
  context->setContextProperty("CategoryController", &categoryController);

  engine.load(QUrl(QLatin1String("qrc:/views/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
