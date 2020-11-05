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
#line 1 "src/parser.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <errno.h>
	#include <string.h>

	#include "lib/symboltable/symbol_table.h"
	#include "lib/quadruples/quadruples.h"
	#include "lib/exp_a_b/exp_a_b.h"
	#include "lib/stack/stack.h"
	#include "lib/util.h"


	extern int yylex();
	extern FILE *yyin;
	extern int yylineno;
	
	void yyerror (const char *);

	Symbol *st[HT_SIZE];
	QuadTable *qt;

	Stack stack;

	FILE *fdebug;


#line 99 "parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_exp_a_b = 99,                   /* exp_a_b  */
  YYSYMBOL_M = 100,                        /* M  */
  YYSYMBOL_oprel = 101,                    /* oprel  */
  YYSYMBOL_operando = 102,                 /* operando  */
  YYSYMBOL_instrucciones = 103,            /* instrucciones  */
  YYSYMBOL_instruccion = 104,              /* instruccion  */
  YYSYMBOL_asignacion = 105,               /* asignacion  */
  YYSYMBOL_alternativa = 106,              /* alternativa  */
  YYSYMBOL_lista_opciones = 107,           /* lista_opciones  */
  YYSYMBOL_iteracion = 108,                /* iteracion  */
  YYSYMBOL_it_cota_exp = 109,              /* it_cota_exp  */
  YYSYMBOL_it_cota_fija = 110,             /* it_cota_fija  */
  YYSYMBOL_accion_d = 111,                 /* accion_d  */
  YYSYMBOL_funcion_d = 112,                /* funcion_d  */
  YYSYMBOL_a_cabecera = 113,               /* a_cabecera  */
  YYSYMBOL_f_cabecera = 114,               /* f_cabecera  */
  YYSYMBOL_d_par_form = 115,               /* d_par_form  */
  YYSYMBOL_d_p_form = 116,                 /* d_p_form  */
  YYSYMBOL_accion_ll = 117,                /* accion_ll  */
  YYSYMBOL_funcion_ll = 118,               /* funcion_ll  */
  YYSYMBOL_l_ll = 119                      /* l_ll  */
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
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

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
       0,   162,   162,   165,   168,   171,   172,   173,   176,   177,
     178,   181,   184,   185,   186,   187,   201,   209,   212,   223,
     228,   252,   256,   272,   273,   274,   278,   281,   282,   289,
     301,   304,   308,   312,   316,   320,   334,   338,   342,   346,
     350,   367,   382,   389,   439,   440,   469,   487,   504,   505,
     506,   513,   516,   522,   523,   526,   572,   616,   660,   722,
     766,   821,   830,   837,   865,   869,   891,   912,   932,   952,
     983,  1002,  1030,  1034,  1035,  1036,  1037,  1038,  1039,  1051,
    1079,  1080,  1081,  1087,  1088,  1091,  1092,  1093,  1094,  1095,
    1098,  1151,  1154,  1155,  1158,  1159,  1162,  1165,  1170,  1173,
    1176,  1179,  1182,  1183,  1186,  1187,  1188,  1191,  1194,  1197,
    1198
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
  "expresion", "exp_a_b", "M", "oprel", "operando", "instrucciones",
  "instruccion", "asignacion", "alternativa", "lista_opciones",
  "iteracion", "it_cota_exp", "it_cota_fija", "accion_d", "funcion_d",
  "a_cabecera", "f_cabecera", "d_par_form", "d_p_form", "accion_ll",
  "funcion_ll", "l_ll", YY_NULLPTR
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

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -37,    25,    30,  -122,     0,   -16,    -4,    27,     2,
       0,     0,    45,    98,    87,    79,    85,   138,   154,    -7,
      27,    27,    27,   106,   112,    89,     2,     2,  -122,  -122,
     321,  -122,   137,   125,   126,   148,   136,  -122,  -122,   170,
     131,   170,  -122,   134,    -1,  -122,   142,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,   139,    27,   141,    27,
      85,    85,   197,   160,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,   167,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,   145,  -122,   137,   159,  -122,   170,    51,   170,   170,
     169,   168,  -122,   235,   234,    53,  -122,  -122,    85,  -122,
     149,   162,    13,   173,   -34,   170,  -122,   170,   170,   165,
      -7,     8,   212,    85,   193,  -122,  -122,  -122,  -122,   -16,
     180,   205,  -122,   166,   235,   176,   170,   229,   185,    -4,
     166,  -122,  -122,  -122,  -122,  -122,  -122,   170,   170,  -122,
    -122,   170,   170,   170,   170,   170,  -122,    58,   186,    -7,
     170,    -7,   -40,   175,   235,   244,  -122,    53,  -122,    85,
      85,    85,  -122,   188,  -122,   204,   170,  -122,   137,  -122,
     215,   207,  -122,  -122,  -122,   235,   250,   170,   170,   185,
     185,   250,   250,   250,    85,    85,   249,   191,   216,   170,
    -122,  -122,   220,   221,   224,     8,   228,     5,   238,   166,
    -122,   176,   176,  -122,  -122,  -122,   170,   170,   253,  -122,
     137,   137,   137,  -122,  -122,  -122,   145,   231,    52,   214,
    -122,  -122,  -122,  -122,  -122,   256,    -7,    -7,   137,   285,
     216,  -122,  -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    42,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    45,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,    17,     0,     0,    47,     0,     0,     2,     4,     0,
       0,     0,    85,    79,     0,    11,    84,    86,    87,    88,
      95,    94,    89,    12,    13,    14,     0,    15,     0,    15,
      45,    45,     0,    48,    50,     8,     9,    36,    37,    38,
      39,    40,     0,    61,    62,    28,    31,    32,    33,    34,
      35,    30,    71,     0,     0,    70,     0,    79,     0,     0,
       0,     0,    21,    27,    53,    64,    54,    16,     0,    18,
       0,    79,     0,     0,     0,     0,    82,     0,     0,     0,
       0,   103,     0,    45,     0,    51,    52,     3,    49,    42,
       0,     0,    23,     0,     0,    67,     0,    53,    63,    20,
       0,    77,    75,    78,    76,    73,    74,     0,     0,    72,
      72,     0,     0,     0,     0,     0,    46,    79,     0,     0,
       0,     0,   110,     0,    90,     0,    79,    80,    83,     0,
       0,     0,   100,     0,    98,     0,     0,    41,     0,    25,
       0,     0,    68,    19,    24,    69,    60,     0,     0,    55,
      56,    57,    58,    59,    45,    45,     0,     0,    93,     0,
     107,    81,     0,     0,     0,   103,     0,     0,     0,     0,
     108,    66,    65,    43,    44,    96,     0,     0,     0,   109,
       0,     0,     0,   102,   101,    99,    30,     0,     0,     0,
      91,   104,   106,   105,    29,     0,     0,     0,     0,     0,
      93,    26,    97,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   174,   161,    72,   143,    84,   105,
    -122,   182,   -76,  -119,    96,  -122,  -122,   211,   -47,   -88,
    -122,  -122,   268,   -38,   -80,   192,  -122,   -19,  -108,  -122,
    -122,  -122,   103,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
     140,  -122,  -122,  -122,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    90,    91,   121,    92,    72,    13,    35,    36,
      62,    63,    64,    93,    94,   177,   137,    95,    45,    46,
      47,    48,   208,    49,    50,    51,    26,    27,    57,    59,
     162,   163,    52,    96,   153
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   102,   158,   104,   170,   171,   125,   122,   127,   128,
     146,   174,   189,   115,   116,    39,    23,    40,     6,    41,
       1,   151,    24,     3,   148,     4,   215,    42,     7,   131,
     132,   133,   134,   135,   136,   131,   132,   133,   134,   135,
     136,   186,   106,   188,    12,     6,   159,   160,   124,   107,
     124,   124,   161,    43,   149,     7,    14,   108,   176,    16,
     109,   179,   180,   181,   182,   183,   165,   152,   209,   154,
     155,   192,   193,   194,   131,   132,   133,   134,   135,   136,
     217,     5,   131,   132,   133,   134,   135,   136,   152,    10,
     157,    44,   198,   226,    10,    10,   106,   201,   202,   175,
     124,    30,   -22,   124,   124,   124,   124,   124,    33,   184,
      11,   108,   187,   126,   109,    11,    11,    31,   229,   230,
     126,   131,   132,   133,   134,   135,   136,    60,   197,   112,
      44,   114,    44,    61,   221,   222,   223,   203,   204,   124,
     124,    73,    74,    32,    75,    34,    76,    77,    78,    79,
      80,   152,   231,    73,    74,    37,    75,    38,    76,    77,
      78,    79,    80,    53,    54,    55,    56,    81,   218,   219,
      73,    74,    58,    75,    73,    74,    97,    82,    98,    81,
      83,    99,    84,    85,    28,    29,    86,    65,    66,    82,
     100,   103,    83,   110,    84,    85,   105,    87,    86,    88,
     117,   111,    89,   113,    61,   120,    82,    44,    44,   147,
      82,    88,    85,   138,    89,    86,    85,   123,   119,    86,
     129,   130,   138,   150,   126,   156,   101,   164,    88,   166,
     101,    89,    88,   206,   168,    89,   169,   185,   190,   195,
     141,   142,   143,   144,   145,   -53,   -53,   -53,   -53,   -53,
     -53,   143,   144,   145,   -53,   -53,   -53,   -53,   -53,   -53,
     131,   132,   133,   134,   135,   136,   138,   196,   199,   227,
     200,   138,   205,   207,   210,   211,   139,   140,   212,   214,
     220,   139,   140,   131,   132,   133,   134,   135,   136,   216,
     225,   228,   172,   141,   142,   143,   144,   145,   141,   142,
     143,   144,   145,   191,   131,   132,   133,   134,   135,   136,
     232,   173,   224,   131,   132,   133,   134,   135,   136,   -53,
     -53,   -53,   -53,   -53,   -53,    67,    68,    69,    70,    71,
     167,   118,   178,   233,     0,   213
};

