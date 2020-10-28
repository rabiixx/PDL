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

	#include "lib/symboltable/symbol_table.h"
	#include "lib/quadruples/quadruples.h"
	#include "lib/exp_a_b/exp_a_b.h"
	#include "lib/stack/stack.h"


	extern int yylex();
	extern FILE *yyin;
	extern yylineno;

	void yyerror (char const *);

	Symbol *st[HT_SIZE];
	QuadTable *qt;

	Stack stack;


#line 95 "parser.tab.c"

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
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
       0,   107,   107,   110,   113,   116,   117,   118,   121,   122,
     123,   126,   129,   130,   131,   132,   146,   154,   157,   168,
     173,   198,   202,   217,   218,   219,   223,   226,   227,   234,
     241,   244,   248,   252,   256,   260,   274,   281,   285,   288,
     292,   308,   320,   327,   377,   378,   407,   425,   439,   440,
     441,   448,   451,   457,   458,   461,   507,   551,   595,   657,
     701,   756,   765,   772,   800,   804,   826,   847,   867,   887,
     918,   937,   965,   969,   970,   971,   972,   973,   974,   986,
    1012,  1013,  1014,  1020,  1021,  1024,  1025,  1026,  1027,  1028,
    1031,  1082,  1085,  1086,  1089,  1090,  1093,  1096,  1101,  1104,
    1107,  1110,  1113,  1114,  1117,  1118,  1119,  1122,  1125,  1128,
    1129
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

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -31,    64,    18,  -120,    94,    30,    43,   103,   172,
      94,    94,    73,    91,    77,   118,    85,   140,   173,    -7,
     103,   103,   103,   130,   135,   149,   172,   172,  -120,  -120,
     306,   127,   139,   147,   150,   179,   161,  -120,  -120,    53,
     143,    53,  -120,   144,   116,  -120,   154,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   165,   103,   167,   103,
      85,    85,   228,   188,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,   196,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,   189,  -120,   139,   190,  -120,    53,    -8,    53,
      53,   200,   199,  -120,   229,   213,   122,  -120,  -120,    85,
     202,   151,   192,    14,   207,   -39,    53,  -120,    53,    53,
     198,    -7,   -18,   244,    85,   226,  -120,  -120,  -120,  -120,
      30,   216,   258,  -120,   168,   229,   170,    53,   208,   152,
      43,   168,  -120,  -120,  -120,  -120,  -120,  -120,    53,    53,
    -120,  -120,    53,    53,    53,    53,    53,  -120,  -120,    47,
     239,    -7,    53,    -7,   194,   252,   229,   223,  -120,   122,
    -120,    85,    85,    85,  -120,   240,  -120,   253,    53,  -120,
     139,  -120,   264,   255,  -120,  -120,  -120,   229,   235,    53,
      53,   152,   152,   235,   235,   235,    85,    85,   296,   -33,
     263,    53,  -120,  -120,   267,   268,   269,   -18,   273,     7,
     274,   168,  -120,   170,   170,  -120,  -120,  -120,    53,    53,
     299,  -120,   139,   139,   139,  -120,  -120,  -120,   189,   270,
      54,   214,  -120,  -120,  -120,  -120,  -120,   292,    -7,    -7,
     139,   303,   263,  -120,  -120,  -120
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
       0,     0,    85,    79,     0,    11,    84,    86,    87,    88,
      95,    94,    89,    12,    13,    14,     0,    15,     0,    15,
      45,    45,     0,    48,    50,     8,     9,    36,    37,    38,
      39,    40,     0,    17,    61,    62,    28,    31,    32,    33,
      34,    35,    30,    71,     0,     0,    70,     0,    79,     0,
       0,     0,     0,    21,    27,    53,    64,    54,    16,     0,
       0,     0,    79,     0,     0,     0,     0,    82,     0,     0,
       0,     0,   103,     0,    45,     0,    51,    52,     3,    49,
      42,     0,     0,    23,     0,     0,    67,     0,    53,    63,
      20,     0,    77,    75,    78,    76,    73,    74,     0,     0,
      72,    72,     0,     0,     0,     0,     0,    46,    18,    79,
       0,     0,     0,     0,   110,     0,    90,     0,    79,    80,
      83,     0,     0,     0,   100,     0,    98,     0,     0,    41,
       0,    25,     0,     0,    68,    19,    24,    69,    60,     0,
       0,    55,    56,    57,    58,    59,    45,    45,     0,     0,
      93,     0,   107,    81,     0,     0,     0,   103,     0,     0,
       0,     0,   108,    66,    65,    43,    44,    96,     0,     0,
       0,   109,     0,     0,     0,   102,   101,    99,    30,     0,
       0,     0,    91,   104,   106,   105,    29,     0,     0,     0,
       0,     0,    93,    26,    97,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,    55,   141,    -9,    25,    13,   106,
    -120,   201,   -76,  -119,   112,  -120,  -120,   212,   -47,   -89,
    -120,  -120,   271,   -38,   -83,   195,  -120,   -19,  -109,  -120,
    -120,  -120,   101,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
     138,  -120,  -120,  -120,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    91,    92,   122,    93,    72,    13,    35,    36,
      62,    63,    64,    94,    95,   179,   138,    96,    45,    46,
      47,    48,   210,    49,    50,    51,    26,    27,    57,    59,
     164,   165,    52,    97,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   103,   160,   105,   126,   172,   128,   129,   123,   208,
     147,   173,   176,   116,   117,    39,   153,    40,    10,    41,
     161,   162,     1,    10,    10,   150,   163,    42,   217,     3,
     132,   133,   134,   135,   136,   137,   132,   133,   134,   135,
     136,   137,   188,   -22,   190,    53,    54,    55,   113,   125,
     115,   125,   125,    43,   127,   151,   178,    74,    75,   181,
     182,   183,   184,   185,     4,    28,    29,   167,   154,     5,
     156,   157,   194,   195,   196,   211,   132,   133,   134,   135,
     136,   137,   219,   132,   133,   134,   135,   136,   137,   154,
      12,   159,    44,    83,   200,   228,   203,   204,   186,    86,
     177,   125,    87,    14,   125,   125,   125,   125,   125,   127,
      31,    11,     6,   102,   189,    89,    11,    11,    90,   231,
     232,     6,     7,   132,   133,   134,   135,   136,   137,    30,
     199,     7,    44,    32,    44,    16,   223,   224,   225,   205,
     206,   125,   125,    74,    75,    34,    76,    33,    77,    78,
      79,    80,    81,   154,   233,    74,    75,    37,    76,   107,
      77,    78,    79,    80,    81,   107,   108,    65,    66,    82,
     220,   221,    74,    75,   109,    76,    38,   110,    73,    83,
     109,    82,    84,   110,    85,    86,    23,    60,    87,   139,
      56,    83,    24,    61,    84,    58,    85,    86,    98,    88,
      87,    89,    99,   104,    90,   111,   106,   139,    83,    44,
      44,   149,   100,    89,    86,   101,    90,    87,   144,   145,
     146,   -53,   -53,   -53,   -53,   -53,   -53,   112,   102,   114,
      89,   118,    61,    90,   142,   143,   144,   145,   146,   -53,
     -53,   -53,   -53,   -53,   -53,   139,   191,   120,   124,   121,
     139,   130,   131,   148,   127,   140,   141,   152,   158,   166,
     140,   141,   168,   132,   133,   134,   135,   136,   137,   229,
     170,   174,   142,   143,   144,   145,   146,   142,   143,   144,
     145,   146,   193,   132,   133,   134,   135,   136,   137,   171,
     187,   197,   132,   133,   134,   135,   136,   137,   132,   133,
     134,   135,   136,   137,   -53,   -53,   -53,   -53,   -53,   -53,
      67,    68,    69,    70,    71,   192,   198,   201,   202,   207,
     209,   212,   213,   214,   216,   218,   222,   230,   234,   227,
     226,   175,   169,   235,   119,   215,   180
};

