#!/usr/bin/env python

def fibonacci():
	x, y = 0, 1
	while True:
		yield x
		x, y = y, x + y

def test_fib1():
	import itertools
	print list(itertools.islice(fibonacci(), 10))

def test_fib2():
	for i in fibonacci():
		if i > 100:
			break
		print i, 
	print ""

def test_fib3():
	print [i for i in fibonacci() if i < 100]

if "__main__" == __name__:
	test_fib1()
	test_fib2()
	# test_fib3()  ??? go infinite why ???