static const yytype_int16 yycheck[] =
{
      19,    39,   110,    41,   123,   126,    86,    83,    88,    89,
      98,   130,    52,    60,    61,    22,    14,    24,    18,    26,
      16,    55,    20,    60,   100,     0,    21,    34,    28,    69,
      70,    71,    72,    73,    74,    69,    70,    71,    72,    73,
      74,   149,    43,   151,    60,    18,    38,    39,    86,    50,
      88,    89,    44,    60,    41,    28,    60,    58,   138,    32,
      61,   141,   142,   143,   144,   145,   113,   105,   189,   107,
     108,   159,   160,   161,    69,    70,    71,    72,    73,    74,
     199,    51,    69,    70,    71,    72,    73,    74,   126,     5,
     109,   110,   168,    41,    10,    11,    43,   177,   178,   137,
     138,    56,    51,   141,   142,   143,   144,   145,    29,    51,
       5,    58,   150,    62,    61,    10,    11,    19,   226,   227,
      62,    69,    70,    71,    72,    73,    74,    38,   166,    57,
     149,    59,   151,    44,   210,   211,   212,   184,   185,   177,
     178,     4,     5,    56,     7,    60,     9,    10,    11,    12,
      13,   189,   228,     4,     5,    17,     7,     3,     9,    10,
      11,    12,    13,    20,    21,    22,    60,    30,   206,   207,
       4,     5,    60,     7,     4,     5,    51,    40,    52,    30,
      43,    33,    45,    46,    10,    11,    49,    26,    27,    40,
      54,    60,    43,    51,    45,    46,    62,    60,    49,    62,
       3,    62,    65,    62,    44,    60,    40,   226,   227,    60,
      40,    62,    46,    37,    65,    49,    46,    58,    51,    49,
      51,    53,    37,    50,    62,    60,    60,    15,    62,    36,
      60,    65,    62,    42,    54,    65,    31,    51,    63,    51,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      69,    70,    71,    72,    73,    74,    37,    63,    53,    55,
      63,    37,    23,    57,    54,    54,    47,    48,    54,    51,
      27,    47,    48,    69,    70,    71,    72,    73,    74,    51,
      59,    35,    63,    64,    65,    66,    67,    68,    64,    65,
      66,    67,    68,    59,    69,    70,    71,    72,    73,    74,
      25,   129,   216,    69,    70,    71,    72,    73,    74,    69,
      70,    71,    72,    73,    74,     4,     5,     6,     7,     8,
     119,    63,   140,   230,    -1,   195
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    76,    60,     0,    51,    18,    28,    77,    79,
      83,    84,    60,    92,    60,    86,    32,    78,    81,    82,
      83,    84,    85,    14,    20,    80,   111,   112,    79,    79,
      56,    19,    56,    29,    60,    93,    94,    17,     3,    22,
      24,    26,    34,    60,   102,   103,   104,   105,   106,   108,
     109,   110,   117,    82,    82,    82,    60,   113,    60,   114,
      38,    44,    95,    96,    97,    80,    80,     4,     5,     6,
       7,     8,    91,     4,     5,     7,     9,    10,    11,    12,
      13,    30,    40,    43,    45,    46,    49,    60,    62,    65,
      87,    88,    90,    98,    99,   102,   118,    51,    52,    33,
      54,    60,    98,    60,    98,    62,    43,    50,    58,    61,
      51,    62,    81,    62,    81,    93,    93,     3,    97,    51,
      60,    89,    87,    58,    98,    99,    62,    99,    99,    51,
      53,    69,    70,    71,    72,    73,    74,   101,    37,    47,
      48,    64,    65,    66,    67,    68,    94,    60,    87,    41,
      50,    55,    98,   119,    98,    98,    60,   102,   103,    38,
      39,    44,   115,   116,    15,    93,    36,    92,    54,    31,
      88,   119,    63,    86,    88,    98,    99,   100,   100,    99,
      99,    99,    99,    99,    51,    51,   103,    98,   103,    52,
      63,    59,    94,    94,    94,    51,    63,    98,    87,    53,
      63,    99,    99,    93,    93,    23,    42,    57,   107,   119,
      54,    54,    54,   115,    51,    21,    51,    88,    98,    98,
      27,    87,    87,    87,    89,    59,    41,    55,    35,   103,
     103,    87,    25,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    78,    79,    79,    79,    80,    80,
      80,    81,    82,    82,    82,    82,    83,    84,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      95,    96,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   104,
     105,   106,   107,   107,   108,   108,   109,   110,   111,   112,
     113,   114,   115,   115,   116,   116,   116,   117,   118,   119,
     119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     4,     3,     3,     5,
       0,     1,     1,     2,     3,     3,     8,     1,     1,     5,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     5,     5,     0,     3,     1,     1,     2,
       1,     2,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     4,     4,     2,     3,     3,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     6,     5,     0,     1,     1,     5,     9,     4,     6,
       3,     5,     3,     0,     4,     4,     4,     4,     4,     3,
       1
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
#line 224 "src/parser.y"
                                {


				}
#line 1403 "parser.tab.c"
    break;

  case 21: /* d_tipo: tipo_base  */
#line 253 "src/parser.y"
                                {
					
				}
#line 1411 "parser.tab.c"
    break;

  case 22: /* d_tipo: BI_IDENTIFICADOR  */
#line 257 "src/parser.y"
                                {
					#ifdef _DEBUG
					printf("d_tipo:BI_IDENTIFICADOR");
					printf("debug: d_tipo");
					#endif
					/*cchar *type = get_type( st, $1 );

					if ( type == UNKNOWN_SYMBOL ) {
						printf("Error: Unknown symbol %s", $1);
					} else {
						$$ = type;
					}*/


				}
#line 1431 "parser.tab.c"
    break;

  case 23: /* d_tipo: BI_REF d_tipo  */
#line 272 "src/parser.y"
                                                     {}
#line 1437 "parser.tab.c"
    break;

  case 24: /* d_tipo: expresion_t BI_SUBRANGO expresion_t  */
#line 273 "src/parser.y"
                                                                           {}
#line 1443 "parser.tab.c"
    break;

  case 25: /* d_tipo: BI_TUPLA lista_campos BI_FTUPLA  */
#line 275 "src/parser.y"
                                {
					/* Que devolver ??? tupla*/
				}
#line 1451 "parser.tab.c"
    break;

  case 26: /* d_tipo: BI_TABLA BI_INI_ARRAY expresion_t BI_SUBRANGO expresion_t BI_FIN_ARRAY BI_DE d_tipo  */
#line 278 "src/parser.y"
                                                                                                                           {}
#line 1457 "parser.tab.c"
    break;

  case 29: /* lista_campos: BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos  */
#line 290 "src/parser.y"
                                {

					#ifdef _DEBUG
					printf("lista de campos:\n");
					printf("BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos\n");
					#endif

					/*add_symbol(st, $1);
					set_symbol_type(st, $1, $3);*/

				}
#line 1473 "parser.tab.c"
    break;

  case 31: /* tipo_base: BI_PR_ENTERO  */
#line 305 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_INTEGER;
				}
