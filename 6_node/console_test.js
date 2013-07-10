#!/usr/bin/env node

/* console time/timeEnd test */

function console_time_test(fn, args) {
  console.time("console_time_test");
  fn(args);
  console.timeEnd("console_time_test");
}

console_time_test(function (args) {
  for (var i = 0; i < args; i++) {
    console.log("i = %d", i);
  }
}, 100)