#include "categorycontroller.h"
#include "entities/category.h"

#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>

CategoryController::CategoryController(std::shared_ptr<Model> model,
                                       QObject *parent)
    : QObject(parent), model(model) {
  auto categories = model->categories();
  m_categories = QVariant::fromValue(categories);
}

void CategoryController::onAddCategory(const QString &category_name) {
  if (category_name.isEmpty())
    return;

  model->addCategory(category_name);
  m_categories = QVariant::fromValue(model->categories());
  emit categoriesChanged();
}

void CategoryController::onUpdateCategory(qint32 categoryId,
                                          QString const &categoryName) {
  if (categoryName.isEmpty())
    return;

  model->updateCategory(categoryId, categoryName);
  m_categories = QVariant::fromValue(model->categories());
  emit categoriesChanged();
}

void CategoryController::onDeleteCategory(qint32 categoryId) {
  model->deleteCategory(categoryId);
  m_categories = QVariant::fromValue(model->categories());
  emit categoriesChanged();
}