#line 1481 "parser.tab.c"
    break;

  case 32: /* tipo_base: BI_PR_REAL  */
#line 309 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_REAL;
				}
#line 1489 "parser.tab.c"
    break;

  case 33: /* tipo_base: BI_PR_BOOLEANO  */
#line 313 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_BOOLEAN;
				}
#line 1497 "parser.tab.c"
    break;

  case 34: /* tipo_base: BI_PR_CARACTER  */
#line 317 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_CHAR;
				}
#line 1505 "parser.tab.c"
    break;

  case 35: /* tipo_base: BI_PR_CADENA  */
#line 321 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_STRING;
				}
#line 1513 "parser.tab.c"
    break;

  case 36: /* literal: BI_LIT_ENTERO  */
#line 335 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_INTEGER;
				}
#line 1521 "parser.tab.c"
    break;

  case 37: /* literal: BI_LIT_REAL  */
#line 339 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_REAL;
				}
#line 1529 "parser.tab.c"
    break;

  case 38: /* literal: BI_LIT_BOOLEANO  */
#line 343 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_BOOLEAN;
				}
#line 1537 "parser.tab.c"
    break;

  case 39: /* literal: BI_LIT_CARACTER  */
#line 347 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_CHAR;
				}
#line 1545 "parser.tab.c"
    break;

  case 40: /* literal: BI_LIT_CADENA  */
