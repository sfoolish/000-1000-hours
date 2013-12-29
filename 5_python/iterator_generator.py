#!/usr/bin/env python

def fibonacci():
	x, y = 0, 1
	while True:
		yield x
		print "----", x
		x, y = y, x + y

def test_fib():
	import itertools
	print list(itertools.islice(fibonacci(), 10))

if "__main__" == __name__:
	test_fib()
