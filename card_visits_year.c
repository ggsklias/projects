#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proj_lib.h"

void year();
void card_visits(){
    printf("Give the card id:\n");
    scanf("%s",&code);
    printf("Give the year:\n");
    scanf("%d",&etos_f);
    gen=hashfunction1(code);
    
    
    flag1=0;
    while (flag1==0){
        if (strcmp(hashtab[gen].id,code)==0){
            year();
            printf("H karta %s exei %d visits\n",code,episkeyeis);
            flag1=1;
        }  
            
        else if(strcmp(hashtab[gen].id,"")==0){
            printf ("H karta %s den vre8hke\n", code);
            flag1=1;
                
        }
        else{
            gen=gen+2;
            if(gen>HashSize)
               gen=0;
        }
        
            
        
    }
    
    
}

void year() 
    {
        
        temp_year=hashtab[gen].head_year;
    if (hashtab[gen].head_year->etos==etos_f){
        episkeyeis=hashtab[gen].head_year->metrhths_etous;
    }
    else{
        check=0;
        while(check==0){
            if(hashtab[gen].head_year->next_year==NULL){
                episkeyeis=0;
                check=1;
            }
            else if(hashtab[gen].head_year->next_year->etos==etos_f){
                episkeyeis=hashtab[gen].head_year->next_year->metrhths_etous;
                check=1;
            }
            else{
                hashtab[gen].head_year=hashtab[gen].head_year->next_year;
            }
        }
    }
    hashtab[gen].head_year=temp_year;
    }