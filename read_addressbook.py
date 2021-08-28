#!/usr/bin/python3.6
"""
Read addressbook of random names and ids that has been previously generated.
"""

import sys

from python_src import addressbook_pb2 as ab


def usage():
    print("read_file.py FILENAME\n\nWhere FILENAME is a required name of file to read from")


if __name__ == '__main__':

    if len(sys.argv) < 2:
        usage()
        sys.exit(1)
    
    src_file = sys.argv[1]
    
    addressbook = ab.AddressBook()

    with open(src_file, 'rb') as src:
        addressbook.ParseFromString(src.read())

    for person in addressbook.people:
        print("Person #" + str(person.id) + " - " + person.name)
    
