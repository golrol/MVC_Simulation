//
// Created by Admin on 19/06/2020.
//

#ifndef AOOP_TARGIL3_VALIDATION_H
#define AOOP_TARGIL3_VALIDATION_H
#include <iostream>
#include "Geometry.h"
#include "Model.h"
#include "Agent.h"
#include "Structure.h"
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

enum {MAX_NAME_SIZE = 16 , AGENT_ARGUMENT_NUM = 4 , CASTLES_ARGUMENT_NUM = 4 , FARM_ARGUMENT_NUM = 3 , MAX_VIEW_SIZE = 30 , MIN_VIEW_SIZE = 6};

double doubleValidation(string str);
Point pointValidation(string str);
bool nameValidation(string str);
int intValidation(string str);

vector<string> tokenizeLine(const string& strLine);
/*validation function to all command in the program*/
bool defaultValidation(const string& strLine);
int sizeValidation(const string& strLine);
int zoomValidation(const string& strLine);
Point panValidation(const string& strLine);
bool showValidation(const string& strLine);
bool statusValidation(const string& strLine);
bool goValidation(const string& strLine);
vector<string> createValidation(const string& strLine);
pair<double,double> courseValidation(const string& strLine,const int& type);
pair<Point,int> positionValidation(const string& strLine);
string destinationValidation(const string& strLine);
bool stopValidation(const string& strLine);
string attackValidation(const string& strLine);


/*GAL*/
Point checkExistingStructure(const vector<shared_ptr<Structure> >& structuresVec, const string& name);


void tokenizeFile(string fileName);

/*inner calla of commandException to throw if found an error*/
class CommandException{
private:
    string data;
public:
    CommandException(const string& str){
        data = str;
    }
    ~CommandException(){}
    void what() const{
        cout << data << endl;
    }
};

#endif //AOOP_TARGIL3_VALIDATION_H
