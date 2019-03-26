#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define esize 5
#define unsize 20

struct paren {
    char sym [esize];
    int line;
    }upa[unsize];
int pac = -1;

struct curly {
    char sym [esize];
    int line;
    }ucu[unsize];
int cuc = -1;


struct comm {
    char sym [esize];
    int line;
    }uco[unsize];

int coc = -1;


void pushparen(char *sym, int l)
{
    pac++;
    if(pac<unsize)
    {
        upa[pac].line = l;
        strcpy(upa[pac].sym,sym);
    }
    else printf("\nOut of memory");
}

void pushcurly(char *sym, int l)
{
    cuc++;
    if(cuc<unsize)
    {
        ucu[cuc].line = l;
        strcpy(ucu[cuc].sym,sym);
    }
    else printf("\nOut of memory");
}


void pushcomm(char *sym, int l)
{
    coc++;
    if(coc<unsize)
    {
        uco[coc].line = l;
        strcpy(uco[coc].sym,sym);
    }
    else printf("\nOut of memory");
}

void addright(char *sym, int l)
{
	if(strcmp(sym, "*/")==0)
	{
		while(coc!=-1 && uco[coc].sym=="/*")
			coc--;
		pushcomm(sym, l);
	}
	else if(strcmp(sym, ")" )==0)
	{
		if(pac!=-1 && upa[pac].sym=="(" && upa[pac].line==l)
			pac--;
		else
			pushparen(sym, l );
	}
	else if(strcmp(sym, "}")==0)
	{
		if(cuc!=-1 && ucu[cuc].sym=="{")
			cuc--;
		else
			pushcurly(sym, l );
	}

}


void addleft(char *sym, int l)
{
	if(strcmp(sym, "/*")==0)
	{
		pushcomm(sym, l );
	}
	else if(strcmp(sym, "(" )==0)
	{
		pushparen( sym, l  );
	}
	else if(strcmp(sym, "{")==0)
	{
		pushcurly( sym, l );
	}
}


void errors()
{
	while(cuc!=-1)
	{
		printf("\nUnmatched curly brace %s at line number %d", ucu[cuc].sym, ucu[cuc].line);
		cuc--;
	}

	while(coc!=-1)
	{
		printf("\nUnmatched comment %s at line number %d", uco[coc].sym, uco[coc].line);
		coc--;
	}

	while(pac!=-1)
	{
		printf("\nUnmatched parenthesis %s at line number %d", upa[pac].sym, upa[pac].line);
		pac--;
	}
}
