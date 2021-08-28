HERE=$(shell pwd)
CPP_SRC=$(HERE)/cpp_src
PYTHON_SRC=$(HERE)/python_src
PROTO_FILES="addressbook.proto"

proto:
	protoc -I=$(HERE) --python_out=$(PYTHON_SRC) $(HERE)/$(PROTO_FILES)
	protoc -I=$(HERE) --cpp_out=$(CPP_SRC) $(HERE)/$(PROTO_FILES)

all: # for the cpp files themselves
	g++ -I $(HERE) -o read_book.tsk reader.cpp $(CPP_SRC)/addressbook.pb.cc -lprotobuf
	g++ -I $(HERE) -o write_book.tsk writer.cpp $(CPP_SRC)/addressbook.pb.cc -lprotobuf