static const yytype_uint8 yycheck[] =
{
      19,    39,   111,    41,    87,   124,    89,    90,    84,    42,
      99,   127,   131,    60,    61,    22,    55,    24,     5,    26,
      38,    39,    16,    10,    11,   101,    44,    34,    21,    60,
      69,    70,    71,    72,    73,    74,    69,    70,    71,    72,
      73,    74,   151,    51,   153,    20,    21,    22,    57,    87,
      59,    89,    90,    60,    62,    41,   139,     4,     5,   142,
     143,   144,   145,   146,     0,    10,    11,   114,   106,    51,
     108,   109,   161,   162,   163,   191,    69,    70,    71,    72,
      73,    74,   201,    69,    70,    71,    72,    73,    74,   127,
      60,   110,   111,    40,   170,    41,   179,   180,    51,    46,
     138,   139,    49,    60,   142,   143,   144,   145,   146,    62,
      19,     5,    18,    60,   152,    62,    10,    11,    65,   228,
     229,    18,    28,    69,    70,    71,    72,    73,    74,    56,
     168,    28,   151,    56,   153,    32,   212,   213,   214,   186,
     187,   179,   180,     4,     5,    60,     7,    29,     9,    10,
      11,    12,    13,   191,   230,     4,     5,    17,     7,    43,
       9,    10,    11,    12,    13,    43,    50,    26,    27,    30,
     208,   209,     4,     5,    58,     7,     3,    61,    51,    40,
      58,    30,    43,    61,    45,    46,    14,    38,    49,    37,
      60,    40,    20,    44,    43,    60,    45,    46,    51,    60,
      49,    62,    52,    60,    65,    51,    62,    37,    40,   228,
     229,    60,    33,    62,    46,    54,    65,    49,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    62,    60,    62,
      62,     3,    44,    65,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    37,    52,    51,    58,    60,
      37,    51,    53,    51,    62,    47,    48,    50,    60,    15,
      47,    48,    36,    69,    70,    71,    72,    73,    74,    55,
      54,    63,    64,    65,    66,    67,    68,    64,    65,    66,
      67,    68,    59,    69,    70,    71,    72,    73,    74,    31,
      51,    51,    69,    70,    71,    72,    73,    74,    69,    70,
      71,    72,    73,    74,    69,    70,    71,    72,    73,    74,
       4,     5,     6,     7,     8,    63,    63,    53,    63,    23,
      57,    54,    54,    54,    51,    51,    27,    35,    25,    59,
     218,   130,   120,   232,    63,   197,   141
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
       7,     8,    91,    51,     4,     5,     7,     9,    10,    11,
      12,    13,    30,    40,    43,    45,    46,    49,    60,    62,
      65,    87,    88,    90,    98,    99,   102,   118,    51,    52,
      33,    54,    60,    98,    60,    98,    62,    43,    50,    58,
      61,    51,    62,    81,    62,    81,    93,    93,     3,    97,
      51,    60,    89,    87,    58,    98,    99,    62,    99,    99,
      51,    53,    69,    70,    71,    72,    73,    74,   101,    37,
      47,    48,    64,    65,    66,    67,    68,    94,    51,    60,
      87,    41,    50,    55,    98,   119,    98,    98,    60,   102,
     103,    38,    39,    44,   115,   116,    15,    93,    36,    92,
      54,    31,    88,   119,    63,    86,    88,    98,    99,   100,
     100,    99,    99,    99,    99,    99,    51,    51,   103,    98,
     103,    52,    63,    59,    94,    94,    94,    51,    63,    98,
      87,    53,    63,    99,    99,    93,    93,    23,    42,    57,
     107,   119,    54,    54,    54,   115,    51,    21,    51,    88,
      98,    98,    27,    87,    87,    87,    89,    59,    41,    55,
      35,   103,   103,    87,    25,   107
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
       0,     2,     2,     2,     2,     0,     4,     4,     4,     5,
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
#line 169 "src/parser.y"
                                {


				}
#line 1399 "parser.tab.c"
    break;

  case 21: /* d_tipo: tipo_base  */
#line 199 "src/parser.y"
                                {
					/****duda: es integer? */
				}
#line 1407 "parser.tab.c"
    break;

  case 22: /* d_tipo: BI_IDENTIFICADOR  */
#line 203 "src/parser.y"
                                {

					char *str = "type";
					char *type = get_attr(st, "hola", str);

					if ( !type ) {
						printf("Identifier %s doesnt exist", yyvsp[0]);
					} else {
						// strcpy();
						yyval = type;
					}


				}
#line 1426 "parser.tab.c"
    break;

  case 25: /* d_tipo: BI_TUPLA lista_campos BI_FTUPLA  */
#line 220 "src/parser.y"
                                {
					/* Que devolver ??? tupla*/
				}
#line 1434 "parser.tab.c"
    break;

  case 29: /* lista_campos: BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos  */
#line 235 "src/parser.y"
                                {

					insertSymbol(st, yyvsp[-4]);
					set_attr(st, yyvsp[-4], "type", yyvsp[-2]);

				}
#line 1445 "parser.tab.c"
    break;

  case 31: /* tipo_base: BI_PR_ENTERO  */
#line 245 "src/parser.y"
                                {
					yyval = INTEGER;
				}
#line 1453 "parser.tab.c"
    break;

  case 32: /* tipo_base: BI_PR_REAL  */
#line 249 "src/parser.y"
                                {
					yyval = FLOAT;
				}
#line 1461 "parser.tab.c"
    break;

  case 33: /* tipo_base: BI_PR_BOOLEANO  */
#line 253 "src/parser.y"
                                {
					yyval = BOOLEAN;
				}
#line 1469 "parser.tab.c"
    break;

  case 34: /* tipo_base: BI_PR_CARACTER  */
#line 257 "src/parser.y"
                                {
					yyval = CHARACTER;
				}
#line 1477 "parser.tab.c"
    break;

  case 35: /* tipo_base: BI_PR_CADENA  */
#line 261 "src/parser.y"
                                {
					yyval = STRING;
				}
#line 1485 "parser.tab.c"
    break;

  case 36: /* literal: BI_LIT_ENTERO  */
#line 275 "src/parser.y"
                                {

					printf("LITERAL_ENTERO");

					yyval = INTEGER;
				}
#line 1496 "parser.tab.c"
    break;

  case 37: /* literal: BI_LIT_REAL  */
#line 282 "src/parser.y"
                                {
					yyval = FLOAT;
				}
#line 1504 "parser.tab.c"
    break;

  case 38: /* literal: BI_LIT_BOOLEANO  */
#line 285 "src/parser.y"
                                                       {
					yyval = BOOLEAN;
				}
#line 1512 "parser.tab.c"
    break;

  case 39: /* literal: BI_LIT_CARACTER  */
#line 288 "src/parser.y"
                                                       {

					yyval = CHARACTER;
				}
#line 1521 "parser.tab.c"
    break;

  case 40: /* literal: BI_LIT_CADENA  */
#line 292 "src/parser.y"
                                                     {
					yyval = STRING;
				}
#line 1529 "parser.tab.c"
    break;

  case 41: /* lista_d_cte: BI_IDENTIFICADOR BI_CREACION_TIPO literal BI_COMP_SEQ lista_d_cte  */
#line 309 "src/parser.y"
                                {


					/** 
					  * We insert the identifier into the symbol table and we define its scope and type.
					  * in this case scope will be, const. The type is returned by literal grammar rule 
					  */
					insertSymbol(st, yyvsp[-4]);
					set_attr(st, yyvsp[-4], "scope", "cte");
					set_attr(st, yyvsp[-4], "type", yyvsp[-2])
				}
#line 1545 "parser.tab.c"
    break;

  case 43: /* lista_d_var: lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var  */
#line 327 "src/parser.y"
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
#line 1600 "parser.tab.c"
    break;

  case 46: /* lista_id: BI_IDENTIFICADOR BI_SEPARADOR lista_id  */
#line 408 "src/parser.y"
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
#line 1622 "parser.tab.c"
    break;

  case 47: /* lista_id: BI_IDENTIFICADOR  */
#line 426 "src/parser.y"
                                {

					if ( !lookup(st, yyvsp[0]) ) {
						
						insertSymbol(st, yyvsp[0]);
						apilar(stack, yyvsp[0]);

					} else {
						printf("Identifier alredy exists")
					}
				}
#line 1638 "parser.tab.c"
    break;

  case 55: /* exp_a_b: exp_a_b BI_SUMA exp_a_b  */
#line 462 "src/parser.y"
                                {

					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);

					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						yyval->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUM, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);

					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						yyval->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUM, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

				}
