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
