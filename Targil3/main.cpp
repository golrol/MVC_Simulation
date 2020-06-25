//
//  main.cpp
//  Targil3
//
//  Created by Gal Raykin on 13/06/2020.
//  Copyright © 2020 Gal Raykin. All rights reserved.
//
#include "skeleton_View.h"
#include "skeletonController.h"
#include "Validation.h"
#include "Thug.h"
#include "Structure.h"
#include "Farm.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello, world!" << endl;
                /*yuvals tests*/
//    if(nameValidation("yuval zel-zion is the king"))
//        cout << "ok" << endl;

//    string point="(22.01, 3)";
//    pointValidation(point);

//    string lineToTokenize="commend yuval (12.12,32.32)";
//    tokenizeCommend(lineToTokenize);

//    string fileToTokenize = "merom_golan, (10,10.5), 15\ntel_adashim, (13,32), 20\nmetula, (0,0), 12";
//    tokenizeFile(fileToTokenize);
cout << argv[1] << endl;
    try{
        Model::getInstance()->farmInit(argv[1]);
        Model::getInstance()->castleInit(argv[2]);
    }
    catch (Model::xFileException){
        cout << "end program." << endl;
    }

    
    Controller c;
    c.run();
    
    

    return 0;
}
