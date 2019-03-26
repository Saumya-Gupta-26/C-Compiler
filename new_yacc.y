%{
#include <stdio.h>
#include <stdlib.h>
#include "structinfo.h"
#include "symboltable.h"
#include "functiontable.h"
#include "unmatched.h"
extern FILE *fp;
FILE * f1;

int pcount=-1;
int gscope = 0;
char lasttype[csize]; //the last datatype encountered in the program. needed for when multiple variables declared in the same line
char returntype[csize];	//the return type of the function

char funcname[20];
char paras[3][20];

char tstr[10]={'N','U','L','L','\0'};	//set identifier in stmt_assign

char laststruct[20];
char structparas[8][20];
char structparastype[8][20];
int spcount = -1;	//struct-parameter count
char currentstructvar[20];
%}

%token INT VOID FLOAT STRUCT
%token WHILE
%token IF ELSE SWITCH CASE BREAK DEFAULT RETURN CONTINUE
%token INT_CONST FLOAT_CONST ID STRUCTMEM
%token ADDR FORMAT 
%token INCOMPLETE_STRING OPENING_COMMENT CLOSING_COMMENT ERR_NOT_IDENTIFER LEX_ERROR
%token SINGLECOMMENT MULTICOMMENT
%token STRING
%token PRINT SCAN
%token HEADER
%right ASGN 
%left LOPS
%left AOPS	 
%left ROPS

%start pgmstart

%nonassoc IFX IFX1
%nonassoc ELSE
  
%%



pgmstart 			: FUNC pgmstart
				| STMTS pgmstart
				| MULTICOMMENT pgmstart
				| SINGLECOMMENT pgmstart
				| HEADER pgmstart
				| STMT_DECLARE  //all types of statements
				| STMT_ASSGN  
				| 
				;

FUNC				: TYPE {setrettype();} ID {setfuncname();} '(' PARAMETER ')' {pushfunc(); func_label2(); pcount=-1; }
				;


PARAMETER			:	TYPE ID {pcount++; addpara();} PARAMETER
				|	',' PARAMETER	
				|	TYPE 
				|	ID {checknew(); pcount++;}
				|	STRUCTMEM {setstructvariable(); checkstructvar();pcount++;}
				|	INT_CONST {pcount++;}
				|	FLOAT_CONST {pcount++;}
				|
				;



STMTS 				: '{' {gscope++;} STMT1 '}' {invalidate(gscope); invalidatestruct(gscope); gscope--;} 
				| ';'
				|;

STMT1				: STMT  STMT1 
				| ;

STMT 				: 
				 STMT_DECLARE  //all types of statements
				| STMT_ASSGN  
				| STMT_IF
				| STMT_WHILE
				| STMT_SCAN 
				| STMT_SWITCH
				| STMT_PRINT
				| STMT_COMMENT
				| RETURNSTMT {fprintf(f1,"return\n");}
				| STRUCT_DECLARE
				| ';'
				;



RETURNSTMT	:	RETURN VALUES ';'
		|	RETURN '(' VALUES ')' ';'
		;

VALUES		:	ID {check1(); checkret(0);}
		|	STRUCTMEM {setstructvariable(); checkstructvar(); checkret(0);}
		|	INT_CONST {checkret(1);}
		|	FLOAT_CONST {checkret(2);}
		|	{checkret(3);}
		;







AEXP		: AEXP AOPS{push();pushop(0);} AEXP  {codegen_algebric();}
				| ID {  push(); check1();}
				| INT_CONST {push();}
				| FLOAT_CONST {push();}
				| STRING {push();}
				| STRUCTMEM { push(); setstructvariable(); checkstructvar(); }
				| '(' AEXP ')'
		;


EXP 				: EXP ROPS{push();pushop(2);} EXP  {codegen_logical();}
				| EXP LOPS{push();pushop(1);} EXP  {codegen_logical();}
				| AEXP
				| '(' EXP ')'
				;

STMT_PRINT			: PRINT '(' STRING {print_func();} OPTIONEND ')'
				| PRINT '(' ID {print_func();} ')'
				;

