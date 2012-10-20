#include "Parcheesi.h"

int main( int argc, const char* argv[] )
{
    Parcheesi *parcheesi = Parcheesi::getInstance();
    
    parcheesi->start();
    
    return 0;
}
