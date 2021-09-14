// print out primes less than 100
// wdg 2016
#include <iostream>

bool isPrime(int x);

const int MAX = 100;

int main( ) {

    int test = 2;

        while( test < MAX ) {
            if( isPrime(test) ){        // note we do not compare it with true
                std::cout << test << "  ";
            }
                test++;
        }

    std::cout << std::endl;

return 0;
}

bool isPrime(int x) {

    for(int y = 2; y < x; y++) {
      if( x % y == 0 )
        return false;
    }

return true;
}
