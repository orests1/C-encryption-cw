coursework: compile test4 test1 test2 test3 

compile:
	cl -w cw1.c
test4:
	cw1 -d -i 04.txt -k 1024
test1:
	cw1 -d -i 01.txt
test2:
	cw1 -d -i 02.txt -k 42
test3:
	cw1 -d -i 03.txt -k 555
