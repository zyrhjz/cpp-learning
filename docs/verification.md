# 本次归档的验证记录

## 检查范围

- Windows，Visual Studio 18 Community 的 MSVC，C++17，`/W4 /EHsc`。
- 12 个非空源文件分别编译；归档副本与本地原文件的 SHA-256 一致。
- 以下为整理时实际执行的样例。它们不代表全部学习要求都已完成，也没有覆盖所有成员函数和全部输入。
- 第 1 课编译成功，但有 C4067 警告，对应头文件指令末尾多余的分号。
- 第 8 课源文件为空，未归档。

## 编译结果

| 课次 | 编译 | 原文件保持一致 |
|---|---|---|
| lesson-01 | 通过 | 是 |
| lesson-02 | 通过 | 是 |
| lesson-03 | 通过 | 是 |
| lesson-04 | 通过 | 是 |
| lesson-05 | 通过 | 是 |
| lesson-06 | 通过 | 是 |
| lesson-07 | 通过 | 是 |
| lesson-09 | 通过 | 是 |
| lesson-10 | 通过 | 是 |
| lesson-11 | 通过 | 是 |
| lesson-12 | 通过 | 是 |
| lesson-13 | 通过 | 是 |

## 运行结果

表格中的 `<br>` 表示换行。输入错误时，部分程序按其原有逻辑以退出码 1 结束，已分别核对。

| 课次 | 输入 | 预期输出 | 实际输出 | 退出码 | 结果 |
|---|---|---|---|---|---|
| 01 | 无 | Name: hujunzhe<br>Goal:lean c plus plus.<br>Day1. | Name: hujunzhe<br>Goal:lean c plus plus.<br>Day1. | 0 | 通过 |
| 02 | 无 | 00011010<br>1a<br>42 | 00011010<br>1a<br>42 | 0 | 通过 |
| 03 | 无 | before:10<br>stock:7<br>7.5 | before:10<br>stock:7<br>7.5 | 0 | 通过 |
| 04 | 7 2 | 3.50<br>1 | 3.50<br>1 | 0 | 通过 |
| 04 | 7 0 | zero | zero | 1 | 通过 |
| 04 | 10001 2 | range error! | range error! | 1 | 通过 |
| 04 | abc 2 | input error! | input error! | 1 | 通过 |
| 04 | -10000 10000 | -1.00<br>0 | -1.00<br>0 | 0 | 通过 |
| 05 | -1 | invalid | invalid | 1 | 通过 |
| 05 | 17 | minor | minor | 0 | 通过 |
| 05 | 18 | adult | adult | 0 | 通过 |
| 05 | 59 | adult | adult | 0 | 通过 |
| 05 | 60 | senior | senior | 0 | 通过 |
| 05 | 150 | senior | senior | 0 | 通过 |
| 05 | 151 | invalid | invalid | 1 | 通过 |
| 05 | abc | invalid | invalid | 1 | 通过 |
| 06 | 0 | 0 | 0 | 0 | 通过 |
| 06 | 6 | 12 | 12 | 0 | 通过 |
| 06 | 10000 | 25005000 | 25005000 | 0 | 通过 |
| 06 | -1 | invalid | invalid | 1 | 通过 |
| 06 | abc | invalid | invalid | 1 | 通过 |
| 07 | 0 | 0 | 0 | 0 | 通过 |
| 07 | 3 -2 4 0 | 2 | 2 | 0 | 通过 |
| 07 | -3 -2 0 | 0 | 0 | 0 | 通过 |
| 07 | 3 abc 4 0 | 1 | 1 | 0 | 通过 |
| 09 | 3 8 | a:8<br>b:3 | a:8<br>b:3 | 0 | 通过 |
| 10 | 无 | 5<br>0 | 5<br>0 | 0 | 通过 |
| 11 | 无 | 8<br>destroy 8<br>destroy 0 | 8<br>destroy 8<br>destroy 0 | 0 | 通过 |
| 12 | 无 | 8<br>destroy 8<br>destroy 0 | 8<br>destroy 8<br>destroy 0 | 0 | 通过 |
| 13 | 无 | 1<br>2 | 1<br>2 | 0 | 通过 |

## 已知范围限制

- 第 7 课未设置计数上限；本次验证的是当前代码实际实现的规则。
- 第 9 课只核对正常整数输入，尚未实现输入失败处理。
- 第 11、12 课中的 `setvalue` 和 `crease` 没有在当前 `main` 中调用，本次未单独验证。
- 本次只检查当前归档快照，不代表对更早练习版本的检查。
