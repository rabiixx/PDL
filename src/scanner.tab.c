/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "scanner.y"

	/* fichero scanner.y */
	#include <stdio.h>
	#include <stdbool.h>
	#include "libs/hash_table.h"

	Symbol *hash_table[HT_SIZE];

	Stack stack;



#line 84 "scanner.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BI_COMENTARIO = 3,              /* BI_COMENTARIO  */
  YYSYMBOL_BI_LIT_ENTERO = 4,              /* BI_LIT_ENTERO  */
  YYSYMBOL_BI_LIT_REAL = 5,                /* BI_LIT_REAL  */
  YYSYMBOL_BI_LIT_BOOLEANO = 6,            /* BI_LIT_BOOLEANO  */
  YYSYMBOL_BI_LIT_CARACTER = 7,            /* BI_LIT_CARACTER  */
  YYSYMBOL_BI_LIT_CADENA = 8,              /* BI_LIT_CADENA  */
  YYSYMBOL_BI_PR_ENTERO = 9,               /* BI_PR_ENTERO  */
  YYSYMBOL_BI_PR_REAL = 10,                /* BI_PR_REAL  */
  YYSYMBOL_BI_PR_BOOLEANO = 11,            /* BI_PR_BOOLEANO  */
  YYSYMBOL_BI_PR_CARACTER = 12,            /* BI_PR_CARACTER  */
  YYSYMBOL_BI_PR_CADENA = 13,              /* BI_PR_CADENA  */
  YYSYMBOL_BI_ACCION = 14,                 /* BI_ACCION  */
  YYSYMBOL_BI_FACCION = 15,                /* BI_FACCION  */
  YYSYMBOL_BI_ALGORITMO = 16,              /* BI_ALGORITMO  */
  YYSYMBOL_BI_FALGORITMO = 17,             /* BI_FALGORITMO  */
  YYSYMBOL_BI_CONST = 18,                  /* BI_CONST  */
  YYSYMBOL_BI_FCONST = 19,                 /* BI_FCONST  */
  YYSYMBOL_BI_FUNCION = 20,                /* BI_FUNCION  */
  YYSYMBOL_BI_FFUNCION = 21,               /* BI_FFUNCION  */
  YYSYMBOL_BI_MIENTRAS = 22,               /* BI_MIENTRAS  */
  YYSYMBOL_BI_FMIENTRAS = 23,              /* BI_FMIENTRAS  */
  YYSYMBOL_BI_PARA = 24,                   /* BI_PARA  */
  YYSYMBOL_BI_FPARA = 25,                  /* BI_FPARA  */
  YYSYMBOL_BI_SI = 26,                     /* BI_SI  */
  YYSYMBOL_BI_FSI = 27,                    /* BI_FSI  */
  YYSYMBOL_BI_TIPO = 28,                   /* BI_TIPO  */
  YYSYMBOL_BI_FTIPO = 29,                  /* BI_FTIPO  */
  YYSYMBOL_BI_TUPLA = 30,                  /* BI_TUPLA  */
  YYSYMBOL_BI_FTUPLA = 31,                 /* BI_FTUPLA  */
  YYSYMBOL_BI_VAR = 32,                    /* BI_VAR  */
  YYSYMBOL_BI_FVAR = 33,                   /* BI_FVAR  */
  YYSYMBOL_BI_CONTINUAR = 34,              /* BI_CONTINUAR  */
  YYSYMBOL_BI_DE = 35,                     /* BI_DE  */
  YYSYMBOL_BI_DEV = 36,                    /* BI_DEV  */
  YYSYMBOL_BI_DIV = 37,                    /* BI_DIV  */
  YYSYMBOL_BI_ENT = 38,                    /* BI_ENT  */
  YYSYMBOL_BI_E_S = 39,                    /* BI_E_S  */
  YYSYMBOL_BI_FALSO = 40,                  /* BI_FALSO  */
  YYSYMBOL_BI_HACER = 41,                  /* BI_HACER  */
  YYSYMBOL_BI_HASTA = 42,                  /* BI_HASTA  */
  YYSYMBOL_BI_REF = 43,                    /* BI_REF  */
  YYSYMBOL_BI_SAL = 44,                    /* BI_SAL  */
  YYSYMBOL_BI_TABLA = 45,                  /* BI_TABLA  */
  YYSYMBOL_BI_VERDADERO = 46,              /* BI_VERDADERO  */
  YYSYMBOL_BI_Y = 47,                      /* BI_Y  */
  YYSYMBOL_BI_O = 48,                      /* BI_O  */
  YYSYMBOL_BI_NO = 49,                     /* BI_NO  */
  YYSYMBOL_BI_ASIGNACION = 50,             /* BI_ASIGNACION  */
  YYSYMBOL_BI_COMP_SEQ = 51,               /* BI_COMP_SEQ  */
  YYSYMBOL_BI_SEPARADOR = 52,              /* BI_SEPARADOR  */
  YYSYMBOL_BI_SUBRANGO = 53,               /* BI_SUBRANGO  */
  YYSYMBOL_BI_DEF_TYPEVAR = 54,            /* BI_DEF_TYPEVAR  */
  YYSYMBOL_BI_ENTONCES = 55,               /* BI_ENTONCES  */
  YYSYMBOL_BI_CREACION_TIPO = 56,          /* BI_CREACION_TIPO  */
  YYSYMBOL_BI_SINOSI = 57,                 /* BI_SINOSI  */
  YYSYMBOL_BI_INI_ARRAY = 58,              /* BI_INI_ARRAY  */
  YYSYMBOL_BI_FIN_ARRAY = 59,              /* BI_FIN_ARRAY  */
  YYSYMBOL_BI_IDENTIFICADOR = 60,          /* BI_IDENTIFICADOR  */
  YYSYMBOL_BI_PUNTO = 61,                  /* BI_PUNTO  */
  YYSYMBOL_BI_PAR_APER = 62,               /* BI_PAR_APER  */
  YYSYMBOL_BI_PAR_CIER = 63,               /* BI_PAR_CIER  */
  YYSYMBOL_BI_SUMA = 64,                   /* BI_SUMA  */
  YYSYMBOL_BI_RESTA = 65,                  /* BI_RESTA  */
  YYSYMBOL_BI_MULTIPLICACION = 66,         /* BI_MULTIPLICACION  */
  YYSYMBOL_BI_DIVISION = 67,               /* BI_DIVISION  */
  YYSYMBOL_BI_MOD = 68,                    /* BI_MOD  */
  YYSYMBOL_BI_MENOR = 69,                  /* BI_MENOR  */
  YYSYMBOL_BI_MAYOR = 70,                  /* BI_MAYOR  */
  YYSYMBOL_BI_MENOR_IGUAL = 71,            /* BI_MENOR_IGUAL  */
  YYSYMBOL_BI_MAYOR_IGUAL = 72,            /* BI_MAYOR_IGUAL  */
  YYSYMBOL_BI_IGUALDAD = 73,               /* BI_IGUALDAD  */
  YYSYMBOL_BI_DISTINTO = 74,               /* BI_DISTINTO  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_desc_algoritmo = 76,            /* desc_algoritmo  */
  YYSYMBOL_cabecera_alg = 77,              /* cabecera_alg  */
  YYSYMBOL_bloque_alg = 78,                /* bloque_alg  */
  YYSYMBOL_decl_globales = 79,             /* decl_globales  */
  YYSYMBOL_decl_a_f = 80,                  /* decl_a_f  */
  YYSYMBOL_bloque = 81,                    /* bloque  */
  YYSYMBOL_declaraciones = 82,             /* declaraciones  */
  YYSYMBOL_declaracion_tipo = 83,          /* declaracion_tipo  */
  YYSYMBOL_declaracion_cte = 84,           /* declaracion_cte  */
  YYSYMBOL_declaracion_var = 85,           /* declaracion_var  */
  YYSYMBOL_lista_d_tipo = 86,              /* lista_d_tipo  */
  YYSYMBOL_d_tipo = 87,                    /* d_tipo  */
  YYSYMBOL_expresion_t = 88,               /* expresion_t  */
  YYSYMBOL_lista_campos = 89,              /* lista_campos  */
  YYSYMBOL_tipo_base = 90,                 /* tipo_base  */
  YYSYMBOL_literal = 91,                   /* literal  */
  YYSYMBOL_lista_d_cte = 92,               /* lista_d_cte  */
  YYSYMBOL_lista_d_var = 93,               /* lista_d_var  */
  YYSYMBOL_lista_id = 94,                  /* lista_id  */
  YYSYMBOL_decl_ent_sal = 95,              /* decl_ent_sal  */
  YYSYMBOL_decl_ent = 96,                  /* decl_ent  */
  YYSYMBOL_decl_sal = 97,                  /* decl_sal  */
  YYSYMBOL_expresion = 98,                 /* expresion  */
  YYSYMBOL_literal_numerico = 99,          /* literal_numerico  */
  YYSYMBOL_exp_a = 100,                    /* exp_a  */
  YYSYMBOL_oprel = 101,                    /* oprel  */
  YYSYMBOL_exp_b = 102,                    /* exp_b  */
  YYSYMBOL_operando = 103,                 /* operando  */
  YYSYMBOL_instrucciones = 104,            /* instrucciones  */
  YYSYMBOL_instruccion = 105,              /* instruccion  */
  YYSYMBOL_asignacion = 106,               /* asignacion  */
  YYSYMBOL_alternativa = 107,              /* alternativa  */
  YYSYMBOL_lista_opciones = 108,           /* lista_opciones  */
  YYSYMBOL_iteracion = 109,                /* iteracion  */
  YYSYMBOL_it_cota_exp = 110,              /* it_cota_exp  */
  YYSYMBOL_it_cota_fija = 111,             /* it_cota_fija  */
  YYSYMBOL_accion_d = 112,                 /* accion_d  */
  YYSYMBOL_funcion_d = 113,                /* funcion_d  */
  YYSYMBOL_a_cabecera = 114,               /* a_cabecera  */
  YYSYMBOL_f_cabecera = 115,               /* f_cabecera  */
  YYSYMBOL_d_par_form = 116,               /* d_par_form  */
  YYSYMBOL_d_p_form = 117,                 /* d_p_form  */
  YYSYMBOL_accion_ll = 118,                /* accion_ll  */
  YYSYMBOL_funcion_ll = 119,               /* funcion_ll  */
  YYSYMBOL_l_ll = 120                      /* l_ll  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   102,   105,   106,   107,   110,   111,
     112,   115,   118,   119,   120,   121,   135,   143,   146,   157,
     162,   187,   191,   205,   206,   207,   211,   214,   215,   222,
     229,   232,   236,   240,   244,   248,   262,   269,   273,   276,
     280,   296,   308,   315,   365,   366,   395,   413,   427,   428,
     429,   436,   439,   445,   446,   447,   450,   451,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   466,   467,
     468,   469,   470,   471,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   485,   486,   487,   488,   494,   495,   498,
     499,   500,   501,   502,   505,   508,   511,   512,   515,   516,
     519,   522,   527,   530,   533,   536,   539,   540,   543,   544,
     545,   548,   551,   554,   555
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BI_COMENTARIO",
  "BI_LIT_ENTERO", "BI_LIT_REAL", "BI_LIT_BOOLEANO", "BI_LIT_CARACTER",
  "BI_LIT_CADENA", "BI_PR_ENTERO", "BI_PR_REAL", "BI_PR_BOOLEANO",
  "BI_PR_CARACTER", "BI_PR_CADENA", "BI_ACCION", "BI_FACCION",
  "BI_ALGORITMO", "BI_FALGORITMO", "BI_CONST", "BI_FCONST", "BI_FUNCION",
  "BI_FFUNCION", "BI_MIENTRAS", "BI_FMIENTRAS", "BI_PARA", "BI_FPARA",
  "BI_SI", "BI_FSI", "BI_TIPO", "BI_FTIPO", "BI_TUPLA", "BI_FTUPLA",
  "BI_VAR", "BI_FVAR", "BI_CONTINUAR", "BI_DE", "BI_DEV", "BI_DIV",
  "BI_ENT", "BI_E_S", "BI_FALSO", "BI_HACER", "BI_HASTA", "BI_REF",
  "BI_SAL", "BI_TABLA", "BI_VERDADERO", "BI_Y", "BI_O", "BI_NO",
  "BI_ASIGNACION", "BI_COMP_SEQ", "BI_SEPARADOR", "BI_SUBRANGO",
  "BI_DEF_TYPEVAR", "BI_ENTONCES", "BI_CREACION_TIPO", "BI_SINOSI",
  "BI_INI_ARRAY", "BI_FIN_ARRAY", "BI_IDENTIFICADOR", "BI_PUNTO",
  "BI_PAR_APER", "BI_PAR_CIER", "BI_SUMA", "BI_RESTA", "BI_MULTIPLICACION",
  "BI_DIVISION", "BI_MOD", "BI_MENOR", "BI_MAYOR", "BI_MENOR_IGUAL",
  "BI_MAYOR_IGUAL", "BI_IGUALDAD", "BI_DISTINTO", "$accept",
  "desc_algoritmo", "cabecera_alg", "bloque_alg", "decl_globales",
  "decl_a_f", "bloque", "declaraciones", "declaracion_tipo",
  "declaracion_cte", "declaracion_var", "lista_d_tipo", "d_tipo",
  "expresion_t", "lista_campos", "tipo_base", "literal", "lista_d_cte",
  "lista_d_var", "lista_id", "decl_ent_sal", "decl_ent", "decl_sal",
  "expresion", "literal_numerico", "exp_a", "oprel", "exp_b", "operando",
  "instrucciones", "instruccion", "asignacion", "alternativa",
  "lista_opciones", "iteracion", "it_cota_exp", "it_cota_fija", "accion_d",
  "funcion_d", "a_cabecera", "f_cabecera", "d_par_form", "d_p_form",
  "accion_ll", "funcion_ll", "l_ll", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -22,    40,     3,  -124,     9,    -8,    10,    98,     1,
       9,     9,    25,    65,    57,    88,    73,   121,   156,    -4,
      98,    98,    98,   103,   105,   111,     1,     1,  -124,  -124,
     233,   115,   141,   116,   118,   139,   128,  -124,  -124,   164,
     123,   164,  -124,   127,    54,  -124,   134,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,   133,    98,   140,    98,
      73,    73,   185,   161,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   142,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   147,  -124,   141,   154,  -124,   164,   -26,   164,
      27,   165,   172,  -124,   149,  -124,   224,   -14,   -32,  -124,
    -124,    73,   180,   187,   173,   201,   184,   213,   164,  -124,
     164,   164,   183,    -4,    52,   230,    73,   210,  -124,  -124,
    -124,  -124,    -8,   197,   223,  -124,   204,   149,   225,   164,
     110,   -24,  -124,    27,  -124,   -23,   -32,    10,   204,  -124,
    -124,  -124,  -124,  -124,  -124,   164,    27,    27,    27,  -124,
      27,    27,   164,   164,  -124,  -124,   -16,   211,    -4,   164,
      -4,    36,   200,   149,   244,   -32,  -124,    73,    73,    73,
    -124,   214,  -124,   237,   164,  -124,   141,  -124,   248,   239,
    -124,  -124,   110,  -124,  -124,   149,  -124,   -23,   -23,  -124,
    -124,   225,   225,    73,    73,   281,   186,   249,   164,  -124,
    -124,   251,   265,   266,    52,   216,   -11,   270,   204,  -124,
    -124,  -124,  -124,   164,   164,   295,  -124,   141,   141,   141,
    -124,  -124,  -124,   147,   264,   207,   238,  -124,  -124,  -124,
    -124,  -124,   289,    -4,    -4,   141,   300,   249,  -124,  -124,
    -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    42,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    45,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,     0,     0,     0,    47,     0,     0,     2,     4,     0,
       0,     0,    89,    83,     0,    11,    88,    90,    91,    92,
      99,    98,    93,    12,    13,    14,     0,    15,     0,    15,
      45,    45,     0,    48,    50,     8,     9,    36,    37,    38,
      39,    40,     0,    17,    56,    57,    28,    31,    32,    33,
      34,    35,    30,    80,     0,     0,    79,     0,    83,     0,
       0,     0,     0,    21,    27,    66,    53,    54,    65,    55,
      16,     0,     0,     0,    83,     0,     0,     0,     0,    86,
       0,     0,     0,     0,   107,     0,    45,     0,    51,    52,
       3,    49,    42,     0,     0,    23,     0,     0,    76,     0,
      53,    54,    83,     0,    66,    67,    65,    20,     0,    71,
      70,    73,    72,    68,    69,     0,     0,     0,     0,    60,
       0,     0,     0,     0,    46,    18,    83,     0,     0,     0,
       0,   114,     0,    94,     0,    84,    87,     0,     0,     0,
     104,     0,   102,     0,     0,    41,     0,    25,     0,     0,
      64,    82,     0,    19,    24,    81,    63,    58,    59,    61,
      62,    74,    75,    45,    45,     0,     0,    97,     0,   111,
      85,     0,     0,     0,   107,     0,     0,     0,     0,   112,
      43,    44,   100,     0,     0,     0,   113,     0,     0,     0,
     106,   105,   103,    30,     0,     0,     0,    95,   108,   110,
     109,    29,     0,     0,     0,     0,     0,    97,    26,   101,
      96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,   126,   131,   -10,   100,    62,   151,
    -124,   189,   -75,  -122,   104,  -124,  -124,   206,   -59,   -89,
    -124,  -124,   267,   -34,   -82,   -48,  -124,   -70,   -19,  -110,
    -124,  -124,  -124,    92,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,   129,  -124,  -124,  -124,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    91,    92,   124,    93,    72,    13,    35,    36,
      62,    63,    64,    94,    95,    96,   145,    97,    98,    45,
      46,    47,    48,   215,    49,    50,    51,    26,    27,    57,
      59,   170,   171,    52,    99,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   118,   119,   166,   178,   105,   179,   107,   134,   125,
     222,   109,   154,     1,   146,    23,   184,   128,    39,   131,
      40,    24,    41,   152,   153,   -22,   111,     6,   157,   112,
      42,    74,    75,   152,   153,   193,   129,     7,     3,   181,
       4,   130,   135,   149,   150,   151,   129,   115,   195,   117,
     197,   134,    12,   127,     5,   127,    43,   173,   139,   140,
     141,   142,   143,   144,   134,   134,   134,    10,   134,   134,
      14,   136,    10,    10,   161,   216,   163,   164,   201,   202,
     203,    30,   191,   192,    31,   182,   224,   132,   198,   133,
     167,   168,    90,   165,    44,   161,   169,   109,   186,   187,
     188,   207,   189,   190,   110,   139,   140,   141,   142,   143,
     144,   185,   111,    32,   136,   112,     6,    33,   127,   127,
      53,    54,    55,   236,   237,   196,     7,   136,   136,   136,
      16,   136,   136,    34,   210,   211,    28,    29,    37,    44,
     206,    44,   228,   229,   230,    74,    75,   146,    76,    60,
      77,    78,    79,    80,    81,    61,    11,    65,    66,    38,
     238,    11,    11,    56,   161,    58,    73,   100,    74,    75,
     101,    82,   102,   180,   147,   148,   149,   150,   151,   225,
     226,    83,   103,   106,    84,   113,    85,    86,   120,   108,
      87,    74,    75,   122,    76,   114,    77,    78,    79,    80,
      81,    88,   116,    89,    83,    61,    90,   123,    74,    75,
      86,    76,   126,    87,    44,    44,   137,    82,   139,   140,
     141,   142,   143,   144,   104,   138,    89,    83,   213,    90,
      84,   155,    85,    86,   159,   129,    87,    67,    68,    69,
      70,    71,   158,   132,    83,   172,   174,   156,   233,    89,
      86,   176,    90,    87,   177,   139,   140,   141,   142,   143,
     144,   146,   194,   199,   104,   204,    89,   221,   160,    90,
     139,   140,   141,   142,   143,   144,   139,   140,   141,   142,
     143,   144,   139,   140,   141,   142,   143,   144,   147,   148,
     149,   150,   151,   234,   -54,   -54,   -54,   -54,   -54,   -54,
     205,   208,   209,   200,   212,   217,   214,   139,   140,   141,
     142,   143,   144,   139,   140,   141,   142,   143,   144,   218,
     219,   223,   227,   232,   235,   239,   183,   231,   175,   240,
     121,     0,     0,   220
};

static const yytype_int16 yycheck[] =
{
      19,    60,    61,   113,   126,    39,   129,    41,    90,    84,
      21,    43,   101,    16,    37,    14,   138,    87,    22,    89,
      24,    20,    26,    47,    48,    51,    58,    18,   103,    61,
      34,     4,     5,    47,    48,    51,    62,    28,    60,    63,
       0,    89,    90,    66,    67,    68,    62,    57,   158,    59,
     160,   133,    60,    87,    51,    89,    60,   116,    69,    70,
      71,    72,    73,    74,   146,   147,   148,     5,   150,   151,
      60,    90,    10,    11,   108,   198,   110,   111,   167,   168,
     169,    56,   152,   153,    19,   133,   208,    60,    52,    62,
      38,    39,    65,   112,   113,   129,    44,    43,   146,   147,
     148,   176,   150,   151,    50,    69,    70,    71,    72,    73,
      74,   145,    58,    56,   133,    61,    18,    29,   152,   153,
      20,    21,    22,   233,   234,   159,    28,   146,   147,   148,
      32,   150,   151,    60,   193,   194,    10,    11,    17,   158,
     174,   160,   217,   218,   219,     4,     5,    37,     7,    38,
       9,    10,    11,    12,    13,    44,     5,    26,    27,     3,
     235,    10,    11,    60,   198,    60,    51,    51,     4,     5,
      52,    30,    33,    63,    64,    65,    66,    67,    68,   213,
     214,    40,    54,    60,    43,    51,    45,    46,     3,    62,
      49,     4,     5,    51,     7,    62,     9,    10,    11,    12,
      13,    60,    62,    62,    40,    44,    65,    60,     4,     5,
      46,     7,    58,    49,   233,   234,    51,    30,    69,    70,
      71,    72,    73,    74,    60,    53,    62,    40,    42,    65,
      43,    51,    45,    46,    50,    62,    49,     4,     5,     6,
       7,     8,    41,    60,    40,    15,    36,    60,    41,    62,
      46,    54,    65,    49,    31,    69,    70,    71,    72,    73,
      74,    37,    51,    63,    60,    51,    62,    51,    55,    65,
      69,    70,    71,    72,    73,    74,    69,    70,    71,    72,
      73,    74,    69,    70,    71,    72,    73,    74,    64,    65,
      66,    67,    68,    55,    69,    70,    71,    72,    73,    74,
      63,    53,    63,    59,    23,    54,    57,    69,    70,    71,
      72,    73,    74,    69,    70,    71,    72,    73,    74,    54,
      54,    51,    27,    59,    35,    25,   137,   223,   122,   237,
      63,    -1,    -1,   204
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    76,    60,     0,    51,    18,    28,    77,    79,
      83,    84,    60,    92,    60,    86,    32,    78,    81,    82,
      83,    84,    85,    14,    20,    80,   112,   113,    79,    79,
      56,    19,    56,    29,    60,    93,    94,    17,     3,    22,
      24,    26,    34,    60,   103,   104,   105,   106,   107,   109,
     110,   111,   118,    82,    82,    82,    60,   114,    60,   115,
      38,    44,    95,    96,    97,    80,    80,     4,     5,     6,
       7,     8,    91,    51,     4,     5,     7,     9,    10,    11,
      12,    13,    30,    40,    43,    45,    46,    49,    60,    62,
      65,    87,    88,    90,    98,    99,   100,   102,   103,   119,
      51,    52,    33,    54,    60,    98,    60,    98,    62,    43,
      50,    58,    61,    51,    62,    81,    62,    81,    93,    93,
       3,    97,    51,    60,    89,    87,    58,    98,   102,    62,
     100,   102,    60,    62,    99,   100,   103,    51,    53,    69,
      70,    71,    72,    73,    74,   101,    37,    64,    65,    66,
      67,    68,    47,    48,    94,    51,    60,    87,    41,    50,
      55,    98,   120,    98,    98,   103,   104,    38,    39,    44,
     116,   117,    15,    93,    36,    92,    54,    31,    88,   120,
      63,    63,   100,    86,    88,    98,   100,   100,   100,   100,
     100,   102,   102,    51,    51,   104,    98,   104,    52,    63,
      59,    94,    94,    94,    51,    63,    98,    87,    53,    63,
      93,    93,    23,    42,    57,   108,   120,    54,    54,    54,
     116,    51,    21,    51,    88,    98,    98,    27,    87,    87,
      87,    89,    59,    41,    55,    35,   104,   104,    87,    25,
     108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    78,    79,    79,    79,    80,    80,
      80,    81,    82,    82,    82,    82,    83,    84,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      95,    96,    97,    98,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   106,   107,   108,   108,   109,   109,
     110,   111,   112,   113,   114,   115,   116,   116,   117,   117,
     117,   118,   119,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     4,     4,     4,     5,
       0,     1,     1,     2,     3,     3,     8,     1,     1,     5,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     5,     5,     0,     3,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     1,     1,     1,
       1,     3,     3,     1,     3,     4,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     6,     5,     0,     1,     1,
       5,     9,     4,     6,     3,     5,     3,     0,     4,     4,
       4,     4,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 19: /* lista_d_tipo: BI_IDENTIFICADOR BI_CREACION_TIPO d_tipo BI_COMP_SEQ lista_d_tipo  */
