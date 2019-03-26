#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define csize 20
#define asize 50

struct symtab {
    char token [csize];
    char name [csize];
    char type [csize];
    int scope;
    int vbit;
    } s[asize];

int symcount = -1;

void pushsymtable(struct symtab ins)
{
    symcount++;

    if(symcount<asize)
    {
        strcpy(s[symcount].token, ins.token);
        strcpy(s[symcount].name, ins.name);
        strcpy(s[symcount].type, ins.type);
        s[symcount].scope = ins.scope;
	s[symcount].vbit = 1;
    }
    else
    {
        printf("\nOut of Memory -- Symbol table capacity is full\n");
    }
}

char* getreturntype(char *id, int scope)
{
	int i=0;
   	while(i<=symcount)
	    {
		if((strcmp(s[i].name, id)==0)&&s[i].scope<=scope && s[i].vbit==1)
		{
		    return(s[i].type);
		}
		i++;
	    }
	 return NULL;
}


void invalidate(int scope)
{
    int i=0;
    while(i<=symcount)
    {
        if(s[i].scope==scope && s[i].vbit==1)
        {
            s[i].vbit=0;
        }
        i++;
    }	
}


void printtable()
{
    int i=0;
    while(i<=symcount)
    {
        printf("\n%s\t%s\t%s\t%d", s[i].token, s[i].name, s[i].type, s[i].scope);
        i++;
    }

}

int lookupsymtable2(char *id, int scope) //0 = not found; 1 = found -- lookup in current scope
{
    int i=0;
    int flag=0;
    while(i<=symcount)
    {
        if((strcmp(s[i].name, id)==0)&&s[i].scope==scope && s[i].vbit==1)
        {
            flag = 1;
            break;
        }
        i++;
    }
    return(flag);
}

int lookupsymtable1(char *id, int scope) //0 = not found; 1 = found -- lookup in outside scope - for use of variable in expressions
{
    int i=0;
    int flag=0;
    while(i<=symcount)
    {
        if((strcmp(s[i].name, id)==0)&&s[i].scope<=scope && s[i].vbit==1)
        {
            flag = 1;
            break;
        }
        i++;
    }
    return(flag);
}

/*char* gettype(char *id, int scope)
{
    int i=0;
    int flag=0;
    char str[10];
    while(i<=symcount)
    {
        if((strcmp(s[i].name, id)==0)&&s[i].scope<=scope)
        {
            flag = 1;
		strcpy(str, s[i].type);
            break;
        }
        i++;
    }
    if(flag==1)
	return str;
    else
	return "NULL";
}
*/
