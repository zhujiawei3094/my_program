//
// Created by zhu on 2024/1/30.
//

#ifndef CLIONPROJECTS_BASE_ROBOT_H
#define CLIONPROJECTS_BASE_ROBOT_H

#include<iostream>

class base_Robot {
public:
    bool islife;
    int group_Id, robot_Id;
    int kind, grade;
    int up_Blood, now_Blood;
    int up_Heat, now_Heat;

    base_Robot(int id1, int id2, int kind) {
        islife = true;
        group_Id = id1;
        robot_Id = id2;
        grade = 1;
        base_Robot::kind = kind;
        if (kind == 0) {
            up_Blood = 100;
            up_Heat = 100;
        } else {
            up_Blood = 300;
            up_Heat = 0;
        }
        now_Blood = up_Blood;
        now_Heat = 0;
    }

    virtual void up_grade(int newgrade) {
    }
};

class infantry : virtual public base_Robot {
public:
    infantry(int id1, int id2, int kind) : base_Robot(id1, id2, kind) {

    }

    void up_grade(int newgrade) {
        if (newgrade > grade) {
            grade = newgrade;
            if (newgrade == 2) {
                up_Blood = 150;
                up_Heat = 200;
            } else if (newgrade == 3) {
                up_Blood = 250;
                up_Heat = 300;
            }
            now_Blood = up_Blood;
        }
    }

};

class tech : virtual public base_Robot {
public:
    tech(int id1, int id2, int kind) : base_Robot(id1, id2, kind) {

    }

    void up_grade(int newgrade) {
    }
};

#endif //CLIONPROJECTS_BASE_ROBOT_H
