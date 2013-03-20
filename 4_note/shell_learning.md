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
##  tar打包指定列表中列出的文件
    $ cat yourlist.lst  
        /etc/fstab  
        /home/admin/bin/somefile.sh  
        /home/mysql/somefile  
        ...  
    $ tar cvzf xxx.tar.gz -T yourlist.lst  

## REF
* [玩Linux五年积累的技巧(3) -- 系统（下）](http://blog.csdn.net/gaopenghigh/article/details/8654084)

