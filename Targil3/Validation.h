//
// Created by Admin on 19/06/2020.
//

#ifndef AOOP_TARGIL3_VALIDATION_H
#define AOOP_TARGIL3_VALIDATION_H
#include <iostream>
#include "Geometry.h"
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

enum {MAX_NAME_SIZE = 16 , AGENT_ARGUMENT_NUM = 4 , CASTLES_ARGUMENT_NUM = 4 , FARM_ARGUMENT_NUM = 3};

double doubleValidation(string str);
Point pointValidation(string str);
bool nameValidation(string str);

void tokenizeCommend(string strLine);

void tokenizeFile(string fileName);

#endif //AOOP_TARGIL3_VALIDATION_H
