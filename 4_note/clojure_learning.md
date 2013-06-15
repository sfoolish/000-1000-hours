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
