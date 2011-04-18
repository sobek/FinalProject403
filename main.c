#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
compile and run instructions:

compile with:
gcc main.c -pthread

run with:
/.a.out /path/to_file/to_be_used
(I decided to just use this as an input)
*/

//prototypes
void my_read_file(char *file_address_from_argv);




//2 dynamic arrays dependent on what the file inputs are
//will store the node data and edge information respectively
/*
char *node;
char *edge;
*/

//my first attempt at reading a file in.  This seems to work so far.
int main(int argc, char *argv[])
{

    my_read_file(argv[1]);

    return 0;
}

//reads the file into here.  this file breaks it down into the nodes and edges I need.
void my_read_file(char *file_address_from_argv)
{
    int c;
    long file_size;
    char *array_for_file;
    FILE *input_file;
    input_file = fopen(file_address_from_argv, "r");
    if((input_file) == NULL)
    {
        printf("Please run again using the format: \"./a.out /path/to/input/file\" where \"./a.out\" is the name of executable, and the path is valid\n");
        exit(-1);
    }

    //read file into an array in memory
    size_t result;
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    array_for_file = (char*)malloc(sizeof(char)*file_size);
    fread(array_for_file,1,file_size,input_file);

    //close the file, should be in mem at this point.
    fclose(input_file);

    printf("%s", array_for_file);
}
