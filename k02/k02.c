#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{   
    double z1,z2;
    double val;
    double vara=5.43, varb=5.5;
    double mua=170.8, mub=169.7;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

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
        z1=(val-mua)/vara;
        L1=p_stdnorm(z1)*L1;
        z2=(val-mub)/varb;
        L2=p_stdnorm(z2)*L2;

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",max_val);
    printf("L_B: %f\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

