---
## tengine ubuntu12.04 编译运行
    $ sudo apt-get install libpcre3 libpcre3-dev openssl libssl-dev zlib1g zlib1g-dev
    $ git clone git://github.com/alibaba/tengine.git
    $ cd tengine/
    $ ./configure --with-debug --prefix=./install
    $ make && make install
    $ sudo ./install/sbin/nginx
    $ sudo ./install/sbin/nginx -s stop

---
## tengine gdb 调试跟踪代码
    $ cd tengine/
    $ sudo ./install/sbin/nginx
    $ ps ax | grep 'nginx' | grep 'worker'
    ```
        12733 ?        t      0:00 nginx: worker process
    ```
    $ sudo gdb attach 12733 ./install/sbin/nginx
具体 gdb 的使用参见：[gdb](https://github.com/sfoolish/000-1000-hours/blob/master/4_note/tools/gdb.md)

---
## [Nginx开发从入门到精通](https://github.com/taobao/nginx-book)
* [雕梁 old](http://simohayha.iteye.com/category/53824?page=2)
* [雕梁 new](http://www.pagefault.info)
* [文景](http://yaoweibin.cn)
* [李子](http://blog.lifeibo.com)
* [卫越](http://blog.sina.com.cn/u/1929617884)
* [袁茁](http://yzprofile.me)
* [小熊](http://dinic.iteye.com)
* [吉兆](http://jizhao.blog.chinaunix.net)
* [静龙](http://blog.csdn.net/fengmo_q)
* [竹权](http://weibo.com/u/2199139545)
* [公远](http://100continue.iteye.com/)
* [布可](http://weibo.com/sifeierss)

---
## nginx http request 处理流程堆栈打印
    (gdb) b ngx_linux_sendfile_chain
    $ curl http://172.9.21.103/index.html
    (gdb) bt
    ```
        #0  ngx_linux_sendfile_chain (c=0x9a386cc, in=0x9a2f57c, limit=0)
            at src/os/unix/ngx_linux_sendfile_chain.c:39
        #1  0x0808fb7f in ngx_http_write_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/ngx_http_write_filter_module.c:238
        #2  0x080a1d04 in ngx_http_chunked_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_chunked_filter_module.c:110
        #3  0x080a7b64 in ngx_http_gzip_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_gzip_filter_module.c:324
        #4  0x080a8a85 in ngx_http_postpone_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/ngx_http_postpone_filter_module.c:83
        #5  0x080aa9c3 in ngx_http_ssi_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_ssi_filter_module.c:395
        #6  0x080ad955 in ngx_http_charset_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_charset_filter_module.c:553
        #7  0x080af9e1 in ngx_http_footer_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_footer_filter_module.c:144
        #8  0x08057b75 in ngx_output_chain (ctx=0x9a2f584, in=0xbf850e94)
            at src/core/ngx_output_chain.c:66
        #9  0x08090213 in ngx_http_copy_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/ngx_http_copy_filter_module.c:143
        #10 0x080a211e in ngx_http_range_body_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/modules/ngx_http_range_filter_module.c:559
        #11 0x08084df3 in ngx_http_output_filter (r=0x9a124c0, in=0xbf850e94)
            at src/http/ngx_http_core_module.c:1946
        #12 0x080a109f in ngx_http_static_handler (r=0x9a124c0)
            at src/http/modules/ngx_http_static_module.c:266
        #13 0x08085251 in ngx_http_core_content_phase (r=0x9a124c0, ph=0x9a358ec)
            at src/http/ngx_http_core_module.c:1434
        #14 0x080801e3 in ngx_http_core_run_phases (r=0x9a124c0) at src/http/ngx_http_core_module.c:907
        #15 0x080802e3 in ngx_http_handler (r=0x9a124c0) at src/http/ngx_http_core_module.c:890
        #16 0x08085f23 in ngx_http_internal_redirect (r=0x9a124c0, uri=0xbf85106c, args=0x9a12658)
            at src/http/ngx_http_core_module.c:2579
        #17 0x080a1c55 in ngx_http_index_handler (r=0x9a124c0)
            at src/http/modules/ngx_http_index_module.c:277
        #18 0x08085251 in ngx_http_core_content_phase (r=0x9a124c0, ph=0x9a358d4)
            at src/http/ngx_http_core_module.c:1434
        #19 0x080801e3 in ngx_http_core_run_phases (r=0x9a124c0) at src/http/ngx_http_core_module.c:907
        #20 0x080802e3 in ngx_http_handler (r=0x9a124c0) at src/http/ngx_http_core_module.c:890
        #21 0x0808bbce in ngx_http_process_request (r=0x9a124c0) at src/http/ngx_http_request.c:1694
        #22 0x0808c27a in ngx_http_process_request_headers (rev=0x9a232ec)
            at src/http/ngx_http_request.c:1147
        #23 0x0808c829 in ngx_http_process_request_line (rev=0x9a232ec)
            at src/http/ngx_http_request.c:945
        #24 0x08088c18 in ngx_http_init_request (rev=0x9a232ec) at src/http/ngx_http_request.c:531
        ---Type <return> to continue, or q <return> to quit---
        #25 0x08075957 in ngx_epoll_process_events (cycle=0x9a1de78, timer=60000, flags=1)
            at src/event/modules/ngx_epoll_module.c:683
        #26 0x0806b2cd in ngx_process_events_and_timers (cycle=0x9a1de78) at src/event/ngx_event.c:249
        #27 0x08073eab in ngx_worker_process_cycle (cycle=0x9a1de78, data=0x0)
            at src/os/unix/ngx_process_cycle.c:853
        #28 0x08071313 in ngx_spawn_process (cycle=0x9a1de78, 
            proc=0x8073dce <ngx_worker_process_cycle>, data=0x0, name=0x80d18cb "worker process", 
            respawn=-4) at src/os/unix/ngx_process.c:189
        #29 0x0807318a in ngx_start_worker_processes (cycle=0x9a1de78, n=1, type=-4)
            at src/os/unix/ngx_process_cycle.c:392
        #30 0x08074fb2 in ngx_master_process_cycle (cycle=0x9a1de78)
            at src/os/unix/ngx_process_cycle.c:269
        #31 0x08054ac9 in main (argc=1, argv=0xbf851694) at src/core/nginx.c:431
    ```
---
## [agentzh 的 Nginx 教程（版本 2013.03.15）](http://openresty.org/download/agentzh-nginx-tutorials-zhcn.html)
**TODO** 抽空好好看看

---
## nginx 代理服务器配置
http 正向代理之前配置过， https 代理没有配置过，下面两个链接感觉不错，留作参考备份。
### REF
* [Nginx反向代理https站点的配置笔记](http://idaemon.net/post-697.html)
* [nginx: Setup SSL Reverse Proxy (Load Balanced SSL Proxy)](http://www.cyberciti.biz/faq/howto-linux-unix-setup-nginx-ssl-proxy/)

---
## sublime text + ctags + grep 阅读代码
### grep 使用技巧
grep 正则增加字母过滤，看实例：

    # grep -rn 'ngx_channel' ./
    ```
        ./os/unix/ngx_process_cycle.c:11:#include <ngx_channel.h>
        ./os/unix/ngx_process_cycle.c:21:static void ngx_pass_open_channel(ngx_cycle_t *cycle, ngx_channel_t *ch);
        ./os/unix/ngx_process_cycle.c:28:static void ngx_channel_handler(ngx_event_t *ev);
        ./os/unix/ngx_process_cycle.c:384:    ngx_channel_t  ch;
        ./os/unix/ngx_process_cycle.c:409:    ngx_channel_t    ch;
        ./os/unix/ngx_process_cycle.c:459:ngx_pass_open_channel(ngx_cycle_t *cycle, ngx_channel_t *ch)
        ...
    ```
    # grep -rn 'ngx_channel[^_.]' ./
    ```
        ./os/unix/ngx_process_cycle.c:1068:    if (ngx_add_channel_event(cycle, ngx_channel, NGX_READ_EVENT,
        ./os/unix/ngx_process.h:90:extern ngx_socket_t   ngx_channel;
        ./os/unix/ngx_process.c:25:ngx_socket_t     ngx_channel;
        ./os/unix/ngx_process.c:167:        ngx_channel = ngx_processes[s].channel[1];
        ./proc/ngx_proc.c:611:    if (ngx_add_channel_event(cycle, ngx_channel, NGX_READ_EVENT,
    ```
### REF
* [sublime text + ctags](https://github.com/sfoolish/000-1000-hours/blob/master/4_note/0_1000_hours.md#2012-09-25-700-----800)