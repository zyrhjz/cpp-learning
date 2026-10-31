# C++ 入门练习

记录从控制台输入输出、条件与循环，到引用、类和静态成员的练习。

本仓库保存平时上机练习的源文件快照。源代码保持归档时的写法，目录和说明经过整理，部分学习过程使用了 AI 辅助。这里是学习记录，后续会随着练习继续修改。

## 练习目录

每个目录中的 `main.cpp` 都是一个独立程序，需要分别编译运行。

| 目录 | 内容 | 输入示例 | 输出或观察点 |
|---|---|---|---|
| [lesson-01](examples/lesson-01/main.cpp) | 控制台输出 | 无 | 输出三行个人练习信息 |
| [lesson-02](examples/lesson-02/main.cpp) | 二进制、十六进制与十进制输出 | 无 | `00011010`、`1a`、`42` |
| [lesson-03](examples/lesson-03/main.cpp) | 变量副本、库存修改与常量 | 无 | `before:10`、`stock:7`、`7.5` |
| [lesson-04](examples/lesson-04/main.cpp) | 输入检查、除法、取余、输出精度 | `7 2` | `3.50`、`1` |
| [lesson-05](examples/lesson-05/main.cpp) | 年龄范围与分支判断 | `18` | `adult` |
| [lesson-06](examples/lesson-06/main.cpp) | 循环与偶数求和 | `6` | `12` |
| [lesson-07](examples/lesson-07/main.cpp) | 循环、退出与跳过 | `3 -2 4 0` | `2` |
| [lesson-09](examples/lesson-09/main.cpp) | 使用引用交换变量 | `3 8` | `a:8`、`b:3` |
| [lesson-10](examples/lesson-10/main.cpp) | 类、对象与成员默认值 | 无 | `5`、`0` |
| [lesson-11](examples/lesson-11/main.cpp) | 构造析构、封装与 const 成员函数 | 无 | `8`、`destroy 8`、`destroy 0` |
| [lesson-12](examples/lesson-12/main.cpp) | 类与 const 对象的再次练习 | 无 | 当前与第 11 课内容基本相同 |
| [lesson-13](examples/lesson-13/main.cpp) | 静态数据成员与类外定义 | 无 | `1`、`2` |

第 8 课的本地源文件为空，未加入本次归档。目录编号保留原来的课次，不代表所有课程练习都已完成。

## 运行方法

### Visual Studio

建立一个控制台项目，将需要运行的某一个 `main.cpp` 添加到项目中，然后编译运行。一个项目只加入一个包含 `main` 的练习文件。

### MSVC 命令行

在 Visual Studio 的开发人员命令提示符中，进入仓库根目录，运行以下命令：

```bat
mkdir build
cl /nologo /std:c++17 /W4 /EHsc examples\lesson-13\main.cpp /Fe:build\lesson-13.exe /Fo:build\lesson-13.obj
build\lesson-13.exe
```

运行其他练习时，将命令中的 `lesson-13` 改成对应目录名。`build` 目录已存在时，无需再次创建。

## 当前版本中值得继续检查的地方

- 第 1 课的 `#include<iostream>;` 末尾多了一个分号，编译器可能报告警告。本次保留原文件，便于之后单独记录修正。
- 第 7 课当前只统计正数，没有实现“最多统计 1000 个”的规则。
- 第 9 课尚未处理非数字输入。
- 第 11、12 课保留了相近的课堂练习；本次检查不代表其中所有成员函数都经过验证。

## 检查记录

编译环境、实际运行的输入输出和检查范围见 [验证记录](docs/verification.md)。

## 后续练习

- 继续理解只读引用、对象生命周期及构造析构。
- 学习常用容器与文件读写。
- 按实际练习进度补充输入检查和边界验证。

以上为后续计划，尚未完成的内容没有作为现有功能列出。