#line 1688 "parser.tab.c"
    break;

  case 56: /* exp_a_b: exp_a_b BI_RESTA exp_a_b  */
#line 508 "src/parser.y"
                                {
					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);

					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						yyval->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUBS, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);

					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						yyval->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUBS, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1736 "parser.tab.c"
    break;

  case 57: /* exp_a_b: exp_a_b BI_MULTIPLICACION exp_a_b  */
#line 552 "src/parser.y"
                                {
					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);

					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						yyval->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTMULT, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);

					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						yyval->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALMULT, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1784 "parser.tab.c"
    break;

  case 58: /* exp_a_b: exp_a_b BI_DIVISION exp_a_b  */
#line 596 "src/parser.y"
                                {

				/**
				 * In case the argumnets are integers we need to convert them to 
				 * real before realizing the division. If both arguments are of
				 * integer type, we need another tmp variable to store the result
				 * of the conversions. 
				 *
				 */

					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);


					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );
						
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1850 "parser.tab.c"
    break;

  case 59: /* exp_a_b: exp_a_b BI_MOD exp_a_b  */
#line 658 "src/parser.y"
                                {

					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);

					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						Quad *quad = new_quad(QUAD_OP_INTMOD, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
						yyval->s->type = DATA_TYPE_INTEGER;
					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_MODREAL, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						yyval->s->type = DATA_TYPE_REAL;
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
#line 1898 "parser.tab.c"
    break;

  case 60: /* exp_a_b: exp_a_b BI_DIV exp_a_b  */
#line 702 "src/parser.y"
                                {

					/* div is division in which the fractional part (remainder) is discarded */

					yyval = new_exp_a_b(ARITHMETIC_EXP);
					yyval->s = new_symbol("_tmp");
					add_symbol(st, yyval->s);


					if ( ( yyvsp[-2]->s->type == INTEGER ) && ( yyvsp[0]->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );

						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);
					}
					else if ( ( yyvsp[-2]->s->type == REAL ) && ( yyvsp[0]->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, yyvsp[-2]->s->id, yyvsp[0]->s->id, yyval->s->id);
						gen(qt, quad);
					}
					else if ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[-2]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, yyval->s->id, yyvsp[0]->s->id, yyval->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( yyvsp[0]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, yyval->s->id, yyvsp[-2]->s->id, yyval->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

					/* Convert result to INTEGER */
					Quad *q = new_quad(QUAD_OP_REAL2INT, yyval->s->id, QUAD_OP_VOID, yyval->s->id);
					gen(qt, q);
					
					yyval->s->type = DATA_TYPE_INTEGER;
				}
#line 1957 "parser.tab.c"
    break;

  case 61: /* exp_a_b: BI_LIT_ENTERO  */
#line 757 "src/parser.y"
                                {

					yyval = new_exp_a_b( ARITHMETIC_EXP );
					yyval->s = new_symbol( "_tmp" );
					yyval->S->type = DATA_TYPE_INTEGER;
					add_symbol(st, yyval->s);

				}
#line 1970 "parser.tab.c"
    break;

  case 62: /* exp_a_b: BI_LIT_REAL  */
#line 766 "src/parser.y"
                                {
					yyval = new_exp_a_b( ARITHMETIC_EXP );
					yyval->s = new_symbol( "_tmp" );
					yyval->S->type = DATA_TYPE_REAL;
					add_symbol(st, yyval->s);
				}
#line 1981 "parser.tab.c"
    break;

  case 63: /* exp_a_b: BI_RESTA exp_a_b  */
#line 773 "src/parser.y"
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
					yyval = new_exp_a_b( ARITHMETIC_EXP );
					yyval->s = new_symbol( "_tmp");
					yyval->s->type = yyvsp[-1]->s->type;

					if ( yyvsp[-1]->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad = new_quad(QUAD_OP_INTUNIMUS, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id)
					}
					else if ( yyvsp[-1]->s->type == DATA_TYPE_REAL )
					{
						Quad *quad = new_quad(QUAD_OP_REALUNIMUS, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id)
					}

				}
