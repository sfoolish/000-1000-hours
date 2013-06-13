## GDB 常用命令
### 帮助命令
    (gdb) help
    (gdb) info
### 结构体格式输出
    (gdb) set print pretty on | off
### 源码显示
    (gdb) list ngx_http_static_handler
### 反汇编显示
    (gdb) disassemble ngx_http_static_handler
### 运行shell 命令
    (gdb) shell ls
### log 功能
    (gdb) set logging on
### 部分技巧
* TAB 有命令补全，函数名补全功能

### 内存信息打印
    (gdb) x/200 0x1f48f00
### 结构体打印
    (gdb) p *__gal_screen->format
