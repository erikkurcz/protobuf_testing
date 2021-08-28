// write addressbook based on given filename

#include <fstream>
#include <iostream>
#include <random>

#include <cstdlib>

#include "cpp_src/addressbook.pb.h"

static char alphabet[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

void usage(){
    std::cout << "Usage: " 
              << "./write_book DEST_ADDRESSBOOK_FILENAME [N]\n\n"
              << "Where DEST_ADDRESSBOOK_FILENAME is a required filename of an addressbook file "
              << "and N is an optional number of records to write (default is 10)"
              << std::endl;
}

std::string generate_name(){
    
    short first_len(rand() % 10 + 5); // random from 5 to 15 
    short last_len(rand() % 15 + 10); // random from 10 to 25 
    std::string first;
    std::string last;

    while (first_len > 0){
        first += alphabet[rand() % 25];
        first_len--;
    }

    while (last_len > 0){
        last += alphabet[rand() % 25];
        last_len--;
    }
    
    first += " ";
    return first.append(last);

}

int generate_id(){
    return rand() % 100000;
}

static std::string dest_filename = "";
static int num_people = 0;

int main(int argc, char* argv[]){
    
    if (argc < 2){
        usage();
        return 1;
    }
    
    if (argc >= 3){
        num_people = atoi(argv[2]); 
    }

    dest_filename = argv[1];
    
    // make addressbook
    AddressBook addressbook;

    
    // initialize rand
    srand(time(NULL));

    while (num_people > 0) {
        Person* person = addressbook.add_people();

        person->set_name(generate_name());
        person->set_id(generate_id());
        std::cout << "Person #" << person->id() << " - " << person->name() << std::endl;

        num_people--;
    }
    
    // write addressbook itself, rather than the people, to the file
    std::fstream dest_file(dest_filename, std::ios::out | std::ios::trunc | std::ios::binary);

    if (!addressbook.SerializeToOstream(&dest_file)){
        std::cerr << "Failed to write to dest_file: " << dest_filename << std::endl;
        return 1;
    }

    return 0;
}
