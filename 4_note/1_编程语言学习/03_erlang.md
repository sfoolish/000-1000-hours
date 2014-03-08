---
## Erlang Building from git
	
	git clone https://github.com/erlang/otp.git
	autoconf
	./otp_build autoconf
    ./configure 
    ./make -j4

[REF](https://github.com/erlang/otp/blob/maint/HOWTO/INSTALL.md)

---
## [Ebot](http://www.redaelli.org/matteo-blog/projects/ebot/)
Erlang Bot (Ebot) is an opensource web crawler written on top of Erlang, a NOSQL database (Apache CouchDB or Riak),  RabbitMQ, Webmachine (Mochiweb), RRDTOOL, .. Using a NOSQL instead of a Relational Database, Ebot can grow easily and cheaply…  Ebot is a solid and highly scalable, distribuited and customizable web crawler.

---
# Erlang ['ə:læŋ] 知乎问题汇总

## 要点汇总
* 尾递归；
* 一颗接受新事物的心；
* SICP;
* 《Erlang 语言编程》;
* [Learn You Some Erlang](http://learnyousomeerlang.com/)
* [http://github.com/basho/rebar](http://github.com/basho/rebar)

## 问答摘录

### [Erlang学习需要什么基础？](http://www.zhihu.com/question/19938101)

对初学者来说最大的障碍可能函数式编程。学习一下尾递归，再学习一下如何将普通的迭代式循环结构转化为尾递归结构，基本上就没啥障碍可言了。 --- 连城

函数式语言是另外一个不同的世界，一颗接受新事物的心，就很容易学。 --- 霸爷/余锋

http://learnyousomeerlang.com/ Learn You Some Erlang for great Good! --- 依云

### [有哪些书籍或者网站资源比较适合从头开始学习erlang?](http://www.zhihu.com/question/19836004)
rebar这个项目做的最好了： [http://github.com/basho/rebar](http://github.com/basho/rebar)

### [Erlang可以做什么？](http://www.zhihu.com/question/19929730)
Some of its uses are in telecoms, banking, e-commerce, computer telephony and instant messaging. Erlang's runtime system has built-in support for concurrency, distribution and fault tolerance. --- 霸爷/余锋

### [有哪些公司在用 Google 的 Go 语言？成熟度和 Erlang 比起来如何？](http://www.zhihu.com/question/19664126)
``` --- Rico
我是一名系统程序员，摸爬滚打在硬件之上，每日目睹着各种字节流过系统的各个角落。但我翻得最多的一本书，是《Erlang 语言编程》。

确切的说，我不认为 Erlang 是一门语言，而是一个世界。《Erlang 语言编程》只用了3章介绍基本语法，其余都是在为我们展现这个世界的壮丽。

这个世界里面有你需要的各种工具，二十多年的积累，全部体现在一份完善的文档上。拉开 Module List，会让你眼花缭乱。
在这个世界里，你会感觉自己不再是一个写程序的人，而是这个世界里一个鲜活的生命。睁开双眼，就能看到自己一样的进程在 ！在 receive 在 loop。这就是并发世界的景象。
OTP 为你提供了坚强的后盾，使你能专注于自己的任务，而不必为外围逻辑、异常、日志等等琐碎却又重要的事情分心。FP 与 模式匹配让你效率倍增，mnesia 帮你分布数据。

接触 Erlang 也有些年了，以前只是很喜欢个系统。直到最近工作需要，分析了 Ejabberd 之后，才愈发感到他的精巧与神奇。用最简单的工具，最轻巧的设计，解决这个真实并发世界的问题。
```

### [常年使用 C、Java 的老程序员想学一门函数式编程语言以了解其思想，选择哪种最合适？为什么？](http://www.zhihu.com/question/20402619)
``` --- 学文，数学初学者
如果从思想入手，并且学的更深入，建议从SICP入手，Scheme是思想的锤炼。

如果你是java程序员，我建议你同时看看clojure，这个极具生产力的玩具，哦~这可不是个玩具，twitter的storm就是拿她写的。可不要小瞧clojure，这个基于jvm的lisp语言，已经是黑客领域最耀眼的明星了。

另外后话，clojure已经出版了两本中文教材，可以入手学习了。顺带加上SICP，你会感觉飞起来，呵呵。
```

---