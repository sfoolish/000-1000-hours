---
## bash中的 $ 相关参数 
* $0 - 表示当前文件名
* $* - 以空格分离所有参数，形成一个字符串
* $@ - 以空格分离所有参数，形成一个字符串组合。与$*的不同表现在被""引用时，"$*"是一个字符串，而"$@"则包含多个字符串
* $# - 传递给进程的参数数目
* $? - 上一条命令的执行结果，没有错误时为0
* $$ - 本条命令的PID

### 测试脚本及输出
    $ cat test.sh 
    ```
        #!/bin/sh
        
        echo $0 $# $* $@
        echo '---------------'
        for arg in $*
        do
                echo $arg
        done
        echo '---------------'
        for arg in "$*"
        do
                echo $arg
        done
        echo '---------------'
        
        for arg in "$@"
        do
                echo $arg
        done
        echo '---------------'
        echo $? $$
    ```
    $ ./test.sh a b
    ```
        ./test.sh 2 a b a b
        ---------------
        a
        b
        ---------------
        a b
        ---------------
        a
        b
        ---------------
        0 27443
    ```

---
##  tar打包指定列表中列出的文件
    $ cat yourlist.lst  
        /etc/fstab  
        /home/admin/bin/somefile.sh  
        /home/mysql/somefile  
        ...  
    $ tar cvzf xxx.tar.gz -T yourlist.lst  

## REF
* [玩Linux五年积累的技巧(3) -- 系统（下）](http://blog.csdn.net/gaopenghigh/article/details/8654084)

---
## shell 命令制作
    ## 创建 hello 命令文件
    $ vim cmd_hello
    ## 简析 hello 命令
    $ cat cmd_hello
    ```
        #!/usr/bin/env bash
    
        echo 'hello'
    ```
    `#!/usr/bin/env bash` 表示通过 env 寻找 bash 来解释执行后面的脚本。
    `echo 'hello'` 通过标准输出字符串 hello 。    
    ## 添加执行权限
    $ chmod +x cmd_hello
    ## 运行命令
    $ ./cmd_hello
    ```
        hello
    ```

---
## sed 命令使用
    $ sed -e '/regexp/d' /path/to/my/test/file | more
    $ sed -n -e '/regexp/p' /path/to/my/test/file | more
    $ sed -n -e '/BEGIN/,/END/p' /my/test/file | more
### 常用正则表达式
    /./         将与包含至少一个字符的任何行匹配
    /../        将与包含至少两个字符的任何行匹配
    /^#/        将与以 '#' 开始的任何行匹配
    /^$/        将与所有空行匹配
    /}^/        将与以 '}'（无空格）结束的任何行匹配
    /} *^/      将与以 '}' 后面跟有 零或多个空格结束的任何行匹配
    /[abc]/     将与包含小写 'a'、'b' 或 'c' 的任何行匹配
    /^[abc]/    将与以 'a'、'b' 或 'c' 开始的任何行匹配 

---
## shell 功能命令
### 代码行数查看
    $ find ./ -name "*.c"  | xargs wc -l | sort -n
    ## 搜索 *.c, *.h, *.cc 三类文件
    $ find . \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -print | xargs wc -l 

---
## for / while loop
    $ cat ./for_test.sh
    ```
        #!/bin/sh
        
        ### for
        for file in $(ls $1) ; do
            ls -l $1$file
            echo "file name: $file"
        done
        
        ### while
        k=0
        end=5
        while [ $k -lt $end ]
        do
            printf "%d \n" $k
            k=$(expr $k + 1)
        done
    ```
    $ ./for_test.sh ./
    ```
        -rwxr-xr-x@ 1 apple  staff  180  5 29 20:58 ./for_test.sh
        file name: for_test.sh
        0 
        1 
        2 
        3 
        4 
    ```