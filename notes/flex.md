# Flex, version 2.5

A fast scanner generator

Edition 2.5, March 1995

Vern Paxson

[原文链接](http://dinosaur.compilertools.net/flex/index.html)

---

- [Name](#Name)
- [Synopsis](#Synopsis)
- [Overview](#Overview)
- [Description](#Description)
- [Some simple examples](#Some simple examples)
- [Format of the input file](#Format of the input file)
- [Patterns](#Patterns)
- [How the input is matched](#How the input is matched)
- [Actions](#Actions)
- [The generated scanner](#The generated scanner)
- [Start conditions](#Start conditions)
- [Multiple input buffers](#Multiple input buffers)
- [End-of-file rules](#End-of-file rules)
- [Miscellaneous macros](#Miscellaneous macros)
- [Values available to the user](#Values available to the user)
- [Interfacing with yacc](#Interfacing with yacc)
- [Options](#Options)
- [Performance considerations](#Performance considerations)
- [Generating C++ scanners](#Generating C++ scanners)
- [Incompatibilities with lex and POSIX](#Incompatibilities with lex and POSIX)
- [Diagnostics](#Diagnostics)
- [Files](#Files)
- [Deficiencies / Bugs](#Deficiencies / Bugs)
- [See also](#See also)
- [Author](#Author)


<h2 id="Name">Name</h2>

flex - fast lexical analyzer generator

<h2 id="Synopsis">Synopsis</h2>

```
flex [-bcdfhilnpstvwBFILTV78+? -C[aefFmr] -ooutput -Pprefix -Sskeleton]
[--help --version] [filename ...]
```

<h2 id="Overview">Overview</h2>

This manual describes flex, a tool for generating programs that perform pattern-matching on text. The manual includes both tutorial and reference sections:

- Description
  - 简要概览。
- Some Simple Examples
- Format Of The Input File
- Patterns
  - flex 使用的扩展的正则表达式。
- How The Input Is Matched
  - 决定如何匹配的规则。
- Actions
  - 指定一个模式匹配时做什么。
- The Generated Scanner
  - 一些关于 flex 生成的扫描器的细节；以及如何控制输入源。
- Start Conditions
  - 在扫描器中引入上下文；管理 “迷你扫描器”。
- Multiple Input Buffers
  - 如何操作多个输入源；如何扫描字符串，而非文件。
- End-of-file Rules
  - 匹配输入末尾的特殊规则。
- Miscellaneous Macros
  - Action 可用的宏。
- Values Available To The User
  - Action 可用的值。
- Interfacing With Yacc
  - 和 yacc 解析器联合使用。
- Options
  - flex 命令行选项，及 "%option" 指令。
- Performance Considerations
  - 如何使你的扫描器尽可能的快。
- Generating C++ Scanners
  - （实验中的）创建 C++ 扫描器类的功能。
- Incompatibilities With Lex And POSIX
  - flex 和 AT&T lex 的不同之处，以及 POSIX lex 标准。
- Diagnostics
  - flex 产生的那些含义可能不明确的错误信息。
- Files
  - flex 使用的文件。
- Deficiencies / Bugs
  - flex 的已知问题。
- See Also
  - 其他文档，关联工具。
- Author
  - 包含联系信息。

<h2 id="Description">Description</h2>
<h2 id="Some simple examples">Some simple examples</h2>
<h2 id="Format of the input file">Format of the input file</h2>
<h2 id="Patterns">Patterns</h2>
<h2 id="How the input is matched">How the input is matched</h2>
<h2 id="Actions">Actions</h2>
<h2 id="The generated scanner">The generated scanner</h2>
<h2 id="Start conditions">Start conditions</h2>
<h2 id="Multiple input buffers">Multiple input buffers</h2>
<h2 id="End-of-file rules">End-of-file rules</h2>
<h2 id="Miscellaneous macros">Miscellaneous macros</h2>
<h2 id="Values available to the user">Values available to the user</h2>
<h2 id="Interfacing with yacc">Interfacing with yacc</h2>
<h2 id="Options">Options</h2>
<h2 id="Performance considerations">Performance considerations</h2>
<h2 id="Generating C++ scanners">Generating C++ scanners</h2>
<h2 id="Incompatibilities with lex and POSIX">Incompatibilities with lex and POSIX</h2>
<h2 id="Diagnostics">Diagnostics</h2>
<h2 id="Files">Files</h2>
<h2 id="Deficiencies / Bugs">Deficiencies / Bugs</h2>
<h2 id="See also">See also</h2>
<h2 id="Author">Author</h2>