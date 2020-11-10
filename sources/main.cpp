#include <func.hpp>
#include <iostream>
#include <vector>


using std::endl;
using std::cout;
using std::cin;

int main(){
    std::vector<Person> population;
    for (size_t i = 0; i < 4; ++i) {
        insert(population, Person(static_cast<double>(std::rand())/
               static_cast<double>(RAND_MAX/4) - 2,
               static_cast<double>(std::rand())/
               static_cast<double>(RAND_MAX/4) - 2));
    }
    while ()

    return 0;
}
