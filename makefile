PROG1 = program1
PROG2 = program2
PROG3 = program3
FLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(PROG1) $(PROG2)
$(PROG1): $(PROG1).o
	g++ $(FLAGS) $(PROG1).o -o $(PROG1)
$(PROG2): $(PROG2).o
	g++ $(FLAGS) $(PROG2).o -o $(PROG2)
$(PROG1).o: $(PROG1).cpp
	g++ $(FLAGS) -c $(PROG1).cpp -o $(PROG1).o
$(PROG2).o: $(PROG2).cpp
	g++ $(FLAGS) -c $(PROG2).cpp -o $(PROG2).o
clean:
	rm -rf $(PROG1)
	rm -rf $(PROG2)
	rm -rf *.o
run: all
	./$(PROG1) filex.txt filey.txt output1.txt
	./$(PROG2) filex.txt filey.txt output2.txt
run1: $(PROG1)
	./$(PROG1) filex.txt filey.txt output1.txt
run2: $(PROG2)
	./$(PROG2) filex.txt filey.txt output2.txt
memcheck: all
	valgrind -v --leak-check=full ./$(PROG1)
