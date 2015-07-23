#include<stdio.h>
#include<unistd.h>
#include<Linux/limits.h>

void my_error(const char *err_string,int line)
{
    fprintf(stderr,"*line:%d ",line);
    perror(err_string);
    exit(1);
}
int main(int argc,char **argv)
{
    char *buf(PATH_MAX+1);
    if(argc<2)
    {
        printf("my_cd<target path");
        exit(0);
    }
    if(chdir(argv[1])<0)
    {
        my_err("getcwd",_LINE_);
    }
    printf("%s\n",buf);
    return 0;
}
