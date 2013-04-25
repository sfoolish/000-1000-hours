---
## MAC Using Tips
### spotlight
* 打开Spotlight菜单：Control+空格
* 在Finder中打开Spotlight：Command+f
* 清空Spotlight搜索框：ESC
* 关闭Spotlight菜单：ESC按两次

### [macports](http://www.macports.org/)
#### 搜索索引中的软件
    $ port search <name>
#### 安装新软件
    $ sudo port install <name>
#### 卸载软件
    $ sudo port uninstall <name>
### 定时关机命令
    sudo shutdown -h 22:00 May 29th 2010
    sudo shutdown -h +20  #shutdown 20 mins later
### 输入法切换
    command＋空格键

### chrome 使用
#### 快捷键
    * 显示书签栏    cmd + shift + b
    * 保存书签      cmd + d
    * 背景色设置    ctl + shift + g (change colors)
    * 全屏显示      cmd + shift + f
    * 开发者工具    cmd + alt + i
#### 常用插件
    * change colors
    * foxy proxy

---
## hg 通过代理下载源码
    $ cat ~/.hgrc
    '''
        [http_proxy]
        host = http://localhost:8087/
    '''
    $ hg clone <url>
### REF
* [How do I specify a proxy server in my .hgrc file ?](http://selenic.com/pipermail/mercurial/2006-May/008450.html)

---
## man 使用技巧
    * 查看指定文件 man <man file path>
    * h       获取帮助文档
    * j       向下滚动一行 
    * k       向上滚动一行
    * /       向下搜索
    * ?       向上搜索
    * f       向下翻页
    * b       向上翻页

## 统计多个CPU利用率
输入 top 进入交互模式，然后输入 1

---
## 控制台使用
#### 控制台配置 --- 让自己的terminal 变得更漂亮
[给Terminal施点魔法](http://imwuyu.me/talk-about/modify-mac-osx-terminal-prompt-and-color.html/)
#### 一些快捷键
    * Ctrl + h   擦除光标前面的一个字符。
    * Ctrl + r   开始增量历史命令搜索，可以按照关键字查查自己用过哪些命令
    * Ctrl + l   清屏
    * Ctrl + a   光标移到行首
    * Ctrl + e   光标移到行尾
    * Ctrl + w   清除光标之前一个单词
    * Ctrl + k   清除光标到行尾的字符
    * Ctrl + u   擦除一行光标前面的部分。
    * Cmd  + K   清屏
    * Cmd  + t   新建标签
    * Cmd  + {}  x向左/向右切换标签

## secure CRT 中文编码设置
options --> appearance --> character encoding --> (utf-8)
