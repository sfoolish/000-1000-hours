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
