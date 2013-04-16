---
## 重新构建 Jekyll 环境
    $ curl -L get.rvm.io | bash -s stable
    $ source ~/.bashrc
    $ source ~/.bash_profile
    
    $ apt-get install ruby-rvm
    $ rvm package install openssl
    $ rvm install 1.9.2 --with-openssl-dir=/usr/share/ruby-rvm/usr
    
    $ rvm use 1.9.2
    $ rvm gemset create jekyll
    $ rvm use 1.9.2@jekyll
    $ gem install jekyll

    $ git clone https://github.com/sfoolish/sfoolish.github.com.git
    $ cd sfoolish.github.com/
    $ mkdir _site
    $ jekyll --server
jekyll 默认使用 4000 端口，上述操作在 ubuntu12.04_x64 上测试通过，部分命令可能需要 `sudo`。
### REF
* [查看 RVM 实用指南](http://ruby-china.org/wiki/rvm-guide)
* [Rubygems 镜像](http://ruby.taobao.org/)
* [Ruby on rails installation error – Halting the installation](http://vkarthickeyan.wordpress.com/2012/02/03/)

