---

## git review steps

git clone https://gerrit.opnfv.org/gerrit/p/yardstick
cd yardstick/

git review -s

git checkout -b YARDSTICK-57
vim yardstick/cmd/cli.py

./run_tests.sh

git add yardstick/cmd/cli.py

git commit -s   # git commit -s --amend

git log -p

git log --name-only

git review

## git review dependency

git review -d $PARENT_CHANGE_NUMBER
git checkout -b $DEV_TOPIC_BRANCH

git commit -a
git review

## git patch 使用

* create patch

git diff --no-prefix > patchfile

* apply the patch:

patch -p0 < patchfile

http://tamsler.blogspot.com/2009/02/patching-with-git-diff.html

## 往 github 上传一个分支

    git checkout -b centos
    git commit -s
    git push origin centos

## 切到 github 上的一个分支

    git clone https://github.com/sfoolish/dtools.git dtools_test
    git checkout origin/centos

## Ref

* http://stackoverflow.com/questions/5082249/pushing-to-git-remote-branch

---
## github 生成 SSH 公钥
    ssh-keygen -t rsa -C sfoolish.liang@gmail.com
    添加SSH公钥到github
    内容在： ~/.ssh/id_rsa.pub

    ssh-keygen -t rsa -C "your_email@example.com"
    # start the ssh-agent in the background
    eval "$(ssh-agent -s)"
    # Agent pid 59566
    ssh-add ~/.ssh/id_rsa
    pbcopy < ~/.ssh/id_rsa.pub

