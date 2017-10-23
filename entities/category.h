#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QString>
#include <QtGlobal>

class Category : public QObject {
  Q_OBJECT
  Q_PROPERTY(qint32 categoryId MEMBER m_id CONSTANT)
  Q_PROPERTY(QString categoryName MEMBER m_name CONSTANT)
public:
  explicit Category(QObject *parent = nullptr);
  explicit Category(qint32 id, QString const &name, QObject *parent = nullptr);
  QString categoryName() const;
  qint32 categoryId() const;

signals:

public slots:

private:
  qint32 m_id;
  QString m_name;
};

#endif // CATEGORY_H
