#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"

int compare_use(struct max_customer_1 *p_a, struct max_customer_1 *p_b)
{
  
 

 
  if  (p_a->use_1 < p_b->use_1)
      return -1;
  else if (p_a->use_1 > p_b->use_1)
      return 1;
  else
      return 0;
  
}
int compare_price(struct max_customer_1 *p_c, struct max_customer_1 *p_d)
{
  
 

  
  if  (p_c->t_price_1 < p_d->t_price_1)
      return -1;
  else if (p_c->t_price_1 > p_d->t_price_1)
      return 1;
  else
      return 0;
  
}

void used_cards(){
    //N=1258;
    max_hashtab_1=malloc(HashSize*sizeof(struct max_customer_1));
    
    
    //printf("To x einai %d\n",x);
    for (i=0;i<HashSize;i++)
         strcpy(max_hashtab_1[i].max_id_1,"empty");
    
    for (i=0;i<HashSize;i++){
        
    if (strcmp(hashtab[i].id,"")!=0){
        
        strcpy(max_hashtab_1[i].max_id_1,hashtab[i].id);
        max_hashtab_1[i].use_1=hashtab[i].use;
        max_hashtab_1[i].t_price_1=hashtab[i].price;
        
    }
    
    
    
    }
    printf("Plhktrologhste poses kartes me thn megaluterh suxnothta 8elete na emfanistoune\n\n");
    scanf("%d",&x);
    
    qsort(max_hashtab_1,HashSize,sizeof(struct max_customer_1),compare_use);
    x=630-x;
    for (i=630;i>x;i--){
        printf("h %dh karta einai h %s kai exei suxnothta %d \n",631-i,max_hashtab_1[i].max_id_1,max_hashtab_1[i].use_1);   
        
    }
    x=0;
    //free(max_hashtab_1);
    
    for (i=0;i<HashSize;i++){
        
    if (strcmp(hashtab[i].id,"")!=0){
        
        strcpy(max_hashtab_1[i].max_id_1,hashtab[i].id);
        max_hashtab_1[i].use_1=hashtab[i].use;
        max_hashtab_1[i].t_price_1=hashtab[i].price;
        
    }
    }
    
    printf("Plhktrologhste poses kartes me thn megaluterh timh 8elete na emfanistoune\n\n");
    scanf("%d",&x);
    x=1171-x;
    //N=1258;
    qsort(max_hashtab_1,HashSize,sizeof(struct max_customer_1),compare_price);
    for (i=1171;i>x;i--)
    {
        
        printf("h %dh karta einai h %s kai exei max timh %f \n",1172-i,max_hashtab_1[i].max_id_1,max_hashtab_1[i].t_price_1);   
        
    }
    
    free(max_hashtab_1);
    
    

}
