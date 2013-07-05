---
### ubuntu 12.04 下 clojure 初体验 ###
    ## 安装 jre
    $ apt-get install default-jre
    $ mkdir clojure
    $ cd clojure/
    ## 下载最新 clojure 稳定版
    $ wget http://repo1.maven.org/maven2/org/clojure/clojure/1.5.1/clojure-1.5.1.zip
    $ unzip clojure-1.5.1.zip 
    $ cd clojure-1.5.1/
    ## clojure REPL
    $ java -cp clojure-1.5.1.jar clojure.main
    ```
        Clojure 1.5.1
        user=> (println "Hello world!")
        Hello world!
        nil
        user=> 
    ```
 MAC OS X 下自带 jre ，因此只需下载 clojure 。

#### REF ####
* [clojure quick start](http://clojure.org/getting_started)

---
### 初识 clojure ###
* [github clojure](https://github.com/clojure)
* [clojure documentation](http://clojure.org/documentation)
* [Clojure - Functional Programming for the JVM](http://java.ociweb.com/mark/clojure/article.html)
* [Clojure – Functional Programming for the JVM中文版](http://xumingming.sinaapp.com/302/clojure-functional-programming-for-the-jvm-clojure-tutorial/)
* [Clojure中文社区](http://blog.clojure.cn/)
* [Clojure资源](http://wiki.clojure.cn/index.php?title=Clojure%E8%B5%84%E6%BA%90)
* [wikipedia Clojure](http://en.wikipedia.org/wiki/Clojure)
* [现实世界的LISP：Clojure语言初探](http://www.csdn.net/article/2013-04-17/2814930)
* [[数据图] 2012 Clojure很忙！](http://www.csdn.net/article/2012-08-07/2808276)
* [Clojure 编程语言 - IBM developerworks](http://www.ibm.com/developerworks/cn/opensource/os-eclipse-clojure/)
* [Clojure_huangz](http://www.huangz.me/en/latest/language/clojure/index.html)

---
### 初识 strom ###
* [storm github wiki](https://github.com/nathanmarz/storm/wiki)
* [Storm入门教程 -- 量子恒道](http://blog.linezing.com/category/storm-quick-start)
* [xumingming blog storm category](http://xumingming.sinaapp.com/category/storm/)
* [storm -- 大圆那些事 淘宝](http://www.cnblogs.com/panfeng412/tag/Storm/)

---
### clojure 源码编译测试 ###
    # uname -a
    ```
        Linux AY1302250940505971892 3.2.0-39-generic #62 SMP Thu Mar 7 10:18:55 CST 2013 x86_64 x86_64 x86_64 GNU/Linux
    ```
    # git clone git://github.com/clojure/clojure.git
    # mv clojure clojure_github
    # cd clojure_github
    # apt-get install ant
    # apt-get install maven2
    # apt-get install openjdk-6-jdk
    # mvn package
    ```
        [INFO] ------------------------------------------------------------------------
        [INFO] BUILD SUCCESSFUL
        [INFO] ------------------------------------------------------------------------
        [INFO] Total time: 5 minutes 32 seconds
        [INFO] Finished at: Thu Jun 20 22:50:14 CST 2013
        [INFO] Final Memory: 40M/95M
        [INFO] ------------------------------------------------------------------------
    ```
    # java -cp target/clojure-1.6.0-master-SNAPSHOT.jar  clojure.main
    ```
        Clojure 1.6.0-master-SNAPSHOT
        user=> (println "Hello world!")
        Hello world!
        nil
        user=> 
    ```
#### REF ####
* [clojure readme](https://github.com/clojure/clojure/blob/master/readme.txt)