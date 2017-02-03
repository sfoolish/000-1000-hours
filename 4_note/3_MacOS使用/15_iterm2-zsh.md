## iterm2 + zsh + oh-my-zsh

http://www.iterm2.com/
http://yijiebuyi.com/blog/e310fc437f32006eb6aa42cad1783587.html
http://linglong117.blog.163.com/blog/static/27714547201241111838971/
https://segmentfault.com/a/1190000002658335
http://www.cnblogs.com/bamanzi/p/zsh-simple-guide.html
http://www.yangzhiping.com/tech/iterm2.html
http://pengjunjie.com/articles/mac-soft-iterm2/
https://skyline75489.github.io/post/2014-7-10_iterm-usage.html

http://zsh.sourceforge.net/
https://github.com/robbyrussell/oh-my-zsh
https://github.com/sjl/oh-my-zsh

sudo apt-get update
sudo apt-get install -y zsh git wget curl
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

ZSH_THEME="gallois"
plugins=(git sublime)

[Zsh not hitting ~/.profile](http://superuser.com/questions/187639/zsh-not-hitting-profile)
Zsh runs ~/.zprofile, not ~/.profile, when it is invoked as a login shell.

export PATH=$PATH:/usr/local/go/bin/
export PS1="%n:%~$ "
export LANG=en_US.UTF-8

## iTerm2 clolor schemes

* https://github.com/mbadolato/iTerm2-Color-Schemes.git
