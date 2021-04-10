#include <iostream>
//#include <vector>
#include <map>
#include <string>
#include <regex>

namespace REG {
    std::regex reg_tagName("<(\\w{1,})");
    std::regex reg_endTagName("<\\/(\\w{1,})\\>");
    std::regex reg_values("[\\'|\"](\\w{1,})[\\'|\"]");
    std::regex reg_attr("(\\w{1,})\\s{0,}?=");
    std::regex reg_pathFinder("(\\w+)\\.");
    std::regex reg_targetElementName("\\.?(\\w+)\\~");
};

class HRML_ELEMENT {
public:
    std::string tagName;
    std::map<std::string, std::string> attrs;
    std::map<std::string, HRML_ELEMENT*> children;
    bool hasChilds = false;
    bool hasEndTage = false;

    HRML_ELEMENT(std::string tagname, std::map<std::string, std::string> atrs) :tagName(tagname), attrs(atrs) {}
    HRML_ELEMENT() {}
    ~HRML_ELEMENT() {}

    std::string getTagName() {
        return tagName;
    }
    void setTagName(std::string str) {
        tagName = str;
    }
    void setAttrs(std::map<std::string, std::string> attrsMap) {
        attrs = attrsMap;
    }

};


int main() {
    std::string arrtest[16] = {
    "<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">", "</tag1>",

    "<tag2 v4 = \"v2\" name = \"Tag2\">",
        "<tag3 v1 = \"Hello\" v2 = \"World!\">","</tag3>",
        "<tag4 v1 = \"Hello\" v2 = \"Universe!\">","</tag4>",
    "</tag2>",

    "<tag5>",
        "<tag7 new_val = \"New\">","</tag7>",
    "</tag5>",

    "<tag6>",
        "<tag8 intval = \"34\" floatval = \"9.845\">","</tag8>",
    "</tag6>",
    };

    std::string arrlines[14] = {
        "tag1~v1",
        "tag1~v2",
        "tag1~v3",
        "tag4~v2",
        "tag2.tag4~v1",
        "tag2.tag4~v2",
        "tag2.tag3~v2",
        "tag5.tag7~new_val",
        "tag5~new_val",
        "tag7~new_val",
        "tag6.tag8~intval",
        "tag6.tag8~floatval",
        "tag6.tag8~val",
        "tag8~intval"
    };

    int Queries = sizeof(arrtest) / sizeof(std::string) , lines = sizeof(arrlines) / sizeof(std::string); //std::cin >> Queries >> lines;
    int i = 0;

    std::string full_ElementsPath = "";
    std::map<std::string, HRML_ELEMENT> elements;

    std::smatch match;


    // processing whole source code line by line  
    for (i = 0; i < Queries; i += 1) {
        HRML_ELEMENT tempElement;
        std::string tempSourceCode = arrtest[i]; //std::getline(std::cin, tempSourceCode);

        // check if string a end tag
        if (std::regex_search(tempSourceCode, match, REG::reg_endTagName)) {
            // need to end element tag here when you switch elments vector to map 
            elements[match.str(1)].hasEndTage = true;
        }
        else {

            // get tag name
            if (std::regex_search(tempSourceCode, match, REG::reg_tagName)) {
                tempElement.setTagName(match.str(1));
                full_ElementsPath += match.str(1);
                full_ElementsPath += ".";
            }

            // get attrs & values
            std::sregex_iterator itr_attr(tempSourceCode.begin(), tempSourceCode.end(), REG::reg_attr);
            std::sregex_iterator itr_vals(tempSourceCode.begin(), tempSourceCode.end(), REG::reg_values);
            std::sregex_iterator itr_end;

            std::map<std::string, std::string> tempAttrs;
            while (itr_attr != itr_end && itr_vals != itr_end) {
                tempAttrs.insert({ itr_attr->str(1) , itr_vals->str(1) });
                itr_attr++;
                itr_vals++;
            }
            tempElement.setAttrs(tempAttrs);

            // push to vector of HRML element  
            elements.insert({ tempElement.getTagName() , tempElement });

            // reffering to parent

            for (std::map <std::string, HRML_ELEMENT>::iterator it = elements.begin(); it != elements.end(); it++) {
                if (it->second.hasEndTage == false) {
                    it->second.children.insert({ tempElement.getTagName() , &tempElement });
                    break;
                }
            }

        }
    }




    for (std::map<std::string, HRML_ELEMENT>::iterator element = elements.begin(); element != elements.end(); element++) {
        std::cout << element->first << std::endl;

        for (std::map<std::string, HRML_ELEMENT*>::iterator subelement = element->second.children.begin(); subelement != element->second.children.end(); subelement++) {
            std::cout << "      " << subelement->first << std::endl;
        }
    }




/*
    // processing lines "requestes"
    for (int i = 0; i < lines; i += 1) {
        std::string tempstr = arrlines[i] ; //std::getline(std::cin, tempstr);

        // get path 
        std::string temppath = tempstr.substr(0, tempstr.find("~"));

        // get attrbuit
        std::string tempattr = tempstr.substr(tempstr.find("~") + 1, tempstr.size());

        // check if "temp request path" in compatible with full_ElementsPath
        if (full_ElementsPath.find(temppath) != std::string::npos) {

            // get target element 
            std::string targetElementName;

            //check if "temp path" has .  , that mean there's more than one element
            if (temppath.find(".") != std::string::npos) {
                targetElementName = temppath.substr(temppath.rfind(".") + 1, temppath.size() - 1);
            }
            else { // if not that's mean "temp path" include only one element  ex => tag1~attr
                targetElementName = temppath;
            }

            // now after all that we need to access "target element" in "element map" by it's name
            // and accessing request attrubites map inside "target element" by using "tempattr"

            if (elements[targetElementName].attrs[tempattr] == "") {
                std::cout << "Not Found!" << std::endl;
            }
            else {
                std::cout << elements[targetElementName].attrs[tempattr] << std::endl;
            }

        }
        else { // if not , that mean "temp request path" is an invalid path 
            std::cout << "Not Found!" << std::endl;
        }
    }
    */
    return 0;
}
