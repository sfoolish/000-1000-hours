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
