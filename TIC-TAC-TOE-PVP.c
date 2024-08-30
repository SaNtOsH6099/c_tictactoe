#include <stdio.h>
void line()
{
    printf("---------------\n");
}
void display(char **ptr,int n)
{
    int i,j,k=0;
    line();
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("|%s|",ptr[k]);
            k++;
        }
        printf("\n");
        line();
    }
}
int condition(char **ptr,int n);
int main()
{
    int i,j,position,check;
    char *a[9]= {"   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " };
    display(a,9);
    for(i=1 ; i<=9 ; i++)
    {
        if(i%2==0)
        {
            printf("\nenter the position you want as:-1 2 3 \n\t\t\t\t4 5 6 \n\t\t\t\t7 8 9\n");

            First:
            printf("Enter position for O:- ");
            scanf("%d",&position);
            if((a[position-1]==" X ") || (a[position-1]==" O "))
            {
                printf("\n!!!!!POSITION IS OCCUPIED!!!!!\nCHOOSE ANOTHER POSITION:\n");
                goto First;
            }

            a[position-1]=" O ";
            printf("\n");
        }
        else
        {
            printf("\nenter the position you want as:-1 2 3 \n\t\t\t\t4 5 6 \n\t\t\t\t7 8 9\n");

            Second:
            printf("enter position for X:- ");
            scanf("%d",&position);
             if((a[position-1]==" X ") || (a[position-1]==" O "))
            {
                printf("\n!!!!!POSITION IS OCCUPIED!!!!!\nCHOOSE ANOTHER POSITION:\n");
                goto Second;
            }

            a[position-1]=" X ";
            printf("\n");
        }
        check=condition(a,position);
        display(a,9);
        if(check==1)
        {
            printf("\n%s WINS!!!!!!!!!!\n",a[position-1]);
            break;
        }
        
    }
        if(check==-1)
                {
                    printf("\n\n--------GAME DRAW---------\n\n");
                }
    display(a,9);
return 0;
}

int condition(char **ptr,int n)
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