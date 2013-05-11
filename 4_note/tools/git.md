---
## github 生成 SSH 公钥
    ssh-keygen -t rsa -C sfoolish.liang@gmail.com
    添加SSH公钥到github
    内容在： ~/.ssh/id_rsa.pub
[github生成SSH公钥](http://blog.chinaunix.net/uid-26185912-id-3327885.html)
[公钥认证管理](http://www.worldhello.net/gotgithub/03-project-hosting/030-repo-authz.html)

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
