#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"
void line()
{
    printf("---------------\n");
}
void display(char **ptr)
{
    int i,j,k=0;
    line();
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(ptr[k]==" X ")
            {
                printf(GREEN"|%s|"RESET,ptr[k]);
            }
            else if(ptr[k]==" O ")
            {
                printf(RED"|%s|"RESET,ptr[k]);
            }
            else
            {
            printf("|%s|",ptr[k]);
            }
            k++;
        }
        printf("\n");
        line();
    }
}
int condition(char **ptr);
int pos(char **ptr);
int main()
{
    int i,j,position,check,r;
    char *a[9]= {"   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " };
    srand(time(0));
    display(a);
    for(i=1 ; i<=9 ; i++)
    {
        if(i%2!=0)
        {
             printf("\nenter the position you want as:-1 2 3 \n\t\t\t\t4 5 6 \n\t\t\t\t7 8 9\n");
            First:
             printf("enter position for X:- ");
            scanf("%d",&position);
             if((a[position-1]==" X ") || (a[position-1]==" O "))
            {
                printf("\n!!!!!POSITION IS OCCUPIED!!!!!\nCHOOSE ANOTHER POSITION:\n");
                goto First;
            }

            a[position-1]=" X ";
            printf("\n");
           
        }
        else
        {
          position=pos(a);
         
            a[position-1]=" O ";
            printf("\nCOMPUTER chose %d\n",position);
        }

        check=condition(a);
        display(a);
        if(check==1)
        {
            printf("\n%s WINS!!!!!!!!!!",a[position-1]);
            printf("\n\n");
            break;
        }
        
    }
        if(check==-1)
                {
                    printf("\n\n--------GAME DRAW---------\n\n");
                }
    display(a);
return 0;
}

