#include <iostream>
#include <algorithm>
#include <vector>

// problem  : https://www.hackerrank.com/challenges/messages-order
// solution O(n log n) ======================================================================
using namespace std;
#include <string> // include string header for using string without problems in compaling :)

int textIndex = 1; // text index importing for refernceing & sorting message in receving time

class Message {
private:
    std::string text = ""; // text message
public:
    int index = 0; // index for each message we make   "" refernceing for sorting "" later :)
    
    Message() { // in case construct without parameter
        index = textIndex; // in construction time we set index to current text index 
        textIndex += 1;    // and increment textIndex for next message
    }
    Message(string txt) :text(txt) { // in case construct with text parameter "we do same thing" 
        index = textIndex; // same thing like construct without params
        textIndex += 1;    // same thing like construct without params
    }
    string get_text() { // simple method just return text value
        return text;
    }
    bool operator <(Message& b) { // "important" ==> for sorting Message by using 'index' , that because in Recipient==>fix_order using std::sort
        return (index < b.index); // std::sort cannot sort "Message elements" without implementation for operator
    };
};

class MessageFactory { // factory just for create new messages 
public:
    MessageFactory() {}
    Message create_message(string& text) { // simple method just create new Message object & return it 
        Message temp(text);
        return temp;
    }
};
// ===========================================================================