#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proj_lib.h"

void delete_whole(){
    int c=0;
    //N=1258;
    for(i=0;i<HashSize;i++){
        if (strcmp(hashtab[i].id,"")!=0){
        hashtab[i].afm=0;
        hashtab[i].day_of_year=0;
        hashtab[i].head=NULL;
        hashtab[i].head_year=NULL;
        strcpy(hashtab[i].id,"");
        hashtab[i].price=0;
        hashtab[i].product_counter=0;
        c++;
        }        
    }
    sug=0;
    printf("H diagrafh twn kartwn egine me epituxia, oi kartes pou diagrafhkan einai %d \n\n", c-1);
    

}