#line 158 "scanner.y"
                                {


				}
#line 1498 "scanner.tab.c"
    break;

  case 21: /* d_tipo: tipo_base  */
#line 188 "scanner.y"
                                {
					/****duda: es integer? */
				}
#line 1506 "scanner.tab.c"
    break;

  case 22: /* d_tipo: BI_IDENTIFICADOR  */
#line 192 "scanner.y"
                                {

					char *type = get_attr(st, yyvsp[0], "type");

					if ( !type ) {
						printf("Identifier %s doesnt exist", yyvsp[0]);
					} else {
						// strcpy();
						yyval = type;
					}


				}
#line 1524 "scanner.tab.c"
    break;

  case 25: /* d_tipo: BI_TUPLA lista_campos BI_FTUPLA  */
#line 208 "scanner.y"
                                {
					/* Que devolver ??? tupla*/
				}
#line 1532 "scanner.tab.c"
    break;

  case 29: /* lista_campos: BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos  */
#line 223 "scanner.y"
                                {

					insertSymbol(st, yyvsp[-4]);
					set_attr(st, yyvsp[-4], "type", yyvsp[-2]);

				}
#line 1543 "scanner.tab.c"
    break;

  case 31: /* tipo_base: BI_PR_ENTERO  */
#line 233 "scanner.y"
                                {
					yyval = INTEGER;
				}
