## [Vim使用笔记](http://www.cnblogs.com/jiqingwu/archive/2012/06/14/vim_notes.html)

---
## vim 多行编辑
    1. ctrl + v 进入列编辑模式；
    2. j or k 选择要编辑的范围；
    3. shift + (i or a) 进入编辑模式，输入编辑内容；
    4. esc 结束。

## vimd 多行编辑

Ctrl+V -> select -> Shift+i/Shift+a -> edit -> esc

## 全局替换

:%s/aa/bb/g      将文档中出现的所有包含 aa 的字符串中的 aa 替换为 bb
:12,23s/aa/bb/g  将从12行到23行中出现的所有包含 aa 的字符串中的 aa 替换为 bb
:12,23s/^/#/     将从12行到23行的行首加入 # 字符

## 删除匹配的行

:v/pattern/d      删除不含该字符串的行
:g/pattern/d      删除包含特定字符串的行
:g/^$/d           删除空行