OPTIONEND			: ',' ID {check1();} OPTIONEND
				| ',' STRUCTMEM {setstructvariable(); checkstructvar();} OPTIONEND
				|
				;


ADDRS			: ',' ADDR
				| ;
				;

STMT_SCAN		: SCAN '(' FORMAT ',' ADDR ADDRS ')'
				;


STMT_IF 			: IF '(' EXP ')'  {if_label1();} STMTS ELSESTMT 
				;

ELSESTMT			: ELSE {if_label2();} STMTS {if_label3();}
				| {if_label3();}
				;

STMT_SWITCH			: SWITCH {switch_start();}'(' swEXP ')' '{' SWITCHBODY '}' {switch_end();}
				;



swEXP				: swEXP ROPS{pushop(2);} swEXP	
				| swEXP LOPS{pushop(1);} swEXP
				| swEXP AOPS{pushop(0);} swEXP 
				| '(' swEXP ')'
				| ID {check1(); checkint();}
				| STRUCTMEM {setstructvariable(); checkstructvar(); checkintstruct();}
				| INT_CONST	
				;


SWITCHBODY			: CASES    
				| CASES DEFAULTSTMT
				|
				;

CASES 				: CASE INT_CONST {switch_case();} ':' SWITCHEXP BREAKSTMT CASES
				| 
				;
BREAKSTMT			: BREAK  ';'{switch_break();} CASES
				| {switch_nobreak();} CASES 
				;

DEFAULTSTMT 			: DEFAULT {switch_default();} ':' SWITCHEXP DE  
				;

DE 				: BREAK ';'
				|
				;

STMT_COMMENT			: SINGLECOMMENT
				| MULTICOMMENT
				;

SWITCHEXP 			: STMTS
				| STMT1
				; 


STMT_WHILE			:{while_start();} WHILE '(' EXP ')' {while_rep();} WHILEBODY  
				;


WHILEBODY			: whileSTMTS {while_end();}
				| STMT {while_end();}
				;



whileSTMTS 				: '{' {gscope++;} whileSTMT1 '}' {invalidate(gscope); invalidatestruct(gscope); gscope--;} 
				|;

whileSTMT1			: STMT  whileSTMT1 
				| BREAK {while_break();} whileSTMT1
				| CONTINUE {while_continue();} whileSTMT1
				| ;



STMT_DECLARE 			: TYPE {settype();}  ID {check2(); pushid(0);push();} IDS   //setting type for that line
				;

IDS 				: ';'
				| ','  ID { check2(); pushid(0);push();} IDS 
				;


STMT_ASSGN			: ANY {push(); setstring();} TEMP {resetstring();}  				
				;


ANY				: ID
				| STRUCTMEM {setstructvariable();}
				;

TEMP				:  ASGN {push();  pushop(3); check_var_or_structvar();} EXP {codegen_assign();}
				|  '(' PARAMETER {checkfunc(); func_label1(); pcount=-1;} ')'
				;


TYPE				: INT
				| VOID
				| FLOAT
				;



STRUCT_DECLARE		: STRUCT {settype();} ID { settype(); storestructname(); } STRUCT_DEF_DEC
			;

STRUCT_DEF_DEC		: '{' { gscope++;} STRUCT_PARAMETER '}' {invalidate(gscope); gscope--; checkifstruct2(); specialsettype(); pushid(1); settypetostruct(); addstructdefn(); spcount=-1;} CONT';'
			| ID {checkifstruct(); check2(); pushid(0);} MULTIPLE_STRUCT_DEF_DEC
			;


MULTIPLE_STRUCT_DEF_DEC : ',' ID {check2(); pushid(0);} MULTIPLE_STRUCT_DEF_DEC
			| ';'
			;


CONT			: ID {check2(); pushid(0);} CONT
			| ',' ID {check2(); pushid(0);} CONT
			|
			;



STRUCT_PARAMETER	:	TYPE {spcount++; addstructparatype();} ID {addstructpara();} ';' STRUCT_PARAMETER
			|
			;


%%

#include<string.h>
#include"lex.yy.c"
int count=0;

char st[1000][10];
int top=0;
int i=1, test=0;
char temp[2]="t";

