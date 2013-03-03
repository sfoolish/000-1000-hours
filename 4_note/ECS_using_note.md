## 常用工具安装
    apt-get install git
    git clone git clone https://github.com/facebook/tornado.git

## python virtualenv 环境
    apt-get install python-setuptools
    easy_install virtualenv
    easy_install pip
    
    cd prj/python/
    mkdir vir_test
    virtualenv vir_test/
    source vir_test/bin/activate
    
    deactivate 

## tornado 测试
    cat ~/.python_sf_dev
        cd /root/prj/python
        source vir_test/bin/activate
    source ~/.python_sf_dev
    pip install tornado 
    
    cat hello_tornado.py
        import tornado.ioloop
        import tornado.web
        
        class MainHandler(tornado.web.RequestHandler):
                def get(self):
                        self.write("hello world !")
        
        application = tornado.web.Application([
                (r"/", MainHandler),
        ])
        
        if __name__ == "__main__":
                application.listen(80)
                tornado.ioloop.IOLoop.instance().start()
    python hello_tornado.py

## OSS 相关介绍
[访阿里云大规模存储“铁三角”：OSS、RDS与OTS](http://www.csdn.net/article/2012-11-16/2811959-Interview-aliyun-OSS-RDS-OTS)
[阿里云存储OSS之九大使用技巧](http://www.programmer.com.cn/12917/)
