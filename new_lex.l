wspace			[\t ]+
header 			#include{wspace}*<[a-z]+\.h>
key 			(case)|(default)|(struct)|(while)|(break)|(continue)|(return)|(if)|(else)|(switch)
datatype 		(int)|(float)|(void)
formattemp		(d)|(f)
format			\"(\%{formattemp}[ ]*)+\"		
id 				[a-zA-Z_][a-z0-9A-Z]*
nid				[0-9][a-z0-9A-Z]+
structmem		{id}[.]{id}
func 			(scanf)|(printf)
userfunc		{datatype}[ ]+{id}[ ]*[\(][ ]*{datatype}[ ]+{id}[ ]*[,][ ]*{datatype}[ ]+{id}[ ]*[\)]
addr			[&]{id}
aops 			[+\-/*]
string 			\"(\\.|[^"])*\"
rops 			(>=)|(<=)|(==)|(!=)|(>)|(<)
lops			(&&)|(\|\|)|(\!)

left_comm 		"/*"
right_comm		"*/"
float_const 	[0-9]+[.][0-9]+
int_const		[0-9]+
punct 			[,;.:]
scomment		\/\/(.*)
mcomment		\/\*[^*]*\*+(?:[^/*][^*]*\*+)*\/				
incomplete_str	\"[^"\n]*
date 			(((19|20)([2468][048]|[13579][26]|0[48])|2000)[/-]02[/-]29|((19|20)[0-9]{2}[/-](0[4678]|1[02])[/-](0[1-9]|[12][0-9]|30)|(19|20)[0-9]{2}[/-](0[1359]|11)[/-](0[1-9]|[12][0-9]|3[01])|(19|20)[0-9]{2}[/-]02[/-](0[1-9]|1[0-9]|2[0-8]\s))) 	
time_12 		[01][0-9]:[0-5][0-9]:[0-5][0-9] 
time_24			[2][0-3]:[0-5][0-9]:[0-5][0-9] 				

%%
\n					{yylineno=yylineno+1;} 

"int"				return INT;
"printf" return PRINT;
"case"	return CASE;
"break"	return BREAK;
"void" return VOID;
"while"	return WHILE;
"switch"	return SWITCH;
"default" return DEFAULT;
"if"	return IF;
"else"	return ELSE;
"float" return FLOAT;
"scanf" return SCAN;
"return" return RETURN;
"continue" return CONTINUE;
"struct" return STRUCT; 
			 
{wspace}			;

{header} 			 return HEADER;
{mcomment}			{
						int i=0;
						while(yytext[i]!='\0')
						{
							if(yytext[i]=='\n')
								yylineno++;
							i++;
						}
						
						return MULTICOMMENT;
					}


{scomment}			return SINGLECOMMENT;

{lops} 				return LOPS;	   	
{addr}				return ADDR;	
{format}			return FORMAT;		
{string}			 return STRING;
{incomplete_str}   	return INCOMPLETE_STRING;
{structmem}		   	return STRUCTMEM;
{id} 				return ID;
{aops} 				return AOPS;   
{rops} 					return ROPS;	  
 			
{left_comm}			return OPENING_COMMENT;		
{right_comm}		return CLOSING_COMMENT;		
{float_const} 		return FLOAT_CONST;
{int_const}			return INT_CONST;
"="					return ASGN;		   	

{nid}				return ERR_NOT_IDENTIFER;
.					return yytext[0];
%%





