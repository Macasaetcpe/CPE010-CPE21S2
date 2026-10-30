#include <iostream>
#include <string.h>

class Fruits{
    private:
       std::string fruitName;
       int fruitPrice;
       int fruitQty;
    public:
       //constructor
       Fruits(std::string newFName = "Blank", int newFPrice = 0, int newFQty = 0){
          fruitName = std::move(newFName);
          fruitPrice = newFPrice;
          fruitQty = newFQty;
          std::cout << "Constructor Called." <<std::endl;
       };
       
       //deconstructor
       ~Fruits(){
        std::cout << "Destructor Called." <<std::endl;
       }

       //copy constructor
       Fruits(const Fruits &copyFruits){
        std::cout <<"Copy Constructor Called." <<std::endl;
        fruitName = copyFruits.fruitName;
        fruitPrice = copyFruits.fruitPrice;
        fruitQty = copyFruits.fruitQty;
       }
       //copy assignment
       Fruits& operator=(const Fruits& copyFruits) {
        if (this == &copyFruits) {
            return *this;
        }

        this->fruitName = copyFruits.fruitName;
        this->fruitPrice = copyFruits.fruitPrice;
        this->fruitQty = copyFruits.fruitQty;

        return *this;
    }
       //display attributes
       void printDetails(){
        std::cout << this->fruitName << "| Price: " << this->fruitPrice << " Qty: " << this->fruitQty << std::endl;
       }
       //sum of fruits prices
        static int fpriceTotal(const int fruitP[], int size){
          int totalFSum = 0;
          for(int i = 0; i < size; i++){
            totalFSum += fruitP[i];
          }
          return totalFSum;
        }
};

class Vegetables{
    private:
       std::string vegName;
       int vegPrice;
       int vegQty;
    public:
       //constructor
       Vegetables(std::string newVName = "Blank", int newVPrice = 0, int newVQty = 0){
          vegName = std::move(newVName);
          vegPrice = newVPrice;
          vegQty = newVQty;
          std::cout << "Constructor Called." <<std::endl;
       };
       
       //deconstructor
       ~Vegetables(){
        std::cout << "Destructor Called." <<std::endl;
       }

       //copy constructor
       Vegetables(const Vegetables &copyVegetables){
        std::cout <<"Copy Constructor Called." <<std::endl;
        vegName = copyVegetables.vegName;
        vegPrice = copyVegetables.vegPrice;
        vegQty = copyVegetables.vegQty;
       }
       //copy assignment 
       Vegetables& operator=(const Vegetables& copyVegetables) {
        if (this == &copyVegetables) {
            return *this;
        }

        this->vegName = copyVegetables.vegName;
        this->vegPrice = copyVegetables.vegPrice;
        this->vegQty = copyVegetables.vegQty;

        return *this;
    }

       //display attributes
       void printDetails(){
        std::cout << this->vegName << "| Price: " << this->vegPrice << " Qty: " << this->vegQty << std::endl;
       }
       //sum of vegetable prices
        static int vpriceTotal(const int vegP[], int size){
          int totalVSum = 0;
          for(int i = 0; i < size; i++){
            totalVSum += vegP[i];
          }
          return totalVSum;
        }

};
//Total price sum of fruits and vegetables
int totalSum(int a, int b){
    int totSum = a + b;
    return totSum;
}


int main(){
    std::string* GroceryList = new std::string[4]{"Apple", "Banana", "Broccoli", "Lettuce"};
    std::string fnameList[2];
    std::string vnameList[2];

    //puts Apple and Banana to fnameList
    for(int i = 0; i < 2; i++){
       fnameList[i] = GroceryList[i];
    }
    //puts Broccoli and Lettuce in fnameList
    for(int i = 0; i < 2; i++){
        vnameList[i] = GroceryList[i+2];
    }
    const size_t j = 2;
    int fpriceList[j] = {10, 10};
    int fqtyList[j] = {7, 8};
    int newfpriceList[j] = {};
    //multiple price to quantity
    for(int i = 0; i < 2; i++){
        newfpriceList[i] = fpriceList[i] * fqtyList[i];  
    }

    int vpriceList[j] = {60, 50};
    int vqtyList[j] = {12, 10};
    int newvpriceList[j] = {};
    for(int i = 0; i < 2; i++){
        newvpriceList[i] = vpriceList[i] * vqtyList[i];  
    }

    Fruits fruitDetails[j] = {};
    Vegetables vegDetails[j] = {};
    for(int i = 0; i < j; i++){ 
        Fruits *ptr = new Fruits(fnameList[i], fpriceList[i], fqtyList[i]);
        fruitDetails[i] = *ptr;
        delete ptr;
    }

    for(int i = 0; i < j; i++){ 
        Vegetables *ptr = new Vegetables(vnameList[i], vpriceList[i], vqtyList[i]);
        vegDetails[i] = *ptr;
        delete ptr;
    }

    std::cout << "Fruits:\n";
    for(int i = 0; i < j; i++){
        fruitDetails[i].printDetails();
    }
    std::cout << "\nVegetables:\n";
    for(int i = 0; i < j; i++){
        vegDetails[i].printDetails();
    }
    int totalFruitP = Fruits::fpriceTotal(newfpriceList, j);
    std::cout << "\nTotal Price of Fruits: " << totalFruitP <<std::endl;

    int totalVegP = Vegetables::vpriceTotal(newvpriceList, j);
    std::cout << "Total Price of Vegetables: " << totalVegP <<std::endl;

    std::cout<<"Total Price: " << totalSum(totalVegP, totalFruitP)<<std::endl;

    GroceryList[3].clear();
    //to make sure that lettuce has been removed
    if(GroceryList[3].empty()){
        std::cout<< "Lettuce has been deleted\n";
    }
    //deallocate memory
    delete[] GroceryList;


    return 0;
}