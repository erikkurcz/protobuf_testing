#!/usr/bin/python3.6
"""
Write addressbook of random names and ids to given filename
"""

from random import randint 
from string import ascii_lowercase as alphabet
import sys

from python_src import addressbook_pb2 as ab


def usage():
    print("write_addressbook.py DEST_ADDRESSBOOK [N_PEOPLE]\n\nWhere DEST_ADDRESSBOOK is a required name of file to write addressbook to, and N is optional number of people")


def generate_name():
    
    first_len = randint(5,15)
    last_len = randint(5,25)

    first = "".join([alphabet[randint(0,25)] for x in range(first_len)])
    last = "".join([alphabet[randint(0,25)] for x in range(last_len)])

    return first + " " + last


def generate_id():
    
    return randint(0,100000)


if __name__ == '__main__':

    if len(sys.argv) < 2:
        usage()
        sys.exit(1)
    
    dest_file = sys.argv[1]
    num_people = 10
    if len(sys.argv) >= 3:
        num_people = int(sys.argv[2])

    addressbook = ab.AddressBook()
    while num_people > 0:
        person = addressbook.people.add()
        person.name = generate_name()
        person.id = generate_id()
        print("Person #" + str(person.id) + " - " + person.name)
        num_people -= 1

    with open(dest_file, 'wb') as dest:
        dest.write(addressbook.SerializeToString())

