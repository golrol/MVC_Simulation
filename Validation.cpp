#include "Validation.h"

/* variable types validation */
int intValidation(string str){/*Check if the string is valid int and return as an int variable*/
    stringstream ssInt;
    unsigned int i;
    int retVal;
    
    for (i=0 ; i<str.size() ; i++){
        if(str.at(i) < '0' || str.at(i) > '9') {/*not a digit*/
            if(str.at(i)=='-' && i==0)/*if the number is negative- minus sign is ok*/
                continue;
            else
                throw xInvalidCommand("invalid int.");
        }
    }
    
    /*it is a valid int*/
    ssInt.str(str);
    ssInt >> retVal;
    return retVal;
}

double doubleValidation(string str){/*Check if the string is valid Double and return it as a Double variable*/
    stringstream ssDouble;
    double retVal;
    unsigned int i, pointsCount=0;
    
    for (i=0 ; i<str.size() ; i++){
        if(str.at(i)<'0' || str.at(i)>'9') {/*not a digit*/
            if(str.at(i)=='-' && i==0)/*if the number is negative- minus sign is ok*/
                continue;
            if (str.at(i) == '.' && pointsCount < 1) {/*not a digit and not a minus sign- only one point allowed*/
                pointsCount++;
                continue;
            } else
                throw xInvalidCommand("invalid double.");
        }
    }
    
    /*it is a valid double*/
    ssDouble.str(str);
    ssDouble >> retVal;
    return retVal;
}

bool nameValidation(string str){/*Check if the string is valid name*/
    stringstream ss;
    if(str.size() > MAX_NAME_SIZE)
        throw xInvalidCommand("invalid name.");
    
    return true;
}

Point pointValidation(string str){/*Check if the string is valid Point and return it as a Point variable*/
    stringstream ssPoint;
    string tmpStr,strX,strY;
    unsigned int i;
    int commaCnt=0;
    double x,y;
    
    if(str.at(0) != '(' || str.at(str.size()-1) != ')')/*make sure starts and ends with '(' and ')'*/
        throw xInvalidCommand("invalid location.");
    
    for (i=0; i<str.size(); i++) {/*only one ',' allowed*/
        if (str[i] == ',')
            commaCnt++;
    }
    if (commaCnt != 1)
        throw xInvalidCommand("invalid location.");
    
    tmpStr = str.substr(1,(str.size()-2));/*remove the '(' from the beginning and the ')' from the end of the string*/
    ssPoint.str(tmpStr);
    getline(ssPoint, strX, ',');/*read the 'X' part of the point*/
    getline(ssPoint, strY);/*read the 'Y' part of the point*/
    
    x = doubleValidation(strX);/*make sure the double values are valid*/
    y = doubleValidation(strY);
    
    /*it is a valid Point*/
    return Point(x,y);
}

bool defaultValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 1)
        throw xInvalidCommand("Wrong number of arguments.");
    else
        return true;
}
int sizeValidation(const string& strLine){/*returns the size*/
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    
    if(vec.size() != 2)
        throw xInvalidCommand("Wrong number of arguments.");
    else{
        retVal = intValidation(vec[1]);
        if(retVal <= MIN_VIEW_SIZE || retVal > MAX_VIEW_SIZE)
            throw xInvalidCommand("Second argument is out of range.");
        return retVal;
    }
}
int zoomValidation(const string& strLine){/*returns the scale*/
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    
    if(vec.size() != 2)
        throw xInvalidCommand("Wrong number of arguments.");
    else{
        retVal = intValidation(vec[1]);
        if(retVal < 1)
            throw xInvalidCommand("Second argument is no positive number.");
        return retVal;
    }
}
Point panValidation(const string& strLine){/*returns the origin*/
    vector<string> vec(tokenizeLine(strLine));
    double x,y;
    
    if(vec.size() != 3)
        throw xInvalidCommand("Wrong number of arguments.");
    
    x = doubleValidation(vec[1]);
    y = doubleValidation(vec[2]);
    
    Point retVal(x,y);
    return retVal;
}
bool showValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 1)
        throw xInvalidCommand("Wrong number of arguments.");
    else
        return true;
    return false;
}
bool statusValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 1){
        throw xInvalidCommand("Wrong number of arguments.");
    }
    else
        return true;
    return false;
}
bool goValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 1)
        throw xInvalidCommand("Wrong number of arguments.");
    else
        return true;
    return false;
}
vector<string> createValidation(const string& strLine){/*returns vector with command, name, type and location*/
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() == 4 || vec.size() == 5){/*need to be 4 arguments for knight or 5 arguments for thug & peasant*/
        nameValidation(vec[1]);/*check if the second element is a valid name*/
        if(vec[2] == "Knight"){
            nameValidation(vec[3]);/*check if the fourth argument is valid name of a Castle*/
            return vec;
        }
        else if(vec[2] == "Peasant" || vec[2] == "Thug"){/*its Peasant or thug*/
            if (vec.size() != 5)
                throw xInvalidCommand("Wrong number of arguments.");
            string strPoint = vec[3];
            strPoint.append(vec[4]);/*append the two arguments to be str and send it to pointValidation to get a Point*/
            pointValidation(strPoint);
            vec.pop_back();/*remove the two values of x and y and put a Point instead*/
            vec.pop_back();
            vec.push_back(strPoint);
            return vec;
        }
        else/*not Knigt, Peasnat or Thug*/
            throw xInvalidCommand("Third argument is not a valid type.");
    }
    else/*wrong number of arguments*/
        throw xInvalidCommand("Wrong number of arguments.");
}

