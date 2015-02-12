// 一个访问有权限控制（authorization）的页面例子
// 使用：
//   1. 运行 `$ node --harmony 0212-roles.js`
//   2. 在浏览器中依次访问 '/', '/article', '/article/new', '/admin' 和 '/admin/user'
// 访问结果：
//   除了 '/admin/user' 不允许访问外，其他页面均可访问
//   每个可访问的页面都显示了当前访问者的角色，以及可访问该页面的所有角色
// 对该类问题进行抽象，其实就是依次解决以下 3 个问题：
//   1. 进行某个操作（本例中是访问某个页面）的用户是谁？
//   2. 该用户扮演了什么角色？
//   3. 该角色是不是具有该操作权限？

var koa = require('koa');
var router = require('koa-router');
var Roles = require('koa-roles');

var app = koa();
app.use(router(app));

var user = new Roles(/*这里可以自定义验权失败的处理函数*/);
app.use(user.middleware());


/*******************************************************************************
 * 对角色的操作类型进行验权
 ******************************************************************************/

/**
 * 本例中 user.use() 的参数说明：
 * @param1 action {String} 操作类型，可为任意字符串，是开发者对业务进行的归纳和抽象
 *   例如 “查看自己发表的所有文章”（访问 '/article'）
 *   和 “发表新文章”（访问 '/article/new'
 *   都被归纳为 'manage articles' 操作类型
 * @param2 validator {Function} 验权函数，当前角色具有操作权限时，返回 true
 *
 * 注：该方法还支持其他参数传入方式，具体请查看相关 API 文档
 */

user.use('view articles', function() {
  return true;
});

user.use('manage articles', function() {
  var role = this.user.role;
  if (role === 'author' || role === 'admin') {
    return true;
  }
});

user.use('manage website', function() {
  if (this.user.role === 'admin') {
    return true;
  }
})


/*******************************************************************************
 * 以页面为验权粒度，对访问的页面加入权限控制
 ******************************************************************************/

app.get('/',
  // 简单起见，我们使用一个前置的中间件来模拟用户角色设置
  // 通常这步工作是由身份验证（authentication）模块来完成的，例如：
  //   用户使用账户名和密码或其他方式进行登录后，
  //   服务端就会获得该用户的信息（this.user）
  //   其中包含了用户的角色信息（this.user.role）
  // 这里将访问者的角色设为 “匿名用户”
  function *(next) {
    this.user = {role: 'anonymous'};
    yield *next;
  },
  // 验权中间件
  // 任何角色都能通过该验权
  user.can('view articles'),
  // 正常返回页面内容
  function *(next) {
    this.body = 'Your role is: ' + this.user.role + '\n'
      + 'Every one can view the posted articles';
  }
);

app.get('/article', function *(next) {
  this.user = {role: 'author'};
  yield *next;
}, user.can('manage articles'), function *(next) {
  this.body = 'Your role is: ' + this.user.role + '\n'
    + 'Both "author" and "admin" can manage their own articles';
}
);

app.get('/article/new',function *(next) {
  this.user = {role: 'admin'};
  yield *next;
}, user.can('manage articles'), function *(next) {
  this.body = 'Your role is: ' + this.user.role + '\n'
    + 'Both "author" and "admin" can post a new article';
});

app.get('/admin',function *(next) {
  this.user = {role: 'admin'};
  yield *next;
}, user.can('manage website'), function *(next) {
  this.body = 'Your role is: ' + this.user.role + '\n'
    + 'Only "admin" can manage the website';
});

app.get('/admin/user',function *(next) {
  this.user = {role: 'author'};
  yield *next;
}, user.can('manage website'), function *(next) {
  this.body = 'Your role is: ' + this.user.role + '\n'
    + 'Only "admin" can manage the users';
});


app.listen(8888);


