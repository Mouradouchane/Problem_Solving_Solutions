#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<int> convertRowToVectorOfInts(std::string &row){
    std::vector<int> values;
    for (int index = 0; index < row.size(); index += 1) {
        values.push_back((int(row[index]) - 48));
    }

    return values;
}

std::string processRow(std::vector<int> &row){
    std::string str;
    str.append(std::to_string(row.at(0)));

    for (int elem = 1; elem < row.size() - 1; elem += 1) {
        if(elem <= 1){
            if (row.at(elem) > row.at(elem - 1) && row.at(elem) > (row.at(elem + 1) + row.at(elem + 2))) {
                str.append("X");
                continue;
            }
        }
        else if(elem >= row.size() - 1){
            if (row.at(elem) > (row.at(elem - 1) + row.at(elem - 2)) && row.at(elem) > row.at(elem + 1) ) {
                str.append("X");
                continue;
            }
        }
        else {
            if (row.at(elem) > (row.at(elem - 1) + row.at(elem - 2)) && row.at(elem) > (row.at(elem + 1) + row.at(elem + 2))) {
                str.append("X");
            }
            else {
                str.append(std::to_string(row.at(elem)));
            }
        }
    }    
    str.append(std::to_string(row.at(row.size()-1)));

    return str;
}

std::vector<std::string> cavityMap(std::vector<std::string> grid) {
    std::vector<int> intgrid;
    std::vector<std::string> processedGrid;

    for (int row = 0; row < grid.size(); row += 1) {
        intgrid = convertRowToVectorOfInts(grid.at(row));
        processedGrid.push_back(processRow(intgrid));
    }
    return processedGrid;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<std::string> x;
    std::vector<std::string> a;

    x.push_back("884179362992919143428887745218617594484248579735335683155622684818584863837361995843138587668725");
    x.push_back("877935637998356834563953298823581234638468352948583671742984367929193951737839286593316118548915");
    x.push_back("958485147934716746152527692875528343974751298294723783494844152444653553259494475842956576368312");
    x.push_back("467933229391924864792567672734265974159213732287177953334569595897365642686149363878875226922937");
    x.push_back("898852889214169242346746379713679739929563439387279442432273774833964226588914794693189322331119");

    a.push_back("884179362992919143428887745218617594484248579735335683155622684818584863837361995843138587668725");
    a.push_back("877X35X37998356X345X3X532988235X123463X468352X4X5X3671X42X84367X2X1X3X51737X3X2865X331611X548X15");
    a.push_back("95X4X514793471674X15252769287552X343X74X512X82X4X237X34X4844152444X5355325X4X4475842X565X6368312");
    a.push_back("467X332293X1X24X647X2567672734265X74159213X32287177X5333456X5X58X7365X4268614X363878875226X22X37");
    a.push_back("8X885288921416X242346X4637X71367X7399295X343X38727X442X322X377483396422X588X147946X318X322331119");

    std::vector<std::string> r = cavityMap(x);

    int as = 0;
    for (auto i : r) {
        if (i == a.at(as)) {
            std::cout <<"TRUE ANSWER : "<< i << std::endl;
        }
        else {
            std::cout << "= FALSE ANSWER =" << '\n';
            std::cout << i << '\n';
            std::cout << a.at(as) << '\n';
        }
        as += 1;
    }


    return 0;
}
