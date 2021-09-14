#include "IntegerArrayQueue.h"

//Implement the enqueue and dequeue functions
//enqueue: if there is space available enqueue value and
//return true, otherwise return false
bool IntegerArrayQueue::enqueue(int value) {

    if (((front == 0) && (back == size - 1)) || ((back == (front - 1) % (size - 1)))){
        return false;
    }
    else if (front == 0){
        front = back = 0;
        array[back] = value;
    }
    else if ((back == size - 1) && (front != 0)) {
        back = 0;
        array[back] = value;
    }
    else {
        back++;
        array[back] = value;
    }

return true;
}


//dequeue: if there is a value at the front of the queue
//return the value and remove from the queue,
//otherwise return 0
int IntegerArrayQueue::dequeue(){


        if (front == 0) {
            return 0;
        }

    int element = array[front];
    array[front] = 0;

        if (front == back) {
            front = back = 0;
        }
        else if (front == (size - 1)){
            front = 0;
        }
        else{
            front++;
        }


return element;
}
