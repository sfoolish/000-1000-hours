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
    * cmd + shift + b                   显示书签栏
    * cmd + d                           保存书签
    * ctl + shift + g (change colors)   背景色设置
    * cmd + shift + f                   全屏显示
    * cmd + alt + i                     开发者工具
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

---
## readelf
readelf displays information about one or more ELF format object files.  The options control what particular information to display.
    
    ## 查看执行文件依赖的动态库
    readelf [-d|--dynamic] <elffile>
### REF
* man readelf

---
## shell 功能命令
### 代码行数查看
    $ find ./ -name "*.c"  | xargs wc -l | sort -n

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
## sed 命令使用
    $ sed -e '/regexp/d' /path/to/my/test/file | more
    $ sed -n -e '/regexp/p' /path/to/my/test/file | more
    $ sed -n -e '/BEGIN/,/END/p' /my/test/file | more
### 常用正则表达式
    /./         将与包含至少一个字符的任何行匹配
    /../        将与包含至少两个字符的任何行匹配
    /^#/        将与以 '#' 开始的任何行匹配
    /^$/        将与所有空行匹配
    /}^/        将与以 '}'（无空格）结束的任何行匹配
    /} *^/      将与以 '}' 后面跟有 零或多个空格结束的任何行匹配
    /[abc]/     将与包含小写 'a'、'b' 或 'c' 的任何行匹配
    /^[abc]/    将与以 'a'、'b' 或 'c' 开始的任何行匹配 