/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <stdio.h>
	#include <errno.h>

	#include "lib/symboltable/symbol_table.h"
	#include "lib/quadruples/quadruples.h"
	#include "lib/exp_a_b/exp_a_b.h"
	#include "lib/stack/stack.h"
	#include "lib/util.h"


	extern int yylex();
	extern FILE *yyin;
	
	void yyerror (char const *);

	Symbol *st[HT_SIZE];
	QuadTable *qt;

	Stack stack;


#line 90 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
    BI_COMENTARIO = 258,
    BI_LIT_ENTERO = 259,
    BI_LIT_REAL = 260,
    BI_LIT_BOOLEANO = 261,
    BI_LIT_CARACTER = 262,
    BI_LIT_CADENA = 263,
    BI_PR_ENTERO = 264,
    BI_PR_REAL = 265,
    BI_PR_BOOLEANO = 266,
    BI_PR_CARACTER = 267,
    BI_PR_CADENA = 268,
    BI_ACCION = 269,
    BI_FACCION = 270,
    BI_ALGORITMO = 271,
    BI_FALGORITMO = 272,
    BI_CONST = 273,
    BI_FCONST = 274,
    BI_FUNCION = 275,
    BI_FFUNCION = 276,
    BI_MIENTRAS = 277,
    BI_FMIENTRAS = 278,
    BI_PARA = 279,
    BI_FPARA = 280,
    BI_SI = 281,
    BI_FSI = 282,
    BI_TIPO = 283,
    BI_FTIPO = 284,
    BI_TUPLA = 285,
    BI_FTUPLA = 286,
    BI_VAR = 287,
    BI_FVAR = 288,
    BI_CONTINUAR = 289,
    BI_DE = 290,
    BI_DEV = 291,
    BI_DIV = 292,
    BI_ENT = 293,
    BI_E_S = 294,
    BI_FALSO = 295,
    BI_HACER = 296,
    BI_HASTA = 297,
    BI_REF = 298,
    BI_SAL = 299,
    BI_TABLA = 300,
    BI_VERDADERO = 301,
    BI_Y = 302,
    BI_O = 303,
    BI_NO = 304,
    BI_ASIGNACION = 305,
    BI_COMP_SEQ = 306,
    BI_SEPARADOR = 307,
    BI_SUBRANGO = 308,
    BI_DEF_TYPEVAR = 309,
    BI_ENTONCES = 310,
    BI_CREACION_TIPO = 311,
    BI_SINOSI = 312,
    BI_INI_ARRAY = 313,
    BI_FIN_ARRAY = 314,
    BI_IDENTIFICADOR = 315,
    BI_PUNTO = 316,
    BI_PAR_APER = 317,
    BI_PAR_CIER = 318,
    BI_SUMA = 319,
    BI_RESTA = 320,
    BI_MULTIPLICACION = 321,
    BI_DIVISION = 322,
    BI_MOD = 323,
    BI_MENOR = 324,
    BI_MAYOR = 325,
    BI_MENOR_IGUAL = 326,
    BI_MAYOR_IGUAL = 327,
    BI_IGUALDAD = 328,
    BI_DISTINTO = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "src/parser.y" /* yacc.c:355  */

	char *sval;
	Data_type data_type;
	Exp_a_b *exp;
	int next_quad;
	Quad_op_code oprel_val;

