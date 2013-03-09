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
