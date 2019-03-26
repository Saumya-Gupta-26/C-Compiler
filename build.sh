#!bin/bash
lex new_lex.l
yacc new_yacc.y
gcc y.tab.c -ll -ly