int label[200];
int flabel[200];				
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];

struct Table
{
	char id[20];
}table[100];

int tableCount=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	f1=fopen("output","w");
	printf("\n\n");
	yyparse();

	if(test!=0)
	{
		printf("\nThe code could not be parsed.\n\n");
		exit(0);
	}
	
	fclose(yyin);
	fclose(f1);
	printf("\n\n\n\n");
	printf("Symbol table\n");
	printtable();
	printf("\n\n\n\n");
	printf("Function table\n");
	printfunctable();
	printf("\n\n\n\n");
	printf("Struct table\n");
	printstructtable();
	printf("\n\n\n\n");
	printf("Intermediate Code\n\n");
	intermediateCode();
    return 0;
}
         
yyerror(char *s) 
{
	test=1;
	printf("Error in line number : %d : %s %s\n", yylineno, s, yytext );
}
   

pushop(int type) //push operators
{
	//0 - AOPs 
	//1 - LOPs
	//2 - ROPs
	//3 - Assignment
	struct symtab temp;
	strcpy(temp.token, "operator");
	strcpy(temp.name, yytext);
	temp.scope = gscope;	
	
	switch(type)
	{
		case 0:	strcpy(temp.type, "arithmetic");  break;
		case 1: strcpy(temp.type, "logical");	break;
		case 2: strcpy(temp.type, "relational");	break;
		case 3: strcpy(temp.type, "assignment");	break;
		default : strcpy(temp.type, "other");	break;
	}
	pushsymtable(temp);
}


settype()
{
	strcpy(lasttype, yytext);
}

setrettype()
{
	strcpy(returntype, yytext);
}

setfuncname()
{
	strcpy(funcname, yytext);
}

storestructname()
{
	strcpy(laststruct, yytext);
}

setstructvariable()
{
	strcpy(currentstructvar, yytext);
}


settypetostruct()
{
//	printf("\nAre we here?\n\n");
	strcpy(lasttype, laststruct);
}

specialsettype()
{
	strcpy(lasttype, "struct");
}

setstring()
{
	strcpy(tstr, yytext);
}

resetstring()
{
	strcpy(tstr, "NULL");
}


pushid(int num) //pushing an identifier
{
//	printf("\n\nAre we in pushid?\n\n");

	struct symtab temp;
	strcpy(temp.token, "identifier");

	strcpy(temp.name, laststruct);

	if(num==0)
		strcpy(temp.name, yytext);
	
	strcpy(temp.type, lasttype);
	temp.scope = gscope;	
	pushsymtable(temp);
//	printf("\n\nHave we made it out of pushid?\n\n");


/*	printf("\n\n\n\n");
	printf("Symbol table\n");
	printtable();
	printf("\n\n\n\n");
*/

}

pushfunc()
{

	int flag = lookupfunctable(funcname, pcount+1);

	if(flag!=-1)
		return;

	struct func_table temp;
	strcpy(temp.type, returntype);
	strcpy(temp.name, funcname);
	temp.nparam = pcount+1;
	int i;
	for(i=0;i<=pcount;i++)
	{
		strcpy(temp.param[i],paras[i]);
	}
	pushfunctable(temp);
}


addstructdefn()
{
	struct structvar temp;
	strcpy(temp.structname, laststruct);
	temp.nparam = spcount+1;
	temp.scope = gscope;

	int i;
	for(i=0;i<=spcount;i++)
	{
		strcpy(temp.membertype[i],structparastype[i]);
		strcpy(temp.member[i],structparas[i]);
	}
		
	pushstructinfo(temp);
}



push()
{
  	strcpy(st[++top],yytext);
}

