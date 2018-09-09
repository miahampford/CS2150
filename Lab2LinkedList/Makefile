#Amelia Hampford
#agh3ft
#Makefile PostLab10

CXX	= clang++
CXXFLAGS = -std=c++0x

OFILES = List.o ListItr.o ListNode.o ListTest.o
.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

List.o: ListItr.o ListNode.o
	$(CXX) -c List.cpp

clean:
	/bin/rm -f *.o *~
