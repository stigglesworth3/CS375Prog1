To run program1 enter the following commands:
make program1
./program1 *file name that contains string X* *file name that contains string Y* *file name for what the output should be*

this program uses a matrix (2D array) to store the information needed to calculate the LCS, each spot of the matrix holds a "boxy" (see "boxy:" for what that is)
boxy: a struct that contains a string and int variable for the arrow direction and the current length of the LCS

compared to the other 2 programs in this assignment, program1 should run the slowest out of all of them
