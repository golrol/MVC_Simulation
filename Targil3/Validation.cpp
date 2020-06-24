
#include "Validation.h"
/*Check if the string is valid Double and return it as Double variable*/
double doubleValidation(string str){
    stringstream ssDouble;
    /*reset string stream*/
    ssDouble.str("");
    ssDouble.clear();
    double retVal;
    int i,pointsCount=0;
    for (i=0;i<str.size();i++){
        if(str.at(i)<'0' || str.at(i)>'9') {
            if(str.at(i)=='-' && i==0)/*if the number is negative*/
                continue;
            if (str.at(i) == '.' && pointsCount < 1) {/*check if not digit only 1 point allowed*/
                pointsCount++;
                continue;
            } else{
                throw ssDouble ;/*throw stringstream*/
            }
        }
    }
    /*Get to this code only if valid double*/
    ssDouble.str(str);
    ssDouble>>retVal;
    return retVal;
}
/*Check if the string is valid Point and return it as Point variable*/
Point pointValidation(string str){
    stringstream ssPoint;
    string tmpStr,strX,strY;
    double x,y;
    /*Reset string stream*/
    ssPoint.str("");
    ssPoint.clear();

    if(str.at(0)!='(' && str.at(str.size())!=')'){/*check the first char of the point string*/
        throw ssPoint ;/*throw stringstream*/
    }
    tmpStr = str.substr(1,(str.size()-2));/*remove the '(' from the beginning and the ')' from the end of the string*/
    ssPoint.str(tmpStr);
    getline(ssPoint, strX, ',');/*read the 'X' part of the point*/
    getline(ssPoint, strY);/*read the 'Y' part of the point*/
    if (strY.at(0) == ' '){
        strY = strY.substr(1, strY.size()-1);/*remove space at the beginning*/
    }
    else{
        throw ssPoint ;/*throw stringstream*/
    }
    try {
        x = doubleValidation(strX);
        y = doubleValidation(strY);
    }
    catch (const stringstream& ss) {/*catch the exception thrown from "doubleValidation"*/
        throw ssPoint ;/*throw stringstream*/
    }
    /*get to this code only if valid point*/
    return Point(x,y);
}

/*Check if the string is valid Name and return true if its valid*/
bool nameValidation(string str){
    stringstream ss;
    if(str.size()>MAX_NAME_SIZE){
        throw ss;
    }
    return true;
}
/*Check if the string is valid int*/
int intValidation(string str){
    stringstream ssInt;
    /*reset string stream*/
    ssInt.str("");
    ssInt.clear();
    int i,retVal;
    for (i=0;i<str.size();i++){
        if(str.at(i)<'0' || str.at(i)>'9') {
            if(str.at(i)=='-' && i==0)/*if the number is negative*/
                continue;
            }
        else{
            throw ssInt ;/*throw stringstream*/
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
        try {
            retVal = intValidation(vec[1]);
        }
        catch (const stringstream& ss) {
            throw CommandException("Second argument is not int.");
        }
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
        try {
            retVal = intValidation(vec[1]);
        }
        catch (const stringstream& ss) {
            throw CommandException("Second argument is not int.");
        }
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
    try {
        x = doubleValidation(vec[1]);
        y = doubleValidation(vec[2]);
    }
    catch (const stringstream& ss) {
        throw CommandException("Second or third argument is not double.");
    }
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
    if(vec.size()==4 || vec.size() ==5){/*need to be 4 arguments for knight or 5 arguments for thug & peasant*/
        throw CommandException("Wrong number of arguments.");
    }
    try {
        if(nameValidation(vec[1]));/*check if the second is  a valid names*/
        if(vec[2] != "Knight" || vec[2] != "Peasant" || vec[2] != "Thug"){
            throw CommandException("Third argument is not valid type.");
        }
        if(vec[2]=="Knight"){
            if(nameValidation(vec[3]));/*check if the third argument is valid name of a fort*/
                return vec;
        }
        else{/*its Peasant or thug*/
            if(vec.size() ==5){
                string strPoint = vec[3];
                strPoint.append(vec[4]);/*append the tow argument to oe str and send it to pointValidation to get point*/
                pointValidation(strPoint);
                vec.pop_back();
                vec.pop_back();
                vec.push_back(strPoint);
                return vec;
            }
        }
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name or double");
    }
    return retVal;
}
pair<Point,int> courseValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    int deg , speed=0;
    if(vec.size()==2 || vec.size()==3)/*need to be 2 arguments for knight & peasant or 3 arguments for thug*/{
        throw CommandException("Wrong number of arguments.");
    }
    try{
        if(nameValidation(vec[0]));
            deg = intValidation(vec[1]);/*check if the angel is valid*/
            if(deg<0 || deg>360){
                throw CommandException("Deg is out of range.");
            }
        if(vec.size()==3) {
            speed = intValidation(vec[1]);/*check if the angel is valid*/
            if(speed<0 || speed>30){
                throw CommandException("Speed is out of range.");
            }
        }
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name or int.");
    }
    //TODO: need to see what to return here , cant make point of destination out of given arguments
    return make_pair(Point(deg,speed),speed);
}
pair<Point,int> positionValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    Point retVal;
    int speed=0;
    if(vec.size()==4 || vec.size()==5)/*need to be 2 arguments for knight and peasant or 3 arguments for thug*/{
        throw CommandException("Wrong number of arguments.");
    }
    try {
        if(nameValidation(vec[0]));
        string strPoint = vec[2];
        strPoint.append(vec[3]);/*append the tow argument to oe str and send it to pointValidation to get point*/
        retVal = pointValidation(strPoint);
        if(vec.size()==5){
            speed = intValidation(vec[4]);
        }
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name , point or int.");
    }
    return make_pair(retVal,speed);
}
string destinationValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=3){
        throw CommandException("Wrong number of arguments.");
    }
    try {
        if(nameValidation(vec[0]) && nameValidation(vec[2]));
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name.");
    }
    return vec[2];
}
bool stopValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=2){
        throw CommandException("Wrong number of arguments.");
    }
    try {
        if(nameValidation(vec[0]));
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name.");
    }
    return true;
}
string attackValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    if(vec.size()!=3){
        throw CommandException("Wrong number of arguments.");
    }
    try {
        if(nameValidation(vec[0]) && nameValidation(vec[2]));
    }
    catch (const stringstream& ss) {
        throw CommandException("InValide name.");
    }
    return vec[1];
}


/*Tokenize line by line from file*/
void tokenizeFile(string fileName){
    string token,tmpLine;
    vector<string> tokens;
    stringstream ssLine, ssFile;
    int i,j=0;
    /*conver to file working*/
//    ifstream configFile(fileName);
//    while(!configFile.eof()) {
//        /*reset stringstreams*/
//        ssLine.str("");
//        ssLine.clear();
//        getline(configFile, ssLine); /*get a line from the file*/
//    }

    ssFile.str(fileName);
    while(!ssFile.eof()) {
//        ssLine.str("");
//        ssLine.clear();
        getline(ssFile, tmpLine);
        ssLine.str(tmpLine);
        while (getline(ssLine, token, ' ')) {
            tokens.push_back(token);/*put the string in the vector*/
        }

        for (i = 0; i < tokens.size(); i++) {
            //TODO: remove cout
            cout << tokens.at(i) << " size: " << tokens.at(i).size() << endl;
        }
        //TODO: remove cout
        cout << "finish to tokenize line number"<< j << endl;
        j++;
    }

}
