---
## 常用工具安装
    # apt-get install git
    # git clone git clone https://github.com/facebook/tornado.git

## python virtualenv 环境
    # apt-get install python-setuptools
    # easy_install virtualenv
    # easy_install pip
    
    # cd prj/python/
    # mkdir vir_test
    # virtualenv vir_test/
    # source vir_test/bin/activate
    
    # deactivate 

---
## tornado 测试
    # cat ~/.python_sf_dev
        cd /root/prj/python
        source vir_test/bin/activate
    # source ~/.python_sf_dev
    # pip install tornado 
    
    # cat hello_tornado.py
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
    # python hello_tornado.py

## OSS 相关介绍
* [访阿里云大规模存储“铁三角”：OSS、RDS与OTS](http://www.csdn.net/article/2012-11-16/2811959-Interview-aliyun-OSS-RDS-OTS)
* [阿里云存储OSS之九大使用技巧](http://www.programmer.com.cn/12917/)

---
## systemtap 安装
参照[systemtap 安装步骤](https://github.com/sfoolish/000-1000-hours/blob/master/4_note/tools/systemtap.md#2013-03-04-ubuntu-1204--systemtap)

遇到两个问题：内核连接时内存不足`ld: final link failed: Memory exhausted`；ssh 超时退出导致内核编译无法正常结束。具体处理方法如下。
### 添加 swap 分区，解决内核编译过程中内核不足问题
    # dd if=/dev/zero of=/mnt/512Mb.swap bs=1M count=512
    # mkswap /mnt/512Mb.swap
    # swapon /mnt/512Mb.swap

    # swapoff /mnt/512Mb.swap
    # rm /mnt/512Mb.swap
ref: [如何设置Ubuntu的swap区](http://blog.csdn.net/chenyongxinglove/article/details/5883315)

### ssh 设置发送心跳参数，解决登陆超时问题
    # ssh -o ServerAliveInterval=60 root@42.x.x*x
