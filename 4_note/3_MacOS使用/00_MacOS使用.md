## 常用技巧

### Mac 常用快捷键汇总

* CMD + W               关闭子页面
* CMD + T               创建 TAB
* CMD + 空格键           输入法切换
* Shift + Alt/Option    音量微调（1/4）
* Shift + CMD + 3       截全屏保存到桌面
* Shift + CMD + 4       截屏指定区域保存到桌面

### spotlight

* 打开Spotlight菜单：Control+空格
* 在Finder中打开Spotlight：Command + F
* 清空Spotlight搜索框：ESC
* 关闭Spotlight菜单：ESC按两次

### Activity Monitor

activity monitor 相当于 MacOS 下的任务管理器，可用于查看内存，CPU，网络等的使用情况。
此外，可以在控制台下输入命令 `top -o rsize` 来安内存使用来进行进程排序。

### Mac OSX 10.9 多桌面创建

1. 在触摸板上4指向上推。进入Mission Control。
2. 将鼠标移到屏幕右上角。就能看到一个新增的桌面出现，并且上面有个加号。点击就能添加桌面了。

### [使用键盘恢复最小化到Dock上的程序窗口](http://www.macx.cn/thread-1011644-1-1.html)
    
    cmd + tab激活程序切换
        -> 按住cmd不放按tab（shift + tab）选中程序 
            -> 松开tab，按住cmd不放的同时按住opt（alt）
                -> 松开cmd

### [App can't be opened because it is from an unidentified developer](http://stackoverflow.com/questions/19551298/app-cant-be-opened-because-it-is-from-an-unidentified-developer)

System Preferences --> Security & Privacy --> General tab --> Allow apps downloaded from Anywhere

### Mac PDF Skim

修改 pdf 文档背景色

defaults write -app skim SKPageBackgroundColor -array 0.78 0.93 0.80 1

http://apple.stackexchange.com/questions/84999/change-background-colour-for-pdf-when-viewing

## Flux 显示器配置眼镜保护

* Flux: https://justgetflux.com/