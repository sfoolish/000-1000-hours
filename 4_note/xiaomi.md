---
# 小米，为发烧而生
---

## 2013-06-01
小米手机正式开玩。

一堆下载：

* [Android SDK](http://developer.android.com/sdk/index.html)
* [Snapdragon SDK for Android Download & Installation](https://developer.qualcomm.com/mobile-development/mobile-technologies/snapdragon-sdk-android/download)

---
### adb 连接小米
#### sdk platform tools 导出环境变量
    $ export PATH=$PATH:/path/to/adt-bundle-mac-x866_64-20130522/sdk/platform-tools
#### 直接 adb 找不到设备
    $ adb devices
    ```
        List of devices attached
    ```
#### usb idVendor 配置
    ## 小米 usb idVendor 为 0x2717
    $ echo "0x2717" > ~/.android/adb_usb.ini
    $ adb kill-server
    $ adb start-server
    $ adb devices
    ```
        List of devices attached
        1edb526a        offline
    ```
#### 手机设置开发模式
    设置 --> 开发者选项 --> 开启开发者选项
    $ adb devices
    ```
        List of devices attached
        1edb526a        device
    ```
    $ adb shell
    ```
        shell@android:/ $ pwd 
        /
    ```
#### REF
* [Android Adb Commands](http://adbshell.com/)
* [Mac OS X下Android系统M2、华为部分手机无法连接问题之解决方案](http://blog.csdn.net/esonpo/article/details/8798594)
* [苹果Macbook上adb无法识别米2的解决办法](http://blog.tisa7.com/tech/solve_the_problem_of_debug_mi2_in_mac_os.html)

---
### 刷机进行时
默认稳定版不能 root ，刷个最新的开发板 miui_MiTwo_3.5.31_fastboot_4.1_2us2nblsbo.exe 。
系统备份

进入fastboot模式

　　米2：将手机关机后，按住“电源键+音量减”进入fastboot模式，并连接数据线（如果要退出fastboot模式，按住电源键10秒左右即可退出）;

　　米1：将手机关机后，按住“电源键+音量减+米键”进入fastboot模式，并连接数据线

#### REF
* [【小米刷机流程全攻略】新手必读](http://www.xiaomi.cn/content-19-10673-1.html)
* [小米手机刷机工具MiFlash](http://www.xiaomi.cn/content-55-2559-1.html)
* [小米手机1/1S/2/2s/2a 各版 线刷包 资源下载](http://bbs.xiaomi.cn/thread-7084703-1-1.html)
* [刷机常用知识](http://bbs.xiaomi.cn/thread-4313759-1-1.html)
* [小米手机刷机工具下载及教程](http://www.xiaomi.cn/content-19-12884-1.html)

---
### 运行原生 C 程序
#### 编辑，编译，下载 hello 测试程序
    ϟSF-Hacking: ~
    $ vim hello.c 
    
    ϟSF-Hacking: ~
    $ cat hello.c    
    # include <stdio.h>
    
    int main(int argc, char *argv[])
    {
            printf("hello xiaomi!\n");
    
            return 0;
    }
    
    ϟSF-Hacking: ~
    $ arm-none-linux-gnueabi-gcc hello.c -o hello -static
    
    ϟSF-Hacking: ~
    $ adb push hello /dev/                               
    4324 KB/s (2770056 bytes in 0.625s)
    
    ϟSF-Hacking: ~
#### 测试 hello 程序
    ϟSF-Hacking: ~
    $ adb shell
    shell@android:/ $ su
    shell@android:/ #
    shell@android:/ # /dev/hello
    ```
        hello xiaomi! 
    ```
#### 杂项
##### 为什么 将文件放在 /dev 下 
/dev 文件夹，挂载的是基于内存的文件系统 tmpfs ，将测试程序放在这个目录，手机重启后不影响任何使用。

    shell@android:/ # mount
    ```
    ...
        tmpfs /dev tmpfs rw,nosuid,relatime,mode=755 0 0
    ```
##### 为什么静态编译
程序运行时，不用依赖任何动态库。 android 用的是google自家的 C 库。

---
## 2013-05-29
拿到机子，充电。。。
## 2013-05-28
手机发货
## 2013-05-27
http://mall.10010.com/ 下单小米 2s 。

    您于2013.05.27提交的信用卡分期 付款申请已经通过审核！
    ----------------------------------------------
    商品名： 小米2S 4核1.7GHz 800万
    订单金额：   2,099.00元
    分期期数：   12期
    提交时间：   2013.05.27

其实，我现在还不是米粉，半个果粉，嘿嘿。买小米的理由是，还算便宜，性能强悍。