#line 213 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   161,   164,   167,   168,   169,   172,   173,
     174,   177,   180,   181,   182,   183,   197,   205,   208,   219,
     224,   249,   253,   266,   267,   268,   272,   275,   276,   283,
     290,   293,   297,   301,   305,   309,   323,   327,   331,   335,
     339,   356,   368,   375,   425,   426,   455,   473,   487,   488,
     489,   496,   499,   505,   506,   509,   555,   599,   643,   705,
     749,   804,   813,   820,   848,   852,   874,   895,   915,   935,
     966,   985,  1013,  1017,  1018,  1019,  1020,  1021,  1022,  1034,
    1060,  1061,  1062,  1068,  1069,  1072,  1073,  1074,  1075,  1076,
    1079,  1130,  1133,  1134,  1137,  1138,  1141,  1144,  1149,  1152,
    1155,  1158,  1161,  1162,  1165,  1166,  1167,  1170,  1173,  1176,
    1177
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BI_COMENTARIO", "BI_LIT_ENTERO",
  "BI_LIT_REAL", "BI_LIT_BOOLEANO", "BI_LIT_CARACTER", "BI_LIT_CADENA",
  "BI_PR_ENTERO", "BI_PR_REAL", "BI_PR_BOOLEANO", "BI_PR_CARACTER",
  "BI_PR_CADENA", "BI_ACCION", "BI_FACCION", "BI_ALGORITMO",
  "BI_FALGORITMO", "BI_CONST", "BI_FCONST", "BI_FUNCION", "BI_FFUNCION",
  "BI_MIENTRAS", "BI_FMIENTRAS", "BI_PARA", "BI_FPARA", "BI_SI", "BI_FSI",
  "BI_TIPO", "BI_FTIPO", "BI_TUPLA", "BI_FTUPLA", "BI_VAR", "BI_FVAR",
  "BI_CONTINUAR", "BI_DE", "BI_DEV", "BI_DIV", "BI_ENT", "BI_E_S",
  "BI_FALSO", "BI_HACER", "BI_HASTA", "BI_REF", "BI_SAL", "BI_TABLA",
  "BI_VERDADERO", "BI_Y", "BI_O", "BI_NO", "BI_ASIGNACION", "BI_COMP_SEQ",
  "BI_SEPARADOR", "BI_SUBRANGO", "BI_DEF_TYPEVAR", "BI_ENTONCES",
  "BI_CREACION_TIPO", "BI_SINOSI", "BI_INI_ARRAY", "BI_FIN_ARRAY",
  "BI_IDENTIFICADOR", "BI_PUNTO", "BI_PAR_APER", "BI_PAR_CIER", "BI_SUMA",
  "BI_RESTA", "BI_MULTIPLICACION", "BI_DIVISION", "BI_MOD", "BI_MENOR",
  "BI_MAYOR", "BI_MENOR_IGUAL", "BI_MAYOR_IGUAL", "BI_IGUALDAD",
  "BI_DISTINTO", "$accept", "desc_algoritmo", "cabecera_alg", "bloque_alg",
  "decl_globales", "decl_a_f", "bloque", "declaraciones",
  "declaracion_tipo", "declaracion_cte", "declaracion_var", "lista_d_tipo",
  "d_tipo", "expresion_t", "lista_campos", "tipo_base", "literal",
  "lista_d_cte", "lista_d_var", "lista_id", "decl_ent_sal", "decl_ent",
  "decl_sal", "expresion", "exp_a_b", "M", "oprel", "operando",
  "instrucciones", "instruccion", "asignacion", "alternativa",
  "lista_opciones", "iteracion", "it_cota_exp", "it_cota_fija", "accion_d",
  "funcion_d", "a_cabecera", "f_cabecera", "d_par_form", "d_p_form",
  "accion_ll", "funcion_ll", "l_ll", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
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
static const yytype_uint8 yydefact[] =
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
static const yytype_uint8 yystos[] =
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
static const yytype_uint8 yyr1[] =
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
static const yytype_uint8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 19:
#line 220 "src/parser.y" /* yacc.c:1646  */
    {


				}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 250 "src/parser.y" /* yacc.c:1646  */
    {
					
				}
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 254 "src/parser.y" /* yacc.c:1646  */
    {

					/*cchar *type = get_type( st, $1 );

					if ( type == UNKNOWN_SYMBOL ) {
						printf("Error: Unknown symbol %s", $1);
					} else {
						$$ = type;
					}*/


				}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "src/parser.y" /* yacc.c:1646  */
    {
					/* Que devolver ??? tupla*/
				}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 284 "src/parser.y" /* yacc.c:1646  */
    {

					/*add_symbol(st, $1);
					set_symbol_type(st, $1, $3);*/

				}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_INTEGER;
				}
