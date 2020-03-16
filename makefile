PROG1 = program1
PROG2 = program2
PROG3 = program3
FLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(PROG1)
$(PROG1): $(PROG1).o
	g++ $(FLAGS) $(PROG1).o -o $(PROG1)
$(PROG1).o: $(PROG1).cpp
	g++ $(FLAGS) -c $(PROG1).cpp -o $(PROG1).o
clean:
	rm -rf $(PROG1)
	rm -rf *.o
run: all
	./$(PROG1) filex.txt filey.txt output1.txt
memcheck: all
	valgrind -v --leak-check=full ./$(PROG1)
