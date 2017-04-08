## Ubuntu Xenial 镜像源配置

### sources.list 备份

```bash
sudo cp /etc/apt/sources.list /etc/apt/sources.list_bkp
```

### sources.list 编辑

```bash
cat << "EOF" > /etc/apt/sources.list_bkp
deb http://mirrors.163.com/ubuntu/ xenial main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ xenial-security main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ xenial-updates main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ xenial-proposed main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ xenial-backports main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ xenial main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ xenial-security main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ xenial-updates main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ xenial-proposed main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ xenial-backports main restricted universe multiverse
EOF
```

or

```console
root@v1288-8:~# docker run -it ubuntu:xenial bash
root@edece84e2722:/# cat /etc/apt/sources.list | egrep -v "^#.*|^$"
deb http://archive.ubuntu.com/ubuntu/ xenial main restricted
deb-src http://archive.ubuntu.com/ubuntu/ xenial main restricted
deb http://archive.ubuntu.com/ubuntu/ xenial-updates main restricted
deb-src http://archive.ubuntu.com/ubuntu/ xenial-updates main restricted
deb http://archive.ubuntu.com/ubuntu/ xenial universe
deb-src http://archive.ubuntu.com/ubuntu/ xenial universe
deb http://archive.ubuntu.com/ubuntu/ xenial-updates universe
deb-src http://archive.ubuntu.com/ubuntu/ xenial-updates universe
deb http://archive.ubuntu.com/ubuntu/ xenial-security main restricted
deb-src http://archive.ubuntu.com/ubuntu/ xenial-security main restricted
deb http://archive.ubuntu.com/ubuntu/ xenial-security universe
deb-src http://archive.ubuntu.com/ubuntu/ xenial-security universe
root@edece84e2722:/# sed -i -e "s|archive.ubuntu.com|mirrors.163.com|g" /etc/apt/sources.list
```

### sources.list 更新

```bash
sudo apt-get update
```

### /etc/apt/apt.conf 配置

- 配置通过代理下包

```bash
cat << "EOF" > /etc/apt/apt.conf
Acquire::http::proxy "http://172.9.21.108:8080/";
Acquire::ftp::proxy "http://172.9.21.108:8080";
Acquire::https::proxy "https://172.9.21.108:8080/";
EOF
```

如果 proxy 需要用户名密码则需要将上述 proxy url 改成： "http://username:password@domain:port/"

**注意** 用名、密码中包含的特殊字符需要用 ascii 码值进行转译，e.g.(passw@rd 要改写成 passw%40rd)
快速查询 ascii 码值

```bash
apt-get install -y ascii
ascii
```

- 其他常用配置

```console
APT::Get::Assume-Yes "true";
APT::Get::force-yes "true";
```

### REF

* [163 Ubuntu镜像使用帮助](http://mirrors.163.com/.help/ubuntu.html)

### 源使用 FAQ

#### 源更新失败

- 错误现象

```cosole
$ sudo apt-get update
    ... ...
    Ign http://extras.ubuntu.com precise/main Translation-en
    Fetched 1 B in 19s (0 B/s)
    W: Failed to fetch gzip:/var/lib/apt/lists/partial/mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages  Hash Sum mismatch
    
    E: Some index files failed to download. They have been ignored, or old ones used instead.

$ ls /var/lib/apt/lists/partial/
    cn.archive.ubuntu.com_ubuntu_dists_precise_universe_binary-i386_Packages
    mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages
    mirrors.163.com_ubuntu_dists_precise_universe_binary-amd64_Packages.decomp.FAILED
```

- 修复方式

```bash
sudo rm /var/lib/apt/lists/partial/*
sudo apt-get update
```

- 错误现象

```console
E: Encountered a section with no Package: header
E: Problem with MergeList /var/lib/apt/lists/archive.ubuntu.com_ubuntu_dists_natty_main_binary-i386_Packages
E: The package lists or status file could not be parsed or opened.
```

- 修复方式

```bash
sudo rm /var/lib/apt/lists/* -vf
sudo apt-get update
```

## ubuntu 12.04 创建本地源

* [ubuntu 12.04创建本地源](http://hi.baidu.com/chenshake/item/8bf5c4d599d6b82839f6f7fe)
* [Ubuntu10.04制作官方源镜像以及搭建本地源](http://www.cnblogs.com/linucos/archive/2012/03/31/2426662.html)