#line 2013 "parser.tab.c"
    break;

  case 64: /* exp_a_b: operando  */
#line 801 "src/parser.y"
                                {

				}
#line 2021 "parser.tab.c"
    break;

  case 65: /* exp_a_b: exp_a_b BI_O M exp_a_b  */
#line 805 "src/parser.y"
                                {

					/**
					 * Production 1: E --> E1 OR M E2
					 * 	{
					 * 		backpatch(E1.falselist, M.quad);
					 *		E.truelist := merge(E1.truelist, E2.truelist)
					 *		E.falselist := E2.falselist
					 *	}
					 */

					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
					add_symbol( st, yyval->s );
					
					backpatch(yyvsp[-3]->falselist, yyvsp[-1]);
					yyval->truelist = merge(yyvsp[-3]->truelist, yyvsp[0]->truelist);
					yyval->falselist = yyvsp[0]->falselist;

				}
#line 2047 "parser.tab.c"
    break;

  case 66: /* exp_a_b: exp_a_b BI_Y M exp_a_b  */
#line 827 "src/parser.y"
                                {
					/**
					 * Production 2: E --> E1 AND M E2
					 * 	{
					 * 		backpatch(E1.truelist, M.quad);
					 *		E.truelist := E2.truelist
					 *		E.falselist := merge(E1.falselist, E2.falselist)
					 *	}
					 */

					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
					add_symbol( st, yyval->s );
					
					backpatch(yyvsp[-3]->truelist, yyvsp[-1]);
					yyval->truelist = yyvsp[0]->truelist;
					yyval->falselist = merge(yyvsp[-3]->falselist, yyvsp[0]->falselist);

				}
