---
## tengine ubuntu12.04 编译运行
    $ sudo apt-get install libpcre3 libpcre3-dev openssl libssl-dev zlib1g zlib1g-dev
    $ git clone git://github.com/alibaba/tengine.git
    $ cd tengine/
    $ ./configure --with-debug --prefix=./install
    $ make && make install
    $ sudo ./install/sbin/nginx
    $ sudo ./install/sbin/nginx -s stop

## tengine gdb 调试跟踪代码
    $ cd tengine/
    $ sudo ./install/sbin/nginx
    $ ps ax | grep 'nginx' | grep 'worker'
    ```
        12733 ?        t      0:00 nginx: worker process
    ```
    $ sudo gdb attach 12733 ./install/sbin/nginx
具体 gdb 的使用参见：[gdb](https://github.com/sfoolish/000-1000-hours/blob/master/4_note/tools/gdb.md)
