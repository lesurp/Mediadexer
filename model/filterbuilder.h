#ifndef FILTERBUILDER_H
#define FILTERBUILDER_H

#include "entities/searchnode.h"
#include <QList>
#include <QString>

class FilterBuilder {
public:
  FilterBuilder();
  bool isValidQuery(QList<SearchNode *> const &);
  QString buildQuery(QList<SearchNode *> const &);

  enum States {
    FirstNode,
    PlusMinus,
    ParseGroup,
    GetCategory,
    GetOperator,
    ValidQuery = PlusMinus,
  };

private:
  bool nextState(SearchNode const *);
  State state;
  QString &output;
};

#endif // FILTERBUILDER_H
