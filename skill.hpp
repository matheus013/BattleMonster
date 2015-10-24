//#pragma once
//#include <QObject>
//#include "enum.h"

//class Skill : public QObject {
//    Q_OBJECT
//    Q_ENUMS(Type)
//    Q_PROPERTY(int power READ power WRITE setPower NOTIFY powerChanged)
//    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
//    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
//    Q_PROPERTY(int accuracy READ accuracy WRITE setAccuracy NOTIFY accuracyChanged)
//public:
//    Skill();
//    Skill(QJsonObject json);
//    QString toJson();

//    QString name() const;
//    void setName(const QString &name);

//    int accuracy() const;
//    void setAccuracy(int accuracy);

//    int power() const;
//    void setPower(int power);

//    Type type() const;
//    void setType(const Type &type);

//signals:
//    void powerChanged(int);
//    void accuracyChanged(int);
//    void typeChanged(Type);
//    void nameChanged(QString);
//private:
//    QString m_name;
//    int m_accuracy;
//    int m_power;
//    Type m_type;
//};
