
#include "Validation.h"
/*Check if the string is valid Double and return it as Double variable*/
double doubleValidation(string str){
    stringstream ssDouble;
    /*reset stringstream*/
    ssDouble.str("");
    ssDouble.clear();
    //TODO: remove cout
    cout << "the string send is " << str << endl;
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
                cout << "throw here exception & end the function (not digit or one ','.)" << endl;
                //TODO: throw exception & end the run of the function
            }
        }
    }
    /*Get to this code only if valid double*/
    //TODO: remove cout
    cout << "validation is fine" << endl;
    ssDouble.str(str);
    ssDouble>>retVal;
    cout << "retval double is : "<<retVal<<endl;
    return retVal;
}
/*Check if the string is valid Point and return it as Point variable*/
Point pointValidation(string str){
    stringstream ssPoint;
    string tmpStr,strX,strY;
    double x,y;
    /*Reset stringstream*/
    ssPoint.str("");
    ssPoint.clear();
    //TODO: remove cout
    cout << "in PV : " << str <<endl;
    cout << str.size()<<endl;
    cout << str.at(0)<<endl;
    cout << str.at(str.size()-1)<<endl;

    if(str.at(0)!='(' && str.at(str.size())!=')'){/*check the first char of the point string*/
        //TODO: wrong input
        cout <<"throw here exception & end the function (first or last char check.) "<<endl;
    }
    tmpStr = str.substr(1,(str.size()-2));/*remove the '(' from the beginning and the ')' from the end of the string*/
    ssPoint.str(tmpStr);
    getline(ssPoint, strX, ',');/*read the 'X' part of the point*/
    getline(ssPoint, strY);/*read the 'Y' part of the point*/
    if (strY.at(0) == ' '){
        strY = strY.substr(1, strY.size()-1);/*remove space at the beginning*/
    }
    else{
        //TODO: throw exception.
    }
    try {
        x = doubleValidation(strX);
        y = doubleValidation(strY);
    }
    catch (...) {
        //TODO: throw exception & end the function
    }
    /*get to this code only if valid point*/
    return Point(x,y);
}

/*Check if the string is valid Name and return true if its valid*/
bool nameValidation(string str){
    if(str.size()>MAX_NAME_SIZE){
        //TODO: remove cout
        cout<<"Name is to long"<<endl;
        return false;
        //TODO: throw exception & end the function
    }
    return true;
}
/*Check if the string is valid int*/
int intValidation(string str){
    stringstream ssInt;
    /*reset stringstream*/
    ssInt.str("");
    ssInt.clear();
    int i,retVal;
    for (i=0;i<str.size();i++){
        if(str.at(i)<'0' || str.at(i)>'9') {
            if(str.at(i)=='-' && i==0)/*if the number is negative*/
                continue;
            }
        else{
            cout << "throw here exception not int" << endl;
            //TODO: throw exception & end the run of the function
            }
    }
    /*get to this code only if valid int*/
    ssInt.str(str);
    ssInt>>retVal;
    return retVal;
}

///*Tokenize line with space delimiter*/
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
    if(vec.size()!=1){
        //TODO: throw exception (wrong number of arguments)
    }
    else
        return true;
}
int sizeValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    if(vec.size()!=2){
        //TODO: throw exception (wrong number of arguments)
    }
    else{
        try {
            retVal = intValidation(vec[1]);
        }
        catch (...) {
            //TODO: throw exception (argument number 2 isn't int)
        }
        if(retVal<=MIN_VIEW_SIZE || retVal > MAX_VIEW_SIZE) {
            //TODO: throw exception (out of range)
        }
        return retVal;
    }
}
int zoomValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    int retVal;
    if(vec.size()!=2){
        //TODO: throw exception (wrong number of arguments)
    }
    else{
        try {
            retVal = intValidation(vec[1]);
        }
        catch (...) {
            //TODO: throw exception (argument number 2 isn't int)
        }
        if(retVal<1) {
            //TODO: throw exception (out of range)
        }
        return retVal;
    }
}
Point panValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
    double x,y;
    if(vec.size()!=3){
        //TODO: throw exception (wrong number of arguments)
    }
    try {
        x = intValidation(vec[1]);
        y = intValidation(vec[2]);
    }
    catch (...) {
        //TODO: throw exception (argument number 2 or 3 isn't double)
    }
    Point retVal(x,y);
}
bool showValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
bool statusValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
bool goValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
bool createValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
pair<Point,int> courseValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
pair<Point,int> positionValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
string destinationValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
bool stopValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
}
string attackValidation(const string& strLine){
    vector<string> vec(tokenizeLine(strLine));
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