#line 2072 "parser.tab.c"
    break;

  case 67: /* exp_a_b: BI_NO exp_a_b  */
#line 848 "src/parser.y"
                                {

					/**
					 * Production 3: E --> not E1
					 * {
					 * 		E.truelist = E1.falselist
					 *		E.falselist = E1.truelist
					 * }
					 */
					
					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
					add_symbol( st, yyval->s );

					yyval->truelist = yyvsp[0]->falselist;
					yyval->falselist = yyvsp[0]->truelist;

				}
#line 2096 "parser.tab.c"
    break;

  case 68: /* exp_a_b: BI_PAR_APER exp_a_b BI_PAR_CIER  */
#line 868 "src/parser.y"
                                {

					/**
					 * Production 4: E --> (E1)
					 * 	{
					 *		E.truelist := E1.truelist
					 *		E.falselist := E1.falselist
					 * 	}
					 */
					
					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
					add_symbol( st, yyval->s );

					yyval->truelist = yyvsp[-1]->truelist;
					yyval->falselist = yyvsp[-1]->falselist;

				}
#line 2120 "parser.tab.c"
    break;

  case 69: /* exp_a_b: expresion oprel expresion  */
#line 888 "src/parser.y"
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

					yyval = new_exp_a_b(BOOLEAN);

					 /* We create new tmp variable and add to symbol table*/
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
					add_symbol( st, yyval->s );

					/* We generate new quadruples */ 
					Quad *quad1 = new_quad(yyvsp[-1], yyvsp[-2]->s->is, yyvsp[-1]->s->id, QUAD_OP_NOGOTO);
					Quad *quad2 = new_quad(QUAD_OP_GOTO, yyval->s->id, QUAD_OP_FALSE, QUAD_OP_NOGOTO);

					gen( qt, quad1 );
					gen( qt, quad2 );

					yyval->truelist = makelist( quad1 );
					yyval->falselist = makelist( quad2 );

				}
