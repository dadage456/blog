# 深入理解计算机系统（第2版）

### 习题 3.4

强制类型转换参考 **2.2.6 扩展一个数字的位表示**

1. `char -> unsigned` 的指令为什么是 `movsbl ...`，而不是 `movzbl ...`？

    根据提示 “当执行既涉及数据宽度变化又涉及符号改变的强制类型转换时，先改变数据宽度”，所以

    `char -> unsigned` 实际上可以看成是 `char -> int（改变数据宽度） -> unsigned int（改变符号）`，`char -> int` 的指令为 `movsbl ...`， 而 `int -> unsigned int` 的位表示实际上是一样的，故无需任何操作。

    结论：是否使用符号扩展，只跟要转换的数据类型有关，跟转换后的数据类型无关。


2. `int -> char` 的指令是 `movb %src, (%edx)`，是否会丢失符号信息？

    会。这种情况下，直接截较宽数据类型的低位传递给较窄数据类型，如下：

    ```
    int i = 0x000000ff;
    char c = (char) i;           // pass 0xff to c
    printf("%d, %d\n", i, c);    // output: 255, -1

    int i2 = 0xffffff7f;
    char c2 = (char) i2;         // pass 0x7f to c2
    printf("%d, %d\n", i2, c2);  // output: -129, 127
    ```


3. `unsigned char -> int` 的指令，使用 `movl %eax, (%edx)` 是否也能达到同样的效果？

    如果 %eax 的其他高位保存有其他数据的话自然是不可以。


4. 在进行 `mov %eax, (%edx)` 操作后，%eax 的值是保持不变还是归零？