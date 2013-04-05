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

