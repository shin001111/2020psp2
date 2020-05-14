#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double var,double ave,double ave2);
int nr = 1;
double ave = 0;
double ave2 = 0;
double var = 0;

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        ave = ave_online(val,ave);
        ave2 = ave_online(val*val,ave2);
        var = var_online(val,var,ave,ave2);
        nr++;

    }

printf("%lf\n",ave);
printf("%lf\n",var);


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave)
{
return  ( ( ( nr - 1 ) * ave ) / nr ) + ( val / nr );
}

double var_online(double val,double var,double ave,double ave2)
{
return 0;
}