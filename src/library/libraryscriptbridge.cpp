#include "library/libraryscriptbridge.h"

#include "moc_libraryscriptbridge.cpp"

LibraryScriptBridge::LibraryScriptBridge()
    : QObject(nullptr) {
}

LibraryScriptBridge& LibraryScriptBridge::instance() {
    static LibraryScriptBridge s;
    return s;
}

void LibraryScriptBridge::setSearchQuery(const QString& query) {
    {
        QMutexLocker lock(&m_mutex);
        m_searchQuery = query;
    }
    emit searchQueryChanged(query);
}

QString LibraryScriptBridge::searchQuery() const {
    QMutexLocker lock(&m_mutex);
    return m_searchQuery;
}