#line 2155 "parser.tab.c"
    break;

  case 70: /* exp_a_b: BI_VERDADERO  */
#line 919 "src/parser.y"
                                {
					/** 
					  * Production 6: E --> true
					  * { E.truelist := makelist(nextaddr) } 
					  * 
					  */
					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, yyval->s);

					Quad *quad = new_quad(GOTO, yyval->s->id, OP_QUAD_TRUE, NOTGOTO);
					gen(qt, quad);
					yyval->truelist = makelist( quad );


				}
#line 2178 "parser.tab.c"
    break;

  case 71: /* exp_a_b: BI_FALSO  */
#line 938 "src/parser.y"
                                {
					/** 
					  * Production 7: E --> false
					  * { E.falselist := makelist(nextaddr) } 
					  * 
					  */
					yyval = new_exp_a_b(BOOLEAN);
					yyval->s = new_symbol("_tmp");
					yyval->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, yyval->s);

					Quad *quad = new_quad(GOTO, yyval->s->id, OP_QUAD_FALSE, NOTGOTO);
					gen(qt, quad);
					yyval->falselist = makelist( quad );

				}
#line 2200 "parser.tab.c"
    break;

  case 72: /* M: %empty  */
#line 965 "src/parser.y"
                                              { yyval = next_quad() }
