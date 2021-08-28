## Protobuf Testing

Just trying out the examples from Google's protobuf.

Goal was to make a python writer and a cpp reader and observe how it works. Ended up with python reader & writer, cpp reader and writer.

Just generates random data to put in to a given filename etc, simple stuff.

### Usage

```
read_addressbook.py FILENAME

Where FILENAME is a required name of file to read from
```

```
write_addressbook.py DEST_ADDRESSBOOK [N_PEOPLE]

Where DEST_ADDRESSBOOK is a required name of file to write addressbook to, and N is optional number of people
```

```
Usage: ./write_book DEST_ADDRESSBOOK_FILENAME [N]

Where DEST_ADDRESSBOOK_FILENAME is a required filename of an addressbook file and N is an optional number of records to write (default is 10)
```

```
Usage: ./read_book ADDRESSBOOK_FILENAME

Where ADDRESSBOOK_FILENAME is a required filename of an addressbook file
```
