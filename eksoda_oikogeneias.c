#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"

void eksoda(){
    
    printf ("Dwse ton kwdiko\n\n");
    scanf("%s",&code);
    gen=hashfunction1(code);
    

    
    
    flag1=0;
    while (flag1==0){
        if (strcmp(hashtab[gen].id,code)==0){
             printf("Ta eksoda ths oikogeneias einai %f \n\n",hashtab[gen].price);
            flag1=1;
        }  
            
        else if(strcmp(hashtab[gen].id,"")==0){
            printf ("H karta den vre8hke\n");
            flag1=1;
                
        }
        else{
            gen=gen+2;
            if(gen>HashSize)
               gen=0;
        }
}
}
