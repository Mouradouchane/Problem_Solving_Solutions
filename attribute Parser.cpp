#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <regex>


// problem : https://www.hackerrank.com/challenges/attribute-parser/problem
// solution ===============================================================
/*

    // REG namespace contain all regex pattrens we need for match needed values
namespace REG {
    std::regex reg_tagName("<(\\w{1,})"); // match tag name ==> <tagname ...
    std::regex reg_endTagName("<\\/(\\w{1,})\\>"); // match end tag </endtag>
    std::regex reg_values("\\=\\s{0,}?[\"|\\'](\\w{0,}\\.?\\-?\\w{0,}\\!?\\$?\\%?)[\"|\\']"); // match attrbuite values in ....=value
    std::regex reg_attr("(\\w{0,})\\s{0,}?\\="); // match attrbuite attr=...
    std::regex reg_targetElementName("\\.?(\\w+)\\~"); // last element in path will be the target one
    std::regex reg_matchPathInQuery("(.+\\~)"); // used in queries for getting paths tag1.tag2....~
    std::regex reg_matchAttrQuery("\\~(\\w+)"); // used in queries for getting target attrbuit in query ...~queryAttr
};

    // HRML for representing all element in code 
class HRML_ELEMENT {
public:
    // each element have tag name 
    std::string tagName;
    // each element have map of attrbutis for fast access 
    std::map<std::string, std::string> attrs;

    // simpe constructors & destructor 
    HRML_ELEMENT(std::string tagname) :tagName(tagname) {}
    HRML_ELEMENT() {}
    ~HRML_ELEMENT() {}


};

    // method for shrinking path & return new path without attrubite or last element div1.div2~id ==> div1.
std::string shrinkPath(std::string path) {
    std::string newPath = "";

    int p = path.size() - 2;
    while (path[p] != '.') {
        p -= 1;
    }

    for (int i = 0; i <= p; i += 1) {
        newPath += path[i];
    }
    return newPath;
}


int main() {
    int N; std::cin >> N; // get N length of HRML codes 
    int Q; std::cin >> Q; // get Q lenght of Queries

    std::vector<std::string> testCodes;  // vector of strings contain all HRML codes
    std::vector<std::string> textQueries; // vector of strings contain all Queries

    std::vector<std::string> Paths = { "" }; // take all shrinked paths :)

    std::string temp; // temp string for getting values
    // get all HRML CODES
    while (N >= 0) {
        std::getline(std::cin, temp);
        // push HRML CODE
        testCodes.push_back(temp);
        N -= 1;
    }
    temp = "";
     // get all HRML Queries
    while (Q >= 1) {
        std::getline(std::cin, temp);
        // push Query
        textQueries.push_back(temp);
        Q -= 1;
    }

    // map of "HRML ELEMENT NAME" & "HRML ELEMENT" important each HRML ELEMENT have access by his tag name
    std::map<std::string, HRML_ELEMENT> elements; // all elements in map of quick access :)

    // we use this "string match" for matching by using regex 
    // each matched value will be here in match :)
    std::smatch match; 

    // after we take HRML CODES it's time to for processe :)
    // P ==> we need it inside loop for knowing each path we are
    // stillOpen ==> for detecting wich HRML ELEMENT still open & not closed yet 'important for making valid paths'
    int P = 0; std::string stillOpen = "";
    // for in over all HRML CODES
    for (std::string code : testCodes) {
        // temp HRML ELEMENT represent current element
        HRML_ELEMENT temp;

        // if end tag detected;
        if (std::regex_search(code, match, REG::reg_endTagName)) {
            // if current end tag equal to "still open" element we need to make new path for next elements & cleaning stillOpen for new HRML ELEMENT
            if (match.str(1) == stillOpen) {
                stillOpen = ""; // clear for new element
                Paths.push_back(""); // push empty path as new path 
                P += 1; // "increment P for" using "last empty path we push" in Paths vector
            }
            // else in case we detected end tag & not equal to still open element
            // we need to make new path but not empty , must contain old path but shrinked 
            else {
                std::string ShrinkedPath = shrinkPath(Paths[P]); // shrink last one 
                Paths.push_back(ShrinkedPath); // push shrinked path & keep going
                P += 1; // "increment P for" using "last path we push" in Paths vector
            }
        }
        // else mean new element "code"
        else { 
            // get tag name
            if (std::regex_search(code, match, REG::reg_tagName)) {

                temp.tagName = match.str(1);

                // push tag name to current path we have
                Paths[P] += (temp.tagName + ".");

            }
            // in case still open not reserved "temp HRML element" can take it :)
            if (stillOpen == "") stillOpen = temp.tagName;

            // get attrs & values
            std::sregex_iterator itr_attr(code.begin(), code.end(), REG::reg_attr); // get all attrs
            std::sregex_iterator itr_vals(code.begin(), code.end(), REG::reg_values); // get all values
            std::sregex_iterator itr_end; // end for check if we found values & attrs or not

            std::map<std::string, std::string> tempAttrs; // making "temp map" for attrs conatin attrs with values
            while (itr_attr != itr_end && itr_vals != itr_end) {
                // push attr & values to tempAttrs map :)
                tempAttrs.insert({ itr_attr->str(1) , itr_vals->str(1) });
                itr_attr++;
                itr_vals++;
            }
            // last step set hole tempAttrs to current HRML ELEMENT attrs map :)
            temp.attrs = tempAttrs;

            // push element to map of elements for using it later :)
            elements.insert({ temp.tagName , temp });
        }
    }

    // now it's time for processing queries & answering if it found or not found
    // for in over all queries :)
    for (std::string Q : textQueries) {
        bool search = false; // boolean for knowing in end of loop if we found target element & attr or not
        std::string fp = ""; // who take a copy of current path
        std::string attr_value = ""; // who take target attrbuit value if we found it 
        std::string Qpath = ""; // who take valid path in Query without attrs div2.div4...~
        std::string tempPath = ""; // who take a copy of current path "valid copy" without '.' in last

        // when we store "matched Path in Query"
        std::smatch m_match;
        if (std::regex_search(Q, m_match, REG::reg_matchPathInQuery)) {
            Qpath = m_match.str(1); // str will be like this "div.div2."
            Qpath = Qpath.substr(0, Qpath.size() - 1); // we only take it without end point like this "div.div2"
        }

        // know loop over all paths we found & check if path in query is a valid path or not
        for (std::string p : Paths) {
            // to do that make sure you have a "valid path" without '.' in last
            tempPath = p.substr(0, p.size() - 1);

            // if tempPath equal Qpath that mean we found it & query is a valid query
            // next step we need to check if attr in query is valid or not
            if (tempPath == Qpath) {
                // know we need a copy of current path 
                fp = p;

                // we take target name for accessing it in map by his name :)
                std::regex_search(Q, m_match, REG::reg_targetElementName);
                std::string targetElement = m_match.str(1); // HRML ELEMENT NAME 

                // we take target element & we store it in iterator 
                std::map<std::string, HRML_ELEMENT>::iterator target = elements.find(targetElement);
                
                // check if it found then we keep going
                if (target != elements.end()) {
                    // matching target attrbuite in query 
                    std::regex_search(Q, m_match, REG::reg_matchAttrQuery);
                    // storing target attrbuite 
                    std::string attrs = m_match.str(1);

                    // map iterator contain all attrs of target element;
                    std::map<std::string, std::string>::iterator attr = target->second.attrs.find(attrs);

                    // check if attr is found :)
                    if (attr != target->second.attrs.end()) {
                        // if it found make search true & save value in 'attr_value'
                        search = true;
                        attr_value = attr->second;
                    }
                }
                // in case we found what we look for we need to stop :)
                break;
            }
        }

        // in case you found target element & target attrbuite in query
        if (search) {
        // cout to value :)
            std::cout << attr_value << std::endl;
        }
        else {
        // else cout to Not Found :(
            std::cout << "Not Found!" << std::endl;
        }
    }

    // last step 
    return 0;
}
*/
//===============================================================
