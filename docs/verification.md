# 修正后的验证记录

## 检查环境与结论

- Windows，Visual Studio 18 Community 的 MSVC，C++17。
- 编译选项：`/W4 /WX /EHsc /utf-8`，12 个练习和 2 个成员测试程序均编译通过；警告按错误处理。
- 共 51 组检查通过：49 组练习程序的输入输出检查，以及第 11、12 课各一组成员回归检查。
- 验证针对本次修正版；桌面原始练习未修改。

## 重新执行

在 Visual Studio Developer PowerShell 中进入仓库根目录，执行：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\run-checks.ps1
```

完整实际结果保存在 `build/checks/results.json`。输出目录已被 `.gitignore` 排除。

## 实际运行结果

表格中的 `<br>` 表示换行。预期的输入错误会以退出码 1 结束，这也属于正确结果。

| 检查 | 输入或场景 | 实际输出 | 退出码 | 结果 |
|---|---|---|---|---|
| lesson-01 | (empty / no input) | Name: hujunzhe<br>Goal:learn c plus plus.<br>Day1. | 0 | 通过 |
| lesson-02 | (empty / no input) | 00011010<br>1a<br>42 | 0 | 通过 |
| lesson-03 | (empty / no input) | before:10<br>stock:7<br>7.5 | 0 | 通过 |
| lesson-04 | 7 2 | 3.50<br>1 | 0 | 通过 |
| lesson-04 | 7 0 | zero | 1 | 通过 |
| lesson-04 | 10001 2 | range error! | 1 | 通过 |
| lesson-04 | abc 2 | input error! | 1 | 通过 |
| lesson-04 | -10000 10000 | -1.00<br>0 | 0 | 通过 |
| lesson-04 | 10000 -10000 | -1.00<br>0 | 0 | 通过 |
| lesson-04 | 1 -10001 | range error! | 1 | 通过 |
| lesson-05 | -1 | invalid | 1 | 通过 |
| lesson-05 | 0 | minor | 0 | 通过 |
| lesson-05 | 17 | minor | 0 | 通过 |
| lesson-05 | 18 | adult | 0 | 通过 |
| lesson-05 | 59 | adult | 0 | 通过 |
| lesson-05 | 60 | senior | 0 | 通过 |
| lesson-05 | 150 | senior | 0 | 通过 |
| lesson-05 | 151 | invalid | 1 | 通过 |
| lesson-05 | abc | invalid | 1 | 通过 |
| lesson-06 | 0 | 0 | 0 | 通过 |
| lesson-06 | 1 | 0 | 0 | 通过 |
| lesson-06 | 6 | 12 | 0 | 通过 |
| lesson-06 | 10000 | 25005000 | 0 | 通过 |
| lesson-06 | 10001 | invalid | 1 | 通过 |
| lesson-06 | -1 | invalid | 1 | 通过 |
| lesson-06 | abc | invalid | 1 | 通过 |
| lesson-07 | 0 | 0 | 0 | 通过 |
| lesson-07 | 3 -2 4 0 | 2 | 0 | 通过 |
| lesson-07 | -3 -2 0 | 0 | 0 | 通过 |
| lesson-07 | 3 abc 4 0 | 1 | 0 | 通过 |
| lesson-07 | 0 2 3 | 0 | 0 | 通过 |
| lesson-07 | 2 3 | 2 | 0 | 通过 |
| lesson-07 | (empty / no input) | 0 | 0 | 通过 |
| lesson-07 | 999 positive values, then 0 | 999 | 0 | 通过 |
| lesson-07 | 1000 positive values, then 0 | 1000 | 0 | 通过 |
| lesson-07 | 1001 positive values, then 0 | 1000 | 0 | 通过 |
| lesson-07 | 1001 positive values interleaved with negatives | 1000 | 0 | 通过 |
| lesson-09 | 3 8 | a:8<br>b:3 | 0 | 通过 |
| lesson-09 | -4 0 | a:0<br>b:-4 | 0 | 通过 |
| lesson-09 | -2147483648 2147483647 | a:2147483647<br>b:-2147483648 | 0 | 通过 |
| lesson-09 | abc 8 | invalid | 1 | 通过 |
| lesson-09 | 3 abc | invalid | 1 | 通过 |
| lesson-09 | 3 | invalid | 1 | 通过 |
| lesson-09 | (empty / no input) | invalid | 1 | 通过 |
| lesson-09 | 2147483648 1 | invalid | 1 | 通过 |
| lesson-10 | (empty / no input) | 5<br>0 | 0 | 通过 |
| lesson-11 | (empty / no input) | 8<br>destroy 8<br>destroy 0 | 0 | 通过 |
| lesson-12 | (empty / no input) | 8<br>destroy 8<br>destroy 0 | 0 | 通过 |
| lesson-13 | (empty / no input) | 1<br>2 | 0 | 通过 |
| counter-11 | constructor, setter, increment and int limits | counter checks passed（另有析构输出） | 0 | 通过 |
| counter-12 | constructor, setter, increment and int limits | counter checks passed（另有析构输出） | 0 | 通过 |

## 成员测试覆盖

第 11、12 课分别检查：默认值为 0；正常和 const 对象可读取；负数与整数最小值构造保留 0；合法设置成功；拒绝负数时保留旧值；正常加一成功；最大值拒绝加一；最大值减一可加到最大值。

## 检查范围

这些结果覆盖本次修正及原有演示行为，不代表对所有输入和完整课程要求的穷尽验证。第 8 课本地文件为空，仍未加入仓库。
