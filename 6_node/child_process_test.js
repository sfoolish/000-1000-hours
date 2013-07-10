#!/usr/bin/env node

/* child process spawn test */

var spawn = require('child_process').spawn;
var ls = spawn('ls', ['-l', '/usr/']);

var start = +new Date();

ls.stdout.on('data', function(data) {
  console.log('stdout: ' + data);
});

ls.stderr.on('data', function(data) {
  console.log('stderr: ' + data);
});

ls.on('exit', function(code) {
  var end = +new Date();
  console.log(end - start);
});
