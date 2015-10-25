#include "skill.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QVariant>

Skill::Skill() {}

Skill::Skill(QJsonObject json){
    m_name = json.value("name").toString();
    m_accuracy = json.value("accuracy").toInt();
    m_type = static_cast<Type>(json.value("type").toInt());
    m_power = json.value("power").toInt();
}

QString Skill::toJson(){
    QJsonObject json;
    json.insert("name",QVariant(m_name).toString());
    json.insert("power",QVariant(m_power).toInt());
    json.insert("accuracy",QVariant(m_accuracy).toInt());
    json.insert("type",m_type);
    //    if(json.value("type") == m_type)
    //        qDebug() << Q_FUNC_INFO << "enum: ok";
    return QJsonDocument(json).toJson();
}

QString Skill::name() const {
    return m_name;
}

void Skill::setName(const QString &name) {
    m_name = name;
    emit nameChanged(name);
}

int Skill::accuracy() const {
    return m_accuracy;
}

void Skill::setAccuracy(int accuracy) {
    m_accuracy = accuracy;
    emit accuracyChanged(accuracy);
}

int Skill::power() const {
    return m_power;
}

void Skill::setPower(int power) {
    m_power = power;
    emit powerChanged(power);
}

Type Skill::type() const {
    return m_type;
}

void Skill::setType(const Type &type) {
    m_type = type;
    emit typeChanged(type);
}

