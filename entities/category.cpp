#include "category.h"

Category::Category(QObject *parent) : QObject(parent) {}

Category::Category(qint32 id, QString const &name, QObject *parent)
    : QObject(parent), m_id(id), m_name(name) {}