pair<double,double> courseValidation(const string& strLine, const int& type){/*returns pair with deg and speed(=-1 if not a Thug)*/
    vector<string> vec(tokenizeLine(strLine));
    double deg, speed = -1;
    
    if (type == PEASANT)
        throw xInvalidCommand("This agent doesn't support this command");
    
    /*need to be 3 arguments for knight or 4 arguments for thug*/
    if((vec.size() == 3 && type == KNIGHT) || (vec.size() == 4 && type == THUG)){
        nameValidation(vec[0]);/*check if name is valid*/
        deg = doubleValidation(vec[2]);/*check if the angle is valid*/
        if(deg < 0 || deg > 360)/*check if deg is in range*/
            throw xInvalidCommand("Deg is out of range.");
        if(vec.size() == 4) {
            speed = doubleValidation(vec[3]);/*check if the speed is valid*/
            if(speed < 0 || speed > 30)/*check if speed is in range*/
                throw xInvalidCommand("Speed is out of range.");
        }
    }
    else
        throw xInvalidCommand("Wrong number of arguments.");
    return make_pair(deg, speed);
}

pair<Point,double> positionValidation(const string& strLine, const int& type){/*returns pair with location and speed(=-1 if not a Thug)*/
    vector<string> vec(tokenizeLine(strLine));
    Point retVal;
    double speed = -1;
    
    if (type == PEASANT)
        throw xInvalidCommand("This agent doesn't support this command");
    
    if((vec.size() == 4 && type == KNIGHT) || (vec.size() == 5 && type == THUG)){/*need to be 4 arguments for knight and 5 arguments for thug*/
        nameValidation(vec[0]);/*check if name is valid*/
        
        string strPoint = vec[2];
        strPoint.append(vec[3]);/*append the two argument to be str and send it to pointValidation to get Point*/
        retVal = pointValidation(strPoint);
        
        if(vec.size() == 5){
            speed = doubleValidation(vec[4]);/*check if the speed is valid*/
            if(speed < 0 || speed > 30)/*check if speed is in range*/
                throw xInvalidCommand("Speed is out of range.");
        }
        return make_pair(retVal,speed);
    }
    else
        throw xInvalidCommand("Wrong number of arguments.");
}

string destinationValidation(const string& strLine, const int& type){/*returns the name of the destination*/
    vector<string> vec(tokenizeLine(strLine));
    
    if (type != KNIGHT)
        throw xInvalidCommand("This agent doesn't support this command");
    
    if(vec.size() != 3)
        throw xInvalidCommand("Wrong number of arguments.");
    
    nameValidation(vec[0]);/*check if name is valid*/
    nameValidation(vec[2]);/*check if name of Structure is valid*/
    return vec[2];
}

bool stopValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 2)
        throw xInvalidCommand("Wrong number of arguments.");
    
    nameValidation(vec[0]);
    return true;
}

string attackValidation(const string& strLine){/*returns the name of the attacked Peasant*/
    vector<string> vec(tokenizeLine(strLine));
    
    if(vec.size() != 3)
        throw xInvalidCommand("Wrong number of arguments.");
    
    nameValidation(vec[0]);
    nameValidation(vec[2]);
    return vec[2];
}

pair<string,string> startWorkingValidation(const string& strLine, const int& type){/*return a pair with the name of the farm and the castle*/
    vector<string> vec(tokenizeLine(strLine));
    
    if(type != PEASANT)
        throw xInvalidCommand("This agent doesn't support this command");
    
    if(vec.size() != 4)
        throw xInvalidCommand("Wrong number of arguments.");
    
    nameValidation(vec[0]);/*check if the Peasant's name is valid*/
    nameValidation(vec[2]);/*check if the farm's & the castle's names are valid*/
    nameValidation(vec[3]);
    return make_pair(vec[2],vec[3]);
}

/*helper function- break lines into words*/
vector<string> tokenizeLine(const string& strLine){
    vector<string> commandVec;
    string token;
    stringstream ssLine;
    ssLine.str(strLine);
    
    while (getline(ssLine, token, ' '))
        commandVec.push_back(token);/*put the string in the vector*/
    
    return commandVec;/*return vector of string made of the command line*/
}
