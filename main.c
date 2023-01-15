#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdbool.h>
#include <assert.h>
#include <string.h>

int    main(void)
{

    char *output;
    char *expect;
    //test case:1 output_line("hello") -> [hello]
    //test case:2 output_line("hello\nworld") -> [hello]
    //test case:3 output_line("") -> []
    //test case:4 output_line("\n") -> []

//test case 1
    expect = "hello";
    output = output_line("hello");
    printf("test case 1 : str = [%s]\n",output);
    assert(strcmp(output,expect) == 0);

//test case 2
    expect = "hello";
    output = output_line("hello\nworld");
    printf("test case 2 : str = [%s]\n",output);
    assert(strcmp(output,expect) == 0);

//test case 3
    expect = "";
    output = output_line("");
    printf("test case 3 : str = [%s]\n",output);
    assert(strcmp(output,expect) == 0);


assert(true);
    return (0);
}


/*
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdbool.h>

int    main(void)
{
    char *txt;
	int fd;

	fd = open("text.txt", O_RDONLY);
    txt = "a";
    txt = get_next_line(fd);
    printf("[Return:] Line: %s\n",txt);
//    printf("%p\n", txt);
    free(txt);
    system("leaks a.out");
    return (0);
}
int    main(void)
{
    // "ctl + c"押すまで読み込まれ続けます
    char *txt;
	int fd;

	fd = open("text.txt", O_RDONLY);
    while(true)
    {
       	printf("start gnl\n");
        txt = get_next_line(fd);
        printf("[Return:] Line: %s\n",txt);
        printf("%p\n", txt);
        if (txt == NULL)
            break;
        free(txt);
    }
   	printf("after while\n");
    system("leaks a.out");
    return (0);
}

int main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while ()
 	get_next_line(fd);
	return (0);
}*/