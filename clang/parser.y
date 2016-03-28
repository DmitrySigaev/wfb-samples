%{
#include <stdio.h>
#include "lexer.flex.h"
extern int lnumber;
%}

%token ADDEQUALS MULEQUALS DIVEQUALS MODEQUALS ANDEQUALS XOREQUALS OREQUALS ANDOPERATOR OROPERATOR 
%token RIGHTOPERATOR LEFTOPERATOR INCOPERATOR DECOPERATOR PTROPERATOR  LEOPERATOR GEOPERATOR EQOPERATOR 
%token IDENTIFIER DATATYPE NEOPERATOR FLOATING_POINT 
%token IF ELSE WHILE FOR DO BREAK 
%token CONTINUE RETURN SUBEQUALS  INTEGER 
%token CHARACTER STRING READ WRITE
 
%%
startstatement:  /*empty*/
						|startofdeclaration startstatement 
						;
startofdeclaration: 	definationoffunction 
						| declaration
						;
declaration: 			datatype id semicolon
						| datatype id '=' the_expression semicolon
						| datatype id leftbracket integer rightbracket semicolon
						;
listofdeclaration: 		declaration 
						| declaration listofdeclaration
						;		
definationoffunction:	datatype id leftparenthesis listofsrguments rightparenthesis compoundstatements
						;
listofsrguments:				/* empty */
						| datatype id 
						| datatype id comma listofsrguments
						;
						
listofparameters:				/* empty */
						| id
						| id comma listofparameters
						;
compoundstatements:			leftbrace rightbrace 
						| leftbrace listofstatements rightbrace
						;
listofstatements:				/*empty*/
						|statement listofstatements
						;
statement:					listofdeclaration 
						| compoundstatements
						| readstatement
						| writestatement
						| conditionalstatement
						| iterationstatement
						| jumpstatement
						| the_expression semicolon
						;
readstatement:   READ id semicolon
				| error {printf(" Wrong read syntax at line  %d\n",lnumber);}
				;
writestatement: WRITE id semicolon
				| error {printf(" Wrong write syntax at line  %d\n",lnumber);}
				;				
iterationstatement:			WHILE leftparenthesis the_expression rightparenthesis statement
						| DO statement WHILE leftparenthesis the_expression rightparenthesis semicolon
						| FOR leftparenthesis the_expression semicolon the_expression semicolon the_expression rightparenthesis statement
						;
jumpstatement:				CONTINUE semicolon
						| BREAK semicolon
						| RETURN semicolon
						| RETURN the_expression semicolon
						;
conditionalstatement:		IF leftparenthesis the_expression rightparenthesis statement
						| IF leftparenthesis the_expression rightparenthesis statement ELSE statement
						;						
the_expression:					number 
						| id 
						| number operator the_expression
						| id operator the_expression
						| id leftparenthesis listofparameters rightparenthesis
						;
operator: 				assignmentOPERATOR
						| relationalOPERATOR
						|EQOPERATOR
						| logicalOPERATOR
						| binaryOPERATOR
						| error			{printf(" operator at line  %d\n",lnumber);}			
						
assignmentOPERATOR:		 	'='
						| MULEQUALS
						| DIVEQUALS
						| MODEQUALS
						| ADDEQUALS
						| SUBEQUALS
						| ANDEQUALS
						| XOREQUALS
						| OREQUALS
						;
binaryOPERATOR:				'+'
						| '-'
						| '*'
						| '/'
						| '%'
						;
relationalOPERATOR:			'<'
						| '>'
						| LEOPERATOR
						| GEOPERATOR
						;
logicalOPERATOR:				'!'
						| ANDOPERATOR
						| OROPERATOR
						;
semicolon:					';'
						| error		{printf(" Semicolon is missing at line  %d\n",lnumber);}
						;
datatype:				DATATYPE
						| error		{printf(" Data type missing at line  %d\n",lnumber);}
						;
id:						IDENTIFIER
						| error		{printf(" Identifier missing at line  %d\n",lnumber);}
						;
integer:				INTEGER
						| error     {printf(" Integer missing at line  %d\n",lnumber);}
						;
number:					INTEGER
						| FLOATING_POINT
						| error 	{printf(" Number missing at line  %d\n",lnumber);}
						;
leftparenthesis:		'('
						| error 	{printf(" ( missing at line  %d\n",lnumber);}
						;
rightparenthesis:		')'
						| error 	{printf(" ) missing at line  %d\n",lnumber);}
						;
leftbrace:				'{'
						| error 	{printf(" { missing at line  %d\n",lnumber);}
						;
rightbrace:			'}'
						| error 	{printf(" } missing at line  %d\n",lnumber);}
						;
leftbracket:			'['
						| error 	{printf(" [ missing at line  %d\n",lnumber);}
						;
rightbracket:			']'
						| error 	{printf(" ] missing at line  %d\n",lnumber);}
						;
comma:					','
						| error 	{printf(" , missing at line  %d\n",lnumber);}
						;
%%
