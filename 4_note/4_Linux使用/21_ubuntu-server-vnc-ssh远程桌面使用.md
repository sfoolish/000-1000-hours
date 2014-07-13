## Ubuntu server vnc ssh 远程桌面使用

VNC 可以对数据进行压缩，使得传输的数据量比直接用 SSH 加密的小，但是 SSH 可以保护VNC的安全，而这需要使用 SSH 的端口转发功能。
对于我现在遇到的问题不是处于安全性，主要是因为 aws 虚拟机没有公网 ip 但可以通过 ssh 登入。

### Ubuntu server 端配置

安装 vnc server：

    $ sudo apt-get install vnc4server

配置 vnc server：

    $ vncserver ; 第一次启动会提示输入密码
    $ vim ~/.vnc/xstartup
    ```
        #x-window-manager &
        gnome-session &
    ```
    $ vncserver -kill :1
    $ vncserver :1

安装 ubuntu 桌面：

    $ sudo apt-get install x-window-system-core
    $ sudo apt-get install gdm 
    $ sudo apt-get install ubuntu-desktop

重启 vncserver：

    $ vncserver -kill :1
    $ vncserver :1

[可选] 编辑 /etc/rc.local 在文件最后一行加入：

    su root -c '/usr/bin/vncserver -name my-vnc-server -depth 16 -geometry 1280x800 :1'即可实现开机自启动

### 建立 ssh 隧道

    $ ssh -o ServerAliveInterval=60 -i ~/.ssh/sf-mac.pem -L 5901:localhost:5901 ubuntu@ec2-54-255-145-110.ap-southeast-1.compute.amazonaws.com

参数说明：

- `-o ServerAliveInterval=60`： 为了维持跟 ssh server 之间的心跳；
- `-i ~/.ssh/sf-mac.pem`： 通过 ssh key 的形式登入 ssh server，当然也可以通过用户名密码的形式登入；
- `-L 5901:localhost:5901 ubuntu@ec2-54-255-145-110.ap-southeast-1.compute.amazonaws.com`： 隧道参数配置的一般格式为 -L 本地端口：本地地址：远程端口 远程地址。

### vncviewer 登入 vncserver

1. 下载 [Download VNC® Viewer](http://www.realvnc.com/download/get/1543/)；
2. 打开 VNC Viewer，VNC Server 输入：`localhost:1`，这里 1 对应的实际端口号就是 5901 ；
3. 其他选项默认，按照向导链接 vnc server 。

### REF

* [ubuntu安装vncserver实现图形化访问](http://help.aliyun.com/view/13435406.html)
* [SSH+VNC实现安全的Linux远程桌面管理](http://www.enet.com.cn/article/2013/0819/A20130819303837.shtml)
* [远程桌面设置:利用putty进行vnc + ssh tunneling](http://www.51cto.com/art/200512/13911.htm)
* [使用ssh和vncserver远程登录](http://fightfxj.blog.163.com/blog/static/67683924201088320897/)
