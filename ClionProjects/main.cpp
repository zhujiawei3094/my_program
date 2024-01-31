#include <iostream>
#include"manage/manage.h"

int main() {
    int n;
    data data;
    std::cin >> n;
    manage ma;
    while (n--) {
        std::cin >> data.time >> data.cmd >> data.d1 >> data.d2 >> data.d3;
        ma.time_count(data.time);
        switch (data.cmd) {
            case 'A':
                ma.A_func(data.d1, data.d2, data.d3);
                break;
            case 'F':
                ma.F_func(data.d1, data.d2, data.d3);
                break;
            case 'H':
                ma.H_func(data.d1, data.d2, data.d3);
                break;
            case 'U':
                ma.U_func(data.d1, data.d2, data.d3);
                break;
        }
    }
    return 0;
}
