#include <stdio.h>
#include <stdlib.h>
#include "proj_lib.h"



int choice;
int main() {
   /* Open for read (will fail if file "data" does not exist) */
     
    
    while ( (choice=menu()) != 0){
       switch (choice){

              case 1:
                   hashcreate();
                   break;
              case 2:
                   delete_f();
                   break;
              case 3:
                   collision();
                   break;
              case 4:
                   delete_card();
                   break;
              case 5:
                   delete_whole();
                   break;
              case 6://100 most used and 100 biggest
                   used_cards();
                   break;
              case 7://eksoda mias oikogeneias kata thn eisodo enos ari8mou kartwn
                  eksoda();
                  break;
              case 8://cards visit per year
                  card_visits();
                  break;
              case 9://100 megaluteres kartes taksinomhmenes kata f8inousa
                   biggest100Cards();
                  break;

              default:
                     printf(" dwse lew ");
                     break;
                     }
    }

       return (EXIT_SUCCESS);
}

    
    int menu(void){            /*emfanizei to menu epilogwn,kai epistrefei ton akeraio pou dinei o xrhsths otan kanei epilogh*/
     
     printf("choice 1: Eisagete arxeio agorwn \n\n");
     printf("choice 2: Eisagete arxeio diagrafwn \n\n");
     printf("choice 3: Ari8mos sugrousewn \n\n");
     printf("choice 4: Diagrafh sugekrimenhs kartas \n\n" );
     printf("choice 5: Diagrafh olwn twn kartwn tou prwtou arxeiou \n\n");
     printf("choice 6: Emfanish twn X poio xrhsimopoihmenwn proiontwn kai twn Y megaluterwn \n\n");
     printf("choice 7: Ta eksoda mias oikogeneias me thn eisodo mias kartas \n\n");
     printf("choice 8: Ari8mos episkeyewn ena etos X \n\n");
     printf("choice 9: Emfanish twn 100 megaluterwn kartwn to etos X \n\n");
     printf("Give your choice\n");
     scanf("%d" , &k);
     return k;
     }






