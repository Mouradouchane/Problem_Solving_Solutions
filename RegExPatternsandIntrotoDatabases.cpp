
/*
	problem : https://www.hackerrank.com/challenges/30-regex-patterns/problem?h_r=internal-search
	solution ====================================================================================
*/

/*
    // inside loop code ============================================================
    // regex patterns
    std::regex regName("([a-z]{1,20})\\s?");
    std::regex regID("([a-z]{1,50}\\@gmail\\.com)");

    // for matching valid values while searching 
    std::smatch match , matchID;
    std::vector<std::string> matches;

    // x : refer to firstName check & y refer to emailID , "just regex_search enough in this case"
    bool x = std::regex_search(firstName, match , regName);
    bool y = std::regex_search(emailID, matchID, regID);

    // when x & y "true" that's mean valid name & email id 
    if (x && y) {
        matches.push_back(match.str());
       // std::cout << match.str() << std::endl;
    }
    // ===========================================================

    // after we end validation and going out from loop 
    // we must do a normal sort before print 
    sort(matches.begin(), matches.end());
    for(int i = 0 ; i < matches.size() ; i += 1){
        cout << matches.at(i) << endl;
    }

*/