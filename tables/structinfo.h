#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define sizec 20
#define sizea 50

struct structvar {
    char structname [sizec];
    int  nparam;
    int scope;
    int vbit;
    char membertype [10][sizec];
    char member [10][sizec];
    } sv[sizea];

int structcount = -1;


void printstructtable()
{
    int i=0, j;
    while(i<=structcount)
    {
        printf("\n%s\t%d", sv[i].structname, sv[i].nparam);
        
	for(j=0;j<sv[i].nparam;j++)
	{
		printf("\t%s %s", sv[i].membertype[j], sv[i].member[j]);
	}
	//printf("\t%d", sv[i].vbit);
	i++;
    }

}





void pushstructinfo(struct structvar ins)
{
    structcount++;
    int i;
    
    if(structcount<sizea)
    {
        strcpy(sv[structcount].structname, ins.structname);
        sv[structcount].nparam = ins.nparam;
	sv[structcount].scope = ins.scope;
	sv[structcount].vbit = 1;

	for(i=0;i<sv[structcount].nparam;i++)
	{
		strcpy(sv[structcount].membertype[i], ins.membertype[i]);		
		strcpy(sv[structcount].member[i], ins.member[i]);
	}

    }
    else
    {
        printf("\nOut of Memory -- Table capacity is full\n");
    }

/*	printf("\n\n\n\n");
	printf("Struct table\n");
	printstructtable();
	printf("\n\n\n\n");
*/
}



void invalidatestruct(int scope)
{
    int i=0;
    while(i<=structcount)
    {
        if(sv[i].scope==scope && sv[i].vbit==1)
        {
            sv[i].vbit=0;
        }
        i++;
    }	
}



//check if member belongs to struct or not
int lookupstructinfo(char *sn, char *member, int scope) //0 = not found; 1 = found
{
    int i=0, j;
    int flag=0;
    while(i<=structcount)
    {
        if(strcmp(sv[i].structname,sn)==0 && sv[i].vbit==1 && sv[i].scope<=scope)
        {
		for(j=0;j<sv[i].nparam;j++)
		{
			if(strcmp(sv[i].member[j], member)==0)
				return 1;
		}
        }
        i++;
    }
    return(flag);
}



char* structgetreturntype(char *structname, char *member, int scope)
{
	int i=0, j;
   	while(i<=structcount)
	    {
		if(strcmp(sv[i].structname, structname)==0 && sv[i].vbit==1 && sv[i].scope<=scope)
		{
			for(j=0;j<sv[i].nparam;j++)
				{
					if(strcmp(sv[i].member[j], member)==0)
						return(sv[i].membertype[j]);
				}	
		}
		i++;
	    }
	 return NULL;
}

