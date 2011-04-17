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

    //my_read_file(argv[1]);

    if(argv[1] == NULL)
    {
        printf("Please run again using the format: \"./a.out /path/to/input/file\" where \"./a.out\" is the name of executable\n");
        return -1;

    }else
    {
        my_read_file(argv[1]);
    }

    return 0;
}

//this needs to process the file into usable pieces
void my_read_file(char *file_address_from_argv)
{
    printf("Hello in fn!\n");
    FILE *input_file;
    input_file = fopen(file_address_from_argv, "r");
    int c;

    while(c != EOF)
    {
    c = fgetc(input_file);
    putchar(c);
    }



    fclose(input_file);
}
