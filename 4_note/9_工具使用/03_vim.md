## [Vim使用笔记](http://www.cnblogs.com/jiqingwu/archive/2012/06/14/vim_notes.html)

---

## vim 多行编辑

Ctrl+V -> select -> Shift+i/Shift+a -> edit -> esc

1. ctrl + v 进入列编辑模式；
2. j or k 选择要编辑的范围；
3. shift + (i or a) 进入编辑模式，输入编辑内容；
4. esc 结束。

## 全局替换

:%s/aa/bb/g      将文档中出现的所有包含 aa 的字符串中的 aa 替换为 bb
:12,23s/aa/bb/g  将从12行到23行中出现的所有包含 aa 的字符串中的 aa 替换为 bb
:12,23s/^/#/     将从12行到23行的行首加入 # 字符

## 删除匹配的行

:v/pattern/d      删除不含该字符串的行
:g/pattern/d      删除包含特定字符串的行
:g/^$/d           删除空行

## 语法高亮语言配置

```bash
:setf language
:setf sh
:setf c
:setf php
```

---

## VIM 多窗口

vim -On file1 file2 ... 垂直分屏
vim -on file1 file2 ... 水平分屏

### 窗口切换

:set mouse = a   为命令、输入、导航都激活鼠标的使用

按住Ctrl + W，然后再加上h, j, k, l，分别表示向左、下、上、右移动窗口

Ctrl+w + h：向左移动窗口
Ctrl+w + j： 向下移动窗口
Ctrl+w + j： 向上移动窗口
Ctrl+w + l： 向右移动窗口

Ctrl+w + w：这个命令会在所有窗口中循环移动
Ctrl+w + t：移动到最左上角的窗口
Ctrl+w + b：移动到最右下角的窗口
Ctrl+w + p：移动到前一个访问的窗口

### 关闭与离开窗口

有4种关闭窗口的方式，分别是：离开（quit）、关闭（close）、隐藏（hide）、关闭其他窗口

^代表Ctrl键
^Wq，离开当前窗口
^Wc，关闭当前的窗口
^Wo，关闭当前窗口以外的所有窗口

### REF

* http://blog.csdn.net/shuangde800/article/details/11430659


## Vim 快捷键

* http://blog.vgod.tw/wp-content/uploads/2009/12/vgod-vim-cheat-sheet-full.pdf


## Vim UTF8

```bash
set encoding=utf-8
set fileencoding=utf-8
```

## Vim tab size

```bash
set expandtab ts=4 sw=4 ai
```

* http://stackoverflow.com/questions/1878974/redefine-tab-as-4-spaces
