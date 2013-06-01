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