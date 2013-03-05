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
