#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;

WebTopic::WebTopic(string filename) {
    file = filename;
    wordlist = new SLL();
    currpriority = 3;
}

void WebTopic::getPriority(string line) {
    // determine the current priority, based on the tag that starts the line
    //Uses line.compare to compare line to potential header strings 
    //Priority assigned based on header value
    
    if (line.compare("tittle") || line.compare("h1") || line.compare("h2")) {
        currpriority = 1;
        
    } else if (line.compare("h3") || line.compare("h4")
            || line.compare("h5") || line.compare("h6")) {
        currpriority = 2;
        
    } else {
        currpriority = 3;
    }
}

void WebTopic::printPage() {
    //Prints out the list of web page words and their priority. You can
    //look at my output below to see what mine looks like
}

void WebTopic::ReadFile() {
    ifstream infile(file.c_str(), ios::in); // open file
    string line = "";
    char c;
    while (infile.get(c)) {
        if (c == '<') {
            if (!line.empty()) {
                parseString(line);
                line = "";
            }
        } else if (c == '>') {
            getPriority(line);
            line = "";
        } else {
            line += c;
        }
    }
    cout << endl;
    infile.close();
}

string WebTopic::stripSpace(string s) {
    unsigned int i = 0;
    while (i < s.length()) {
        if (!isalpha(s[i])) {
            s.erase(i);
        }
        i++;
    }
    return s;
}

void WebTopic::parseString(string line) {
    //takes the line and breaks it down into words (separated by space), calls
    //stripSpace to get rid of anything not alphanumeric, and then inserts each
    //word into the list along with its priority
}