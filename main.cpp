#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>
#include <ctime>

#if defined( _MSC_VER )
#include <direct.h>		// _mkdir
	#include <crtdbg.h>
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	_CrtMemState startMemState;
	_CrtMemState endMemState;
#elif defined(MINGW32) || defined(__MINGW32__)
#include <io.h>  // mkdir
#else
#include <sys/stat.h>	// mkdir
#endif

#include <iostream>
#include <fstream>

#include "tinyxml2.h"
#include "Base.h"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include <iostream>
#include <string>
using namespace tinyxml2;
using namespace std;

int main() {
    ifstream f;
    int len;
    f.open("C:/xmls/sample.xml", std::ifstream::in);
    f.seekg(0, std::ios::end);
    len = f.tellg();
    f.seekg(0, std::ios::beg);
    char currxml[len];
    f.read(currxml, len);
    f.close();
    int i = 0;
    while(i<len){
        cout << currxml[i];
        i++;
    }

    XMLDocument doc;
   // doc.LoadFile( "xmls/sample.xml" );


    return 0;
}