#line 2206 "parser.tab.c"
    break;

  case 73: /* oprel: BI_IGUALDAD  */
#line 969 "src/parser.y"
                                                { yyval = QUAD_OP_EQ }
#line 2212 "parser.tab.c"
    break;

  case 74: /* oprel: BI_DISTINTO  */
#line 970 "src/parser.y"
                                                        { yyval = QUAD_OP_NE }
#line 2218 "parser.tab.c"
    break;

  case 75: /* oprel: BI_MAYOR  */
#line 971 "src/parser.y"
                                                                { yyval = QUAD_OP_GT }
#line 2224 "parser.tab.c"
    break;

  case 76: /* oprel: BI_MAYOR_IGUAL  */
#line 972 "src/parser.y"
                                                        { yyval = QUAD_OP_GE }
#line 2230 "parser.tab.c"
    break;

  case 77: /* oprel: BI_MENOR  */
#line 973 "src/parser.y"
                                                                { yyval = QUAD_OP_LT }
#line 2236 "parser.tab.c"
    break;

  case 78: /* oprel: BI_MENOR_IGUAL  */
#line 974 "src/parser.y"
                                                        { yyval = QUAD_OP_LE }
#line 2242 "parser.tab.c"
    break;

  case 79: /* operando: BI_IDENTIFICADOR  */
#line 987 "src/parser.y"
                                {
					/**
					 * Prodcution 6: E --> id
					 * Semantic Rule:
					 * 	{
					 * 		E.place := id.val
					 *		E.type := consultar_tipo_TS( id.val );
					 *	}
					 */
					
					Symbol *symbol = lookup( st, yyvsp[0] );
					if ( symbol )
					{
						yyval = new_exp_a_b( UNDEFINED_EXP );					
						yyval->s = symbol;

					}
					else
					{
						fprintf(stderr, "Error: Symbol %s doesnt exist in symbom table", yyvsp[0]);
					}


					
				}
#line 2272 "parser.tab.c"
    break;

  case 90: /* asignacion: operando BI_ASIGNACION expresion  */
#line 1032 "src/parser.y"
                                {


					/**
					 *
					 * 
					 *
					 */

					if ( yyvsp[-2]->s->type == yyvsp[0]->s->type )
					{
						Quad *quad = new_quad( QUAD_OP_ASSIGN, yyvsp[-2]->s->id, yyvsp[0]->s->id, QUAD_OP_VOID, yyval->s->id );
						gen( qt, quad );
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER ) && ( yyvsp[0]->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( REAL2INT, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_REAL ) && ( yyvsp[0]->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2REAL, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );	
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_INTEGER ) && ( yyvsp[0]->s->type == DATA_TYPE_BOOLEAN ) )
					{
						Quad *quad = new_quad( BOOL2INT, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );	
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[0]->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[0]->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( INT2BOOL, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );	
					}
					else if ( ( yyvsp[-2]->s->type == DATA_TYPE_BOOLEAN ) && ( yyvsp[0]->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, yyvsp[0]->s->id, QUAD_OP_VOID, yyvsp[-2]->s->id );
						gen( qt, quad );
					}
					


				}
#line 2325 "parser.tab.c"
    break;


#line 2329 "parser.tab.c"

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

#line 1134 "src/parser.y"



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

		if ( ( strcmp( ext, "txt" ) == 0 ) || ( strcmp( ext, "alg") ) )
		{
			FILE *file = fopen( argv[1], "r");
			
			if ( !file )
			{
				fprintf("Error: %s\n",	strerror( errno ) );
				return EXIT_FAILURE;
			}

			yyin = file;			
		
			init_symbol_table( st );
			qt = new_quad_table();

		} else {
			printf("Error: Not supported input file extension.\n\n");
			printf("Usage: compiler <input-file>\n");
			printf("Supported input file extensions: .txt and .alg\n");
			return EXIT_SUCCESS;

		}
	}

	return EXIT_SUCCESS;
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
