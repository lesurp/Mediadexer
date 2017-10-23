#include "model.h"
#include <QDebug>
#include <QFile>
#include <QList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

QString const CATEGORY_TABLE = "categories";
QString const CATEGORY_ID = "id";
QString const CATEGORY_NAME = "name";
QString const QUERY_CATEGORIES =
    "SELECT " + CATEGORY_ID + "," + CATEGORY_NAME + " FROM " + CATEGORY_TABLE;
QString const ADD_CATEGORY = "INSERT INTO " + CATEGORY_TABLE + "(" +
                             CATEGORY_NAME + ") VALUES(:category_name)";
QString const UPDATE_CATEGORY = "UPDATE " + CATEGORY_TABLE + " SET (" +
                                CATEGORY_NAME + ") = (:category_name) WHERE " +
                                CATEGORY_ID + " == :category_id";
QString const DELETE_CATEGORY = "DELETE FROM " + CATEGORY_TABLE + " WHERE " +
                                CATEGORY_ID + " == :category_id";

Model::Model() {
  m_db = QSqlDatabase::addDatabase("QSQLITE");
  m_db.setDatabaseName("mediadexer.db");
  m_db.open();

  if (m_db.tables().isEmpty()) {
    QFile script(":/mediadexer.sql");
    script.open(QIODevice::ReadOnly);
    QSqlQuery query;
    QStringList scriptQueries = QTextStream(&script).readAll().split(';');

    foreach (QString queryTxt, scriptQueries) {
      if (queryTxt.trimmed().isEmpty()) {
        continue;
      }

      if (!query.exec(queryTxt)) {
        qFatal(QString("One of the query failed to execute."
                       " Error detail: " +
                       query.lastError().text())
                   .toLocal8Bit());
      }
      query.finish();
    }
  }
}

QList<QObject *> Model::categories() {
  QSqlQuery q(QUERY_CATEGORIES);
  QList<QObject *> categories;

  while (q.next()) {
    auto id = q.value(0).toInt();
    auto name = q.value(1).toString();

    categories.append(new Category(id, name));
  }

  return categories;
}

void Model::addCategory(const QString &categoryName) {
  QSqlQuery q;
  q.prepare(ADD_CATEGORY);
  q.bindValue(":category_name", categoryName);
  q.exec();
}

void Model::updateCategory(qint32 categoryId, const QString &categoryName) {
  QSqlQuery q;
  q.prepare(UPDATE_CATEGORY);
  q.bindValue(":category_name", categoryName);
  q.bindValue(":category_id", categoryId);
  q.exec();
}

void Model::deleteCategory(qint32 categoryId) {
  QSqlQuery q;
  q.prepare(DELETE_CATEGORY);
  q.bindValue(":category_id", categoryId);
  q.exec();
}
