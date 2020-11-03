modules = lib/symboltable/symbol_table.c lib/quadruples/quadruples.c lib/stack/stack.c lib/exp_a_b/exp_a_b.c

parser:
	bison -d src/parser.y

scanner:
	flex src/scanner.l

all: parser scanner $(modules)
	gcc lex.yy.c parser.tab.c $(modules) -o compiler -lfl

debug: parser scanner $(modules)
	gcc lex.yy.c parser.tab.c $(modules) -o compiler -lfl -D _DEBUG