#line 351 "src/parser.y"
                                {
					(yyval.data_type) = DATA_TYPE_STRING;
				}
#line 1553 "parser.tab.c"
    break;

  case 41: /* lista_d_cte: BI_IDENTIFICADOR BI_CREACION_TIPO literal BI_COMP_SEQ lista_d_cte  */
#line 368 "src/parser.y"
                                {

					#ifdef _DEBUG
					printf("lista_d_cte");
					#endif

					/** 
					  * We insert the identifier into the symbol table and we define its scope and type.
					  * in this case scope will be, const. The type is returned by literal grammar rule 
					  */
					add_symbol( st, new_symbol( (yyvsp[-4].sval) ) );
					//set_attr(st, $1, "scope", "cte");
					set_symbol_type(st, (yyvsp[-4].sval), (yyvsp[-2].data_type));
				}
#line 1572 "parser.tab.c"
    break;

  case 43: /* lista_d_var: lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var  */
#line 389 "src/parser.y"
                                                                                                 {

				/* Debug */
				if ( lookup(st, (yyvsp[-2].sval)) ) {

					Data_type type;

					if ( ( type = get_symbol_type(st, (yyvsp[-2].sval)) ) ) {
						
						/* 
						 * Now we need to assign type to all identifiers reduced by lista_id grammar rule.
						 * Those identifiers have been added to symbol table and they have been added to 
						 * stack. For each identifier, we set the type and we remove it from the stack.
						 */

						/*while ( !esNulaPila( stack ) ) {

							char *id = cima( stack );

							if ( set_attr(st, id, type) == -1 ) {
								printf("Identifier %s is not in the symbol table", id);
							}

							desapilar( stack );

						}*/

					} else {
						printf("Symbol %s type is not defined\n", (yyvsp[-2].sval));
					}


				} else {
					printf("The symbol %s doesnt seem to be decalred\n", (yyvsp[-2].sval));
				}


				/* 
				 * get_attr() function includes lookup, so its not necessary 
				 * to make a lookup before get_attr(). In this case is done for
				 * debugginf reesons 
				 */
				if ( get_symbol_type(st, (yyvsp[-2].sval)) ) {

				} else {
					printf("Symbol %s type is not defined\n", (yyvsp[-2].sval));
				}


}
#line 1627 "parser.tab.c"
    break;

  case 46: /* lista_id: BI_IDENTIFICADOR BI_SEPARADOR lista_id  */