codegen_logical()
{
	int kop;
	char vio,x[10]="";
// 	printf("Line %d: Logical statement.\n", yylineno);
 	strcpy(temp,"$t");
	kop=i;
	while(kop!=0)
	{
		kop=kop%10;
		switch(kop)
		{
			case 1:strcat(x,"1");
			break;
			case 2:strcat(x,"2");
			break;
			case 3:strcat(x,"3");
			break;
			case 4:strcat(x,"4");
			break;
			case 5:strcat(x,"5");
			break;
			case 6:strcat(x,"6");
			break;
			case 7:strcat(x,"7");
			break;
			case 8:strcat(x,"8");
			break;
			case 9:strcat(x,"9");
			break;
			case 0:strcat(x,"0");
			break;
		}
		kop=kop/10;
	}
	for(kop=0;kop=(strlen(x)/2);kop++)
	{
		vio=x[kop];
		x[kop]=x[strlen(x)-kop];
		x[strlen(x)-kop]=vio;
	}
	strcat(temp,x);
  	fprintf(f1,"$t%d\t=\t%s\t%s\t%s\n",i,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

codegen_algebric()
{
	int kop;
	char vio,x[10]="";
// 	printf("Line %d: Algebraic expression.\n", yylineno);
 	strcpy(temp,"$t");
	kop=i;
	while(kop!=0)
	{
		kop=kop%10;
		switch(kop)
		{
			case 1:strcat(x,"1");
			break;
			case 2:strcat(x,"2");
			break;
			case 3:strcat(x,"3");
			break;
			case 4:strcat(x,"4");
			break;
			case 5:strcat(x,"5");
			break;
			case 6:strcat(x,"6");
			break;
			case 7:strcat(x,"7");
			break;
			case 8:strcat(x,"8");
			break;
			case 9:strcat(x,"9");
			break;
			case 0:strcat(x,"0");
			break;
		}
		kop=kop/10;
	}
for(kop=0;kop=(strlen(x)/2);kop++)
	{
		vio=x[kop];
		x[kop]=x[strlen(x)-kop];
		x[strlen(x)-kop]=vio;
	}
	strcat(temp,x);
  	fprintf(f1,"$t%d\t=\t%s\t%s\t%s\n",i,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}
codegen_assign()
{
// 	printf("Line %d: Assignment statement.\n", yylineno);
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
 	top-=3;
}
 
if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	label[++ltop]=lnum;
}

if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	top--;
}

func_label1()
{
	int flag = lookupfunctable(tstr, pcount+1);
	fprintf(f1,"call $F%d: \n",flag);
	
}

func_label2()
{
	int flag = lookupfunctable(funcname, pcount+1);
	fprintf(f1,"$F%d: \n",flag);
}
print_func()
{
	fprintf(f1,"print statement\n");
}


comment()
{
	fprintf(f1,"Comment");
}
while_start()
{
//	printf("Line %d: While loop.\n", yylineno);
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
}
while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

while_break()
{
 	fprintf(f1,"\tgoto $L%d\n",lnum);
}




while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	top--;
}


while_continue()
{
	int x;
	x=label[ltop-1];
	fprintf(f1,"\t\tgoto $L%d\n",x);
}


switch_start()
{
//	printf("Line %d: Switch case.\n", yylineno);
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
}
switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
 	}
}
switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
}
switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
}
switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	top--;
	stop--;
}


/* for symbol table*/

pushTable()
{
	strcpy(table[tableCount++].id,yytext);
}


check2()
{

	int flagfunc = lookuppara(funcname, yytext);

	int flag = lookupsymtable2(yytext, gscope);
 
	if(flag==1 || flagfunc==1)
	{
		yyerror("Variable redeclared");
		exit(0);
	}
	
	
}

check1()
{
	if(strcmp(tstr, "NULL")!=0)
		strcpy(yytext, tstr);
	
	int flag = lookupsymtable1(yytext, gscope); 

	int flagfunc = lookuppara(funcname, yytext);

	if(flag==0 && flagfunc==0)
	{
		yyerror("Variable not declared");
		exit(0);	
	}
	
} 


checknew()
{

	int flag = lookupsymtable1(yytext, gscope); 
	if(flag==0)
	{
		yyerror("Variable not declared");
		exit(0);	
	}
	
}



checkifstruct() //in struct student stud, check if student exists
{
/*	char temp[20];
	printf("\n\nError0\n\n");
	strcpy(temp, yytext);
	printf("\n\nError1\n\n");
	strcpy(yytext, laststruct);
	printf("\n\nError2\n\n");
	check1();
	strcpy(yytext, temp);
	printf("\n\nError3\n\n");

*/
	int flag = lookupsymtable1(laststruct, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: struct not declared %s\n\n", yylineno, laststruct);
		exit(0);	
	}
}

