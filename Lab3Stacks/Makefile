#Amelia Hampford
#agh3ft
#Makefile PostLab10

CXX	= clang++
CXXFLAGS = -std=c++0x

OFILES = postfixCalculator.o stack.o stackNode.o testPostfixCalc.o
.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

clean:
	/bin/rm -f *.o *~
