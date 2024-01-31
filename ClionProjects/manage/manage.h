//
// Created by zhu on 2024/1/30.
//

#ifndef CLIONPROJECTS_MANAGE_H
#define CLIONPROJECTS_MANAGE_H

#include "../base_Robot/base_Robot.h"
#include<iostream>
#include<memory>
#include<vector>

struct data {
    int time;
    char cmd;
    int d1;
    int d2;
    int d3;
};

class manage {
public:
    std::vector<std::shared_ptr<base_Robot>> robo;

    void time_count(int time) {
        int gaptime = time - oldtime;
        oldtime = time;
        for (const auto &i: robo) {
            if (i->islife == true && i->kind == 0) {
                if ((i->now_Heat - i->up_Heat) > gaptime) {
                    i->now_Blood -= gaptime;
                } else if ((i->now_Heat - i->up_Heat) > 0) {
                    i->now_Blood -= (i->now_Heat - i->up_Heat);
                }
                i->now_Heat -= gaptime;
                if (i->now_Heat < 1) i->now_Heat = 0;
                if (i->now_Blood < 1) {
                    i->islife = false;
                    std::cout << 'D' << ' ' << i->group_Id << ' ' << i->robot_Id << std::endl;
                }

            }
        }
    }

    void A_func(int id1, int id2, int kind) {
        for (const auto &i: robo)
            if (i->kind == kind && i->group_Id == id1 && i->robot_Id == id2) {
                if (i->islife == false) {
                    i->islife = true;
                    i->now_Heat = 0;
                    i->now_Blood = i->up_Blood;
                    return;
                } else return;
            }

        if (kind == 0) {
            robo.push_back(std::make_shared<infantry>(id1, id2, 0));
        } else robo.push_back(std::make_shared<tech>(id1, id2, 1));

    }

    void F_func(int id1, int id2, int hurt) {
        for (const auto &i: robo) {
            if (i->islife == true && i->group_Id == id1 && i->robot_Id == id2) {
                i->now_Blood -= hurt;
                if (i->now_Blood < 1) {
                    i->islife = false;
                    std::cout << 'D' << ' ' << i->group_Id << ' ' << i->robot_Id << std::endl;
                }
                return;
            }
        }
    }

    void H_func(int id1, int id2, int heat) {
        for (const auto &i: robo) {
            if (i->islife == true && i->group_Id == id1 && i->robot_Id == id2) {
                i->now_Heat += heat;
                return;
            }
        }
    }

    void U_func(int id1, int id2, int grade) {
        for (const auto &i: robo) {
            if (i->islife == true && i->group_Id == id1 && i->robot_Id == id2) {
                if (i->kind == 0) {
                    i->up_grade(grade);
                }
                return;
            }
        }
    }

    int oldtime = 0;

};


#endif //CLIONPROJECTS_MANAGE_H
