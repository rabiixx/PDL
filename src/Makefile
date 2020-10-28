all: parser scanner
	gcc lex.yy.c scanner.tab.c -o scanner -lfl -lm

parser:
	bison -d scanner.y

scanner:
	flex scanner.l
