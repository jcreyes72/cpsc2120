#include <iostream>
#include "blister.h"

using namespace std;

int main()
{

    Blister firstSeq("MAAM");

    std::cout << "Your string is: " << firstSeq;
    std::cout << "\nThere are a total of " << firstSeq.length() << " different bases in your sequence\n\n";

    Blister secondSeq("MADAM");

    std::cout << "Your second string is: " << secondSeq;
    std::cout << "\nThere are a total of " << secondSeq.length() << " different bases in your sequence\n\n";

        if (secondSeq.isInsertionOf(firstSeq) == true){
            std::cout << firstSeq << " is an insertion of " << secondSeq << std::endl;
        }

        if (secondSeq.isInsertionOf(firstSeq) == false){
            std::cout << firstSeq << " is NOT an insertion of " << secondSeq << std::endl;
        }


    return 0;
}
