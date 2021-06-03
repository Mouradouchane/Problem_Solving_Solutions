#include <iostream>

// problem https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem
// soultion O(1) =========================================================================
/*
template <typename T> struct Traits {
    static std::string name(int index) { // return must be string 
        // using orange in both enums for checking if 'T' is Fruit or Color
        int fg = (int)Fruit::orange; // fg ==> fruit orange
        int cg = (int)Color::orange; // cg ==> color orange

        // casting to int T->orange & check if used Fruit enum :)
        if ((int)T::orange == fg) {
            // a normal switch case over all to get correct index of 'fruit'
            switch (index) {
                case 0: return "apple";
                case 1: return "orange";
                case 2: return "pear";
                default: return "unknown"; // in case not found :)
            }
        }

        // casting to int T->orange & check if used Color enum :)
        if ((int)T::orange == cg) {
            // a normal switch case over all to get correct index of 'color'
            switch (index) {
                case 0: return "red";
                case 1: return "green";
                case 2: return "orange";
                default: return "unknown"; // in case not found :)
            }
        }

        return "unknown"; // in case not found :)
    }
};

// another solution :)
// solution O(1) =========================================================================

#include<vector> // include vector for strick
template <typename T> struct Traits {
    static std::string name(int index) {
        int fg = (int)Fruit::orange; // like first example for checking wich enum :)
        int cg = (int)Color::orange; // like first example for checking wich enum :)
        
        // in this case we make vector take all values for O(1) access
        std::vector<std::string> fruits = { "apple", "orange", "pear" }; 
        std::vector<std::string> color = { "red", "green", "orange" };

        // if fruit enum && index less than length of vector 
        if ((int)T::orange == fg && index < fruits.size()) {
            // just return fruit in index 
            return fruits[index]; // O(1) :)
        }

        // same tricks like previous if 
        if ((int)T::orange == cg && index < color.size()) {
            // just return color in index 
            return color[index]; // O(1) :)
        }

        // if no one we return unknown as last step :)
        return "unknown";
    }
};

*/
// =======================================================================================