---
### ubuntu 12.04 下 clojure 初体验
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

#### REF
* [clojure quick start](http://clojure.org/getting_started)

---
### 初识 clojure
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