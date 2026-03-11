//*****************************************************************************
// COMSC-210 | Lab 20 | Gabriel Marquez
// Description: this program modifies given starter code that uses a Chair
// class, pointers, and dynamic memory.
//*****************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

//constants for RNG in default constructor
const int MIN = 10000, MAX = 99999, MIN_LEGS = 3, MAX_LEGS = 4;
const double DIVISOR = 100;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    //default constructor changed to randomly select legs and prices
    Chair() {
        prices = new double[SIZE];
        legs = rand() % (MAX_LEGS - MIN_LEGS + 1) + MIN_LEGS;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / DIVISOR;
    }
    //parameter constructor changed to also take an array of 3 doubles
    Chair(int l, double arr[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0)); //setting seed value for rand() 
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    delete chairPtr; //deleting dynamically allocated memory
    chairPtr = nullptr;

    //creating dynamic chair object with parameter constructor
    double priceArr[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, priceArr);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    //Chair objects populated using default constructor
    for (int i = 0; i < SIZE; i++)
       collection[i].print(); 
        collection[i].print();
    
    return 0;
}