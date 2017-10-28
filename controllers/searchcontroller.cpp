#include "searchcontroller.h"
#include <QDebug>
#include <QTextStream>

SearchController::SearchController(std::shared_ptr<Model> model,
                                   QObject *parent)
    : QObject(parent), model(model) {}

void SearchController::onCategoryClicked(qint32 const categoryId,
                                         QString const categoryName) {
  m_nodesList.append(new SearchNode(categoryId, categoryName));
  emit searchQueryChanged();
}

void SearchController::onFormatterClicked(int const op) {
  m_nodesList.append(new SearchNode(static_cast<SearchNode::Operator>(op)));
  emit searchQueryChanged();
}

QString SearchController::searchQuery() {
  QString searchQuery;
  for (auto const &node : m_nodesList)
    searchQuery += node->getQueryString();

  return searchQuery;
}
