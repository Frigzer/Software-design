#include "CEO.h"

void CEO::setPrices() {

    int task=0;
    while (task != 7)
    {
        std::cout << "What price would you like to change?\n";

        std::cout << "\n\t1) Default price: " << defaultPrice;
        std::cout << "\n\t2) Weekend price: " << weekendPrice;
        std::cout << "\n\t3) Holiday price: " << holidayPrice;
        std::cout << "\n\t4) Standard room price: " << standardPrice;
        std::cout << "\n\t5) Penthouse price: " << penthousePrice;
        std::cout << "\n\t6) Luxury room price: " << luxuryPrice;

        std::cout << "\n\n7) Return \n";

        std::cout << "\nYour choice: ";

        std::cin >> task;

        std::cout << "New price: ";

        if (task == 1)
            std::cin >> defaultPrice;
        else if (task == 2)
            std::cin >> weekendPrice;
        else if (task == 3)
            std::cin >> holidayPrice;
        else  if (task == 4)
            std::cin >> standardPrice;
        else if (task == 5)
            std::cin >> penthousePrice;
        else if (task == 6)
            std::cin >> luxuryPrice;
        else if (task == 7)
            break;
        
        system("cls");
    }
    
    
}
