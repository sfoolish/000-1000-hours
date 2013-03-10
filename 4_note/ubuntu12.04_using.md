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
## ubuntu 12.04创建本地源
* [ubuntu 12.04创建本地源](http://hi.baidu.com/chenshake/item/8bf5c4d599d6b82839f6f7fe)
* [Ubuntu10.04制作官方源镜像以及搭建本地源](http://www.cnblogs.com/linucos/archive/2012/03/31/2426662.html)

试了一下只下载32位的就需要53G，太耗空间就没做下去。

---
## nfs 服务器安装
### 安装
    $ sudo apt-get install nfs-kernel-server
### 配置
    $ sudo vim /etc/exports
    $ sudo cat /etc/exports
    ```
        /home/sfoolish/share 172.9.21.108(rw,sync,all_squash,root_squash,no_subtree_check,anonuid=1000,anongid=1000)
    ```
### 重启
    $ sudo service nfs-kernel-server restart
### 参数说明
* all_squash              共享文件的UID和GID映射匿名用户anonymous，适合公用目录。
* no_all_squash           保留共享文件的UID和GID（默认）
* root_squash             root用户的所有请求映射成如anonymous用户一样的权限（默认）
* no_root_squas           root用户具有根目录的完全管理访问权限 
* anonuid=xxx             指定NFS服务器/etc/passwd文件中匿名用户的UID
* anongid=xxx             指定NFS服务器/etc/passwd文件中匿名用户的GID

### FAQ
#### MAC OS 下 nfs 挂载 
    $ sudo mount_nfs -P 172.9.21.102:/home/sfoolish/share tmp  # "-P" to force the use of a reserved port number
#### gid / uid 数值获取
    $ grep `id -un` /etc/passwd
    ```
        sfoolish:x:1000:1000:sfoolish,,,:/home/sfoolish:/bin/bash
    ```

---
## 常用工具安装
    $ sudo apt-get install minicom
    $ sudo apt-get install vim
    $ sudo apt-get install git git-core
    $ sudo apt-get install openssh-server openssh-client
    $ sudo apt-get install samba smbfs system-config-samba samba-common
    $ sudo apt-get install build-essential kernel-package libncurses5-dev
## dns 服务器地址添加
    $ sudo vim /etc/resolvconf/resolv.conf.d/tail
    $ sudo cat /etc/resolvconf/resolv.conf.d/tail
    ```
        nameserver 192.168.1.1
    ```
    $ sudo /etc/init.d/resolvconf restart
通过局域网代理上网可以不用设置 dns 。
### 浙江省杭州市（中国电信）DNS
* 首选DNS：202.101.172.35
* 备份DNS：202.101.172.47

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