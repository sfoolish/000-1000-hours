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