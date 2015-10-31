#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_lib.h"





void hashcreate(){
    
    printf("Dwse to onoma tou arxeiou\n");
    scanf("%s",&arxeio1);
    hash_file=fopen(arxeio1,"r");
    int dif_ids;
if (hash_file==NULL)
      printf( "The file 'arxeio' was not opened\n" );
else{
    if (strcmp(arxeio1,"arxeio1.txt")==0){
      printf( "The file 'arxeio1' was opened\n" );
    }
    else if (strcmp(arxeio1,"arxeio3.txt")==0){
        printf( "The file 'arxeio3' was opened\n" );
    }
      fscanf(hash_file,"%d",&dif_ids);
      //printf("ta dif_ids einai %d\n", dif_ids);
      HashSize=2*dif_ids;
      hashtab=malloc(HashSize*sizeof(struct customer));
      x=0;
      for (i=0;i<HashSize;i++)
         strcpy(hashtab[i].id,"");
      
      while(fgetc(hash_file)!=EOF)
      {
          
          
          fscanf(hash_file,"%[^;]",code);
          printf("o kwdikos einai %s\n",code);
          
          gen=hashfunction1(code);
          printf("o ari8mos apo thn has function einai %d\n\n",gen);
          
          flag1=0;// flag pou elegxei an uparxei neos kwdikos, dld an h 8esh tou hasthtab einai kenh
          flag2=0;//elegxos sugrousewn
          
          
          while (flag1==0){
              
              if (strcmp(hashtab[gen].id,"")==0){
                  flag1=1;
                  if (flag2==1){
                      sug++;
                  }
                  store_new_id();
                  fseek (hash_file , 1 , SEEK_CUR );
                  }
          
              else if (strcmp(hashtab[gen].id,code)==0){
                   //asdf();
                  flag1=1;
                  store_same_id();
                  fseek (hash_file , 1 , SEEK_CUR ); 
                   
              }
                 
              else{
                  gen=gen+2;
                  if(gen>HashSize)
                  gen=0;
                  flag2=1;
                  
              }
          }
          
   }
      fclose(hash_file);
      
}



}