int condition(char **ptr)
{
    if((ptr[0]==" X " && ptr[1]==" X " && ptr[2]==" X ") || (ptr[0]==" O " && ptr[1]==" O " && ptr[2]==" O "))
    {
        return 1;
    }
    else if((ptr[3]==" X " && ptr[4]==" X " && ptr[5]==" X ") || (ptr[3]==" O " && ptr[4]==" O " && ptr[5]==" O "))
    {
        return 1;
    }
    else if((ptr[6]==" X " && ptr[7]==" X " && ptr[8]==" X ") || (ptr[6]==" O " && ptr[7]==" O " && ptr[8]==" O "))
    {
        return 1;
    }

    else if((ptr[0]==" X " && ptr[3]==" X " && ptr[6]==" X ") || (ptr[0]==" O " && ptr[3]==" O " && ptr[6]==" O "))
    {
        return 1;
    }
    else if((ptr[1]==" X " && ptr[4]==" X " && ptr[7]==" X ") || (ptr[1]==" O " && ptr[4]==" O " && ptr[7]==" O "))
    {
        return 1;
    }
    else if((ptr[2]==" X " && ptr[5]==" X " && ptr[8]==" X ") || (ptr[2]==" O " && ptr[5]==" O " && ptr[8]==" O "))
    {
        return 1;
    }

    else if((ptr[0]==" X " && ptr[4]==" X " && ptr[8]==" X ") || (ptr[0]==" O " && ptr[4]==" O " && ptr[8]==" O "))
    {
        return 1;
    }

    else if((ptr[2]==" X " && ptr[4]==" X " && ptr[6]==" X ") || (ptr[2]==" O " && ptr[4]==" O " && ptr[6]==" O "))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int pos(char **ptr)
{
    int i,sp=0,r;
    int a[4]={1,3,7,9};
    int b[4]={2,4,6,8};
    for(i=0;i<9;i++)
    {
        if(ptr[i]=="   ")
        {
            sp++;
        }
    }

    if((ptr[4]==" X ") && sp==8)
    {
        r=(rand()%(4-1+1)+1);
        return a[r-1];
    }

        // checking winning possibilities for computer
        if((ptr[3]==" O " && ptr[4]==" O " && ptr[5]=="   "))
        {
            return 6;
        }
        if((ptr[5]==" O " && ptr[4]==" O " && ptr[3]=="   "))
        {
            return 4;
        }

        if((ptr[0]==" O " && ptr[4]==" O " && ptr[8]=="   "))
        {
            return 9;
        }
        if((ptr[8]==" O " && ptr[4]==" O " && ptr[0]=="   "))
        {
            return 1;
        }

        if((ptr[2]==" O " && ptr[4]==" O " && ptr[6]=="   "))
        {
            return 7;
        }
        if((ptr[6]==" O " && ptr[4]==" O " && ptr[2]=="   "))
        {
            return 3;
        }
        
        if((ptr[1]==" O " && ptr[4]==" O " && ptr[7]=="   "))
        {
            return 8;
        }
        if((ptr[7]==" O " && ptr[4]==" O " && ptr[1]=="   "))
        {
            return 2;
        }
            
            if(ptr[0]==" O " && ptr[1]==" O " && ptr[2]=="   ")
            {
                return 3;
            }           
            if(ptr[2]==" O " && ptr[1]==" O " && ptr[0]=="   ")
            {
                return 1;
            }

            if(ptr[0]==" O " && ptr[3]==" O " && ptr[6]=="   ")
            {
                return 7;
            }
            if(ptr[6]==" O " && ptr[3]==" O " && ptr[0]=="   ")
            {
                return 1;
            }
             
            if(ptr[2]==" O " && ptr[5]==" O " && ptr[8]=="   ")
            {
                return 9;
            }
            if(ptr[8]==" O " && ptr[5]==" O " && ptr[2]=="   ")
            {
                return 3;
            }

            if(ptr[6]==" O " && ptr[7]==" O " && ptr[8]=="   ")
            {
                return 9;
            }
            if(ptr[8]==" O " && ptr[7]==" O " && ptr[6]=="   ")
            {
                return 7;
            }

            if(ptr[0]==" O " && ptr[1]=="   " && ptr[2]==" O ")
            {
                return 2;
            }
            if(ptr[0]==" O " && ptr[3]=="   " && ptr[6]==" O ")
            {
                return 4;
            }

            if(ptr[6]==" O " && ptr[7]=="   " && ptr[8]==" O ")
            {
                return 8;
            }
            if(ptr[2]==" O " && ptr[5]=="   " && ptr[8]==" O ")
            {
                return 6;
            }

            


        if((ptr[3]==" X " && ptr[4]==" X " && ptr[5]=="   "))
        {
            return 6;
        }
        if((ptr[5]==" X " && ptr[4]==" X " && ptr[3]=="   "))
        {
            return 4;
        }

        if((ptr[0]==" X " && ptr[4]==" X " && ptr[8]=="   "))
        {
            return 9;
        }
        if((ptr[8]==" X " && ptr[4]==" X " && ptr[0]=="   "))
        {
            return 1;
        }

        if((ptr[2]==" X " && ptr[4]==" X " && ptr[6]=="   "))
        {
            return 7;
        }
        if((ptr[6]==" X " && ptr[4]==" X " && ptr[2]=="   "))
        {
            return 3;
        }
        
        if((ptr[1]==" X " && ptr[4]==" X " && ptr[7]=="   "))
        {
            return 8;
        }
        if((ptr[7]==" X " && ptr[4]==" X " && ptr[1]=="   "))
        {
            return 2;
        }
           
        if((ptr[0]==" X " && ptr[4]==" X " && ptr[8]==" O ") || (ptr[2]==" X " && ptr[4]==" X " && ptr[6]==" O ") || (ptr[8]==" X " && ptr[4]==" X " && ptr[0]==" O ") || (ptr[6]==" X " && ptr[4]==" X " && ptr[2]==" O "))
        {
            if(sp==6)
            {
            Cross:
            r=(rand()%(4-1+1)+1);
            if(ptr[a[r-1]-1]==" X " || ptr[a[r-1]-1]==" O ")                    
            {
                goto Cross;
            }
            return a[r-1];
            }

         rando:
         r=(rand()%(9-1+1)+1);
         if(ptr[r-1]==" X " || ptr[r-1]==" O ")
         {
            goto rando;
         }
         return r;     
        }

                
if(ptr[4]!=" X " && sp==8)
{
return 5;
}
            
            if(ptr[0]==" X " && ptr[1]==" X " && ptr[2]=="   ")
            {
                return 3;
            }           
            if(ptr[2]==" X " && ptr[1]==" X " && ptr[0]=="   ")
            {
                return 1;
            }

            if(ptr[0]==" X " && ptr[3]==" X " && ptr[6]=="   ")
            {
                return 7;
            }
            if(ptr[6]==" X " && ptr[3]==" X " && ptr[0]=="   ")
            {
                return 1;
            }
             
            if(ptr[2]==" X " && ptr[5]==" X " && ptr[8]=="   ")
            {
                return 9;
            }
            if(ptr[8]==" X " && ptr[5]==" X " && ptr[2]=="   ")
            {
                return 3;
            }

            if(ptr[6]==" X " && ptr[7]==" X " && ptr[8]=="   ")
            {
                return 9;
            }
            if(ptr[8]==" X " && ptr[7]==" X " && ptr[6]=="   ")
            {
                return 7;
            }

            if(ptr[0]==" X " && ptr[1]=="   " && ptr[2]==" X ")
            {
                return 2;
            }
            if(ptr[0]==" X " && ptr[3]=="   " && ptr[6]==" X ")
            {
                return 4;
            }

            if(ptr[6]==" X " && ptr[7]=="   " && ptr[8]==" X ")
            {
                return 8;
            }
            if(ptr[2]==" X " && ptr[5]=="   " && ptr[8]==" X ")
            {
                return 6;
            }

            

        if((ptr[0]==" X " && ptr[4]==" O " && ptr[8]==" X ") || (ptr[2]==" X " && ptr[4]==" O " && ptr[6]==" X "))
        {
            if((ptr[1]=="   ") || (ptr[3]=="   ") || (ptr[5]=="   ") || (ptr[7]=="   "))
            {
                Third:
                 r=(rand()%(4-1+1)+1);  
                 if(ptr[b[r-1]-1]==" X " || ptr[b[r-1]-1]==" O ")
                 {
                    goto Third;
                 }
                 return b[r-1];
            }  
        }
        
         Fourth:
         r=(rand()%(9-1+1)+1);
         if(ptr[r-1]==" X " || ptr[r-1]==" O ")
         {
            goto Fourth;
         }
         return r;    

         
}