checkifstruct2() //in struct student stud, see if student is being redeclared
{
/*	char temp[20];
	printf("\n\n2Error0\n\n");
	strcpy(temp, yytext);
	printf("\n\n2Error1\n\n");
	strcpy(yytext, laststruct);
	printf("\n\n2Error2\n\n");
	check2();
	strcpy(yytext, temp);
	printf("\n\n2Error3\t%s\n\n", yytext);
*/
	int flag = lookupsymtable2(laststruct, gscope); 
	if(flag==1)
	{
		test=1;
		printf("\nError in linenumber %d: struct redeclared %s\n\n", yylineno, laststruct);
		exit(0);
	}
	



}

checkstructvar()
{
	char sname[sizec], mname[sizec]; //struct-name, member-name

	int i, k=0;
	for(i=0; currentstructvar[i]!='.';i++)
	{
		sname[k] = currentstructvar[i];
		k++;
	}
	sname[k]='\0';

	i++; k=0;

	for(;currentstructvar[i]!='\0';i++)
	{
		mname[k] = currentstructvar[i];
		k++;
	}
	mname[k]='\0';

	int flag = lookupsymtable1(sname, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: variable not declared %s\n\n", yylineno, sname);
		exit(0);	
	}



	char stype[sizec]; //type of struct variable
	strcpy(stype, getreturntype(sname,gscope));
	
//	printf("\n\nReturn type = %s\n", stype);

	flag = lookupstructinfo(stype, mname, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: This member is not a part of the struct %s\n\n", yylineno, stype);
		exit(0);	
	}

}


check_var_or_structvar()
{
	if(strchr(tstr, '.')!=NULL)
	{
//		printf("\n\nChecking for struct member line %d\n\n", yylineno);
		checkstructvar();
//		printf("\n\nDone checking for struct member\n\n");
	}		
	else
		check1();
}


checkret(int what)
{
	int flag=1;

	if(strcmp(returntype,"void")==0)
	{
		if(what!=3)
			flag=0;
	}

	if(flag==0)
	{
		yyerror("\nError: return type mismatch\n");
		exit(0);
	}
	return;
}


checkfunc()
{
	int flag = lookupfunctable(tstr, pcount+1);
	if(flag==-1)
	{
		yyerror("\nError: function not declared\n");
		exit(0);
	}
}

addpara()
{
	strcpy(paras[pcount], yytext);
}

addstructpara()
{
	strcpy(structparas[spcount], yytext);
}

addstructparatype()
{
	strcpy(structparastype[spcount], yytext);
}



checkint()
{
	char typeofid[10];
	strcpy(typeofid, getreturntype(yytext, gscope));
	if(strcmp(typeofid, "int")!=0)
	{
		yyerror("\nSwitch expression should be of int type\n");
		exit(0);
	}
}

checkintstruct()
{
	char typeofid[10];
	char sname[sizec], mname[sizec];  //struct-name and member-name

	int i, k=0;
	for(i=0; currentstructvar[i]!='.';i++)
	{
		sname[k] = currentstructvar[i];
		k++;
	}
	sname[k]='\0';

	i++; k=0;
	for(;currentstructvar[i]!='\0';i++)
	{
		mname[k] = currentstructvar[i];
		k++;
	}
	mname[k]='\0';


	char stype[sizec]; //type of struct variable
	strcpy(stype, getreturntype(sname,gscope));	

	strcpy(typeofid, structgetreturntype(stype, mname, gscope));

	if(strcmp(typeofid, "int")!=0)
	{
		yyerror("\nSwitch expression should be of int type\n");
		exit(0);
	}
}


intermediateCode()
{
	char buf[100];
	f1=fopen("output","r");
	int lineno=1;
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		printf("%3d :\t%s",lineno,buf);
		lineno++;
	}

	++lineno;
	printf("  end\n");
	
//	printf("%3d :\tend\n",++lineno);
	fclose(f1);
}
