#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <regex>

namespace REG {
    std::regex reg_tagName("<(\\w{1,})");
    std::regex reg_endTagName("<\\/(\\w{1,})\\>");
    std::regex reg_values("[\\'|\"](\\w{1,})[\\'|\"]");
    std::regex reg_attr("(\\w{1,})\\s{0,}?=");

    std::regex reg_firstPath("(\\w{0,})\\.");
    std::regex reg_dotPath("\\.(\\w{0,})");
    std::regex reg_attrAsk("~(\\w{0,})");
};

class HRML_ELEMENT {
private:
    std::string sourceCode;
    std::string tagName;

    std::map<std::string, std::string> attrs;
    //std::map<std::string, HRML_ELEMENT*> childs;
    HRML_ELEMENT* child;

public:
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

    void printName() {
        std::cout << "NAME => " << tagName << std::endl;
    }

    void printAttrs() {
        for (auto& atr : attrs) {
            std::cout << "  " << atr.first << " : " << atr.second << std::endl;
        }
    }

    void appendChild(HRML_ELEMENT& childElement) {
        child = &childElement;
    }
};

class line {
public:
    std::vector<std::string> path;
    std::vector<std::string> RequestedAttrs;
    line() {

    }
    ~line() {

    }
};

int main() {

    int Queries = 4 , lines = 3;
    //std::cin >> Queries >> lines;

    std::vector<HRML_ELEMENT> elements;
    HRML_ELEMENT tempElement;
    std::smatch match;

    std::string strs[] = {"<tag1 value = 'HelloWorld'>","<tag2 name = 'Name1'>","</tag2>","</tag1>"};
    // processing whole source code line by line  
    while (Queries >= 1) {
        std::string tempSourceCode = strs[Queries-1]; //std::getline(std::cin, tempSourceCode);

        // check if string a end tag
        if (std::regex_search(tempSourceCode, match, REG::reg_endTagName)) {

        }
        else {
           
            // get tag name
            if (std::regex_search(tempSourceCode, match, REG::reg_tagName)) tempElement.setTagName(match.str(1));

            // get attrs & values
            std::sregex_iterator itr_attr(tempSourceCode.begin(), tempSourceCode.end(), REG::reg_attr);
            std::sregex_iterator itr_vals(tempSourceCode.begin(), tempSourceCode.end(), REG::reg_values);
            std::sregex_iterator itr_end;

            std::map<std::string, std::string> tempAttrs;
            while (itr_attr != itr_end) {
                tempAttrs.insert({ itr_attr->str(1) , itr_vals->str(1) });
                itr_attr++;
                itr_vals++;
            }
            tempElement.setAttrs(tempAttrs);

            // check if there's end tag
            if (std::regex_search(tempSourceCode, match, REG::reg_endTagName)) {
                tempElement.hasEndTage = true;
            }

            // push to vector of HRML element  
            elements.push_back(tempElement);

            //reffering to parent element 
            if (elements.size() > 1) {
                elements.at(Queries - 1).appendChild(elements.at(Queries));
            }
        }

        Queries -= 1;
    }

    std::string linesSearch[] = { "tag1.tag2~name","tag1~name","tag1~value" };

    // processing requestes
    while (lines >= 1) {
        line tempLine;
        std::string tempstr = linesSearch[lines-1];
        //std::getline(std::cin, tempstr);

        // main idea !!! => iterate over line & search depend . or ~
        std::sregex_iterator it(tempstr.begin(),tempstr.end(),REG::reg_dotPath);
        std::sregex_iterator end;

        // get first element in path
        std::regex_search(tempstr, match, REG::reg_firstPath);
        tempLine.path.push_back(match.str(1));

        // get all next elements in path one by one
        while (it != end) {
            tempLine.path.push_back(it->str(1)); 
            it++;
        }

        std::sregex_iterator itattr(tempstr.begin(), tempstr.end(), REG::reg_attrAsk);
        std::sregex_iterator attrend;
        while (itattr != attrend) {
            tempLine.RequestedAttrs.push_back(itattr->str(1));
            itattr++;
        }
        
        std::cout << tempLine.path.size() << " \n " << tempLine.RequestedAttrs.size();

        lines -= 1;
    }



    return 0;
}