#line 1563 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 298 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_REAL;
				}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 302 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_BOOLEAN;
				}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_CHAR;
				}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 310 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_STRING;
				}
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_INTEGER;
				}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_REAL;
				}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 332 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_BOOLEAN;
				}
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_CHAR;
				}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 340 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = DATA_TYPE_STRING;
				}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 357 "src/parser.y" /* yacc.c:1646  */
    {


					/** 
					  * We insert the identifier into the symbol table and we define its scope and type.
					  * in this case scope will be, const. The type is returned by literal grammar rule 
					  */
					add_symbol(st, (yyvsp[-4].sval));
					//set_attr(st, $1, "scope", "cte");
					set_symbol_type(st, (yyvsp[-4].sval), (yyvsp[-2].data_type));
				}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 375 "src/parser.y" /* yacc.c:1646  */
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
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 456 "src/parser.y" /* yacc.c:1646  */
    {

					if ( !lookup(st, (yyvsp[-2].sval)) ) {

						add_symbol(st, (yyvsp[-2].sval));
						
						/* 
						 * We add identifiers to stack, to be able to set their type
						 * when we know it 
						 */
						//apilar(stack, $1);


					} else {
						printf("Identifier alredy exists");
					}
				}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 474 "src/parser.y" /* yacc.c:1646  */
    {

					if ( !lookup(st, (yyvsp[0].sval)) ) {
						
						add_symbol(st, (yyvsp[0].sval));
						//apilar(stack, $1);

					} else {
						printf("Identifier alredy exists");
					}
				}
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 510 "src/parser.y" /* yacc.c:1646  */
    {

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = add_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUM, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
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
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 556 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUBS, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
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
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 600 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTMULT, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);

					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
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
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 644 "src/parser.y" /* yacc.c:1646  */
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


					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );
						
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);

						(yyval.exp)->s->type = DATA_TYPE_REAL;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
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
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 706 "src/parser.y" /* yacc.c:1646  */
    {

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);

					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						Quad *quad = new_quad(QUAD_OP_INTMOD, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
						gen(qt, quad);
						(yyval.exp)->s->type = DATA_TYPE_INTEGER;
					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_MODREAL, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);
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
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 750 "src/parser.y" /* yacc.c:1646  */
    {

					/* div is division in which the fractional part (remainder) is discarded */

					(yyval.exp) = new_exp_a_b(ARITHMETIC_EXP);
					(yyval.exp)->s = new_symbol("_tmp");
					add_symbol(st, (yyval.exp)->s);


					if ( ( (yyvsp[-2].exp)->s->type == INTEGER ) && ( (yyvsp[0].exp)->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );

						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, (yyvsp[-2].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, (yyval.exp)->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);
					}
					else if ( ( (yyvsp[-2].exp)->s->type == REAL ) && ( (yyvsp[0].exp)->s->type == REAL ) )
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
#line 2063 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 805 "src/parser.y" /* yacc.c:1646  */
    {

					(yyval.exp) = new_exp_a_b( ARITHMETIC_EXP );
					(yyval.exp)->s = new_symbol( "_tmp" );
					(yyval.exp)->S->type = DATA_TYPE_INTEGER;
					add_symbol(st, (yyval.exp)->s);

				}
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 814 "src/parser.y" /* yacc.c:1646  */
    {
					(yyval.exp) = new_exp_a_b( ARITHMETIC_EXP );
					(yyval.exp)->s = new_symbol( "_tmp" );
					(yyval.exp)->S->type = DATA_TYPE_REAL;
					add_symbol(st, (yyval.exp)->s);
				}
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 821 "src/parser.y" /* yacc.c:1646  */
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
						Quad *quad = new_quad(QUAD_OP_INTUNIMUS, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id)
					}
					else if ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL )
					{
						Quad *quad = new_quad(QUAD_OP_REALUNIMUS, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyval.exp)->s->id)
					}

				}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 849 "src/parser.y" /* yacc.c:1646  */
    {

				}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 853 "src/parser.y" /* yacc.c:1646  */
    {

					/**
					 * Production 1: E --> E1 OR M E2
					 * 	{
					 * 		backpatch(E1.falselist, M.quad);
					 *		E.truelist := merge(E1.truelist, E2.truelist)
					 *		E.falselist := E2.falselist
					 *	}
					 */

					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
					add_symbol( st, (yyval.exp)->s );
					
					backpatch((yyvsp[-3].exp)->falselist, (yyvsp[-1].next_quad));
					(yyval.exp)->truelist = merge((yyvsp[-3].exp)->truelist, (yyvsp[0].exp)->truelist);
					(yyval.exp)->falselist = (yyvsp[0].exp)->falselist;

				}
#line 2153 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 875 "src/parser.y" /* yacc.c:1646  */
    {
					/**
					 * Production 2: E --> E1 AND M E2
					 * 	{
					 * 		backpatch(E1.truelist, M.quad);
					 *		E.truelist := E2.truelist
					 *		E.falselist := merge(E1.falselist, E2.falselist)
					 *	}
					 */

					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
					add_symbol( st, (yyval.exp)->s );
					
					backpatch((yyvsp[-3].exp)->truelist, (yyvsp[-1].next_quad));
					(yyval.exp)->truelist = (yyvsp[0].exp)->truelist;
					(yyval.exp)->falselist = merge((yyvsp[-3].exp)->falselist, (yyvsp[0].exp)->falselist);

				}
