#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char **argv)
{
    int mode;
    int mode_u;
    int mode_g;
    int mode_o;
    char *path;
    if(argc<3)
    {
        printf("Error\n");
        exit(0);
    }
    mode=atoi(argv[1]);
    if(mode>777||mode<0)
    {
        printf("Error\n");
        exit(0);
    }
    mode_u=mode/100;
    mode_g=(mode%100)/10;
    mode_o=((mode%100)%10);
    mode=(mode_u*8*8)+(mode_g*8)+mode_o;
    path=argv[2];
    if(-1==chmod(path,mode))
    {
        printf("Error\n");
        exit(0);
    }
    else
    {
        printf("success\n");
    }
    return 0;
}