* [Generating SSH keys](https://help.github.com/articles/generating-ssh-keys/)
* [github生成SSH公钥](http://blog.chinaunix.net/uid-26185912-id-3327885.html)
* [公钥认证管理](http://www.worldhello.net/gotgithub/03-project-hosting/030-repo-authz.html)
---

[Make git diff show UTF8 encoded characters properly](http://stackoverflow.com/questions/19435071/make-git-diff-show-utf8-encoded-characters-properly)

export LESSCHARSET=UTF-8

---
## XP Git Bash 简要使用步骤
### 远程代码更新：
    $ git pull
### 添加修改日志：
    $ git commit -a -m 'commit log'
### 撤销最后一次提交:
    $ git reset HEAD~1
### 上传到服务器：
    $ git push origin master

---
## ubuntu 下简要使用步骤
    $ git add -A
    $ git commit -a -m 'change log'
    $ git push origin master
    $ git git mv ECS_using_note.md ECS_using.md  # 文件重命名

---
## git 常用命令
### config:
开发人员需要为git仓库配置相关信息，这样在提交代码时，这些信息会自动
反映在git仓库的日志中。

    $ git config user.name "your name"
    $ git config user.email yourname@email_server
    $ git config core.editor vim
    $ git config core.paper "less -N"
    $ git config color.diff true
    $ git config alias.co checkout
    $ git config core.filemode false  # 不检查文件的读/写/执行权限
    $ git config -l                   # 查看当前树配置和全局配置
git config alias表示，可以用git co代表git checkout。git var -l可以查看
已经设置的配置。
### diff:
开发人员在本地进行开发后，可以使用git diff查看改动。
除了直接比较当前开发后的改动外，git diff还可以：

    $ git diff tag                    # 比较tag和HEAD之间的不同。
    $ git diff tag file               # 比较一个文件在两者之间的不同。
    $ git diff tag1..tag2             # 比较两个tag之间的不同。
    $ git diff SHA11..SHA12           # 比较两个提交之间的不同。
    $ git diff tag1 tag2 file or
    $ git diff tag1:file tag2:file    # 比较一个文件在两个tag之间的不同。
    $ git diff --stat                 # 用于生成统计信息。
    $ git diff --name-only            # 列出所有修改过的文件名
### log:
    $ git log file                    # 查看一个文件的改动。
    $ git log -p                      # 查看日志和改动。
    $ git log tag1..tag2              # 查看两个tag之间的日志。
    $ git log -p tag1..tag2 file      # 查看一个文件在两个tag之间的不同。
    $ git log tag..                   # 查看tag和HEAD之间的不同。
### commit:
    $ git commit -a -e                # 提交全部修改文件，并调用vim编辑提交日志。
    $ git reset HEAD^ or
    $ git reset HEAD~1                # 撤销最后一次提交。
    $ git reset --hard HEAD^          # 撤销最后一次提交并清除本地修改。
    $ git reset SHA1                  # 回到SHA1对应的提交状态。
### add/delete/ls:
    $ git add -a                      # 添加所有文件。除了.gitignore文件中的文件。
    $ git rm file                     # 从git仓库中删除文件。
    $ git commit                      # 添加或是删除后要提交。
    $ git ls-files -m                 # 显示修改过的文件。
    $ git ls-files                    # 显示所有仓库中的文件。
### patch:
    $ git format-patch -1             # 生成最后一个提交对应的patch文件。
    $ git am < patch                  # 把一个patch文件加入git仓库中。
    $ git am --resolved               # 如果有冲突，在解决冲突后执行。
    $ git am --skip                   # 放弃当前git am所引入的patch。
### branch:
    $ git branch -a                   # 查看所有分支。
    $ git branch new_branch           # 创建新的分支。
    $ git branch -d branch            # 删除分支。
    $ git checkout branch             # 切换当前分支。-f参数可以覆盖未提交内容。
### tag:
    $ git tag -l                      # 列出全部的 tag
    $ git checkout <tag_name>         # 切换到 <tag_name> 下。

---
## Git + 代理服务器
如果是 git clone http:// 或 git clone https:// 的话直接把代理服务器加到环境变量就可以了：

    $ export http_proxy="http://sfoolish:sfoolish@172.9.21.108:3128/"
    $ export https_proxy="http://sfoolish:sfoolish@172.9.21.108:3128/"

如果是 git clone git:// 的话麻烦一些（可能有的 git 源不提供 http/https 的方式），需要先安装 socat，然后创建一个叫做 gitproxy 的脚本并填上合适的服务器地址、端口号等，最后配置 git 使用 gitproxy 脚本：

    $ sudo apt-get install socat
    $ sudo vim /usr/bin/gitproxy
    $ cat /usr/bin/gitproxy
    ```
        #!/bin/bash

        PROXY=172.9.21.108
        PROXYPORT=3128
        PROXYAUTH=sfoolish:sfoolish
        exec socat STDIO PROXY:$PROXY:$1:$2,proxyport=$PROXYPORT,proxyauth=$PROXYAUTH
    ```
    $ sudo chmod +x /usr/bin/gitproxy
    $ git config --global core.gitproxy gitproxy
### REF
* [如何让 Git 使用 HTTP 代理服务器](http://www.vpsee.com/2011/07/how-to-use-git-through-a-http-proxy/)

---
## [Git显示漂亮日志的小技巧](http://coolshell.cn/articles/7755.html)
    $ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --"
    $ git config --global alias.lgp "log -p --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --"

---
## git daemon 的使用
通过 `git daemon` 可以实现本地的 git 代码仓库。一个比较不错的使用场景是 `origin master <--> local master <--> local dev` ，`origin master <--> local master` 保持最终版本的同步，`local master <--> local dev` 保留所有本地开发记录。

### local master config
    $ mkdir local_master && cd local_master/                       # base path /root/prj
    $ git clone https://github.com/sfoolish/000-1000-hours.git ./
    $ git config receive.denyCurrentBranch ignore
    $ git daemon --reuseaddr --export-all --verbose --enable=receive-pack
### local dev
    $ mkdir local_dev && cd local_dev/
    $ git clone git://localhost/root/prj/local_master ./           # 本地直接用 localhost
    ## $ git clone git://<IP_ADDR>/root/prj/local_master ./        # 跨主机则用 local master 的 IP 地址
    # local dev modify
    $ git commit -a -m 'log'
    $ git push origin master                                       # 向 local master 提交修改
### local master push
    $ git reset --hard
    $ git commit -a -m 'log'
    $ git push origin master                                       # 向 origin master 提交修改

### REF
* ['receive-pack': service not enabled for './.git'](http://stackoverflow.com/questions/792611/receive-pack-service-not-enabled-for-git)
* `git daemon --help`

---

## git config 异常

warning: gitreview.username has multiple values

Edit .gitconfig delete duplicate configs

vim ~/.gitconfig

---
#2012-06-26
ping 127.0.0.1:8080并不是ping你电脑的8080端口，而是当做域名处理，当然ping不同咯。。但是电信在他的DNS里搞了鬼，所有不能用的域名统统转到60.191.124.236，也就是在IE里面输入一些不能解析的域名时，也会转到那里去，几时经常看到的114页面，还有难看的广告
$ ping www.shadingnet.com
PING www.shadingnet.com (60.191.124.236): 56 data bytes
$ ping 127.0.0.1:8080
PING 127.0.0.1:8080 (60.191.124.236): 56 data bytes

$ dig @8.8.8.8 -t a sfoolish.github.com
$ dig @8.8.8.8 -t a shadingnet.com

$ dig @8.8.8.8 -t a blog.shadingnet.com

; <<>> DiG 9.6-ESV-R4-P3 <<>> @8.8.8.8 -t a blog.shadingnet.com
; (1 server found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 22226
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;blog.shadingnet.com.   IN  A

;; ANSWER SECTION:
blog.shadingnet.com.  3600  IN  CNAME sfoolish.github.com.
sfoolish.github.com.  43200 IN  A 204.232.175.78

;; Query time: 82 msec
;; SERVER: 8.8.8.8#53(8.8.8.8)
;; WHEN: Tue Jun 26 07:22:17 2012
;; MSG SIZE  rcvd: 83

# REF
[github page 使用专有域名](http://www.worldhello.net/gotgithub/03-project-hosting/050-homepage.html#dedicate-domain)
[使用github作为博客引擎](http://blog.leezhong.com/tech/2010/08/25/make-github-as-blog-engine.html)
