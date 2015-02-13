// 使用 http 模块编写的 post 大段数据的小例子
var http = require('http');
var qs = require('querystring');


var server = http.createServer();

server.on('request', function(req, res) {
  console.log('SERVER: received a request, method =', req.method, ', head =', req.headers)

  req.on('data', function(chunk) {
    var len = Buffer.byteLength(chunk);
    console.log('SERVER: received data, length =', len);
    res.write('server receive a chunk from client of length ' + len);
  });

  req.on('end', function() {
    res.end('client end');
  })
});

server.on('connect', function(req, socket, head) {
  console.log('a new connection');
});

server.listen(8888);


var msg = '';
for(var i = 0; i < 400000; i++) {
  msg += i % 10;
}

var data = qs.stringify({
  msg: msg
});

var opts = {
  hostname: 'localhost',
  port: 8888,
  path: '/',
  method: 'POST',
  headers: {
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Content-Length': data.length
  }
}

var req = http.request(opts, function(res) {
  console.log('CLIENT: status =', res.statusCode);
  console.log('CLIENT: headers =', JSON.stringify(res.headers));
  res.setEncoding('utf8');
  res.on('data', function(chunk) {
    console.log('CLIENT: data =', chunk);
  });
});

req.on('error', function(e) {
  console.log('CLIENT: error =', e.message);
});

req.write(data);
req.end();


