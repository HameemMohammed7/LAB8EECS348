all: football_score temp_convert

football_score: football_score.c
	gcc -o football_score football_score.c

temp_convert: temp_convert.c
	gcc -o temp_convert temp_convert.c

clean:
	rm -f football_score temp_convert