#line 2178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 896 "src/parser.y" /* yacc.c:1646  */
    {

					/**
					 * Production 3: E --> not E1
					 * {
					 * 		E.truelist = E1.falselist
					 *		E.falselist = E1.truelist
					 * }
					 */
					
					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					(yyval.exp)->truelist = (yyvsp[0].exp)->falselist;
					(yyval.exp)->falselist = (yyvsp[0].exp)->truelist;

				}
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 916 "src/parser.y" /* yacc.c:1646  */
    {

					/**
					 * Production 4: E --> (E1)
					 * 	{
					 *		E.truelist := E1.truelist
					 *		E.falselist := E1.falselist
					 * 	}
					 */
					
					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					(yyval.exp)->truelist = (yyvsp[-1].exp)->truelist;
					(yyval.exp)->falselist = (yyvsp[-1].exp)->falselist;

				}
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 936 "src/parser.y" /* yacc.c:1646  */
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

					(yyval.exp) = new_exp_a_b(BOOLEAN);

					 /* We create new tmp variable and add to symbol table*/
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
					add_symbol( st, (yyval.exp)->s );

					/* We generate new quadruples */ 
					Quad *quad1 = new_quad((yyvsp[-1].oprel_val), (yyvsp[-2].exp)->s->is, (yyvsp[-1].oprel_val)->s->id, QUAD_OP_NOGOTO);
					Quad *quad2 = new_quad(QUAD_OP_GOTO, (yyval.exp)->s->id, QUAD_OP_FALSE, QUAD_OP_NOGOTO);

					gen( qt, quad1 );
					gen( qt, quad2 );

					(yyval.exp)->truelist = makelist( quad1 );
					(yyval.exp)->falselist = makelist( quad2 );

				}
#line 2261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 967 "src/parser.y" /* yacc.c:1646  */
    {
					/** 
					  * Production 6: E --> true
					  * { E.truelist := makelist(nextaddr) } 
					  * 
					  */
					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, (yyval.exp)->s);

					Quad *quad = new_quad(GOTO, (yyval.exp)->s->id, OP_QUAD_TRUE, NOTGOTO);
					gen(qt, quad);
					(yyval.exp)->truelist = makelist( quad );


				}
#line 2284 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 986 "src/parser.y" /* yacc.c:1646  */
    {
					/** 
					  * Production 7: E --> false
					  * { E.falselist := makelist(nextaddr) } 
					  * 
					  */
					(yyval.exp) = new_exp_a_b(BOOLEAN);
					(yyval.exp)->s = new_symbol("_tmp");
					(yyval.exp)->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, (yyval.exp)->s);

					Quad *quad = new_quad(GOTO, (yyval.exp)->s->id, OP_QUAD_FALSE, NOTGOTO);
					gen(qt, quad);
					(yyval.exp)->falselist = makelist( quad );

				}
#line 2306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1013 "src/parser.y" /* yacc.c:1646  */
    { (yyval.next_quad) = next_quad() }
#line 2312 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1017 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_EQ }
#line 2318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1018 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_NE }
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1019 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_GT }
#line 2330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1020 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_GE }
#line 2336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1021 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_LT }
#line 2342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1022 "src/parser.y" /* yacc.c:1646  */
    { (yyval.oprel_val) = QUAD_OP_LE }
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1035 "src/parser.y" /* yacc.c:1646  */
    {
					/**
					 * Prodcution 6: E --> id
					 * Semantic Rule:
					 * 	{
					 * 		E.place := id.val
					 *		E.type := consultar_tipo_TS( id.val );
					 *	}
					 */
					
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
#line 2378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1080 "src/parser.y" /* yacc.c:1646  */
    {


					/**
					 *
					 * 
					 *
					 */

					if ( (yyvsp[-2].exp)->s->type == (yyvsp[0].exp)->s->type )
					{
						Quad *quad = new_quad( QUAD_OP_ASSIGN, (yyvsp[-2].exp)->s->id, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( REAL2INT, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_REAL ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2REAL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_INTEGER ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_BOOLEAN ) )
					{
						Quad *quad = new_quad( BOOL2INT, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );	
					}
					else if ( ( (yyvsp[-2].exp)->s->type == DATA_TYPE_BOOLEAN ) && ( (yyvsp[0].exp)->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, (yyvsp[0].exp)->s->id, QUAD_OP_VOID, (yyvsp[-2].exp)->s->id );
						gen( qt, quad );
					}
					


				}
#line 2431 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2435 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1182 "src/parser.y" /* yacc.c:1906  */



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
			stack = nuevaPila( &stack );

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
