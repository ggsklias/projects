#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"



void store_same_id(){
    
    //printf("to gen einai %d\n\n",gen);
    //flag_s=0;
    fseek (hash_file , 1 , SEEK_CUR );
    
    fscanf(hash_file,"%d",&etos_same);
    temp_year=hashtab[gen].head_year;
    
    
    //printf ("to N einai %d\n\n",HashSize);
        flag_s=0;
        while (flag_s==0){
        if (hashtab[gen].head_year->etos==etos_same){
            flag_s=1;
            same_year();
            
            //printf("vrhkame idio etos\n");
            hashtab[gen].head_year=temp_year;
            
        }
        else if ((hashtab[gen].head_year->next_year)==NULL){
            
            flag_s=1;
            new_year();
            
            //printf("vrhkame kainourio etos\n");
            hashtab[gen].head_year=temp_year;
        }
        else {
            hashtab[gen].head_year=hashtab[gen].head_year->next_year;
        }
    }
   

    
    hashtab[gen].head_year=temp_year;
    fseek (hash_file , -1 , SEEK_CUR );
   
}
