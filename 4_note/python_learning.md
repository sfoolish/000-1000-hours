# 2013-01-26
## [How do I start a session in a Python web application?](http://stackoverflow.com/questions/1185406/how-do-i-start-a-session-in-a-python-web-application/1185437#1185437)
[Wikipedia](http://en.wikipedia.org/wiki/Session_cookie) is always a good place to start. Bottom line: session data gets stored somewhere on the server and indexed by a unique identifier (hash of some sort). This identifier gets passed back and forth between the client and server, usually as a cookie or as part of the query string (the URL). For security's sake, you'll want to use an SSL connection or validate the session ID with some other piece of data (e.g. IP address). By default PHP stores sessions as files, but on a shared server that could pose a security risk, so you might want to override the session engine so you store sessions in a database. Python web frameworks have similar functionality.

[Beaker](http://beaker.groovie.org/) is a library for caching and sessions for use with web applications and stand-alone Python scripts and applications. It comes with WSGI middleware for easy drop-in use with WSGI based web applications, and caching decorators for ease of use with any Python based application.

# 2013-01-23
## python 中文使用
直接上代码：

    #!/usr/bin/python
    # -*- coding: utf-8 -*-
    
    s='测试'
    print s
    print s.decode('utf-8').encode('gbk')
    
    path = './文件.txt'
    spath = unicode(path, 'utf-8')
    f = open(spath, 'r')
    print f.read()
[PEP 0263 -- Defining Python Source Code Encodings](www.python.org/dev/peps/pep-0263)

## [Understanding Python decorators](http://stackoverflow.com/questions/739654/understanding-python-decorators)
Decorators are wrappers which means that they let you execute code before and after the function they decorate without the need to modify the function itself.
    
    def makebold(fn):
        def wrapped():
            return "<b>" + fn() + "</b>"
        return wrapped
    
    def makeitalic(fn):
        def wrapped():
            return "<i>" + fn() + "</i>"
        return wrapped
    
    @makebold
    @makeitalic
    def hello():
        return "hello world"
    
    print hello() ## returns <b><i>hello world</i></b>

# 2013-01-20
## python-guid
    $ mkdir python-guide-git && cd python-guide-git
    $ git clon https://github.com/kennethreitz/python-guide.git .
    $ sudo apt-get install python-sphinx
    $ make                        ## 生成的文档在 doc/_build/ 下。
[python-guide](http://docs.python-guide.org), python best practices guidebook, written for Humans.

## [Google Python Style Guide](http://google-styleguide.googlecode.com/svn/trunk/pyguide.html)
  - Function and Method Decorators   ??
  - Access Control                   ??

## [A guide to Python packaging](http://www.ibm.com/developerworks/opensource/library/os-pythonpackaging/index.html)

## pip 通过代理下载软件包
    $ sudo pip --proxy=127.0.0.1:8087 install -r requirements.txt

# 2013-01-19
## virtualenv 使用
之前提到过 pip 安装 virtualenv ，这里直接使用源码

    $ wget http://pypi.python.org/packages/source/v/virtualenv/virtualenv-1.8.4.tar.gz
    $ tar xvf virtualenv-1.8.4.tar.gz
    $ sudo python virtualenv-1.8.4/virtualenv.py ENV  # 创建虚拟环境
    $ #sudo virtualenv ENV                            # pip 安装的，直接使用 virtualenv 命令
    $ source ENV/bin/activate                         # 激活虚拟环境
    $ deactivate                                      # 退出虚拟环境
上面创建虚拟环境的时候需要 sudo ，否则可能会有问题。原因是 python pip 安装的时候，用户权限没处理好。暂时先这样用，以后抽空查一下。有了虚拟环境，就可以不用害怕破坏系统的原始环境。

***
VirtualEnv用于在一台机器上创建多个独立的python运行环境

使用 VirtualEnv 的理由
* 隔离项目之间的第三方包依赖
* 为部署应用提供方便，把开发环境的虚拟环境打包到生产环境即可
* 解决库之间的版本依赖，比如同一系统上不同应用依赖同一个库的不同版本。
* 解决权限限制，比如你没有root权限。
* 尝试新的工具，而不用担心污染系统环境。 

使用说明：
安装： sudo easy_install virtualenv
* 建立新的运行环境：virtualenv <env-name>
* 进入相应的独立环境：source <env-path>/bin/activate

# 2013-01-07
## 基于 Google App Engine 的 doudou 网
[创建 GAE APP](https://appengine.google.com/): APP ID doudou-sfoolish

本地测试：

    $ dev_appserver.py doudou/
代码部署：
    
    $ appcfg.py update doudou/
上传失败的时候，通过 rollback 进行恢复。

    $ appcfg.py help rollback
    $ appcfg.py rollback doudou
部署成功后就能访问[doudou](http://doudou-sfoolish.appspot.com/)

[doudou 源码](https://github.com/sfoolish/doudou)
# 2013-01-03
## [Python-2.7.3](http://www.python.org/ftp/python/2.7.3/Python-2.7.3.tar.bz2)源码编译
    $ wget http://www.python.org/ftp/python/2.7.3/Python-2.7.3.tar.bz2
    $ tar xvf Python-2.7.3.tar.bz2 
    $ cd Python-2.7.3
    $ ./configure --prefix=/Users/apple/APP_PRJ/d_python/3_Python-2.7/install
    $ make -j4
    $ make install
    $ export PATH=/Users/apple/APP_PRJ/d_python/3_Python-2.7/install/bin:$PATH
    $ python
        > Python 2.7.3 (default, Jan  3 2013, 16:15:14) 
        > [GCC 4.2.1 (Apple Inc. build 5666) (dot 3)] on darwin
        > Type "help", "copyright", "credits" or "license" for more information.
        > >>> quit()

注：为了避免对原有 python 的干扰，通过环境变量进行切换 python 执行程序。

    $ pwd
        > /Users/apple/APP_PRJ/d_python
    $ cat .export_path 
        > export PATH=/Users/apple/APP_PRJ/d_python/3_Python-2.7/install/bin:$PATH
    $ source .export_path 

##  package manager 安装
### [EasyInstall](http://en.wikipedia.org/wiki/EasyInstall)安装
    $ wget http://pypi.python.org/packages/2.7/s/setuptools/setuptools-0.6c11-py2.7.egg#md5=fe1f997bc722265116870bc7919059ea
    $ sh setuptools-0.6c11-py2.7.egg --help
    $ sh setuptools-0.6c11-py2.7.egg --prefix=/Users/apple/APP_PRJ/d_python/3_Python-2.7/install/

    ## 上面几步后easy_install 无法正常使用
    $ wget http://python-distribute.org/distribute_setup.py
    $ python distribute_setup.py
    [ref](http://pypi.python.org/pypi/setuptools)

### [Pip](http://en.wikipedia.org/wiki/Pip_%28Python%29)安装
    $ easy_install pip

### virtualenv 安装
    $ easy_install virtualenv
    or
    $ pip install virtualenv
    ## $ pip uninstall virtualenv
    ## 安装的 vitrualenv 不好用
[virtualenv: python的沙盒环境](http://iamsmallka.blog.163.com/blog/static/72703637201151994232351/)

## Google App Engine
- [GAE SDK Python](https://developers.google.com/appengine/downloads#Google_App_Engine_SDK_for_Python)
- [在GAE(Google App Engine)上搭建python2.7的web.py程序](http://blog.csdn.net/five3/article/details/7848748)

# 2012-09-26
## ubuntu 12.04 下测试tornado
    $ mkdir -p 2_tornado/1_tornado_git
    $ cd 2_tornado/1_tornado_git
    $ git clone https://github.com/facebook/tornado.git .
    $ export PYTHONPATH=$PYTHONPATH:/home/sfoolish/share/2_tornado/1_tornado_git
    $ cat hello_tornado.py
        >    import tornado.ioloop
        >    import tornado.web
        >
        >    class MainHandler(tornado.web.RequestHandler):
        >        def get(self):
        >            self.write("Hello, world !")
        >       
        >    application = tornado.web.Application([
        >        (r"/", MainHandler),
        >    ])
        > 
        >    if __name__ == "__main__":
        >        application.listen(8888)
        >        tornado.ioloop.IOLoop.instance().start()

    $ python hello_tornado.py
