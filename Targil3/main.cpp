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




    View v;
    v.update_location("Yuval", Point(20, 30));
    v.draw();
    v.update_remove("Yuval");
    v.draw();
    v.set_size(10);
    v.draw();
    v.set_scale(1);
    v.draw();
    v.set_origin(Point(-1,-1));
    v.draw();
    v.set_defaults();
    v.draw();
    
    return 0;
}
