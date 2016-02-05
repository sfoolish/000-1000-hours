---
## ubuntu 12.04 源修改
### sources.list 备份
	$ sudo mv /etc/apt/sources.list /etc/apt/sources.list_bkp
### sources.list 编辑
    $ sudo vim /etc/apt/sources.list
    $ cat /etc/apt/sources.list
    ```
        deb http://mirrors.163.com/ubuntu/ precise main restricted universe multiverse
        deb http://mirrors.163.com/ubuntu/ precise-security main restricted universe multiverse
        deb http://mirrors.163.com/ubuntu/ precise-updates main restricted universe multiverse
        deb http://mirrors.163.com/ubuntu/ precise-proposed main restricted universe multiverse
        deb http://mirrors.163.com/ubuntu/ precise-backports main restricted universe multiverse
        deb-src http://mirrors.163.com/ubuntu/ precise main restricted universe multiverse
        deb-src http://mirrors.163.com/ubuntu/ precise-security main restricted universe multiverse
        deb-src http://mirrors.163.com/ubuntu/ precise-updates main restricted universe multiverse
        deb-src http://mirrors.163.com/ubuntu/ precise-proposed main restricted universe multiverse
        deb-src http://mirrors.163.com/ubuntu/ precise-backports main restricted universe multiverse
        deb http://extras.ubuntu.com/ubuntu precise main
        deb-src http://extras.ubuntu.com/ubuntu precise main
    ```
### sources.list 更新
    $ sudo apt-get update
### sources.list FAQ
#### 如何通过代理更新
    $ sudo vim /etc/apt/apt.conf
    $ cat /etc/apt/apt.conf
    ```
        Acquire::http::proxy "http://172.9.21.108:8080/";
        Acquire::ftp::proxy "http://172.9.21.108:8080";
        Acquire::https::proxy "https://172.9.21.108:8080/";
    ```
