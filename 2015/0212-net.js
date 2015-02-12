// 一个简单的 telnet 程序
// 使用：
//   $ node 0212-net.js
//   $ telnet localhost 8888
// 功能：
//   1. 回显客户端的任何输入
//   2. 客户端输入 exit 时，断开连接
//   3. 客户端空闲 5 秒后，断开连接

var net = require('net');

var server = net.createServer(function(conn) {
  console.log('A new connection');

  conn.write('Welcome!\n');

  conn.on('data', function(data) {
    data = data.toString();
    process.stdout.write('Received data: ' + data);
    conn.write('> ' + data);
    if (data.match(/exit\r\n/)) {
      conn.write('About to exit...\r\n', function() {
        conn.end();
      });
    }
  });

  conn.on('end', function() {
    console.log('Client disconnected');
  });

  conn.setTimeout(5 * 1000, function() {
    conn.write('Timeout! About to exit...\r\n', function() {
      conn.end();
    })
  });
});

server.listen(8888, function() {
  console.log('Opened server on %j', server.address());
});


