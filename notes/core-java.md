# Core Java

## Volume 1

- ？char 类型，代码点与代码单元（34）
- UTF-16 编码（46）
- `Arrays.deepToString()`（83）
- `intp[][] odds = new int[rows][]`（85）
- 一个实例可以访问其同类实例的私有方法（109）
- ？System.setOut 可以将 final 变量 System.out 重置为不同的流。是因为 System.setOut 是一个 **本地方法**，可以绕过 Java 的存取控制机制（111）
- Java 总是采用值调用（115）
- 构造器的第一个语句为 `this(...)`，是调用该类的另一个构造器（124）
- `$ javac com/mycompany/Employee.java`，`$ java com.mycompany.Employee`（131）
- `super(...)`，`super.method(...)` (145)
- 父类变量引用一个子类实例时，无法使用子类特有的属性和方法（150）
- 子类覆盖方法是，必须保证返回类型是原返回类型及其子类型（151）
- 编写 equals 方法的最佳实践（163）
- hashCode（165）
- `"" + arr` 和 `Arrays.toString(arr)`（167）
- ！！反射（183）
- ？`o.getClass().newInstance()` 如需提供参数，就必须使用 Constructor 类中的 newInstance 方法（184）
- `fieldObj.setAccessible(true)`（191）
- 泛型方法 `public static <T> T getMiddle(T[] a) { ... }`（527）
- 类型限定 `<T extends class & interface1 & interface2 ...>`（528）
- ？翻译泛型方法

## Volume 2

- ? stream, getUTF，修订过的 UTF-8 格式
- ？修改默认的序列化机制（45）
- System.getProperty('line.seperator'), File.seperator