#include "datacreate.h"

DataCreate::DataCreate() {

}

void DataCreate::buildMonster(){
    for (int var = 0; var < 99; ++var) {
        data.newMonster(QString(var),random(),random(),random(),random(),random(),random());
    }
    data.saveMonster();
}

int DataCreate::random(int a, int b){
    return rand()%b + a;
}

