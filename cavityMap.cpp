//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>

// problem : https://www.hackerrank.com/challenges/cavity-map
// soultion ==============================================================
std::vector<std::string> cavityMap(std::vector<std::string>& grid) {
    std::vector<std::string> x;

    //convert
    std::vector<std::vector<int>> ints;

    for (int x = 0; x < grid.size(); x += 1) {
        std::vector<int> temp;
        for (int c = 0; c < grid.at(x).size(); c += 1) {
            temp.push_back(grid.at(x).at(c) - 48);
        }
        ints.push_back(temp);
    }

    // processing 
    std::vector<std::string> str;
    for (int x = 0; x < ints.size(); x += 1) {

        std::string temp;

        if (x == 0 || x == (ints.size() - 1)) {
            for (int y = 0; y < ints.at(x).size(); y += 1) {
                temp += std::to_string(ints.at(x).at(y));
            }
        }
        else {
            for (int y = 0; y < ints.at(x).size(); y += 1) {

                if (y == 0) {
                    temp += std::to_string(ints.at(x).at(0));
                    continue;
                }
                if (y == (ints.at(x).size() - 1)) {
                    temp += std::to_string(ints.at(x).at(y));
                    continue;
                }

                if (ints.at(x).at(y) > (ints.at(x).at(y - 1)) &&
                    ints.at(x).at(y) > (ints.at(x).at(y + 1)) &&
                    ints.at(x).at(y) > (ints.at(x - 1).at(y)) &&
                    ints.at(x).at(y) > (ints.at(x + 1).at(y))) {
                    temp += 'X';
                    continue;
                }
                else {
                    temp += std::to_string(ints.at(x).at(y));
                }
            }
        }

        str.push_back(temp);
    }

    return str;
}
//======================================================


/*
int main() {

    //just for simple test 
    std::vector<std::string> grid;
    std::vector<std::string> a;

    grid.push_back("884179362992919143428887745218617594484248579735335683155622684818584863837361995843138587668725");
    grid.push_back("877935637998356834563953298823581234638468352948583671742984367929193951737839286593316118548915");
    grid.push_back("958485147934716746152527692875528343974751298294723783494844152444653553259494475842956576368312");
    grid.push_back("467933229391924864792567672734265974159213732287177953334569595897365642686149363878875226922937");
    //grid.push_back("898852889214169242346746379713679739929563439387279442432273774833964226588914794693189322331119");

    a.push_back("884179362992919143428887745218617594484248579735335683155622684818584863837361995843138587668725");
    a.push_back("877X35X37998356X345X3X532988235X123463X468352X4X5X3671X42X84367X2X1X3X51737X3X2865X331611X548X15");
    a.push_back("95X4X514793471674X15252769287552X343X74X512X82X4X237X34X4844152444X5355325X4X4475842X565X6368312");
    a.push_back("467X332293X1X24X647X2567672734265X74159213X32287177X5333456X5X58X7365X4268614X363878875226X22X37");
    //a.push_back("8X885288921416X242346X4637X71367X7399295X343X38727X442X322X377483396422X588X147946X318X322331119");

    std::vector<std::string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i += 1) {
        std::cout << "result ========================" << std::endl;
        std::cout << result.at(i) << std::endl;
        std::cout << "answer ========================" << std::endl;
        std::cout << a.at(i) << std::endl;
        std::cout << std::endl;
        if (result.at(i) == a.at(i)) {
            std::cout << "      TRUE" << std::endl;
        }
        else {
            std::cout << "      FALSE" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "==============================="<< std::endl;
        std::cout << a.at(i) << std::endl;
    }

    return 0;
}
*/
