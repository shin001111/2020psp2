#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA{
    int gender;double heights;double ID;
} data[15];

int main(void)
{
    char fname_1[FILENAME_MAX], fname_2[FILENAME_MAX];
    char buf[256];
    FILE* fp_1;
    FILE* fp_2;
    int gender;
    double heights;
    double ID;
    double search;
    int i;
    int nodata=0;

    struct DATA;

    printf("input the filename of sample heights:");
    fgets(fname_1,sizeof(fname_1),stdin);
    fname_1[strlen(fname_1)-1] = '\0';
    printf("input the filename of sample IDs:");
    fgets(fname_2,sizeof(fname_2),stdin);
    fname_2[strlen(fname_2)-1] = '\0';

    fp_1 = fopen(fname_1,"r");
    if(fp_1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fp_2 = fopen(fname_2,"r");
    if(fp_2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i = 0;

    while(fgets(buf,sizeof(buf),fp_1) != NULL){
        sscanf(buf,"%d,%lf",&gender,&heights);
        data[i].gender = gender;
        data[i].heights = heights;
        i++;
    }

    i = 0;

    while(fgets(buf,sizeof(buf),fp_2) != NULL){
        sscanf(buf,"%lf",&ID);
        data[i+1].ID = ID;
        i++;
    }    
    
    printf("Which ID's data do you want?: ");
    scanf("%lf",&search);

    for(i = 1;i < 15;i++){
        if(data[i].ID == search){
            printf("ID :%.0lf\n",data[i].ID);

            if(data[i].gender == 1){
                printf("gender :Male\n");
            }
            else{
                printf("gender :Female\n");
            }

            printf("heights :%.2lf\n",data[i].heights);
        }
        else{
            nodata++; 
        }
    }

    if(nodata == 14){
        printf("No data");
    }

    if(fclose(fp_1) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    if(fclose(fp_2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;
}