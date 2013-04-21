## LNMP 安装
    $ sudo apt-get install nginx
    $ sudo apt-get install php5-cli php5-cgi php5-fpm php5-mcrypt php5-mysql

    ## 备份原始配置文件
    $ sudo cp /etc/nginx/sites-available/default  \
        /etc/nginx/sites-available/default_bkp
    $ sudo vim /etc/nginx/sites-available/default
    ## 查看 default 做了哪些修改
    $ diff /etc/nginx/sites-available/default  \
        /etc/nginx/sites-available/default_bkp
     ```
         24,28c24,25
        < 	# modify by liang
        < 	#root /usr/share/nginx/www;
        < 	#index index.html index.htm;
        < 	root /home/liang/prj/www;
        < 	index index.html index.htm index.php;
        ---
        > 	root /usr/share/nginx/www;
        > 	index index.html index.htm;
        65,75c62,72
        < 	location ~ \.php$ {
        < 		fastcgi_split_path_info ^(.+\.php)(/.+)$;
        < 		# NOTE: You should have "cgi.fix_pathinfo = 0;" in php.ini
        < 	
        < 		# With php5-cgi alone:
        < 		fastcgi_pass 127.0.0.1:9000;
        < 		# With php5-fpm:
        < 		#fastcgi_pass unix:/var/run/php5-fpm.sock;
        < 		fastcgi_index index.php;
        < 		include fastcgi_params;
        < 	}
        ---
        > 	#location ~ \.php$ {
        > 	#	fastcgi_split_path_info ^(.+\.php)(/.+)$;
        > 	#	# NOTE: You should have "cgi.fix_pathinfo = 0;" in php.ini
        > 	#
        > 	#	# With php5-cgi alone:
        > 	#	fastcgi_pass 127.0.0.1:9000;
        > 	#	# With php5-fpm:
        > 	#	fastcgi_pass unix:/var/run/php5-fpm.sock;
        > 	#	fastcgi_index index.php;
        > 	#	include fastcgi_params;
        > 	#}
    ```
    ## 启动或重启 nginx
    $ sudo /etc/init.d/nginx start    # [reload | restart]
    
    $ mkdir -p /home/liang/prj/www
    $ echo "<?php phpinfo(); ?>" > /home/liang/prj/www/test.php
    $ curl http://localhost/test.php
    $ sudo apt-get install mysql-server

