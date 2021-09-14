#include <iostream>
#include "NumberCount.h"

int main() {

    NumberCount N(11, 16);  //creating new object

    N.addElement(12);       //adding elements to the array
    N.addElement(12);
    N.addElement(12);
    N.addElement(14);
    N.addElement(17);
    N.addElement(13);
    N.removeElement(11);
    N.removeElement(13);

    N.display();

return 0;
}
