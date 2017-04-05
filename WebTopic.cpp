#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <sstream>
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

    if (line.compare(0,5,"tittle") || line.compare(0,2,"h1") || line.compare(0,2,"h2")) {
        currpriority = 1;

    } else if (line.compare(0,2,"h3") || line.compare(0,2,"h4")
            || line.compare(0,2,"h5") || line.compare(0,2,"h6")) {
        currpriority = 2;

    } else {
        currpriority = 3;
    }
}

void WebTopic::printPage() {
	for(int i=1;i<4;i++){
		SNode *tmp = wordlist->first;
		cout << "Priority " << i << ":" <<endl;
		while(tmp->next != NULL){
			if(tmp->priority == i){
				tmp->printNode();
			}
			tmp = tmp->next;
		}
		cout << endl;
		cout << endl;
		delete[] tmp;
	}
}
void WebTopic::ReadFile() {
    cout << "testing..." << endl;
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
    int i = 0;
    string indexChar;
    getPriority(line);
    stripSpace(line);
    
    do {
       if(line[i] != ' '){
			indexChar = indexChar + line[i];
		}
		else{
			wordlist->priorityInsert(indexChar, currpriority);
			indexChar = "";
		} 
       i++;
       
    } while (i<=line.length());
}