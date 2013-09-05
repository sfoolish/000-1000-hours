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

* 阅读 [Redis 设计与实现](http://www.redisbook.com/en/latest/index.html) 进行中