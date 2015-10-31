#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proj_lib.h"

void delete_f(){
    
    printf("Dwse to onoma tou arxeiou\n");
    scanf("%s",&delete_c);
    delete_file=fopen(delete_c,"r");
    int k;
    
      
if (delete_file==NULL)
      printf( "The file 'arxeio1' was not opened\n" );
else{
      printf( "The file 'arxeio1' was opened\n" );
      //printf("To N einai %d",HashSize);
      fscanf(delete_file,"%d",&delete_number);
      printf ("8a diagrafoun %d kataxwrhseis\n\n", delete_number);
      fseek (delete_file,4,SEEK_CUR);
      for(k=0;k<delete_number;k++){
            fseek(delete_file,1,SEEK_CUR);
            fscanf(delete_file,"%s",code);
            
            printf("0 %dos kwdikos pou tha ginei prospa8eia na diagrafei einai: %s \n\n",k+1,code);
            
            gen=hashfunction1(code);
            printf("to gen einai %d ",gen);
            
          flag1=0;
         
          while (flag1==0){
              
              if (strcmp(hashtab[gen].id,code)==0){
                  printf("O kwdikos pou 8a diagrafei antistoixei sthn 8esh %d \n\n",gen);
                  strcpy(hashtab[gen].id,"Deleted");
                  hashtab[gen].day_of_year=0;
                  hashtab[gen].afm=0;
                  hashtab[gen].price=0;
                  hashtab[gen].head=NULL;
                  hashtab[gen].maxp=-1;
                  hashtab[gen].head_year=NULL;
                  strcpy(hashtab[gen].max_product,"EEEE");
                  hashtab[gen].product_counter=0;
                  flag1=1;
                  
                  }
          
              else if (strcmp(hashtab[gen].id,"")==0){
                  flag1=1;
                  printf("den vrethike o kwdikos\n");
                 
              }
              else{
                gen=gen+2;
                if(gen>HashSize)
                gen=0;
                }
                 
          }
          
      }
      free(hashtab);
      fclose(delete_file);
}
}
      
      

    
    

