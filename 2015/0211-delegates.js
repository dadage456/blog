// 将一个对象的属性的子属性、方法委托到对象本身上面
// 这是一种对常用子属性、方法提供便捷访问的方式
var delegate = require('delegates');

function Person() {}
Person.prototype.hand = {
  fetch: function(thing) {
    console.log('fetch', thing, 'using', this.fingers, 'fingers.');
  },
  fingers: 5
}

var p = new Person();

console.log('委托前：');
console.log('typeof p.fetch is', typeof p.fetch);
console.log('p.fingers =', p.fingers);

// 将 p.hand 的 fingers 属性和 fetch 方法委托到对象 p 上
delegate(p, 'hand')
  .access('fingers')
  .method('fetch');

console.log('\n委托后：');
p.fingers = 6;
p.fetch('a cup');

/* 输出结果：
 *
 * 委托前：
 * typeof p.fetch is undefined
 * p.fingers = undefined
 *
 * 委托后：
 * fetch a cup using 6 fingers.
 */