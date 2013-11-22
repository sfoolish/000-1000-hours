---
## 2013-03-04 ubuntu 12.04 安装 systemtap

### 安装 systemtap 包

    $ sudo apt-get install systemtap
    $ sudo apt-get install systemtap-sdt-dev

### 安装 kernel

    $ cd ~/prj/
    $ mkdir ubuntu_kernel
    $ cd ubuntu_kernel/
    $ sudo apt-get install dpkg-dev debhelper gawk
    $ sudo apt-get build-dep --no-install-recommends linux-image-$(uname -r)
    $ apt-get source linux-image-$(uname -r)
    $ cd linux-3.2.0/
    $ fakeroot debian/rules clean
    $ AUTOBUILD=1 fakeroot debian/rules binary-generic skipdbg=false
    $ sudo dpkg -i linux-image-3.2.0-39-generic_3.2.0-39.62_amd64.deb 
    # 重启继续安装
    $ sudo dbus-send --system --print-reply  --dest=org.freedesktop.ConsoleKit /org/freedesktop/ConsoleKit/Manager  org.freedesktop.ConsoleKit.Manager.Restart
    $ cd prj/ubuntu_kernel/
    $ sudo dpkg -i linux-image-3.2.0-39-generic-dbgsym_3.2.0-39.62_amd64.ddeb
    $ sudo apt-get install linux-headers-3.2.0-39
    $ sudo dpkg -i linux-headers-3.2.0-39-generic_3.2.0-39.62_amd64.deb 

### 启动 stap

    $ sudo stap -e 'probe kernel.function("sys_open") {log("hello world") exit()}' 

### REF

[ubuntu上安装systemtap](http://www.cnblogs.com/hdflzh/archive/2012/07/25/2608910.html)

---

## 2013-03-05 systemtap 使用

### systemtap 源码下载

    $ apt-get source systemtap

### vim systemtap 语法高亮

    $ cd systemtap-1.6/vim
    $ sudo cp stap.vim /usr/share/vim/vim73/syntax/
    $ sudo cp indent/stap.vim /usr/share/vim/vim73/indent
    $ sudo cp ftplugin/stap.vim /usr/share/vim/vim73/ftplugin
    $ sudo vim /usr/share/vim/vim73/filetype.vim # 添加下面两行
        " SystemTap scripts
        au BufNewFile,BufRead *.stp                     setf stap

[Add Vim Syntax Highlighting for SystemTap](http://sourceware.org/systemtap/wiki/VIMSyntaxHighlightingForSystemtap)

### systemtap 相关文档资料

* [systemtap documentation](http://sourceware.org/systemtap/documentation.html)
* [systemtap wiki](http://sourceware.org/systemtap/wiki)
* [Linux 自检和 SystemTap](www.ibm.com/developerworks/cn/linux/l-systemtap/)
* [SystemTap wikipedia](http://en.wikipedia.org/wiki/SystemTap)
* [SystemTap: Instrumenting the Linux Kernel for Analyzing Performance and Functional Problems](http://www.redbooks.ibm.com/abstracts/redp4469.html)

---

## Systemtap 交叉编译资料

* [交叉编译 perf for arm](http://freenix.blogcn.com/articles/%E4%BA%A4%E5%8F%89%E7%BC%96%E8%AF%91-perf-for-arm.html) : elfutil zlib 编译过程
* [用systemtap研究内核](http://blog.csdn.net/absurd/article/details/1643003) :  李先静 用处不大
* [Systemtap-omap pedia](http://omappedia.org/wiki/Systemtap) : Mark 需要仔细认真阅读 
* [systemtap在android、pandaboard上的移植](http://blog.csdn.net/lzuzhp06/article/details/7778189)
