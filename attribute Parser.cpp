/*
<name>   <(\\w{1,})
</name>  (<\\/\\s{0,}?\\w{1,}\\>)
=values  [\\'|\"](\\w{1,})[\\'|\"]
attr=    (\\w{1,})\\s{0,}?=
<(\\w{ 1, }) | (\\w{ 1, })\\s{ 0, } ? = | [\\'|\"](\\w{1,})[\\' | \"]|(<\\/\\s{0,}?\\w{1,}\\>)
*/

/*
 parser code
 try {
        std::regex re("<(\\w{1,})|(\\w{1,})\\s{0,}?=|[\\'|\"](\\w{1,})[\\'|\"]|(<\\/\\s{0,}?\\w{1,}\\>)");

        std::sregex_iterator next(subject.begin(), subject.end(), re);
        std::sregex_iterator end;

        std::smatch match;
        while (next != end) {
            match = *next;
            std::cout << match.str(1) << "\n";
            next++;
        }

        std::cout << match.size() << "\n";
        std::cout << match.length() << "\n";

    }
    catch (std::regex_error& e) {
        // Syntax error in the regular expression
    }
*/

/*
class elements {
public:
     elements(std::string srcCode):sourceCode(srcCode){
         if (sourceCode.find("</")) isParent = false;
         // processe & get all attrs
     }
    ~elements(){}
    std::string name;
    std::string sourceCode;
    std::vector<std::string> attrs;
    std::vector<elements *> childs;
    int q;
    bool isParent = false;

    bool isThereAttr(std::string attr) {


    }

    std::string isThereChild() {
        if (!isParent) return "Not Found!";
    }
};

class HRMLELEMENT {
    protected:
        std::vector<elements> sources;
        std::vector<std::string> queries;
        int q;
    public:
        HRMLELEMENT(){ }

        void setSource(std::string HRMLsrc){
            elements temp(HRMLsrc); sources.push_back(temp);
            return;
        };

        void setQuery(std::string Query) {
            queries.push_back(Query);
            return;
        };

        void printSources() {
            q = 0;
            while (q < sources.size()) {
                std::cout <<"Source " << q << " : " << sources.at(q) << std::endl;
                q += 1;
            }

            return;
        };

        void printQueries() {
            q = 0;
            while (q < queries.size()) {
                std::cout <<"Query " << q <<" : "<< queries.at(q) << std::endl;
                q += 1;
            }

            return;
        }

        ~HRMLELEMENT(){ }
};
*/

/*
  HRMLELEMENT HRML;
  int N, Q , i = 0;
  std::cin >> N >> Q;

  std::string HRMLstring;
  std::string HRMLqueries;

  // cin new lines of HRML
  while(i <= N) {
      std::getline(std::cin,HRMLstring);
      HRML.setSource(HRMLstring);
      i += 1;
  }
  i = 1;

  HRML.printSources();

  std::cout << "queries time :)" << std::endl;
  // cin all queries
  while (i <= Q) {
      std::getline(std::cin, HRMLqueries);
      HRML.setQuery(HRMLqueries);
      i += 1;
  }

  HRML.printQueries();
  */

  /*
  std::regex reg("<(\\w{1,})");
  std::smatch smatch;

  std::string str = "<tag1 value=\"value\" id='tr' src=\"node\"> </tag1>";

  std::sregex_iterator next(str.begin(), str.end(), reg);
  std::sregex_iterator end;

  while (next != end) {
      smatch = *next;

      std::cout <<"name  : "<< smatch.str(1) << "\n";
      std::cout <<"attr  : " << smatch.str(2) << "\n";
      std::cout <<"value : " << smatch.str(3) << "\n";
      std::cout <<"/end  : " << smatch.str(4) << "\n";

      next++;
  }*/