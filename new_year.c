#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"



void new_year(){
    
    hashtab[gen].use++;
    hashtab[gen].head_year->next_year=(struct year*)malloc(sizeof(struct year));
    hashtab[gen].head_year->next_year->etos=etos_same;
    fseek (hash_file , 1 , SEEK_CUR );
    
    fscanf(hash_file,"%d",&day_of_year_f);
    fseek (hash_file , 1 , SEEK_CUR );
    fscanf(hash_file,"%f",&lefta);
    fseek (hash_file , 1 , SEEK_CUR );
    
    hashtab[gen].price+=lefta;
    hashtab[gen].head_year->next_year->whole_price=lefta;
    hashtab[gen].head_year->next_year->metrhths_etous=1;
    hashtab[gen].head_year->next_year->next_year=NULL;
    
    
    
    fscanf(hash_file,"%d",&afm_f);
   
    
    product_reg_same_card();
    
}
