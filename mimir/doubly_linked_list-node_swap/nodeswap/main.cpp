#include <iostream>
#include "doublyLinkedSwap.h"

using namespace std;

int main(){

    int linkedList[5] = {1, 2, 3, 4, 5};

    Node* head = new Node();
    Node* tail = new Node();

    Node* tempList = arrayToList(linkedList, 5);
    head = getNode(tempList, 1);
    tail = getNode(tempList, 5);



    cout << "Hello world!" << endl;
return 0;
}
