#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>

int main(int argc,char* argv[]){

    int m,n,k;
    double *cost,*inventory;
    // file reading
    FILE *f=fopen(argv[1],"r");
    if(!f){
        printf("File is not opened properly");
        return 0;
    }
    fscanf(f,"%d,%d,%d",&m,&n,&k);

    cost=(double **)malloc((n)*sizeof(double *));
    inventory=(double **)malloc((n)*sizeof(double *));

    for(int i=0;i<n;i++){
        cost[i]=(double *)malloc((m)*sizeof(double));
        inventory[i]=(double *)malloc((m)*sizeof(double));
    }

    double temp1,temp2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(f,"%lf,%lf",&temp1,&temp2);
            cost[i][j]=temp1;
            inventory[i][j]=temp2;
        }
    }

    glp_prob *lp;
    lp = glp_create_prob();
    glp_set_prob_name(lp,"Test2");
    glp_set_obj_dir(lp, GLP_MIN);// minimize the objective objective

    return 0;
}