#line 470 "src/parser.y"
                                {

					if ( !lookup(st, (yyvsp[-2].sval)) ) {

						add_symbol( st, new_symbol( (yyvsp[-2].sval) ) );
						
						/* 
						 * We add identifiers to stack, to be able to set their type
						 * when we know it 
						 */
						//apilar(stack, $1);


					} else {
						printf("Identifier alredy exists");
					}
				}
#line 1649 "parser.tab.c"
    break;

  case 47: /* lista_id: BI_IDENTIFICADOR  */
#line 488 "src/parser.y"
                                {

					printf("debug: list_id");

					if ( !lookup(st, (yyvsp[0].sval)) ) {
						

						add_symbol( st, new_symbol( (yyvsp[0].sval) ) );
						//apilar(stack, $1);

					} else {
						printf("Identifier alredy exists");
					}
				}
#line 1668 "parser.tab.c"
    break;

  case 54: /* expresion: funcion_ll  */
#line 523 "src/parser.y"
                                                  {}
#line 1674 "parser.tab.c"
    break;

  case 55: /* exp_a_b: exp_a_b BI_SUMA exp_a_b  */
#line 527 "src/parser.y"
                                {

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUM, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUM, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

				}
#line 1724 "parser.tab.c"
    break;

  case 56: /* exp_a_b: exp_a_b BI_RESTA exp_a_b  */
