#include <stdlib.h>
#include <stdio.h>

#define FILESUCCESS 0
#define FILEOPENFAIL 1

int savefile(char *name_head, int index, char *msg);

int main(int argc, char const *argv[])
{
    char *save_filename_head = "./test_index_make_name_long_long_long_";
    int iterate_idx = 0;

    for(iterate_idx = 0; iterate_idx < 10; iterate_idx++)
    {
        // iterate code for 10 times
        // save file
        printf("Iterate %d\n",iterate_idx);
        savefile(save_filename_head,iterate_idx,"Good");
    } 

    return 0;
}

int savefile(char *name_head, int index, char *msg)
{
    char savename[10];
    FILE *fp = NULL;
    sprintf(savename,"%s%d.txt",name_head,index);
    fp = fopen(savename,"w");
    if(fp == NULL)
    {
        printf("%s open failed!\n",savename);
        return FILEOPENFAIL;
    }
    fprintf(fp,"%s\n",msg);
    fclose(fp);
    return FILESUCCESS;
}

