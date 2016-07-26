---
## Windows 使用记录
### win7 wireshark 使用
在 win7 下 wireshark 使用，默认需要手动启用 NPF 服务：
    
    1. 按下windows徽标键->键盘输入cmd(此时注意按下徽标键后窗口下的搜索栏内会输入你键入的cmd)，搜到cmd,->同时按下ctrl+shift+enter—>接下来的就是弹出的是否以管理员运行，一切OK了
    2. net start npf
### windows 保护色设置：
“色调”（Hue）设为85，“饱和度”（Sat）设为90，“亮度” （Lum）设为205

### Windows 窗口最小化快捷键
    Alt + 空格 --> N（是最小化） 

### 关闭不必要的服务
    System --> Administration --> Server Settings --> Services

### Foxmail 使用异常处理
Foxmail 无法创建文件，cannot create file,查看邮件空白，不能回复邮件

点“开始”-运行，输入CMD，确定，进入DOS，然后输入del C:\Documents and Settings\Administrator\Local Settings\Temporary Internet Files\*.* 命令清除Temporary Internet Files文件夹内所有文件即可使邮件恢复正常

### windows xp hosts 文件路径
    C:\WINDOWS\system32\drivers\etc\hosts

### Windwos 系统安装异常处理
    "Units specified don't exist SHSUCDX can't install"

    BIOS -> SATA MODE “AHCI” 改成“IDE”

## Windows admin run cmd

    shutdown.exe -r

## Xshell 使用技巧

* 编辑和查看快捷键
	Tools -> Options -> Keyboard and Mouse -> Key Mapping
* Ctrl+R 窗口透明切换
