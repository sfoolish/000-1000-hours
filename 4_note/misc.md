---
## MAC Using Tips
### spotlight
* 打开Spotlight菜单：Control+空格
* 在Finder中打开Spotlight：Command+f
* 清空Spotlight搜索框：ESC
* 关闭Spotlight菜单：ESC按两次

### [macports](http://www.macports.org/)
#### 更新Port的index
    $ sudo port selfupdate 
#### 搜索索引中的软件
    $ port search <name>
#### 查看软件包的内容和说明
    $ sudo port info <name>
#### 查看软件包的依赖关系
    $ sudo port deps <name>
#### 安装新软件
    $ sudo port install <name>
#### 卸载软件
    $ sudo port uninstall <name>

[MacPorts Guide](http://guide.macports.org/)
[Mac Port 基本用法总结](http://guibin.iteye.com/blog/986838)

### 定时关机命令
    sudo shutdown -h 22:00 May 29th 2010
    sudo shutdown -h +20  #shutdown 20 mins later
### 输入法切换
    command＋空格键
### 微调音量
缺省情况下，使用音量调节按钮，每次都是一次增加或者减少一格音量。如果我们先按下Shift键和Option键，然后再按音量调整键，则把一格音量分成了4份，每次增加或者减少1/4格音量，非常方便。

### 屏幕截图
最简单的对整个屏幕截图的快捷键是Shift+Command+3，默认会把快照照片保存到桌面，格式为png. Shift+Command+4则允许你对特定的区域进行截图。

如果是想把截图放在剪贴板里而不是保存到桌面上，那就分别使用Shift+Control+Command+3和Shift+Control+Command+4

### chrome 使用
#### 快捷键
    * cmd + shift + b                   显示书签栏
    * cmd + d                           保存书签
    * ctl + shift + g (change colors)   背景色设置
    * cmd + shift + f                   全屏显示
    * cmd + alt + i                     开发者工具
#### 常用插件
    * change colors
        颜色配置：
            Background color:       516154 / night    6D8271 / day
            Text color:             1DF00E
            Links color:            CFDB2E
            Visited links color:    FF7B17
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
## MAC 下源码安装正向代理 squid
### 个人应用场景
房间里没有网口，有 wifi 信号，一台台式机跟笔记本网线直连，笔记本通过 wifi 上网，台式机通过笔记本做代理上网。 http 之前用 nginx 做代理已经能正常访问，https 无法正常访问。
### 源码安装 squid
    ## 下载并解压缩源码
    $ wget http://www.squid-cache.org/Versions/v3/3.2/squid-3.2.3.tar.bz2
    $ tar xvf squid-3.2.3.tar.bz2
    $ cd squid-3.2.3
    ## 查看安装说明
    $ vim INSTALL
    ## 创建安装目录
    $ mkdir ../install
    ## 配置，制定安装路径
    $ ./configure --prefix=<path(/Users/apple/APP_PRJ/squid_test/install)>
    ## 编译安装
    $ make -j8 && make install
### 配置运行 squid
    ## 切换到安装目录
    $ cd ../install/etc/
    ## 添加用户名密码
    $ htpasswd -cb passwd <user(sfoolish)> <password(sfoolish)>
    ## 修改配置文件
    $ mv squid.conf squid.conf.bkp
    $ vim squid.conf
    $ cat etc/squid.conf
    ```
        http_port 3128
        #
        #cache_mem 128 MB
        #cache_dir ufs /var/spool/squid 100 16 256
        #
        auth_param basic program /Users/apple/APP_PRJ/squid_test/install/libexec/basic_ncsa_auth /Users/apple/APP_PRJ/squid_test/install/etc/passwd
        auth_param basic children 5
        auth_param basic realm Squid proxy-caching web server
        auth_param basic credentialsttl 12 hours
        auth_param basic casesensitive off
        #
        acl ncsa_users proxy_auth REQUIRED
        acl all src all
        header_access Via deny all
        header_access X-Forwarded-For deny all
        http_access allow ncsa_users
        http_access deny all
    ```
    ## 查看 squid 命令参数帮助说明
    $ ./sbin/squid -h
    ## 启动 squid 服务，如果遇到异常可以添加 `-d level` 输出调试打印
    $ ./sbin/squid start
    ## 启动时遇到如下打印，由于 squid 已经能正常使用没有进一步跟踪
    ```
        2013/05/11 19:33:56| WARNING: (B) '::/0' is a subnetwork of (A) '::/0'
        2013/05/11 19:33:56| WARNING: because of this '::/0' is ignored to keep splay tree searching predictable
        2013/05/11 19:33:56| WARNING: You should probably remove '::/0' from the ACL named 'all'
        2013/05/11 19:33:56| ERROR: Directive 'header_access' is obsolete.
        2013/05/11 19:33:56| ERROR: Directive 'header_access' is obsolete.
    ```
### REF
#### [用Squid搭建带密码认证的http匿名代理服务器](http://www.libertyvps.com/thread-46-1-1.html)
基本上都是按这篇文章来操作的，很详细的，呵呵。
#### [Getting error "Too few basicauthenticator processes are running"](http://www.squid-cache.org/mail-archive/squid-users/200511/0220.html)
最初配置squid.conf 的时候 basic_ncsa_auth, passwd 路径没指定对访问时登入失败。`./sbin/squid -d 9 start` 打开调试打印后，发现一堆如下打印。
    
    ```
        2013/05/11 19:27:24 kid1| WARNING: basicauthenticator #1 exited
        2013/05/11 19:27:24 kid1| Too few basicauthenticator processes are running (need 1/5)
        2013/05/11 19:27:24 kid1| Starting new helpers
        2013/05/11 19:27:24 kid1| helperOpenServers: Starting 1/5 'basic_ncsa_auth' processes
        2013/05/11 19:27:24 kid1| WARNING: basicauthenticator #1 exited
        2013/05/11 19:27:24 kid1| Too few basicauthenticator processes are running (need 1/5)
    ```
### [How To: Install and configure Squid on Mac OS X](http://maxpowerindustries.com/2009/09/27/how-to-install-and-configure-squid-on-mac-os-x/)
大致浏览了下，没仔细看，感觉是不错条理清晰。(来源 google `mac squid proxy`)

---
## mac hfs/hfs+ 文件系统默认不区分大小写
### 现象描述
    $ git clone https://github.com/sfoolish/linux_3.2.0-39.62_ubuntu12.04.git 
    $ cd linux_3.2.0-39.62_ubuntu12.04/
    $ git diff --name-only
    ```
        drivers/net/ethernet/intel/e1000e/netdev.c
        include/linux/netfilter/xt_CONNMARK.h
        include/linux/netfilter/xt_DSCP.h
        include/linux/netfilter/xt_MARK.h
        include/linux/netfilter/xt_RATEEST.h
        include/linux/netfilter/xt_TCPMSS.h
        include/linux/netfilter_ipv4/ipt_ECN.h
        include/linux/netfilter_ipv4/ipt_TTL.h
        include/linux/netfilter_ipv6/ip6t_HL.h
        net/ipv4/netfilter/ipt_ECN.c
        net/netfilter/xt_DSCP.c
        net/netfilter/xt_HL.c
        net/netfilter/xt_RATEEST.c
        net/netfilter/xt_TCPMSS.c
    ```
### REF && 原因解释
#### [How can I discard modified files?](http://stackoverflow.com/questions/8273823/how-can-i-discard-modified-files)
这个链接描述的现象跟我遇到的一模一样，下面是正确的解释。

` this problem was caused, for me, by a non-case-sensitive filesystem (e.g. on Mac OS). You can either create a case-sensitive disk image and mount it and do your git work on there, or use a different OS to do your development.`

将 `linux_3.2.0-39.62_ubuntu12.04/` 拷贝到 ubuntu 下，然后运行 `git reset --hard HEAD` 就恢复正常了。
#### [Mac OS X/HFS+ case-insensitive? Why?](http://davidwinter.me/articles/2008/05/17/mac-os-xhfs-case-insensitive-why/)
It's case-insensitive for historical reasons (Mac OS < OS X was case insensitive, but case-preserving), and some apps that started on the classic Mac OS are still not fully compatible. The Disk Utility in Leopard (and Tiger?) can create a case-insensitive version of HFS+, and the capability has existed since Panther.

I have all my boot volumes set up as case-insensitive. You should test your important apps first, though. FileMaker Pro, for example, works except for the networking component, so I am not able to open network databases. Fortunately, my need for FMP is temporary.

Keep in mind you can create a disk image that is case-sensitive, and mount it somewhere convenient. For example, create a case-sensitive spare image called ~/Projects.sparseimage, then mount it at ~/Projects. This is what FileVault does, for example.

---
### MAC OS 10.6 交叉编译环境构建
* 下载安装 [MAC OSX ARM 交叉工具链](http://www.carlson-minot.com/available-arm-gnu-linux-g-lite-builds-for-mac-os-x/mac-os-x-arm-gnu-linux-g-lite-201109-70-toolchain)

* 安装部分 MAC 不存在的头文件
    #!/bin/sh

    CROSS_INCLUDE_PATH="/usr/local/carlson-minot/crosscompilers/arm-none-linux-gnueabi/libc-2011.09-70-sysroot/usr/include/"
    SYS_INCLUDE_PATH="/usr/include/"
    
    FILES="elf.h features.h bits/predefs.h bits/wordsize.h gnu/stubs.h gnu/stubs-64.h"

    for file in $FILES ;
    do
        diff $CROSS_INCLUDE_PATH$file $SYS_INCLUDE_PATH$file
    done
* 制作安装 mkimage 命令
    $ cd uboot_src
    $ make tools
    $ sudo cp tools/mkimage /usr/bin
#### REF
* [building linux kernel on mac osx](http://stackoverflow.com/questions/10018764/building-linux-kernel-on-mac-os-x)
* [uboot git](http://git.denx.de/?p=u-boot.git;a=summary)

### 用户管理
    $ sudo useradd apple
    $ sudo passwd apple
    
    $ sudo mkdir /home/apple
    $ sudo chown apple:apple /home/apple
    
    $ su - apple

### ssh免输入密码登录
    mac : $ ssh-keygen -t rsa -C sfoolish@172.9.21.101
    mac : $ scp ~/.ssh/id_rsa.pub sfoolish@172.9.21.101:~/workspace
    mac : $ ssh sfoolish@172.9.21.101

    linux : $ cat ~/workspace/id_rsa.pub >> ~/.ssh/authorized_keys
#### REF
* [ssh免输入密码登录](http://www.colorfuldays.org/linux/ssh_login_without_password/)

### dtruss
It basically uses dtrace and lists process’ syscall details like strace does on Linux. 

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
if name contains a slash (/)  then man  interprets  it  as  a  file  specification,  so that you can do man ./foo.5 or even man /cd/foo/bar.1.gz.

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
    * Ctrl + p   同方向键Up，显示上一个命令
    * Ctrl + n   同方向键Down，显示下一条命令
    * Ctrl + b   同方向键Left
    * Ctrl + f   同方向键Right
    * Ctrl + z   将当前命令移至后台执行，fg可招回
    * Cmd  + K   清屏
    * Cmd  + t   新建标签
    * Cmd  + {}  x向左/向右切换标签
    * Tab        自动补全文件名或者目录名，按下两次会列出多个选项
    * !!         重复上一个命令符

## secure CRT 中文编码设置
options --> appearance --> character encoding --> (utf-8)

---
## readelf
readelf displays information about one or more ELF format object files.  The options control what particular information to display.
    
    ## 查看执行文件依赖的动态库
    readelf [-d|--dynamic] <elffile>
### REF
* man readelf

---
## windows linux 回车换行处理方式不同问题
脚本运行时，出现如下错误
    
    ```
        /bin/sh^M: bad interpreter 
    ```
原因是.sh脚本在 Windows 系统下用记事本文件编写的。不同系统的编码格式引起的。
### 解决方法1：通过vi编辑器：
    vi test.sh
    查看文件格式
    :set ff 或 :set fileformat
    修改文件格式
    :set ff=unix 或 :set fileformat=unix
    :wq
## 解决方法2：通unix2dos  / dos2unix命令
    $ dos2unix ./test.sh
## 解决方法3：tr 命令
    $ cat filename1 | tr -d "\r" > newfile 去掉^M生成一个新文件

---
## rpm 命令使用
### 命令选项说明 
    rpm   --rebuild   name.src.rpm   "install "
    rpm   -ivh   name.rpm   "install "
    rpm   -Uvh   name.rpm   "update "
    rpm   -e   name   "uninstall "
    rpm   -qpl   name.rpm   "列出包内的文件的安装路径，用于未安装的包 "
    rpm   -qpi   name.rpm   "列出包内的信息，用于未安装的包 "
### 实例演示
    [root@localhost rpm]# rpm -pql openssh-5.0p1-1.fc9.src.rpm
    ```
        warning: openssh-5.0p1-1.fc9.src.rpm: Header V3 DSA signature: NOKEY, key ID 4f2a6fd2
        openssh-3.8.1p1-krb5-config.patch
        openssh-3.8.1p1-skip-initial.patch
        openssh-3.9p1-askpass-keep-above.patch
        openssh-4.0p1-exit-deadlock.patch
        openssh-4.2p1-askpass-progress.patch
        openssh-4.3p1-fromto-remote.patch
        openssh-4.3p2-allow-ip-opts.patch
        openssh-4.3p2-askpass-grab-info.patch
        openssh-4.3p2-cve-2007-3102.patch
        openssh-4.3p2-gssapi-canohost.patch
        openssh-4.3p2-no-v6only.patch
        openssh-4.5p1-controlcleanup.patch
        openssh-4.7p1-audit.patch
        openssh-4.7p1-cloexec.patch
        openssh-4.7p1-gssapi-role.patch
        openssh-4.7p1-log-in-chroot.patch
        openssh-4.7p1-master-race.patch
        openssh-4.7p1-mls.patch
        openssh-4.7p1-nss-keys.patch
        openssh-4.7p1-redhat.patch
        openssh-4.7p1-selinux.patch
        openssh-4.7p1-vendor.patch
        openssh-5.0p1-noacss.tar.bz2
        openssh-nukeacss.sh
        openssh.spec
        sshd.init
        sshd.pam
    ```
    [root@localhost rpm]# rpm -ivh openssh-5.0p1-1.fc9.src.rpm
    ```
        warning: openssh-5.0p1-1.fc9.src.rpm: Header V3 DSA signature: NOKEY, key ID 4f2a6fd2
           1:openssh                warning: user mockbuild does not exist - using root
        ########################################### [100%]
        
        [root@localhost rpm]# ls /usr/src/redhat/SOURCES/ -l
        total 992
        -rw-r--r-- 1 root root    578 2004-09-09 05:47 openssh-3.8.1p1-krb5-config.patch
        -rw-r--r-- 1 root root   1183 2004-09-09 05:47 openssh-3.8.1p1-skip-initial.patch
        -rw-r--r-- 1 root root    413 2005-02-08 09:44 openssh-3.9p1-askpass-keep-above.patch
        -rw-r--r-- 1 root root    472 2005-07-27 07:42 openssh-4.0p1-exit-deadlock.patch
        -rw-r--r-- 1 root root   2470 2005-12-20 09:44 openssh-4.2p1-askpass-progress.patch
        -rw-r--r-- 1 root root    432 2006-04-14 04:26 openssh-4.3p1-fromto-remote.patch
        -rw-r--r-- 1 root root   1964 2006-08-23 17:06 openssh-4.3p2-allow-ip-opts.patch
        -rw-r--r-- 1 root root    947 2006-07-17 10:09 openssh-4.3p2-askpass-grab-info.patch
        -rw-r--r-- 1 root root   1636 2007-09-06 15:49 openssh-4.3p2-cve-2007-3102.patch
        -rw-r--r-- 1 root root   1126 2006-11-30 05:50 openssh-4.3p2-gssapi-canohost.patch
        -rw-r--r-- 1 root root    446 2006-08-08 07:58 openssh-4.3p2-no-v6only.patch
        -rw-r--r-- 1 root root    476 2008-04-07 16:14 openssh-4.5p1-controlcleanup.patch
        -rw-r--r-- 1 root root   5592 2007-09-06 15:49 openssh-4.7p1-audit.patch
        -rw-r--r-- 1 root root    734 2008-02-29 11:11 openssh-4.7p1-cloexec.patch
        -rw-r--r-- 1 root root    920 2008-01-03 12:45 openssh-4.7p1-gssapi-role.patch
        -rw-r--r-- 1 root root   1807 2007-09-06 15:49 openssh-4.7p1-log-in-chroot.patch
        -rw-r--r-- 1 root root   2529 2008-04-07 16:14 openssh-4.7p1-master-race.patch
        -rw-r--r-- 1 root root  12810 2008-04-07 16:14 openssh-4.7p1-mls.patch
        -rw-r--r-- 1 root root  38478 2007-11-20 09:53 openssh-4.7p1-nss-keys.patch
        -rw-r--r-- 1 root root   3784 2007-09-06 15:49 openssh-4.7p1-redhat.patch
        -rw-r--r-- 1 root root   8612 2007-09-06 15:49 openssh-4.7p1-selinux.patch
        -rw-r--r-- 1 root root   6345 2007-09-06 15:49 openssh-4.7p1-vendor.patch
        -rw-r--r-- 1 root root 843610 2008-04-07 15:52 openssh-5.0p1-noacss.tar.bz2
        -rwxr-xr-x 1 root root    540 2005-09-06 15:55 openssh-nukeacss.sh
        -rwxr-xr-x 1 root root   3407 2008-04-07 16:14 sshd.init
        -rw-r--r-- 1 root root    285 2008-04-07 16:14 sshd.pam
    ```

---
## svn 最近更新版本号获取命令
    svn info | grep 'Last Changed Rev' | awk '{print $4}'

---
## 杭州 DNS 服务器 IP 地址
202.101.172.35
202.101.172.47



---
## 文档的编写方法
### [编写《Redis 设计与实现》时用到的工具](http://www.huangz.me/en/latest/diary/2013/tools-for-writing-redisbook.html)
非常不错的文档编写经验终结，用到的工具有：Sphinx, git/github/bitbucke, Graphviz, ReadTheDocs 。
### [怎么样写出更好、也更简短的源码分析书](http://www.huangz.me/en/latest/diary/2013/how-to-write-a-better-and-shorter-code-analysis-book.html)
* 关注程序本身的抽象和设计，而不是源码细节；
* 分离书本和源码，让它们各司其职；
* 文章中应该避免出现大量代码，更不要大量粘贴源码；
* 不要假设读者的水平，不要写（太多）文字，举例子；
* 仔细分割章节，减低读者的负担，帮助他们保持自己的注意力；

---
## 文件编码转换
1. 在Vim中直接进行转换文件编码,比如将一个文件转换成utf-8格式
:set fileencoding=utf-8

2. enconv 转换文件编码，比如要将一个GBK编码的文件转换成UTF-8编码，操作如下
enconv -L zh_CN -x UTF-8 filename

3. iconv 转换，iconv的命令格式如下：
iconv -f encoding -t encoding inputfile
比如将一个UTF-8 编码的文件转换成GBK编码
iconv -f GBK -t UTF-8 file1 -o file2

---
## 中文字数统计

* vim打开，g ctrl-g

    Col 1 of 13; Line 1 of 2154; Word 1 of 2942; Char 1 of 47101; Byte 1 of 110151

* wc -m

    -m, --chars   print the character counts

## [Linux文件分割与合并：split & cat](http://www.truevue.org/linux/%E6%96%87%E4%BB%B6%E5%88%86%E5%89%B2%E4%B8%8E%E5%90%88%E5%B9%B6)
    
split

    split -l 300 large_file.txt new_file_prefix
    split -b 10m large_file.bin new_file_prefix

merge

    cat small_files* > large_file
