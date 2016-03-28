/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADDEQUALS = 258,
    MULEQUALS = 259,
    DIVEQUALS = 260,
    MODEQUALS = 261,
    ANDEQUALS = 262,
    XOREQUALS = 263,
    OREQUALS = 264,
    ANDOPERATOR = 265,
    OROPERATOR = 266,
    RIGHTOPERATOR = 267,
    LEFTOPERATOR = 268,
    INCOPERATOR = 269,
    DECOPERATOR = 270,
    PTROPERATOR = 271,
    LEOPERATOR = 272,
    GEOPERATOR = 273,
    EQOPERATOR = 274,
    IDENTIFIER = 275,
    DATATYPE = 276,
    NEOPERATOR = 277,
    FLOATING_POINT = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    FOR = 282,
    DO = 283,
    BREAK = 284,
    CONTINUE = 285,
    RETURN = 286,
    SUBEQUALS = 287,
    INTEGER = 288,
    CHARACTER = 289,
    STRING = 290,
    READ = 291,
    WRITE = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
