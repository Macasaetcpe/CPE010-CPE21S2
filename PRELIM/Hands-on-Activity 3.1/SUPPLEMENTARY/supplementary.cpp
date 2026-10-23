#include <iostream>
#include "supplesingly_ll.h"
#include <string>


int main(){
    // create a playlist
    musicList<std::string>* head = AddSong(std::string("Linger - The Cranberries"));
    musicList<std::string>* second = AddSong(std::string("Boys Don't Cry - The Cure"));
    musicList<std::string>* third = AddSong(std::string("Let Down - Radiohead"));
    musicList<std::string>* fourth = AddSong(std::string("Playing God - Paramore"));
    musicList<std::string>* fifth = AddSong(std::string("Lovers Rock - TV Girl"));

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    int options = 0;
    while(options <= 3){
     std::cout<<"Menu:\n1. Start the Playlist\n2. Insert Song\n3. Remove Song\n4. Exit\n";
     std::cout<<"Type the number of the option you want: ";
     std::cin>>options;
     switch(options){
        case 1:{
           //traversal
           playlistTraverse(head);
           std::cout<<std::endl;
           break;
        }
        case 2:{
           std::cout<<"Song Name: ";
           std::string insertSong;
           std::cin>>std::ws;
           std::cout<<std::endl;
           std::getline(std::cin, insertSong);
           playlistInsertEnd(insertSong, head);
           break;
        }
        case 3:{
           std::cout<<"Song Name: ";
           std::string removeSong;
           std::cin>>std::ws;
           std::cout<<std::endl;
           std::getline(std::cin, removeSong);
           deleteSong(removeSong, &head);
           break;
         }
         case 4:{
            break;
         }
    }
 }
}