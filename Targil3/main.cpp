#include "Controller.h"
using namespace std;

int main(int argc, const char * argv[]) {
    /*format prints*/
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
