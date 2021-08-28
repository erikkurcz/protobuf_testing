// read addressbook based on given filename

#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "cpp_src/addressbook.pb.h"

void usage(){
    std::cout << "Usage: " 
              << "./read_book ADDRESSBOOK_FILENAME\n\n"
              << "Where ADDRESSBOOK_FILENAME is a required filename of an addressbook file"
              << std::endl;
}

int main(int argc, char* argv[]){
    
    
    if (argc < 2){
        usage();
        return 1;
    }

    std::string src_filename(argv[1]);

    AddressBook addressbook;

    std::fstream src_file(src_filename, std::ios::in | std::ios::binary);

    if (!addressbook.ParseFromIstream(&src_file)){
        std::cerr << "Failed to parse src_file" << std::endl;
        return 1;
    }

    // successful read at this point
    for (int i = 0; i < addressbook.people_size(); i++){
        const Person& person = addressbook.people(i);

        std::cout << "Person #" << person.id() << " - " << person.name() << std::endl;
    }

    return 0;
}
