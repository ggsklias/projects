#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"


void store_new_id(){
          
        strcpy(hashtab[gen].id,code);
        //etos_f=5;
        fseek (hash_file , 1 , SEEK_CUR );
        //deikths=fgetc(hash_file); //diavazei to erwthmatiko sto arxeio kai proxwraei o deikths gia na diavasoume etos
        fscanf(hash_file,"%d",&etos_f);
        //printf ("To etos einai %d\n",etos_f);
        hashtab[gen].head_year=(struct year*)malloc(sizeof (struct year));
        hashtab[gen].head_year->etos=etos_f;
        hashtab[gen].head_year->next_year=NULL;
        //printf("To etos ths domhs einai %d\n\n",hashtab[gen].head_year->etos);
        
    
        fseek (hash_file , 1 , SEEK_CUR );
        //deikths=fgetc(hash_file);
        fscanf(hash_file,"%d",&day_of_year_f);
        hashtab[gen].day_of_year=day_of_year_f;
        //printf ("H hmera einai %d\n",day_of_year_f);
        //printf("H hmera ths domhs einai %d\n\n",hashtab[gen].day_of_year);
    
        fseek (hash_file , 1 , SEEK_CUR );
        //deikths=fgetc(hash_file);
        fscanf(hash_file,"%f",&lefta);
        hashtab[gen].price=lefta;
        //printf("Ta lefta ths domhs einai %f\n\n",hashtab[gen].price);
        hashtab[gen].head_year->whole_price=lefta;
    
        hashtab[gen].head_year->metrhths_etous=1;
    
        hashtab[gen].head_year->next_year=NULL;
        fseek (hash_file , 1 , SEEK_CUR );
        //deikths=fgetc(hash_file); //kounaw ton deikti gia na parw to afm
        fscanf(hash_file,"%d",&afm_f);
        //printf ("To afm einai %d\n",afm_f);
        hashtab[gen].afm=afm_f;
        //printf("To afm ths domhs einai %d\n\n",hashtab[gen].afm);
        hashtab[gen].head=(struct product*)malloc(sizeof(struct product));
        temp_pointer_1=hashtab[gen].head;// krataw to pou deixnei to hashtab[a].head giati meta 8a allaksei
    
        hashtab[gen].use=1;
        deikths=fgetc(hash_file);
        first_p=0;
        
        counter=0;
        
        while (deikths!=EOL&&deikths!=EOF){
            //counter++;
            //printf("O counter einai %d\n",counter);
        //printf("to N prin einai %d\n\n",HashSize);
        fscanf(hash_file,"%[^;\n]",product_f);
        //printf("to N meta einai %d\n\n",HashSize);
        //printf("To product pou saved einai %s\n\n",product_f);
        hashtab[gen].head=temp_pointer_1;//epanaferw thn arxikh timh sto hashtab[a].head
                        
        if (first_p==0)//h flag afth einai mhden otan diavazw to prwto proion ths kartas
              {  //an einai to prwto kanw ta parakatw
                  if (product_f[0]=='P')
                      {  
                         strcpy(hashtab[gen].max_product,product_f);//apothikevw to prwto proion san max
                         hashtab[gen].product_counter=1;
                         hashtab[gen].head->metrhths_product=1;//einai to prwto pou diavazw ara metrhths_product=1
                         hashtab[gen].maxp=1;
                      }                
                               
                         strcpy(hashtab[gen].head->product_id,product_f);//metaferw afto pou diavasa sto hashtab[a].head->product_id
                               
                             // printf("to proion %s agorasthke %d fores\n",kwdikos_proiontos,hashtab[a].head->metrhths_product);
                         hashtab[gen].head->next=NULL;//ypothetw pws dn yparxei allo proion meta opote o next den deixnei kapou
                         temp_pointer_1=hashtab[gen].head;//vazw se mia proswrinh metavlhth pou deixnei o head gt pio katw tha alla3ei
                         first_p=1;//apothikevw thn pliroforia oti diavasa to prwto proion
        //printf("prwth egrafh %s\n\n",hashtab[gen].head->product_id);
            //printf("sunolo proiodwn1 %d\n\n",hashtab[gen].product_counter);              
        }
        
        else if (strcmp(product_f,hashtab[gen].head->product_id)==0)//elegxw an o kwdikos pou diavasa einai idios me ton kwdiko pou deixnei o head
                      {  
              if (product_f[0]=='P')
                    { 
                           hashtab[gen].product_counter++;
                           hashtab[gen].head->metrhths_product=hashtab[gen].head->metrhths_product+1;//an einai prosthetw +1 ston metrhth
                                 
                         if (hashtab[gen].head->metrhths_product>hashtab[gen].maxp)
                            {
                              hashtab[gen].maxp=hashtab[gen].head->metrhths_product;
                              strcpy(hashtab[gen].max_product,product_f);
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
                      else if (strcmp(product_f,hashtab[gen].head->next->product_id)==0)//elegxw an o kwdikos pou diavasw einai idios me ton kwdiko pou deixnei o head->next 
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
        //printf ("to gamhdi o deikths einai %c",deikths);
         
        }
        
        hashtab[gen].head=temp_pointer_1;
        
        fseek (hash_file , -1 , SEEK_CUR );
        
    
}
