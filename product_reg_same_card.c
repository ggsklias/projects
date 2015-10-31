#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"

void product_reg_same_card(){
   
    temp_pointer_1=hashtab[gen].head;// krataw to pou deixnei to hashtab[a].head giati meta 8a allaksei
    
        deikths=fgetc(hash_file);
        
        
        
        
        //while ((fseek(hash_file,1,SEEK_CUR)!=EOL)&&(fseek(hash_file,1,SEEK_CUR)!=EOF)){
        while (deikths!=EOL&&deikths!=EOF){
        fscanf(hash_file,"%[^;\n]",product_f);
        //printf("To product pou saved einai %s\n\n",product_f);
        hashtab[gen].head=temp_pointer_1;//epanaferw thn arxikh timh sto hashtab[a].head
                        
       
        
         if (strcmp(product_f,hashtab[gen].head->product_id)==0)//elegxw an o kwdikos pou diavasa einai idios me ton kwdiko pou deixnei o head
                      {  
              if (product_f[0]=='P')
                    { 
                           hashtab[a].product_counter++;
                           hashtab[a].head->metrhths_product=hashtab[a].head->metrhths_product+1;//an einai prosthetw +1 ston metrhth
                                 
                         if (hashtab[a].head->metrhths_product>hashtab[a].maxp)
                            {
                              hashtab[a].maxp=hashtab[a].head->metrhths_product;
                              strcpy(hashtab[a].max_product,product_f);
                            }
                          }//printf("sunolo proiodwn2 %d\n\n",hashtab[gen].product_counter);
                             // printf("to proion %s agorasthke %d fores\n",kwdikos_proiontos,hashtab[a].head->metrhths_product);
                               //printf("to %d maxp einai:%d\n",a,hashtab[a].maxp);
                        }
         else//an den einai idios
             {  flag3=0;
                            
                while (flag3==0)//elegxos gia to an vrethike proion pou yparxei h an eftasa sthn teleftaia thesh pou yparxei apothikevmeno proion
                    {
                      if (hashtab[gen].head->next==NULL)//elegxw an eftasa sthn teleftaia thesh pou yparxei apothikevmeno proion 
                         {  
                                    
                          flag3=1;//apothikefsh ths pliroforias pws eftasa sthn teleftaia thesh pou yparxei apothikevmeno proion
                          hashtab[gen].head->next=(struct product*)malloc(sizeof(struct product));//desmefsh xwrou
                          strcpy(hashtab[gen].head->next->product_id,product_f);//apothikefsh tou kwdikou pou diavasthke
                          if (product_f[0]=='P')
                            {                                   
                                hashtab[gen].product_counter++;
                                hashtab[gen].head->next->metrhths_product=1;//efoson einai prwth fora pou diavazetai to proion afto kane ton metrhth 1
                            }
                          //printf("sunolo proiodwn3 %d\n\n",hashtab[gen].product_counter);
                             //     printf("to proion %s agorasthke %d fores\n",kwdikos_proiontos,hashtab[a].head->next->metrhths_product);
                               hashtab[gen].head->next->next=NULL;//ypothetw pws dn yparxei allo proion meta opote o next den deixnei kapou
                         }
                        else if (strcmp(product_f,hashtab[a].head->next->product_id)==0)//elegxw an o kwdikos pou diavasw einai idios me ton kwdiko pou deixnei o head->next 
                           {    
                             if (product_f[0]=='P')
                              { 
                                hashtab[gen].product_counter++;
                                hashtab[gen].head->next->metrhths_product=hashtab[gen].head->next->metrhths_product+1;//prosthetw +1 ston metrhth
                                if (hashtab[gen].head->next->metrhths_product>hashtab[gen].maxp)
                                  {
                                    hashtab[gen].maxp=hashtab[gen].head->next->metrhths_product;
                                    strcpy(hashtab[gen].max_product,product_f);
                                  }
                                //printf("sunolo proiodwn4 %d\n\n",hashtab[gen].product_counter);
                               }
                           // printf("to proion %s agorasthke %d fores\n",kwdikos_proiontos,hashtab[a].head->next->metrhths_product);
                              //  printf("to %d maxp einai:%d\n",a,hashtab[a].maxp);
                               flag3=1;//apothikefsh ths pliroforias pws vrhka ton idio kwdiko 
                            }
                        else//an dn exw ftasei sto teleftaio proion kai an dn exw vrei idio kwdiko mexri stigmhs
                                    hashtab[gen].head=hashtab[gen].head->next;//o head na deixnei ekei pou deixnei o head->next
                                   
                         }
                                    
                         }
        
        //printf("sunolo proiodwn5 %d\n\n",hashtab[gen].product_counter);
        
        deikths=fgetc(hash_file);
        //fseek (hash_file,1,SEEK_CUR);
        
        }
        
        hashtab[gen].head=temp_pointer_1;
        
        
}