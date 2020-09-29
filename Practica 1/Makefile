default:
	clear
	flex scanner.l
	gcc lex.yy.c -o scanner -lfl -lm
clean:
	clear
	rm -v lex.yy.c
	rm -v scanner
