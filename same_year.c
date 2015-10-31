#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"



void same_year(){
    
    hashtab[gen].use++;
    //printf("H kardta %s exei xrhsimopoihsh %d \n\n",hashtab[gen].id,hashtab[gen].use);
    hashtab[gen].head_year->metrhths_etous++;
    //printf ("o metrhths auksh8hke kai einai %d",hashtab[gen].head_year->metrhths_etous);
    fseek (hash_file , 1 , SEEK_CUR );
    fscanf(hash_file,"%d",&day_of_year_f);
    fseek (hash_file , 1 , SEEK_CUR );
    fscanf(hash_file,"%f",&lefta);
    hashtab[gen].head_year->whole_price+=lefta;
    hashtab[gen].price += lefta;    
    
    fseek (hash_file , 1 , SEEK_CUR );
    fscanf(hash_file,"%d",&afm_f);
        
    product_reg_same_card();
}
