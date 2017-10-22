#include "category_controller.h"
#include "entities/category.h"

#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>

CategoryController::CategoryController(QObject *parent) : QObject(parent) {
  auto categories = model.categories();
  m_categories = QVariant::fromValue(categories);

  QQuickView view;
  QQmlContext *context = view.rootContext();
  context->setContextProperty("categoryModel", m_categories);
}

void CategoryController::addCategory(const QString &category_name) {
  if (category_name.isEmpty())
    return;

  model.addCategory(category_name);
  m_categories = QVariant::fromValue(model.categories());
  emit categoriesChanged();
}
