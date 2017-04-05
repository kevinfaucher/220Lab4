/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SNode.cpp
 * Author: Kevin
 * 
 * Created on April 2, 2017, 3:05 PM
 */

#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

SNode::SNode(string word, int p) {
    word = word;
    priority = p;
    next = NULL;
}

SNode::~SNode(){
	word = "";
	priority = 1;
	next = NULL;
}

void SNode::printNode(){
	cout << this->word << ":" << this->priority << ", ";
}