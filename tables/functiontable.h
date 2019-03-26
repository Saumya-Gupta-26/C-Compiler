#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define fsize 20

struct func_table
{
	char type[10];
	char name[20];
	int  nparam;
	char param[3][20];
//	int flabel;		
}ft[fsize];

int ftcount = -1;

void pushfunctable(struct func_table ins)
{
    ftcount++;
	int i;
    if(ftcount<fsize)
    {
	strcpy(ft[ftcount].type, ins.type);
        strcpy(ft[ftcount].name, ins.name);
        ft[ftcount].nparam = ins.nparam;
//	ft[ftcount].flabel=ftcount;					 

	for(i=0;i<ft[ftcount].nparam;i++)
		strcpy(ft[ftcount].param[i], ins.param[i]);

    }
    else
    {
        printf("\nOut of Memory -- Function table capacity is full\n");
    }
}

void printfunctable()
{
    int i=0, j;
    while(i<=ftcount)
    {
        printf("\n%s\t%s\t%d", ft[i].type , ft[i].name, ft[i].nparam);
        
	for(j=0;j<ft[i].nparam;j++)
	{
		printf("\t%s", ft[i].param[j]);
	}
	i++;
	
    }

}


int lookuppara(char *id, char *para) 	//0 = not found
{
    int i=0, j;
    while(i<=ftcount)
    {
        if(strcmp(ft[i].name, id)==0)
	{
		for(j=0;j<ft[i].nparam;j++)
		{
			if(strcmp(ft[i].param[j], para)==0)
				return 1;
		}
	}        
	i++;
    }
    return 0;	
}

int lookupfunctable(char *id, int nparam) //0 = not found; 1 = found -- lookup irrespective of scope
{
    int i=0;
    int flag=-1;
    while(i<=ftcount)
    {
        if((strcmp(ft[i].name, id)==0)&&ft[i].nparam==nparam)
        {
            flag = i;
            break;
        }
        i++;
    }
    return(flag);
}

