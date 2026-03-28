#pragma once

#include <QMutex>
#include <QObject>
#include <QString>

class LibraryScriptBridge : public QObject {
    Q_OBJECT
public:
    static LibraryScriptBridge& instance();

    void setSearchQuery(const QString& query);
    QString searchQuery() const;

signals:
    void searchQueryChanged(const QString& query);

private:
    LibraryScriptBridge();
    mutable QMutex m_mutex;
    QString m_searchQuery;
};
