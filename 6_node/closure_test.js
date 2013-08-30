#!/usr/bin/env node

function closure_counter() {
  var x = 0
  function counter() {
  	x += 1
  	return x
  };
  return counter
}

c1 = closure_counter()
c2 = closure_counter()
console.log("%d %d %d %d", c1(), c1(), c2(), c2());
