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
    $ jekyll --server --auto       # 本地测试，可边修改边看效果
jekyll 默认使用 4000 端口，上述操作在 ubuntu12.04_x64 上测试通过，部分命令可能需要 `sudo`。

## mac os 10.6 下 Jekyll 环境的使用

    $ rvm use 1.9.2@rails31
    $ jekyll --server --auto

### REF
* [查看 RVM 实用指南](http://ruby-china.org/wiki/rvm-guide)
* [Rubygems 镜像](http://ruby.taobao.org/)
* [Ruby on rails installation error – Halting the installation](http://vkarthickeyan.wordpress.com/2012/02/03/)
* [mytharcher.github blog](mytharcher.github.com)
* [allthelucky.github blog](allthelucky.github.com)

---
### rdiscount 安装
rdiscount 最新版本 rdiscount-2.0.7.2，在 ubuntu12.04 x64 下会安装失败。64 位系统指针大小为 8 字节，int 大小为 4 字节，‘conftest_const’ 数组大小为负数编译出错。通过安装较老的版本解决这个问题。
    
    $ gem install rdiscount
    ```
        Building native extensions.  This could take a while...
        ERROR:  Error installing rdiscount:
                ERROR: Failed to build gem native extension.
        
                /usr/share/ruby-rvm/rubies/ruby-1.9.2-p180/bin/ruby extconf.rb
        checking for random()... yes
        checking for srandom()... yes
        checking for rand()... yes
        checking for srand()... yes
        checking size of unsigned long... long
        checking size of unsigned int... int
        no int with size 4
        *** extconf.rb failed ***
        Could not create Makefile due to some reason, probably lack of
        necessary libraries and/or headers.  Check the mkmf.log file for more
        details.  You may need configuration options.
        
        Provided configuration options:
                --with-opt-dir
                --without-opt-dir
                --with-opt-include
                --without-opt-include=${opt-dir}/include
                --with-opt-lib
                --without-opt-lib=${opt-dir}/lib
                --with-make-prog
                --without-make-prog
                --srcdir=.
                --curdir
                --ruby=/usr/share/ruby-rvm/rubies/ruby-1.9.2-p180/bin/ruby
                --with-rdiscount-dir
                --without-rdiscount-dir
                --with-rdiscount-include
                --without-rdiscount-include=${rdiscount-dir}/include
                --with-rdiscount-lib
                --without-rdiscount-lib=${rdiscount-dir}/lib
    ```
    $ vim /<path>/mkmf.log
    ```
        68 conftest.c:7:5: error: size of array ‘conftest_const’ is negative
        69 checked program was:
        70 /* begin */
        71 1: #include "ruby.h"
        72 2:
        73 3: typedef unsigned long rbcv_typedef_;
        74 4: static rbcv_typedef_ *rbcv_ptr_;
        75 5:
        76 6: /*top*/
        77 7: int conftest_const[(sizeof((*rbcv_ptr_)) == sizeof(int)) ? 1 : -1];
        78 /* end */
    ```

    $ gem install rdiscount -v 1.6.8
### REF
* [Installation Issues with ruby and gem rdiscount windows 8 64bit](http://stackoverflow.com/questions/15283059/installation-issues-with-ruby-and-gem-rdiscount-windows-8-64bit)

---
# cloud foundry
## ubuntu 10.04 install sequence
    sudo apt-get install ruby-full rubygems
    sudo gem install rubygems-update
    
    gem sources --remove http://rubygems.org/
    gem sources -a http://ruby.taobao.org/
    gem sources -l
    gem install vmc

    sfoolish@sfoolish-desktop:~$ vmc target api.cloudfoundry.com
    Successfully targeted to [http://api.cloudfoundry.com]
    sfoolish@sfoolish-desktop:~$ vmc login
    Attempting login to [http://api.cloudfoundry.com]
    Password: ********
    Successfully logged into [http://api.cloudfoundry.com]
    sfoolish@sfoolish-desktop:~$ vmc passwd
    Changing password for 'sfoolish.liang@gmail.com'
    New Password: ********
    Verify Password: ********
    Successfully changed password

---
## 第一段 ruby 功能代码
记录以下自己的第一段 ruby 功能代码，简单的日志文件搜索打印。(2012-09-18)

    #!/usr/bin/env ruby

    file = File.open("Serial-COM1_07-19.log", "r")
    while str = file.gets
        print str if str.match("1117: Babble condition on musb")
        #print str if str.match("mice    mouse0")
        print str if str.match("mice")
    end

---
## [Ruby社区应该去Rails化了](http://robbinfan.com/blog/40/ruby-off-rails)
### 移动时代，Web服务将取代Web网站
随着最近几年智能手机的迅速普及，如今来自智能手机和移动设备的总体Web访问和服务请求量已经超过了传统的PC，这意味着Web时代主流的Browser/Server的架构重新回到了Mobile Client/Server的架构。在B/S架构下，在服务器端生成完整的HTML页面，我们需要开发一个完整的Website；但在移动时代，服务器端的功能大大简化了，退化成了Web API调用接口提供者，而复杂的界面构造、交互和运算都是在移动客户端完成的。

Web服务器端并发常见的三种应用场景：

    Website：传统Web网站
    Web Service：Web服务端提供API调用接口
    real-time：Web实时推送

Rails适合开发Website，但不太适合Web Service，而移动时代的发展趋势就是：未来服务器端会更多的使用Web Service而不是Website，这也意味着Rails将越来越不适合时代的发展

---
## ruby
[安装 Ruby, Rails 运行环境](http://ruby-china.org/wiki/install_ruby_guide)
### install rvm
$ curl -L get.rvm.io | bash -s stable
$ source ~/.bashrc 

$ sudo gem update
$ sudo gem install rails bundler

$ rails -v
> Rails 3.2.3
$ bundle -v
> Bundler version 1.1.3
bundler可以理解为用来管理 gems 之间依赖关系的工具。Gemfile文件就是bundler的配置文件。

[Getting Started with Rails]
(http://guides.rubyonrails.org/getting_started.html)
$ rails new blog
$ rake db:create
> rake aborted!
> uninitialized constant Rake::DSL

blog/Gemfile add
    gem 'rake', '0.8.7'

$ bundle update rake
$ bundle show rake
> /Library/Ruby/Gems/1.8/gems/rake-0.8.7
$ rake db:create

* 版本兼容性问题太难折腾了，暂时直接吧rake-0.9.2的版本删除；
`gem uninstall rake -v=0.9.2`  然后从头到尾重新做了一遍；
做法有点低效，是照着文档一步一步做下来的，通篇大致看一遍再做更合理一些；

