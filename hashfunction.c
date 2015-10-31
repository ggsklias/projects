#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proj_lib.h"


int hashfunction1(char code[26])
{
int j=0;   
int temp[26];
int module;
temp[0]=1;
     for (i=0;i<25;i++)
  { j++;
         temp[j] = temp[j - 1] * 33 ^ code[i];

  }
  if (temp[j]<0)
  temp[j]=temp[j]*(-1);
module=HashSize+1;
a=temp[j]%module;
return a;
}
/*unsigned hashfunction1(char *code)
{
unsigned hashval;

for (hashval = 0; *code != '\0'; code++)
hashval = *code + 31 * hashval;
return hashval % N;
}*/

/*
int hashfunction1(char code[26]){
int j=0;
int hash[26];
int module;
hash[0]=1;
     for (i=0;i<25;i++)
  { j++;
         hash[j] = hash[j - 1] * 33 ^ code[i];
         
  }   
if (hash[j]<0)
hash[j]=hash[j]*(-1);
module=N+1;                       
a=hash[j]%module;
return a;
}*/