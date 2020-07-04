
#include "Validation.h"
/*Check if the string is valid Double and return it as Double variable*/
double doubleValidation(string str){
    stringstream ssDouble;
    /*reset string stream*/
    ssDouble.str("");
    ssDouble.clear();
    double retVal;
    unsigned int i, pointsCount=0;
    for (i=0;i<str.size();i++){
        if(str.at(i)<'0' || str.at(i)>'9') {
            if(str.at(i)=='-' && i==0)/*if the number is negative*/
                continue;
            if (str.at(i) == '.' && pointsCount < 1) {/*check if not digit only 1 point allowed*/
                pointsCount++;
                continue;
            } else
                throw CommandException("invalid double.");
        }
    }
    /*Get to this code only if valid double*/
    ssDouble.str(str);
    ssDouble>>retVal;
    return retVal;
}
/*Check if the string is valid Point and return it as Point variable*/
Point pointValidation(string str){ //TODO: case where no ',' at all.
    stringstream ssPoint;
    string tmpStr,strX,strY;
    double x,y;
    /*Reset string stream*/
    ssPoint.str("");
    ssPoint.clear();
    
    if(str.at(0) != '(' || str.at(str.size()-1) != ')'){/*check the first char of the point string*/
        throw CommandException("invalid location.") ;
    }
    tmpStr = str.substr(1,(str.size()-2));/*remove the '(' from the beginning and the ')' from the end of the string*/
    ssPoint.str(tmpStr);
    getline(ssPoint, strX, ',');/*read the 'X' part of the point*/
    getline(ssPoint, strY);/*read the 'Y' part of the point*/
    //    if (strY.at(0) == ' '){
    //        strY = strY.substr(1, strY.size()-1);/*remove space at the beginning*/
    //    }
    //    else{
    //        throw ssPoint ;/*throw stringstream*/
    //    }
    x = doubleValidation(strX);
    y = doubleValidation(strY);
    
    /*get to this code only if valid point*/
    return Point(x,y);
}

/*Check if the string is valid Name and return true if its valid*/
bool nameValidation(string str){
    stringstream ss;
    if(str.size()>MAX_NAME_SIZE){
        throw CommandException("invalid name.");
    }
    return true;
}
/*Check if the string is valid int*/
int intValidation(string str){
    stringstream ssInt;
    /*reset string stream*/
    ssInt.str("");
    ssInt.clear();
    unsigned int i;
    int retVal;
    for (i=0;i<str.size();i++){
        if(str.at(i)<'0' || str.at(i)>'9') {
            if(str.at(i)=='-' && i==0){/*if the number is negative*/
                continue;
            }
            else{
                throw CommandException("invalid int.");
            }
            
        }
    }
    /*get to this code only if valid int*/
    ssInt.str(str);
    ssInt>>retVal;
    return retVal;
}

/*Tokenize line with space delimiter*/
vector<string> tokenizeLine(const string& strLine){
    vector<string> commandVec;
    string token;
    stringstream ssLine;
    ssLine.str(strLine);
    while (getline(ssLine, token, ' ')) {
        commandVec.push_back(token);/*put the string in the vector*/
    }
    return commandVec;/*return vector of string made of the command line*/
}

