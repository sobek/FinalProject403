#include <stdio.h>
#include <stdlib.h>

//prototypes
//pass an address location?
void my_read_file(char *file_address_from_argv);


int main(int argc, char *argv[])
{

    //my_read_file(argv[1]);
readinput:
    if(argv[1] == NULL)
    {
        printf("Please enter a input file.");
        goto readinput;
    }else
    {
        my_read_file(argv[1]);
    }

    return 0;
}


void my_read_file(char *file_address_from_argv)
{
    printf("%s should be the input.", file_address_from_argv);
}
