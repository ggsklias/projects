#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proj_lib.h"


void delete_card(){
    printf("Dwse ton kwdiko ths kartas pros diagrafh\n");
    scanf("%s",&code);
    printf ("O kwdikos einai %s",code);
    gen=hashfunction1(code);
    printf("Hashfunction code %d",gen);
    
    flag1=0;
    while (flag1==0){
        if (strcmp(hashtab[gen].id,code)==0)
        {
            strcpy(hashtab[gen].id,"Deleted");
            hashtab[gen].day_of_year=0;
            hashtab[gen].afm=0;
            hashtab[gen].price=0;
            hashtab[gen].head=NULL;
            hashtab[gen].maxp=-1;
            hashtab[gen].head_year=NULL;
            strcpy(hashtab[gen].max_product,"Zero");
            hashtab[gen].product_counter=0;
            printf("H karta %s diagrafhke epituxws",code);
            flag1=1;
        }
        else if(strcmp(hashtab[gen].id,code)=="")
        {
            printf("H karta %s den uparxei",code);
            flag1=1;
        }
        
            
    }
}
