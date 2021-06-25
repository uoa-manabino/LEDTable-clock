var serialport = require('serialport');

var value = 0;

const Readline = require('@serialport/parser-readline')

var portName = "COM7";
var port = new serialport(portName, {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    waitMsecAfterOpen: 2000
});

const parser = new Readline()

port.pipe(parser)

parser.on('data', function (data) {
  console.log('Data: ' + data);
});
port.on('open', function () {
    console.log('Serial open.');
    setInterval(myWrite, 1000)
  });

function myWrite(){
  var now = new Date();
  write(now.getHours() + '\n' + now.getMinutes() + '\n');
}

function write(data) {
    console.log('Time\n' + data);
    port.write(new Buffer(data), function(err, results) {
      if(err) {
        console.log('Err: ' + err);
        console.log('Results: ' + results);
      }
  });
}