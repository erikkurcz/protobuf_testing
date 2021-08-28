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

### Example

Write with python:
```
./write_addressbook.py ab1 5
Person #78571 - rmvhnfmi nnyjutlruleosujptyxhhaqfr
Person #10624 - hjaclhpb ybbxvqgxpladhitzpfntxed
Person #5154 - nvwbi mhljskbwkomubz
Person #1008 - qwgegggyjraellc yxvdegqcm
Person #54553 - nteghaizmszs abpexhfivsrhwcbdxjeh
```

Read with cpp:
```
./read_book.tsk ab1
Person #78571 - rmvhnfmi nnyjutlruleosujptyxhhaqfr
Person #10624 - hjaclhpb ybbxvqgxpladhitzpfntxed
Person #5154 - nvwbi mhljskbwkomubz
Person #1008 - qwgegggyjraellc yxvdegqcm
Person #54553 - nteghaizmszs abpexhfivsrhwcbdxjeh
```

Write with cpp:
```
./write_book.tsk ab2 4
Person #22159 - uatyjrvqdd rgxvdichyakcsgwwuc
Person #58008 - gwhfjybafg rlgprqtyqtjspqpontxljg
Person #9283 - rrrtwynlfdd wyepvoklhacwvd
Person #84554 - rxxlqqiprv dycixbnnyexmnapkyst
```

Read with python:
```
./read_addressbook.py ab2
Person #22159 - uatyjrvqdd rgxvdichyakcsgwwuc
Person #58008 - gwhfjybafg rlgprqtyqtjspqpontxljg
Person #9283 - rrrtwynlfdd wyepvoklhacwvd
Person #84554 - rxxlqqiprv dycixbnnyexmnapkyst
```
