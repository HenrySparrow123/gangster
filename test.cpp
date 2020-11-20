#include "gangster.hpp"

int main() 
{
    Chef lieutenant;
    std::cout << " avant Bob = " << lieutenant.inf << std::endl;
    lieutenant.inf ++;
    std::cout << " apres Bob = " << lieutenant.inf << std::endl;

    Gangster Bill;

    std::cout << "Bill = " << Bill.getId() << std::endl;
    
}