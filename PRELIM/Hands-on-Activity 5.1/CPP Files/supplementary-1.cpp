#include <iostream>
#include "queuejobs.h"

int main() {
    Printer<Job> myPrinter;
    qNode<Job>* front = nullptr;
    qNode<Job>* back = nullptr;
    std::string name;
    int pageNum;
    int choice;
    int jobID = 1;
    while (true) {
        std::cout << "1. Add new job\n2. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Enter Username: ";
            std::cin >> name;
            std::cout << "Enter number of pages: ";
            std::cin >> pageNum;
            Job job(jobID++, name, pageNum);
            myPrinter.enqueue(job, &front, &back);
        } 
        else if (choice == 2) {
          while(front != nullptr && back != nullptr){
            std::cout << "\nQueue:\n";
            myPrinter.displayQ(&front, &back);
            std::cout << "\nProcessing the top...\n";
            myPrinter.dequeue(&front, &back);
          }
          std::cout << "\nNothing left to print!\n";
          break;
        }
    }
    return 0;
}