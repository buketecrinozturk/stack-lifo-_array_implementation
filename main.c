#include <stdio.h>
#define kapasite 5
 
 struct stack
{
    int stk[kapasite];
    int top;
};
typedef struct stack S;
S s;
 
void push(void);
int  pop(void);
void display(void);
void reset(void);
 
void main ()
{
    int choice;
    int option = 1;
    s.top = -1;
 
     printf ("Yapmak istediginiz islemi seciniz\n");
    while (option)
    {
        printf ("*************************************\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    RESET               \n");
        printf ("      5    -->    EXIT           \n");
        printf ("*************************************\n");
        
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
        	reset();
            break;
        case 5:
        	option=0;
            return;
        }
       /* fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option); */
    }
}
/* Eleman ekleme kismi */
void push ()
{
    int eleman;
    if (s.top == (kapasite - 1)) // top son indisi tutuyorsa dizi dolmustur
    {
        printf ("!!!!!! Yigin Doldu Ekleme Yapilamaz !!!!!!\n");
        return;
    }
    else
    {
        printf ("Eklemek Istediginiz Elemani Giriniz.\n");
        scanf ("%d", &eleman);
        s.top = s.top + 1; // üstteki eleman yeni eklenen eleman oluyor
        s.stk[s.top] = eleman;
    }
    return;
}
/*  Cikarma islemi */
int pop ()
{
    int eleman;
    if (s.top == - 1)
    {
        printf ("!!!!!! Yigin Boþ Çýkarma Yapilamaz !!!!!!\n");
        return (s.top);
    }
    else
    {
        eleman = s.stk[s.top];
        printf ("Cikarilan Eleman= %dn", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(eleman);
}
/*  Elemanlarin Gösterilme Kismi*/
void display ()
{
	
    int i;
    if (s.top == -1)
    {
        printf ("!!!!!! Yiginda Eleman Yok !!!!!!\n");
        return;
    }
    else
    {
        printf ("\n****Yigin'in Icerigi****\n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}

void reset()
{
	printf ("\n****Yigin Resetleniyor****\n");
	while(s.top!=-1){
		s.top=s.top-1;
	}
}
