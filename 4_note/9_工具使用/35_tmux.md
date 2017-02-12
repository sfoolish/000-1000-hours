# tmux

创建名字为 sf-centos-k8s 的 session

`tmux new -s sf-centos-k8s`

列出tmux的session

`tmux ls`

恢复指定session

`tmux att -d -t 0`
`tmux att -d -t sf-centos-k8s`

概念：

* session	会话:一个服务器可以包含多个会话
* window	窗口:一个会话可以包含多个窗口
* pane	面板:一个窗口可以包含多个面板[强悍的分屏]


Ctrl+b前提下才可以使用的命令

```console
?	列出所有快捷键；按q返回
d	脱离当前会话,可暂时返回Shell界面，输入tmux attach能够重新进入之前会话
D	选择要脱离的会话；在同时开启了多个会话时使用

“	将当前面板上下分屏
%	将当前面板左右分屏
x	关闭当前分屏
n/p   window 间切换

PgUp 输出上翻页
PgDn 输出下翻页
[    然后就可以用鼠标翻看历史记录

1. Ctrl+a  按 [ 进入 tmux屏幕拷贝模式
2. 然后按空格键开始复制
3. 使用类似vim的上下左右键方式进行选中
4. 按enter退出复制模式
5. Ctrl＋a  按 ］ 进行粘贴
```

## tmux.conf

```bash

cat << "EOF" > ~/.tmux.conf
# key bindings for horizontal and vertical panes
unbind %
bind \ split-window -h # horizontal
bind | split-window -h # horizontal
unbind '"'
bind - split-window -v # vertical

bind K confirm-before -p "kill-window #W? (y/n)" kill-window
bind '"' choose-window

set -g history-limit 1000000                # scrollback buffer n lines
setw -g mode-keys vi                        # use vi mode
bind h select-pane -L
bind j select-pane -D
bind k select-pane -U
bind l select-pane -R

setw -g utf8 on
EOF

```

## REF

* http://kumu-linux.github.io/blog/2013/08/06/tmux/
* http://www.opstool.com/article/253
* http://www.tuicool.com/articles/fqIZZn