#### 源更新失败
    $ sudo apt-get update
    ```
        ... ...
        Ign http://extras.ubuntu.com precise/main Translation-en
        Fetched 1 B in 19s (0 B/s)
        W: Failed to fetch gzip:/var/lib/apt/lists/partial/mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages  Hash Sum mismatch
        
        E: Some index files failed to download. They have been ignored, or old ones used instead.
    ```
    $ ls /var/lib/apt/lists/partial/
    ```
        cn.archive.ubuntu.com_ubuntu_dists_precise_universe_binary-i386_Packages
        mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages
        mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages.decomp.FAILED
    ```
    $ sudo rm /var/lib/apt/lists/partial/*
    $ sudo apt-get update
#### public key is not available
    $ sudo apt-get update
    ```
        W: GPG error: http://extras.ubuntu.com precise Release: The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 16126D3A3E5C1192
    ```
    $ sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 437D05B5 3E5C1192
### REF
[163 Ubuntu镜像使用帮助](http://mirrors.163.com/.help/ubuntu.html)

## apt-get error
E: Encountered a section with no Package: header
E: Problem with MergeList /var/lib/apt/lists/archive.ubuntu.com_ubuntu_dists_natty_main_binary-i386_Packages
E: The package lists or status file could not be parsed or opened.

sudo rm /var/lib/apt/lists/* -vf
sudo apt-get update

---
## ubuntu 12.04创建本地源
* [ubuntu 12.04创建本地源](http://hi.baidu.com/chenshake/item/8bf5c4d599d6b82839f6f7fe)
* [Ubuntu10.04制作官方源镜像以及搭建本地源](http://www.cnblogs.com/linucos/archive/2012/03/31/2426662.html)

试了一下只下载32位的就需要53G，太耗空间就没做下去。

---
## nfs 服务器安装
### 安装
    $ sudo apt-get install nfs-kernel-server
    $ sudo apt-get install portmap nfs-common
### 配置
    $ sudo vim /etc/exports
    $ sudo cat /etc/exports
    ```
        /home/sfoolish/share 172.9.21.108(rw,sync,all_squash,root_squash,no_subtree_check,anonuid=1000,anongid=1000)
        /tftpboot *(rw,nohide,insecure,no_subtree_check,async,no_root_squash)
    ```
### 重启
    $ sudo service nfs-kernel-server restart
    $ sudo /etc/init.d/portmap restart
### 参数说明
* all_squash              共享文件的UID和GID映射匿名用户anonymous，适合公用目录。
* no_all_squash           保留共享文件的UID和GID（默认）
* root_squash             root用户的所有请求映射成如anonymous用户一样的权限（默认）
* no_root_squas           root用户具有根目录的完全管理访问权限 
* anonuid=xxx             指定NFS服务器/etc/passwd文件中匿名用户的UID
* anongid=xxx             指定NFS服务器/etc/passwd文件中匿名用户的GID

---
## telnetd 服务安装
    ## 安装相应的软件
    $ sudo apt-get install xinetd
    $ sudo apt-get install telnetd

    ## 对该服务进行简单的配置
    $ sudo vim /etc/xinet.d/telnet
    $ sudo cat /etc/xinet.d/telnet
    ```
        service telnet
        {
            flags = REUSE
            socket_type = stream
            wait = no
            user = root
            server = /usr/sbin/in.telnetd
            log_on_failure += USERID
            disable = no
        }
    ```

    ## 对服务进行重启
    $ sudo /etc/init.d/xinetd restart
    
    ## 本地测试
    $ telnet localhost 
    ```
        Trying 127.0.0.1...
        Connected to localhost.
        Escape character is '^]'.
        Ubuntu 12.04.1 LTS
        sfoolish login: 
    ```
### REF
* [ubuntu下简单体验telnet服务器](http://blog.chinaunix.net/uid-27033491-id-3381919.html)

### FAQ
#### MAC OS 下 nfs 挂载 
    $ sudo mount_nfs -P 172.9.21.102:/home/sfoolish/share tmp  # "-P" to force the use of a reserved port number
#### gid / uid 数值获取
    $ grep `id -un` /etc/passwd
    ```
        sfoolish:x:1000:1000:sfoolish,,,:/home/sfoolish:/bin/bash
    ```
---
## Ubuntu samba配置
    $ sudo apt-get install samba
    $ sudo apt-get install smbfs
    $ sudo apt-get install smbclient
    $ sudo smbpasswd -a sfoolish
    
    $ sudo vim /etc/samba/smb.conf
    $ sudo cat /etc/samba/smb.conf
    ```
        #########################################
        ##sfoolish share
        #   security = share
        #[My_PRJ]
        #   comment = share my prj
        #   path = /home/sfoolish/Desktop/My_Prj
        #   read only = no
        #   guest ok = yes
        ############################################
           security = user
        [My_Prj]
           comment = share my project
           path = /home/sfoolish/Desktop/My_Prj
           read only = no
           valid users = sfoolish
        ############################################
    ```
    $ sudo service smbd restart
    $ sudo service nmbd restart
### REF
[Ubuntu的samba设置](http://wenku.baidu.com/view/2dc8b03a376baf1ffc4fad02.htm)

---
## tftp server 安装
    $ sudo apt-get install tftpd tftp xinetd
    $ sudo vim /etc/xinetd.d/tftp
    $ cat /etc/xinetd.d/tftp
    ```
        service tftp
        {
            protocol = udp
            port = 69
            socket_type = dgram
            wait = yes
            user = nobody
            server = /usr/sbin/in.tftpd
            server_args = /tftpboot
            disable = no
        }
    ```
    $ sudo /etc/init.d/xinetd restart

---
## samba 服务器安装
    $ sudo apt-get install samba smbfs system-config-samba samba-common
## 图形界面配置
    $ sudo system-config-samba
### 手动修改配置
    $ sudo cd /etc/samba
    $ sudo cp smb.conf smb.conf_bkp
    $ sudo vim /etc/samba/smb.conf
    $ diff smb.conf smb.conf_bkp 
    ```
        102c102
        <    security = user
        ---
        > #   security = user
        337,347d336
        < 
        < [share]
        <         path = /home/sfoolish/workspace
        <         writeable = yes 
        <         browseable = no
        <         valid users = sfoolish
        < [project]
        <         path = /home/sfoolish/prj
        <         writeable = yes 
        <         browseable = no
        <         valid users = sfoolish
    ```
### 添加用户
    $ sudo smbpasswd sfoolish
### 重启 samba 服务
    $ sudo service smbd restart
    $ sudo service smbd restart

---
## 常用工具安装
    $ sudo apt-get install minicom
    $ sudo apt-get install vim
    $ sudo apt-get install git git-core
    $ sudo apt-get install openssh-server openssh-client
    $ sudo apt-get install build-essential kernel-package libncurses5-dev
    $ sudo apt-get install subversion
    $ sudo apt-get install autoconf
    $ sudo apt-get install sysstat
    $ sudo apt-get install apache2-utils
    $ sudo apt-get install curl
    $ sudo apt-get install gdb fakeroot wget bzip2 
    $ sudo apt-get install libelf-dev binutils-dev kernel-wedge makedumpfile kexec-tools crash

## ubuntu 12.04 perf 工具安装
    $ sudo apt-get install linux-base linux-tools-common linux-tools
---
## ubuntu 桌面系统关机，重启，挂起，休眠命令
### 关机命令
    $ sudo dbus-send --system --print-reply  --dest=org.freedesktop.ConsoleKit /org/freedesktop/ConsoleKit/Manager org.freedesktop.ConsoleKit.Manager.Stop
### 重启命令:
    $ sudo dbus-send --system --print-reply  --dest=org.freedesktop.ConsoleKit /org/freedesktop/ConsoleKit/Manager  org.freedesktop.ConsoleKit.Manager.Restart
### 挂起命令:
    $ sudo dbus-send --system --print-reply  --dest=org.freedesktop.UPower /org/freedesktop/UPower org.freedesktop.UPower.Suspend
### 休眠命令:
    $ sudo dbus-send --system --print-reply  --dest=org.freedesktop.UPower /org/freedesktop/UPower  org.freedesktop.UPower.Hibernate

---
## ubuntu root用户
首先设置root密码，利用现有管理员帐户登陆Ubuntu，在终端执行命令：`sudo passwd root`，接着输入密码和root密码，重复密码。这样就有了可用的root用户。当然不建议切换到 root 下直接运行命令。
## 系统网络校时
    $ sudo ntpdate clock.stdtime.gov.tw
    $ sudo hwclock -w

---
## dns 服务器地址添加
    $ sudo vim /etc/resolvconf/resolv.conf.d/tail
    $ sudo cat /etc/resolvconf/resolv.conf.d/tail
    ```
        nameserver 192.168.1.1
    ```
    $ sudo /etc/init.d/resolvconf restart
通过局域网代理上网，可以不用设置 dns 。
### 浙江省杭州市（中国电信）DNS
* 首选DNS：202.101.172.35
* 备份DNS：202.101.172.47

---
## 开机默认不启动图形用户界面
    $ sudo vim /etc/init/rc-sysinit.conf # 在第14行附近：确认`env DEFAULT_RUNLEVEL=2`
    $ sudo vim /etc/init/lightdm.conf    # 在第12行附近，原句` and runlevel [!06]` 改为` and runlevel [!026]`
    $ sudo reboot

    $ sudo /etc/init.d/gdm stop          # 能将所有图形界面相关的进程都关闭
系统起来后，如果需要启动桌面则运行：

    $ startx
startx 后，注销系统就重新进入控制台模式。

在 /etc/init/*.conf 下有很多配置文件，用于设置在特定运行级别下，是否开启相应功能。
如将/etc/init/nova-api.conf 中的 `stop on runlevel [016]` 修改为 `stop on runlevel [0126]`，则在 runlevel 为 2 时，nova-api 将不启动。
### REF
[ubuntu设置开机启动图形应用程序，替换默认图形桌面](http://blog.csdn.net/liebergott/article/details/7793408)

---
## ubuntu 内核源码下载上传 github
### 源码下载
    $ sudo apt-get install dpkg-dev
    $ sudo apt-get source linux-image-$(uname -r)
上述命令会下载 linux_3.2.0-39.62.diff.gz, linux_3.2.0-39.62.dsc, linux_3.2.0.orig.tar.gz 三个文件，并将源码解压，打好补丁，生成到 linux-3.2.0 。

内核 dsc, diff.gz, orig.tar.gz 文件，可以通过下面命令展开：

    $ dpkg-source -x linux_3.2.0-39.62.dsc
### 源码上传
先在 github 创建空的 repo linux_3.2.0-39.62_ubuntu12.04 ，然后执行下面命令将代码上传。由于文件比较多，整个过程相当耗时间。

    $ cd linux-3.2.0/
    $ git init
    $ git add -A
    $ git commit -m "commit ubuntu12.04 linux_3.2.0-39.62 kernel"
    $ git remote add origin git@github.com:sfoolish/linux_3.2.0-39.62_ubuntu12.04.git
    $ git push -u origin master
### REF
* [ubuntu 编译源码包 dsc diff.gz orig.tar.gz](http://hi.baidu.com/avr_tutorial/item/624a6899b404da81591461da)
* [自己编译Ubuntu内核](http://it.tomcat-lily.com/index.php/2011/01/%E8%87%AA%E5%B7%B1%E7%BC%96%E8%AF%91ubuntu%E5%86%85%E6%A0%B8/)

---
## Ubuntu 关闭防火墙命令
    $ sudo ufw disable
## Ubuntu 64 支持 32 bit 程序
    $ sudo apt-get install ia32-libs
## 系统启动时自动挂载硬盘配置
假设硬盘接的为 /dev/sda3 要挂载的路径为 /mnt 文件系统类型为 ext4 ，则在 /etc/fstab 文件最后增加一行：
    
    /dev/sda3 /mnt ext4 defaults, 0 1     
## [ubuntu 12.04 内核 git 地址](git://kernel.ubuntu.com/apw/ubuntu-precise.git)

---
## 软件彻底卸载
    $ sudo apt-get --pruge remove <name>

### 添加 swap 分区，解决内核编译过程中内核不足问题
    # dd if=/dev/zero of=/mnt/512Mb.swap bs=1M count=512
    # mkswap /mnt/512Mb.swap
    # swapon /mnt/512Mb.swap

    # swapoff /mnt/512Mb.swap
    # rm /mnt/512Mb.swap
ref: [如何设置Ubuntu的swap区](http://blog.csdn.net/chenyongxinglove/article/details/5883315)

### ssh 设置发送心跳参数

    # ssh -o ServerAliveInterval=60 root@42.x.x.x

---

## permission denied for root@localhost for ssh connection

Edit /etc/ssh/sshd_config

Change

PermitRootLogin without-password

to

PermitRootLogin yes

or

sed -i -e '/^PermitRootLogin/s/without-password/yes/' /etc/ssh/sshd_config
service ssh restart

REF: http://askubuntu.com/questions/497895/permission-denied-for-rootlocalhost-for-ssh-connection