#line 573 "src/parser.y"
                                {
					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUBS, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUBS, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1772 "parser.tab.c"
    break;

  case 57: /* exp_a_b: exp_a_b BI_MULTIPLICACION exp_a_b  */
#line 617 "src/parser.y"
                                {
					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTMULT, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALMULT, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1820 "parser.tab.c"
    break;

  case 58: /* exp_a_b: exp_a_b BI_DIVISION exp_a_b  */
#line 661 "src/parser.y"
                                {

				/**
				 * In case the argumnets are integers we need to convert them to 
				 * real before realizing the division. If both arguments are of
				 * integer type, we need another tmp variable to store the result
				 * of the conversions. 
				 *
				 */

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);


					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( st, tmp_symbol );
						
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1886 "parser.tab.c"
    break;

  case 59: /* exp_a_b: exp_a_b BI_MOD exp_a_b  */
#line 723 "src/parser.y"
                                {

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad(QUAD_OP_INTMOD, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALMOD, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1934 "parser.tab.c"
    break;

  case 60: /* exp_a_b: exp_a_b BI_DIV exp_a_b  */
#line 767 "src/parser.y"
                                {

					/* div is division in which the fractional part (remainder) is discarded */

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);


					if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( st, tmp_symbol );

						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
					}
					else if ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, (yyval.exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, (yyval.exp)->s->id, (yyvsp[-2].exp)->s->id, (yyval.exp)->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

					/* Convert result to INTEGER */
					Quad *q = new_quad(QUAD_OP_REAL2INT, (yyval.exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
					gen(qt, q);
					
					(yyval.exp)->s->type = DATA_TYPE_INTEGER;
				}
#line 1993 "parser.tab.c"
    break;

  case 61: /* exp_a_b: BI_LIT_ENTERO  */
#line 822 "src/parser.y"
                                {

					(yyval.exp) = new_exp_a_b( ARITHMETIC_EXP );
					(yyval.exp)->s = new_symbol( "_tmp" );
					(yyval.exp)->s->type = DATA_TYPE_INTEGER;
					add_symbol(st, (yyval.exp)->s);

				}
#line 2006 "parser.tab.c"
    break;

  case 62: /* exp_a_b: BI_LIT_REAL  */
#line 831 "src/parser.y"
                                {
					(yyval.exp) = new_exp_a_b( ARITHMETIC_EXP );
					(yyval.exp)->s = new_symbol( "_tmp" );
					(yyval.exp)->s->type = DATA_TYPE_REAL;
					add_symbol(st, (yyval.exp)->s);
				}
#line 2017 "parser.tab.c"
    break;

  case 63: /* exp_a_b: BI_RESTA exp_a_b  */
#line 838 "src/parser.y"
                                {
					/**
					 * Productio: E --> -E1
					 * Semantic Rule:
					 * 	{
					 * 		T := newTemp();
					 *		modificarTipoTS(T, E1.type);
					 *		E.place = T;
					 * 		si ( E1.type = entero ) --> gen(E.place := -ent E1.place);
					 *		[] ( E1.type = real ) --> gen(E.place := -real E1.place)
					 *		fsi
					 *	}
					 */
					(yyval.exp) = new_exp_a_b( ARITHMETIC_EXP );
					(yyval.exp)->s = new_symbol( "_tmp");
					(yyval.exp)->s->type = (yyvsp[0].exp)->s->type;

					if ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad = new_quad(QUAD_OP_INTUNIMUS, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL )
					{
						Quad *quad = new_quad(QUAD_OP_REALUNIMUS, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
					}

				}
#line 2049 "parser.tab.c"
    break;

  case 64: /* exp_a_b: operando  */
#line 866 "src/parser.y"
                                {

				}
#line 2057 "parser.tab.c"
    break;

  case 65: /* exp_a_b: exp_a_b BI_O M exp_a_b  */
#line 870 "src/parser.y"
                                {

					/**
					 * Production 1: E --> E1 OR M E2
					 * 	{
					 * 		backpatch(E1.falselist, M.quad);
					 *		E.truelist := merge(E1.truelist, E2.truelist)
					 *		E.falselist := E2.falselist
					 *	}
					 */

					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
					add_symbol( st, (yyval.exp)->s );
					
					backpatch((yyvsp[-3].exp)->falselist, (yyvsp[-1].next_quad));
					(yyval.exp)->truelist = merge((yyvsp[-3].exp)->truelist, (yyvsp[0].exp)->truelist);
					(yyval.exp)->falselist = (yyvsp[0].exp)->falselist;

				}
#line 2083 "parser.tab.c"
    break;

  case 66: /* exp_a_b: exp_a_b BI_Y M exp_a_b  */
#line 892 "src/parser.y"
                                {
					/**
					 * Production 2: E --> E1 AND M E2
					 * 	{
					 * 		backpatch(E1.truelist, M.quad);
					 *		E.truelist := E2.truelist
					 *		E.falselist := merge(E1.falselist, E2.falselist)
					 *	}
					 */

					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
					add_symbol( st, (yyval.exp)->s );
					
					backpatch((yyvsp[-3].exp)->truelist, (yyvsp[-1].next_quad));
					(yyval.exp)->truelist = (yyvsp[0].exp)->truelist;
					(yyval.exp)->falselist = merge((yyvsp[-3].exp)->falselist, (yyvsp[0].exp)->falselist);

				}
#line 2108 "parser.tab.c"
    break;

  case 67: /* exp_a_b: BI_NO exp_a_b  */
#line 913 "src/parser.y"
                                {

					/**
					 * Production 3: E --> not E1
					 * {
					 * 		E.truelist = E1.falselist
					 *		E.falselist = E1.truelist
					 * }
					 */
					
					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					(yyval.exp)->truelist = (yyvsp[0].exp)->falselist;
					(yyval.exp)->falselist = (yyvsp[0].exp)->truelist;

				}
#line 2132 "parser.tab.c"
    break;

  case 68: /* exp_a_b: BI_PAR_APER exp_a_b BI_PAR_CIER  */
#line 933 "src/parser.y"
                                {

					/**
					 * Production 4: E --> (E1)
					 * 	{
					 *		E.truelist := E1.truelist
					 *		E.falselist := E1.falselist
					 * 	}
					 */
					
					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					(yyval.exp)->truelist = (yyvsp[-1].exp)->truelist;
					(yyval.exp)->falselist = (yyvsp[-1].exp)->falselist;

				}
#line 2156 "parser.tab.c"
    break;

  case 69: /* exp_a_b: expresion oprel expresion  */
#line 953 "src/parser.y"
                                {

					/**
					 * Production 5: E --> id1 relop id2
					 * { 	
					 *		E.truelist := makelist( nextaddr )
					 * 		E.falselist := makelist( nextaddr + 1)
					 *		emit( 'if' id1.place relop.op id2.place 'goto_')
					 *		emit( 'goto_' )
					 * }
					 */

					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);

					 /* We create new tmp variable and add to symbol table*/
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					/* We generate new quadruples */ 
					Quad *quad1 = new_quad((yyvsp[-1].oprel_val), (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, QUAD_OP_NOGOTO);
					Quad *quad2 = new_quad(QUAD_OP_GOTO, (yyval.exp)->s->id, QUAD_OP_FALSE, QUAD_OP_NOGOTO);

					gen( qt, quad1 );
					gen( qt, quad2 );

					(yyval.exp)->truelist = makelist( quad1 );
					(yyval.exp)->falselist = makelist( quad2 );

				}
#line 2191 "parser.tab.c"
    break;

  case 70: /* exp_a_b: BI_VERDADERO  */
#line 984 "src/parser.y"
                                {
					/** 
					  * Production 6: E --> true
					  * { E.truelist := makelist(nextaddr) } 
					  * 
					  */
					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, (yyval.exp)->s);

					Quad *quad = new_quad(QUAD_OP_GOTO, (yyval.exp)->s->id, QUAD_OP_TRUE, QUAD_OP_NOGOTO);
					gen(qt, quad);
					(yyval.exp)->truelist = makelist( quad );


				}
#line 2214 "parser.tab.c"
    break;

  case 71: /* exp_a_b: BI_FALSO  */
#line 1003 "src/parser.y"
                                {
					/** 
					  * Production 7: E --> false
					  * { E.falselist := makelist(nextaddr) } 
					  * 
					  */
					(yyval.exp) = new_exp_a_b(BOOLEAN_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = DATA_TYPE_BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, (yyval.exp)->s);

					Quad *quad = new_quad(QUAD_OP_GOTO, (yyval.exp)->s->id, QUAD_OP_FALSE, QUAD_OP_NOGOTO);
					gen(qt, quad);
					(yyval.exp)->falselist = makelist( quad );

				}
#line 2236 "parser.tab.c"
    break;

  case 72: /* M: %empty  */
#line 1030 "src/parser.y"
                                              { (yyval.next_quad) = next_quad(); }
#line 2242 "parser.tab.c"
    break;

  case 73: /* oprel: BI_IGUALDAD  */
#line 1034 "src/parser.y"
                                                { (yyval.oprel_val) = QUAD_OP_EQ; }
#line 2248 "parser.tab.c"
    break;

  case 74: /* oprel: BI_DISTINTO  */
#line 1035 "src/parser.y"
                                                        { (yyval.oprel_val) = QUAD_OP_NE; }
#line 2254 "parser.tab.c"
    break;

  case 75: /* oprel: BI_MAYOR  */
#line 1036 "src/parser.y"
                                                                { (yyval.oprel_val) = QUAD_OP_GT; }
#line 2260 "parser.tab.c"
    break;

  case 76: /* oprel: BI_MAYOR_IGUAL  */
#line 1037 "src/parser.y"
                                                        { (yyval.oprel_val) = QUAD_OP_GE; }
#line 2266 "parser.tab.c"
    break;

  case 77: /* oprel: BI_MENOR  */
#line 1038 "src/parser.y"
                                                                { (yyval.oprel_val) = QUAD_OP_LT; }
#line 2272 "parser.tab.c"
    break;

  case 78: /* oprel: BI_MENOR_IGUAL  */
#line 1039 "src/parser.y"
                                                        { (yyval.oprel_val) = QUAD_OP_LE; }
#line 2278 "parser.tab.c"
    break;

  case 79: /* operando: BI_IDENTIFICADOR  */
#line 1052 "src/parser.y"
                                {
					/**
					 * Prodcution 6: E --> id
					 * Semantic Rule:
					 * 	{
					 * 		E.place := id.val
					 *		E.type := consultar_tipo_TS( id.val );
					 *	}
					 */

					 printf("debug: operando");
					
					Symbol *symbol = lookup( st, (yyvsp[0].sval) );
					if ( symbol )
					{
						(yyval.exp) = new_exp_a_b( UNDEFINED_EXP );					
						(yyval.exp)->s = symbol;

					}
					else
					{
						fprintf(stderr, "Error: Symbol %s doesnt exist in symbom table", (yyvsp[0].sval));
					}


					
				}
#line 2310 "parser.tab.c"
    break;

  case 90: /* asignacion: operando BI_ASIGNACION expresion  */
#line 1099 "src/parser.y"
                                {


					/**
					 *
					 * 
					 *
					 */

					printf("***********HEllo world***********\n");

					if ( (yyvsp[-2].exp)->s->type == (yyvsp[0].exp)->s->type )
					{
						Quad *quad = new_quad( QUAD_OP_ASSIGN, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( QUAD_OP_REAL2INT, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_BOOLEAN ) )
					{
						Quad *quad = new_quad( QUAD_OP_BOOL2INT, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( QUAD_OP_INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( QUAD_OP_INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( QUAD_OP_INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					


				}
#line 2365 "parser.tab.c"
    break;


#line 2369 "parser.tab.c"

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

#line 1203 "src/parser.y"



int main(int argc, char const *argv[])
{
	

	if ( argc == 2 && ( strcmp( argv[1], "--help" ) == 0 || strcmp( argv[1], "--help" ) == 0 ) )
	{
		printf("Usage: compiler <input-file>\n");
		printf("Supported input file extensions: .txt and .alg\n");
		return EXIT_SUCCESS;
	}
	else if ( argc == 2 )
	{
		
		char *ext = strrchr( argv[1], '.' );
		++ext;

		/* No extension */
		if ( !ext ) {
			printf("Usage: compiler <input-file>\n");
			printf("Supported input file extensions: .txt and .alg\n");
			return EXIT_SUCCESS;
		}

		if ( ( strcmp( ext, "txt" ) == 0 ) || ( strcmp( ext, "alg") == 0 ) )
		{
			
			fdebug = fopen("debug.txt", "w");

			FILE *file = fopen( argv[1], "r");
			
			if ( !file )
			{
				fprintf(stderr, "Error: %s\n",	strerror( errno ) );
				return EXIT_FAILURE;
			}

			yyin = file;			
		
			init_symbol_table( st );
			qt = new_quad_table();

			    int ret;

		    do{
		       	ret = yyparse();
		    } while ( !feof( yyin ) );

		    if ( ret == 0 ) { print_quadruples( qt ); }
			//stack = nuevaPila( &stack );

		} else {
			printf("Error: Not supported input file extension.\n\n");
			printf("Usage: compiler <input-file>\n");
			printf("Supported input file extensions: .txt and .alg\n");
			return EXIT_SUCCESS;

		}
	}

	return EXIT_SUCCESS;
}


void yyerror (const char *str)
{
	fprintf (stderr, "Unexpected error has ocurred on line %d: %s\n", yylineno, str);
	exit(-1);
}














/*
|	BI_PAR_APER exp_a_b BI_PAR_CIER
				{
					**
					 * Production 5: E --> ( E1 )
					 * Semantic Rule:
					 * 	{
					 *		E.place := E1.place 
					 *		E.type = E1.type
					 *	}
					 *

					if ( !( $2->type == BOOLEAN_EXP ) && !( $2->type == ARITHMETIC_EXP ) )	
					{
				 		fprintf(stderr, "Error: Not valid expresion type\n");
				 	} else {
						$$ = $2;
				 	}

				}
*/
