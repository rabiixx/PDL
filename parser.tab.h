/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BI_COMENTARIO = 258,           /* BI_COMENTARIO  */
    BI_LIT_ENTERO = 259,           /* BI_LIT_ENTERO  */
    BI_LIT_REAL = 260,             /* BI_LIT_REAL  */
    BI_LIT_BOOLEANO = 261,         /* BI_LIT_BOOLEANO  */
    BI_LIT_CARACTER = 262,         /* BI_LIT_CARACTER  */
    BI_LIT_CADENA = 263,           /* BI_LIT_CADENA  */
    BI_PR_ENTERO = 264,            /* BI_PR_ENTERO  */
    BI_PR_REAL = 265,              /* BI_PR_REAL  */
    BI_PR_BOOLEANO = 266,          /* BI_PR_BOOLEANO  */
    BI_PR_CARACTER = 267,          /* BI_PR_CARACTER  */
    BI_PR_CADENA = 268,            /* BI_PR_CADENA  */
    BI_ACCION = 269,               /* BI_ACCION  */
    BI_FACCION = 270,              /* BI_FACCION  */
    BI_ALGORITMO = 271,            /* BI_ALGORITMO  */
    BI_FALGORITMO = 272,           /* BI_FALGORITMO  */
    BI_CONST = 273,                /* BI_CONST  */
    BI_FCONST = 274,               /* BI_FCONST  */
    BI_FUNCION = 275,              /* BI_FUNCION  */
    BI_FFUNCION = 276,             /* BI_FFUNCION  */
    BI_MIENTRAS = 277,             /* BI_MIENTRAS  */
    BI_FMIENTRAS = 278,            /* BI_FMIENTRAS  */
    BI_PARA = 279,                 /* BI_PARA  */
    BI_FPARA = 280,                /* BI_FPARA  */
    BI_SI = 281,                   /* BI_SI  */
    BI_FSI = 282,                  /* BI_FSI  */
    BI_TIPO = 283,                 /* BI_TIPO  */
    BI_FTIPO = 284,                /* BI_FTIPO  */
    BI_TUPLA = 285,                /* BI_TUPLA  */
    BI_FTUPLA = 286,               /* BI_FTUPLA  */
    BI_VAR = 287,                  /* BI_VAR  */
    BI_FVAR = 288,                 /* BI_FVAR  */
    BI_CONTINUAR = 289,            /* BI_CONTINUAR  */
    BI_DE = 290,                   /* BI_DE  */
    BI_DEV = 291,                  /* BI_DEV  */
    BI_DIV = 292,                  /* BI_DIV  */
    BI_ENT = 293,                  /* BI_ENT  */
    BI_E_S = 294,                  /* BI_E_S  */
    BI_FALSO = 295,                /* BI_FALSO  */
    BI_HACER = 296,                /* BI_HACER  */
    BI_HASTA = 297,                /* BI_HASTA  */
    BI_REF = 298,                  /* BI_REF  */
    BI_SAL = 299,                  /* BI_SAL  */
    BI_TABLA = 300,                /* BI_TABLA  */
    BI_VERDADERO = 301,            /* BI_VERDADERO  */
    BI_Y = 302,                    /* BI_Y  */
    BI_O = 303,                    /* BI_O  */
    BI_NO = 304,                   /* BI_NO  */
    BI_ASIGNACION = 305,           /* BI_ASIGNACION  */
    BI_COMP_SEQ = 306,             /* BI_COMP_SEQ  */
    BI_SEPARADOR = 307,            /* BI_SEPARADOR  */
    BI_SUBRANGO = 308,             /* BI_SUBRANGO  */
    BI_DEF_TYPEVAR = 309,          /* BI_DEF_TYPEVAR  */
    BI_ENTONCES = 310,             /* BI_ENTONCES  */
    BI_CREACION_TIPO = 311,        /* BI_CREACION_TIPO  */
    BI_SINOSI = 312,               /* BI_SINOSI  */
    BI_INI_ARRAY = 313,            /* BI_INI_ARRAY  */
    BI_FIN_ARRAY = 314,            /* BI_FIN_ARRAY  */
    BI_IDENTIFICADOR = 315,        /* BI_IDENTIFICADOR  */
    BI_PUNTO = 316,                /* BI_PUNTO  */
    BI_PAR_APER = 317,             /* BI_PAR_APER  */
    BI_PAR_CIER = 318,             /* BI_PAR_CIER  */
    BI_SUMA = 319,                 /* BI_SUMA  */
    BI_RESTA = 320,                /* BI_RESTA  */
    BI_MULTIPLICACION = 321,       /* BI_MULTIPLICACION  */
    BI_DIVISION = 322,             /* BI_DIVISION  */
    BI_MOD = 323,                  /* BI_MOD  */
    BI_MENOR = 324,                /* BI_MENOR  */
    BI_MAYOR = 325,                /* BI_MAYOR  */
    BI_MENOR_IGUAL = 326,          /* BI_MENOR_IGUAL  */
    BI_MAYOR_IGUAL = 327,          /* BI_MAYOR_IGUAL  */
    BI_IGUALDAD = 328,             /* BI_IGUALDAD  */
    BI_DISTINTO = 329              /* BI_DISTINTO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "src/parser.y"

	char *sval;
	Data_type data_type;		/* Data Types */
	Exp_a_b *exp;				/* Boolean/Atihmetic expressions */
	Inst *inst;					/* Instructions */
	int next_quad;
	Quad_op_code oprel_val;

#line 147 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
