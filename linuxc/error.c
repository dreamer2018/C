#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
void my_perror(char *str)
{
    printf("%s:%s\n", str,strerror(errno));
}

int main()
{
    int fd=10;
    int ret = close(fd);
    my_perror("lala");
}

