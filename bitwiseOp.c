#include <stdio.h>
#include "Project1.h"

//shows menu again
void showMenu()
    {
        printf("\nPlease type in  one of the following options: \n");  
        printf("Press '1' to display number in new base\n");
        printf("Press '2' to shift left circular\n");  
        printf("Press '3' to shift right circular\n");
	#ifdef BIN
        printf("Press '4' to display the complement\n");  
	#endif
        printf("Press '5' to display menu\n");
        printf("Press '0' to exit\n");
    }
//displays a number in hexadecimal
void hexNum(unsigned int n)
{
    printf("0x%x\n",n);
}
//displays a number in binary
void binaryNum(unsigned int n)
{ int i=0;
     for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
}

int main() { 
    int choice=0;
    unsigned int num=0,length=0;
    printf("Enter number to convert: ");
    scanf("%d", &num);
	/*#ifdef BIN	//displays number's new base after entered (Optional)
        binaryNum(num);
	#endif
	#ifdef HEX
        hexNum(num);
	#endif*/
    showMenu();
    printf("Enter number for operation (5 for menu): ");
    scanf("%d",&choice);
    while (choice!=0)
    {
        switch (choice) {
            case 1:
        #ifdef BIN
        binaryNum(num);
	#endif
    #ifdef HEX
        hexNum(num);
    #endif

                break;
            case 2:
                num=SLC(num);   //shifts number left
                #ifdef BIN	
        binaryNum(num);
	#endif
	#ifdef HEX
        hexNum(num);
	#endif
                break;
            case 3:
                num=SRC(num);   //shifts number right
                #ifdef BIN	
        binaryNum(num);
	#endif
	#ifdef HEX
        hexNum(num);
	#endif
                break;
            case 4:
                 num=~num;
                 binaryNum(num);
                break;
            case 5:
                showMenu();
                break;
            default:
                printf("Invalid choice, Try again\n");
                break;
        }
        printf("\n");
        printf("Enter number for operation (5 for menu): ");
        scanf("%d",&choice);
    }
    return 0;

}
