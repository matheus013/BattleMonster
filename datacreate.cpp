#include "datacreate.h"
#include <QDebug>

DataCreate::DataCreate() {

}

void DataCreate::buildMonster(){
    for (int var = 0; var < 99; ++var) {
        data.newMonster(QString().setNum(var),random(),random(),random(),random(),random(),random());
    }
    data.saveMonster();
    //qDebug() << "build monster ok";
}

int DataCreate::random(int a, int b){
    return qrand() % ((b + 1) - a) + a;
}

