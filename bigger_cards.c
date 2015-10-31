#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"



/*int porownaj(struct max_customer *p_e,struct max_customer *p_f)
{
  
  //struct max_customer *pkt_a = p_e;
  //struct max_customer *pkt_b = p_f;

 
  if (p_e->t_price > p_f->t_price) 
      return -1;
  else if (p_e->t_price < p_f-> t_price) 
      return 1;
  else
      return 0;

 
  
}*/

int porownaj(const void *a, const void *b) 
{ 	
    struct max_customer *ia = (struct max_customer *)a;
    struct max_customer *ib = (struct max_customer *)b;
    if (ia->t_price > ib->t_price) 
      return -1;
    else if (ia->t_price < ib-> t_price) 
      return 1;
    else
      return 0;
		
}
void fyear();

void biggest100Cards(){
   
    printf("---Finding the 100 bigger cards---\n\n");
    printf("Please give the year:\n");
    scanf("%d",&etos_big);
    
    //N=1258;
    max_hashtab=malloc(HashSize*sizeof(struct max_customer));
    if(max_hashtab == NULL)
      {
                printf( "out of memory\n");
      }
    //printf ("To n einai %d",HashSize);
    for (i=0;i<HashSize;i++){
        strcpy(max_hashtab[i].max_id,"");
    }
    for (i=0;i<HashSize;i++){
        flag_max=0;
        while(flag_max==0){
            if(strcmp(hashtab[i].id,"")==0){
                strcpy(max_hashtab[i].max_id,"EMPTY"); 
                flag_max=1;
            }
            
            else{
                fyear();
                flag_max=1;
            }
            
        }
        
    }
   
    qsort(max_hashtab,HashSize,sizeof(struct max_customer),porownaj);
    
    
    printf("Oi 100 megaluteres kartes to etos %d einai: \n\n",etos_big);     
    
    for(j=0;j<100;j++)
    {
        
        printf("%d:H karta (%s) exei total timh: %f \n",j+1,max_hashtab[j].max_id,max_hashtab[j].t_price);
        
    }
    
    free(max_hashtab);
    
    
 
    
}


void fyear(){
   
    temp_year=hashtab[i].head_year;
    if (hashtab[i].head_year->etos==etos_big){
        max_hashtab[i].t_price=hashtab[i].head_year->whole_price;
        strcpy(max_hashtab[i].max_id,hashtab[i].id);
       
    }
    else{
        flag_max1=0;
        while(flag_max1==0){
            if(hashtab[i].head_year->next_year==NULL){
                max_hashtab[i].t_price=0;
               
                flag_max1=1;
            }
            else if(hashtab[i].head_year->next_year->etos==etos_big){
                max_hashtab[i].t_price=hashtab[i].head_year->next_year->whole_price;
                strcpy(max_hashtab[i].max_id,hashtab[i].id);
                
                flag_max1=1;
            }
            else{
                hashtab[i].head_year=hashtab[i].head_year->next_year;
            }
        }
    }
    hashtab[i].head_year=temp_year;
}