### REF
* [ubuntu 12.04 安装 nginx+php+mysql web服务器](http://imcn.me/html/y2012/11833.html)
* [ubuntu 12.04 安装 Nginx+PHP5 (PHP-FPM) +MySQL主机详解](http://www.myhack58.com/Article/sort099/sort0102/2012/33937_4.htm)

---
## php error log 配置
    ## 修改配置文件
    ## php.ini 中有 Development 和 Production 的建议值
    $ cp /etc/php5/fpm/php.ini /etc/php5/fpm/php.ini_bkp 
    ## 编辑配置文件
    $ vim /etc/php5/fpm/php.ini
    ## 比较修改前后差异
    $ diff /etc/php5/fpm/php.ini /etc/php5/fpm/php.ini_bkp 
    ```
        521c521
        < error_reporting = E_ALL
        ---
        > error_reporting = E_ALL & ~E_DEPRECATED
        538c538
        < display_errors = On
        ---
        > display_errors = Off
        549c549
        < display_startup_errors = On
        ---
        > display_startup_errors = Off
        593c593
        < track_errors = On
        ---
        > track_errors = Off
        611c611
        < html_errors = On
        ---
        > html_errors = Off
        643c643
        < error_log = /home/liang/prj/log/php_errors.log
        ---
        > ;error_log = php_errors.log
    ```
    ## 重启 php5-fpm
    $ sudo /etc/init.d/php5-fpm restart
    ## 编辑测试程序
    $ vim error.php
    ## 查看测试程序
    $ cat error.php
    ```
        <?php error_log("error !!!", 0); ?>
    ```
    ## 运行测试程序
    $ curl http://localhost/error.php
    $ ls /home/liang/prj/log/php_errors.log
    ```
        ls: 无法访问/home/liang/prj/log/php_errors.log: 没有那个文件或目录
    ```
    ## strace 跟踪 open 系统调用
    $ sudo strace -f -e trace=open sudo /etc/init.d/php5-fpm restart &
    ```
        [pid 32536] open("/home/liang/prj/www/www_duankou/abc.php", O_RDONLY) = 4
        [pid 32536] open("/home/liang/prj/log/php_errors.log", O_WRONLY|O_CREAT|O_APPEND, 0644) = -1 EACCES (Permission denied)
        [pid 32536] open("/dev/urandom", O_RDONLY) = 3
        [pid 32536] open("/dev/urandom", O_RDONLY) = 3
        [pid 32536] open("/dev/urandom", O_RDONLY) = 3

    ```
    ## 找到原因 php_errors.log 文件打开失败
    $ touch /home/liang/prj/log/php_errors.log
    $ chmod 666 /home/liang/prj/log/php_errors.log
    ## 继续测试
    $ curl http://localhost/error.php
    ```
        [pid 32715] open("/home/liang/prj/www/www_duankou/abc.php", O_RDONLY) = 4
        [pid 32715] open("/home/liang/prj/log/php_errors.log", O_WRONLY|O_CREAT|O_APPEND, 0644) = 4
        [pid 32715] open("/dev/urandom", O_RDONLY) = 3
        [pid 32715] open("/dev/urandom", O_RDONLY) = 3
        [pid 32715] open("/dev/urandom", O_RDONLY) = 3
    ```
    ## 查看日志文件
    $ cat /home/liang/prj/log/php_errors.log
    ```
        [20-Apr-2013 11:16:18 UTC] error !!!
    ```

### REF
* [How do you restart php-fpm?](http://serverfault.com/questions/189940/how-do-you-restart-php-fpm)
* [error_log](http://php.net/manual/en/function.error-log.php)
* [PHP的错误日志配置](http://www.vfeelit.com/232.html)

---
## php 调试方法
### php 变量打印方法
print_r、var_dump 和 var_export 三个函数都可以打印对象的值、系统函数值以及数组的内容； 
    
    1、 echo、print、printf 可以打印变量内容，但不能显示数组及系统超级变量数组； 
    2、 print_r 和 var_dump 不仅可以打印数组、标量变量，还可以打印对象的内容； 
    3、 var_dump 语句不仅能打印变量、数组内容，还可以显示布尔变量和资源（Resource）的内容； 
    4、 var_export 函数返回关于传递给该函数的变量的结构信息，和 var_dump()函数类似，不同的是其返回的内容是合法的PHP代码。
### REF
* [php中print_r、var_dump和var_export几个函数的用法区别](http://www.phpzixue.cn/detail1147.shtml)

---
## mongo php driver install
    ## 下载安装[mongodb-linux-x86_64](http://fastdl.mongodb.org/linux/mongodb-linux-x86_64-2.4.2.tgz)
	## 运行 mongod
	$ mongod --dbpath=/home/liang/prj/database/mongodb/data

	## 下载 driver 源码
    $ git clone git://github.com/mongodb/mongo-php-driver.git
    $ cd mongo-php-driver
    ## checkout tag 1.3.7
    $ git checkout 1.3.7
    
    ## 编译安装
    $ phpize
    $ ./configure 
    $ make -j4
    $ sudo make install
    
    ## php.ini add `extension=mongo.so`
    ## restart fpm
    $ sudo /etc/init.d/php5-fpm restart
### REF
* [mongo-php-driver](https://github.com/mongodb/mongo-php-driver)
* [MongoDB Native Driver](http://php.net/manual/en/book.mongo.php)
* [用PHP实现MONGODB的基本操作](http://www.bumao.com/index.php/2010/08/php-mongo-isud.html)

---
## memcached php driver install
	## 安装 memcached
	$ sudo apt-get install memcached
	## 运行 memcached
	$ memcached -d -m 128 -l 192.168.1.117 -p 11211 -u httpd

	## 下载[memcache-2.2.7.tgz](http://pecl.php.net/get/memcache-2.2.7.tgz)
	$ wget http://pecl.php.net/get/memcache-2.2.7.tgz
    $ tar xvf memcache-2.2.7.tgz
    $ cd memcache-2.2.7
    $ phpize
    $ ./configure 
    $ make -j4
    $ sudo make install

    ## edit php.ini add `extension=memcache.so`
    ## restart fpm
    $ sudo /etc/init.d/php5-fpm restart
### REF
* [memcached php-memcache 的安装及使用](http://meizhini.iteye.com/blog/185165)
* [Memcache](http://php.net/manual/zh/book.memcache.php)

---
### 调试技巧 -- 将对象信息写到 error_log 中
    $x = "My string";
    // Dump x
    ob_start();
    var_dump($x);
    $contents = ob_get_contents();
    ob_end_clean();
    error_log($contents);
### REF
* [PHP var_dump into error log](http://www.nolte-schamm.za.net/2011/05/php-var_dump-into-error-log/)
* [How to Log PHP Errors like a Pro](http://aaronsaray.com/blog/2010/05/25/how-to-log-php-errors-like-a-pro/)