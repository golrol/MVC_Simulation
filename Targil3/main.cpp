//
//  main.cpp
//  Targil3
//
//  Created by Gal Raykin on 13/06/2020.
//  Copyright © 2020 Gal Raykin. All rights reserved.
//
#include "Controller.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    /*yuvals tests*/
    //    if(nameValidation("yuval zel-zion is the king"))
    //        cout << "ok" << endl;
    
    //    string point="(22.01, 3)";
    //    pointValidation(point);
    
    //    string lineToTokenize="commend yuval (12.12,32.32)";
    //    tokenizeCommend(lineToTokenize);
    
    //    string fileToTokenize = "merom_golan, (10,10.5), 15\ntel_adashim, (13,32), 20\nmetula, (0,0), 12";
    //    tokenizeFile(fileToTokenize);
    cout << fixed;
    cout.precision(2);
    
    try{
        if (argc != NUMBER_OF_FILES)
            throw Model::xFileException("wrong number of input files.");
        
        Model::getInstance()->castleInit(argv[1]);
        Model::getInstance()->farmInit(argv[2]);
    }
    catch (const Model::xFileException& e){
        e.what();
        return 1;
    }
    
    Controller c;
    c.run();
    
    //TODO: allow point without space (e.g. (0,0) ) ?
    return 0;
}
