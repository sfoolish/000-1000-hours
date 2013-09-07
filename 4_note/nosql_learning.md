## Redis REF
* [Redis 设计与实现](http://www.redisbook.com/en/latest/index.html)
* [Redis核心解读系列](http://blog.nosqlfan.com/html/4198.html)
* [Redis 源码分析](http://www.huangz.me/en/latest/storage/redis_code_analysis/index.html)
* [带有详细注释的 Redis 2.6 源码](https://github.com/huangz1990/annotated_redis_source)

---

# Redis 突击强化笔记 [2013.09.04 21:00]

之前对 Redis 的了解是，她是非常不错的 key-value nosql 类数据库。Redis 支持的数据结构比较丰富。知道的东西都比较的笼统模糊。使用方面也只是停留在源码编译，然后通过 `redis-cli` 做过简单的操作。简单的浏览过 `redis-py` 和 `tornado-redis` 的代码。

翻出之前读过的一篇文章[如何熟悉一个开源项目？](http://www.blogjava.net/killme2008/archive/2012/05/22/378885.html)。觉得写的非常不错打算照着实践一下。

上面 Redis REF 中的链接都是非常不错的资料，之前都没有细看。

* 浏览一遍 [Redis documentation](http://redis.io/documentation)，基本知道后续看那些文章。

* 阅读 [Data types](http://redis.io/topics/data-types)

* 阅读 [15 minutes introduction to Redis data types](http://redis.io/topics/data-types-intro)

* 阅读 [Writing a simple Twitter clone with PHP and Redis](http://redis.io/topics/twitter-clone)

* https://code.google.com/p/redis/downloads/list 下载早期代码(github 中的代码库包含早期版本)及 retwis-0.3.tar.gz 实例代码。      测试代码的运行[TODO]。

* 源码下载，编译，单元测试
	$ git clone git@github.com:antirez/redis.git
	$ cd redis
	$ git checkout v2.0.4-stable
	$ find ./ | grep '\.c$' | xargs wc -l | grep total
	    ``` 17474 total ```
	$ make -j8
	$ make test

* 阅读 [The Little Redis Book](http://openmymind.net/2012/1/23/The-Little-Redis-Book/)

* 阅读 [Redis 设计与实现](http://www.redisbook.com/en/latest/index.html) 浏览完毕，原计划晚上看完的，到十二点的时候还有最后几个小节没看，实在太困，眯了一会儿后，被外面的敲门声吵醒，起来继续看。
看完之后对 Redis 的内部实现有了大致的了解。图文并貌，条理清晰，很不错的一份文档。

* 阅读 [Connections Handling](http://redis.io/topics/clients)
* 阅读 [Signals Handling](http://redis.io/topics/signals)
* 阅读 [Redis Administration](http://redis.io/topics/admin)
* 阅读 [Redis Persistence](http://redis.io/topics/persistence)
    * TO READ [Redis persistence demystified](http://oldblog.antirez.com/post/redis-persistence-demystified.html)
* 阅读 [Replication](http://redis.io/topics/replication)
* 阅读 [Redis Internals documentation](http://redis.io/topics/internals)
	* 阅读 [Hacking Strings the Redis String implementation](http://redis.io/topics/internals-sds): 巧妙的指针处理，使得 `sds *` 兼容 `char *`
	* 阅读 [virtual memory implementation details](http://redis.io/topics/internals-vm)
	* 阅读 [Event Library](http://redis.io/topics/internals-eventlib)
		* TO READ [why Redis uses its own event library](https://groups.google.com/forum/#!topic/redis-db/tSgU6e8VuNA)
	* 阅读 [Redis Event Library](http://redis.io/topics/internals-rediseventlib)

---

## redis 代码阅读笔记

### 阅读版本 2.6.9
	$ git clone git@github.com:antirez/redis.git
	$ cd redis
	$ git checkout 2.6.9

	$ cd src && make -j8
	$ make test

#### 测试代码的进一步说明

redis 的绝大多少的测试代码在代码树的 `tests` 目录下用 tcl 脚步实现，一小部分单元测试代码直接内嵌在 `.c` 文件中，如 `ziplist.c`， `zipmap.c` 等。

`runtest` 脚本的简单使用记录：

    $ ./runtest --help
    ```
        /usr/bin/tclsh8.5
        --valgrind         Run the test over valgrind.
        --accurate         Run slow randomized tests for more iterations.
        --quiet            Don't show individual tests.
        --single <unit>    Just execute the specified unit (see next option).
        --list-tests       List all the available test units.
        --clients <num>    Number of test clients (16).
        --force-failure    Force the execution of a test that always fails.
        --help             Print this help screen.
    ```
    $ ./runtest --list-tests
    ```
        /usr/bin/tclsh8.5
        unit/printver
        ... ...
    ```
    $ ./runtest --single unit/printver
    ```
        /usr/bin/tclsh8.5
        Cleanup: may take some time... OK
        Starting test server at port 11111
        
        Testing unit/printver
        
        ... ...
        
        Execution time of different units:
          0 seconds - unit/printver
        
        \o/ All tests passed without errors!
        
        Cleanup: may take some time... OK
    ```

ziplist.c 单元测试代码运行

	$ git diff
	```
        diff --git a/src/redis.c b/src/redis.c
        index 23083fb..d86e173 100644
        --- a/src/redis.c
        +++ b/src/redis.c
        @@ -2528,7 +2528,7 @@ void redisOutOfMemoryHandler(size_t allocation_size) {
             redisPanic("OOM");
         }
         
        -int main(int argc, char **argv) {
        +int __main(int argc, char **argv) {
             struct timeval tv;
         
             /* We need to initialize our libraries, and the server configuration. */
        diff --git a/src/ziplist.c b/src/ziplist.c
        index d4ac4f9..e439f5d 100644
        --- a/src/ziplist.c
        +++ b/src/ziplist.c
        @@ -951,6 +951,7 @@ void ziplistRepr(unsigned char *zl) {
             printf("{end}\n\n");
         }
         
        +#define ZIPLIST_TEST_MAIN
         #ifdef ZIPLIST_TEST_MAIN
         #include <sys/time.h>
         #include "adlist.h"
    ```
    $ make -j8
    $ ./redis-server
    ```
        {total bytes 75} {length 6}
        {tail offset 44}
        
        ... ...
        
        List size:    15872, bytes:    95243, 100000x push+pop (TAIL): 439907 usec
        List size:    16128, bytes:    96779, 100000x push+pop (TAIL): 425798 usec
    ```