#line 1551 "scanner.tab.c"
    break;

  case 32: /* tipo_base: BI_PR_REAL  */
#line 237 "scanner.y"
                                {
					yyval = FLOAT;
				}
#line 1559 "scanner.tab.c"
    break;

  case 33: /* tipo_base: BI_PR_BOOLEANO  */
#line 241 "scanner.y"
                                {
					yyval = BOOLEAN;
				}
#line 1567 "scanner.tab.c"
    break;

  case 34: /* tipo_base: BI_PR_CARACTER  */
#line 245 "scanner.y"
                                {
					yyval = CHARACTER;
				}
#line 1575 "scanner.tab.c"
    break;

  case 35: /* tipo_base: BI_PR_CADENA  */
#line 249 "scanner.y"
                                {
					yyval = STRING;
				}
#line 1583 "scanner.tab.c"
    break;

  case 36: /* literal: BI_LIT_ENTERO  */
#line 263 "scanner.y"
                                {

					printf("LITERAL_ENTERO");

					yyval = INTEGER;
				}
#line 1594 "scanner.tab.c"
    break;

  case 37: /* literal: BI_LIT_REAL  */
#line 270 "scanner.y"
                                {
					yyval = FLOAT;
				}
#line 1602 "scanner.tab.c"
    break;

  case 38: /* literal: BI_LIT_BOOLEANO  */
