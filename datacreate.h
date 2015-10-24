#ifndef DATACREATE_H
#define DATACREATE_H
#include <QObject>

class DataCreate : public QObject {
    Q_OBJECT
public:
    DataCreate();
    void buildMonster();

signals:

};

#endif // DATACREATE_H
