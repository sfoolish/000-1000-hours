---
## node 参考资源
* [Node.js Manual & Documentation](http://nodejs.org/api/all.html)
* [JavaScript 参考手册](http://www.w3school.com.cn/js/js_reference.asp)
### Node Modules
* [momentjs](http://momentjs.com) Parse, validate, manipulate, and display dates in javascript. 
* [Commander.js](http://visionmedia.github.io/commander.js/) is a light-weight, expressive, and powerful command-line framework for nodejs

---
## node 源码安装
    $ cd /<path>
    $ wget http://nodejs.org/dist/v0.10.3/node-v0.10.3.tar.gz
    $ tar xvf node-v0.10.3.tar.gz 
    $ cd node-v0.10.3
    $ ./configure --prefix=../install
    $ make -j4 && make install               # -j4 4 线程
    $ export PATH=/<path>/install/bin:$PATH  # 添加到 ~/.profile 下次启动 shell 自动生效
node-v0.10.3 已经将 npm 集成了，默认就会自动安装. 当然可以也在 config 的时候，--without-npm 取消安装，应该不会有人会这么干吧 :).

---
## npm 使用
    $ npm install                  # install both "dependencies" and "devDependencies"
    $ npm install --production     # only install "dependencies"
npm 会根据 package.json 安装依赖包到本地。
### REF
* [Introduction to npm](http://howtonode.org/introduction-to-npm)

---
## [node-inspector](https://github.com/dannycoates/node-inspector)
### REF
* [使用node-inspector来调试node](http://blog.goddyzhao.me/post/11522397416/how-to-debug-node-with-node-inspector)
* [如何开始使用nodejs调试debug利器node-inspector](http://liuxiaoming.com/dev/2012/06/20/how-to-debug-nodejs-code-with-node-inspector/)
* [Chrome DevTools -- Using the Console](https://developers.google.com/chrome-developer-tools/docs/console)
* [Chrome DevTools -- Debugging JavaScript](https://developers.google.com/chrome-developer-tools/docs/javascript-debugging)

---
## 单元测试
### REF
* [mocha](http://visionmedia.github.io/mocha/)
* [mocha github source code](https://github.com/visionmedia/mocha)

---
## 跨域请求
* [JSONP](http://en.wikipedia.org/wiki/JSONP)
* [通过iframe实现跨域通信](http://blog.leezhong.com/tech/2011/01/25/iframe-crossdomain.html)
* [iframe跨域通信的通用解决方案--腾讯](http://www.alloyteam.com/2012/08/lightweight-solution-for-an-iframe-cross-domain-communication/)