#line 273 "scanner.y"
                                                       {
					yyval = BOOLEAN;
				}
#line 1610 "scanner.tab.c"
    break;

  case 39: /* literal: BI_LIT_CARACTER  */
#line 276 "scanner.y"
                                                       {

					yyval = CHARACTER;
				}
#line 1619 "scanner.tab.c"
    break;

  case 40: /* literal: BI_LIT_CADENA  */
#line 280 "scanner.y"
                                                     {
					yyval = STRING;
				}
#line 1627 "scanner.tab.c"
    break;

  case 41: /* lista_d_cte: BI_IDENTIFICADOR BI_CREACION_TIPO literal BI_COMP_SEQ lista_d_cte  */
#line 297 "scanner.y"
                                {


					/** 
					  * We insert the identifier into the symbol table and we define its scope and type.
					  * in this case scope will be, const. The type is returned by literal grammar rule 
					  */
					insertSymbol(st, yyvsp[-4]);
					set_attr(st, yyvsp[-4], "scope", "cte");
					set_attr(st, yyvsp[-4], "type", yyvsp[-2])
				}
#line 1643 "scanner.tab.c"
    break;

  case 43: /* lista_d_var: lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var  */
#line 315 "scanner.y"
                                                                                                 {

				/* Debug */
				if ( lookup(st, yyvsp[-2]) ) {

					char *type;

					if ( ( type = get_attr(st, %3) ) ) {
						
						/* 
						 * Now we need to assign type to all identifiers reduced by lista_id grammar rule.
						 * Those identifiers have been added to symbol table and they have been added to 
						 * stack. For each identifier, we set the type and we remove it from the stack.
						 */

						while ( !esNulaPila( stack ) ) {

							char *id = cima( stack );

							if ( set_attr(st, id, type) == -1 ) {
								printf("Identifier %s is not in the symbol table", id);
							}

							desapilar( stack );

						}

					} else {
						printf("Symbol %s type is not defined\n", yyvsp[-2]);
					}


				} else {
					printf("The symbol %s doesnt seem to be decalred\n", yyvsp[-2]);
				}


				/* 
				 * get_attr() function includes lookup, so its not necessary 
				 * to make a lookup before get_attr(). In this case is done for
				 * debugginf reesons 
				 */
				if ( get_attr(st, %3) ) {

				} else {
					printf("Symbol %s type is not defined\n", yyvsp[-2]);
				}


}
#line 1698 "scanner.tab.c"
    break;

  case 46: /* lista_id: BI_IDENTIFICADOR BI_SEPARADOR lista_id  */
#line 396 "scanner.y"
                                {

					if ( !lookup(st, yyvsp[-2]) ) {

						insertSymbol(st, yyvsp[-2]);
						
						/* 
						 * We add identifiers to stack, to be able to set their type
						 * when we know it 
						 */
						apilar(stack, yyvsp[-2]);


					} else {
						printf("Identifier alredy exists")
					}
				}
#line 1720 "scanner.tab.c"
    break;

  case 47: /* lista_id: BI_IDENTIFICADOR  */
#line 414 "scanner.y"
                                {

					if ( !lookup(st, yyvsp[0]) ) {
						
						insertSymbol(st, yyvsp[0]);
						apilar(stack, yyvsp[0]);

					} else {
						printf("Identifier alredy exists")
					}
				}
#line 1736 "scanner.tab.c"
    break;


#line 1740 "scanner.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 560 "scanner.y"



int main(int argc, char const *argv[])
{
	
	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;


	return 0;
}





