bool defaultValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size() != 1){
        throw CommandException("Wrong number of arguments.");
    }
    else
        return true;
}
int sizeValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    if(vec.size()!=2){
        throw CommandException("Wrong number of arguments.");
    }
    else{
        retVal = intValidation(vec[1]);
        if(retVal<=MIN_VIEW_SIZE || retVal > MAX_VIEW_SIZE) {
            throw CommandException("Second argument is out of range.");
        }
        return retVal;
    }
}
int zoomValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    if(vec.size()!=2){
        throw CommandException("Wrong number of arguments.");
    }
    else{
        retVal = intValidation(vec[1]);
        if(retVal<1) {
            throw CommandException("Second argument is no positive number.");
        }
        return retVal;
    }
}
Point panValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    double x,y;
    if(vec.size()!=3){
        throw CommandException("Wrong number of arguments.");
    }
    x = doubleValidation(vec[1]);
    y = doubleValidation(vec[2]);
    Point retVal(x,y);
    return retVal;
}
bool showValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=1){
        throw CommandException("Wrong number of arguments.");
    }
    else
        return true;
    return false;
}
bool statusValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=1){
        throw CommandException("Wrong number of arguments.");
    }
    else
        return true;
    return false;
}
bool goValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=1){
        throw CommandException("Wrong number of arguments.");
    }
    else
        return true;
    return false;
}
vector<string> createValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size() == 4 || vec.size() == 5){/*need to be 4 arguments for knight or 5 arguments for thug & peasant*/
        nameValidation(vec[1]);/*check if the second is a valid name*/
        if(vec[2] == "Knight"){
            nameValidation(vec[3]);/*check if the fourth argument is valid name of a Castle*/
            return vec;
        }
        else if(vec[2] == "Peasant" || vec[2] == "Thug"){/*its Peasant or thug*/
            string strPoint = vec[3];
            strPoint.append(vec[4]);/*append the tow argument to oe str and send it to pointValidation to get point*/
            pointValidation(strPoint);
            vec.pop_back();
            vec.pop_back();
            vec.push_back(strPoint);
            return vec;
        }
        else/*not Knigt, Peasnat or Thug*/
            throw CommandException("Third argument is not valid type.");
    }
    else{
        throw CommandException("Wrong number of arguments.");
    }
}

pair<double,double> courseValidation(const string& strLine, const int& type){
    vector<string> vec(tokenizeLine(strLine));
    double deg , speed = -1;
    if (type == PEASANT)
        throw CommandException("This agent doesn't support this command");
    /*need to be 3 arguments for knight or 4 arguments for thug*/
    if((vec.size() == 3 && type == KNIGHT) || (vec.size() == 4 && type == THUG)){
        nameValidation(vec[0]);
        deg = doubleValidation(vec[2]);/*check if the angle is valid*/
        if(deg < 0 || deg > 360)
            throw CommandException("Deg is out of range.");
        if(vec.size() == 4) {
            speed = doubleValidation(vec[3]);/*check if the speed is valid*/
            if(speed < 0 || speed > 30)
                throw CommandException("Speed is out of range.");
        }
    }
    else{
        throw CommandException("Wrong number of arguments.");
    }
    return make_pair(deg, speed);
}
pair<Point,double> positionValidation(const string& strLine, const int& type){
    vector<string> vec(tokenizeLine(strLine));
    Point retVal;
    double speed=0.0;
    if (type == PEASANT)
        throw CommandException("This agent doesn't support this command");
    if((vec.size() == 4 && type == KNIGHT) || (vec.size() == 5 && type == THUG)){/*need to be 4 arguments for knight and 5 arguments for thug*/
        nameValidation(vec[0]);
        string strPoint = vec[2];
        strPoint.append(vec[3]);/*append the tow argument to oe str and send it to pointValidation to get point*/
        retVal = pointValidation(strPoint);
        if(vec.size()==5){
            speed = doubleValidation(vec[4]);
            if(speed < 0 || speed > 30)
                throw CommandException("Speed is out of range.");
        }
        return make_pair(retVal,speed);
    }
    else
        throw CommandException("Wrong number of arguments.");
}
string destinationValidation(const string& strLine, const int& type){
    vector<string> vec(tokenizeLine(strLine));
    if (type != KNIGHT)
        throw CommandException("This agent doesn't support this command");
    if(vec.size()!=3){
        throw CommandException("Wrong number of arguments.");
    }
    nameValidation(vec[0]);
    nameValidation(vec[2]);
    return vec[2];
}
bool stopValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=2){
        throw CommandException("Wrong number of arguments.");
    }
    nameValidation(vec[0]);
    return true;
}
string attackValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=3){
        throw CommandException("Wrong number of arguments.");
    }
    nameValidation(vec[0]);
    nameValidation(vec[2]);
    return vec[2];
}

pair<string,string> startWorkingValidation(const string& strLine, const int& type){
    if(type != PEASANT)
    {
        throw CommandException("This agent doesn't support this command");
    }
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size() != 4){
        throw CommandException("Wrong number of arguments.");
    }
    nameValidation(vec[0]);/*check the peasant name*/
    nameValidation(vec[2]);/*vec[2] ,vec[3] - check the farm & the castle names*/
    nameValidation(vec[3]);
    return make_pair(vec[2],vec[3]);/*return the name of the farm and the castle*/
}
