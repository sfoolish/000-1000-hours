---
## 使用问题

### 中文乱码
* Sublime Text2 目前还不支持gbk编码，UTF-8完美支持；
* sublime text2 支持 GBK 编码插件，https://github.com/akira-cn/sublime-gbk；
* UTF8 通用性比GBK要强，中文用3个字节来表示，GBK只需要两个字节；
* 它对英文使用8位（即一个字节），中文使用24为（三个字节）来编码。UTF-8包含全世界
  所有国家需要用到的字符，是国际编码，通用性强。
* GBK是国家标准GB2312基础上扩容后兼容GB2312的标准,GBK的文字编码是用双字节来表示；

---
## 使用技巧

### sublime 快捷键
* Access the Command Palette:    `Shift + Command + P`
* Lightning-Fast File Switching: `Control or Command + P`
* Functions:                     `Control/Command + r`
* Go to Line Number:             `Control + g` and then `:LINE_NUMBER`

### Multi-Selection:
* Press Alt or Command and then click in each region where you require a cursor.
* Select a block of lines, and then press `Shift + Command + L`.
* Place the cursor over a particular word, and press `Control/Command + D` repeatedly to select additional occurrences of that word.
* Alternatively, add an additional cursor at all occurrences of a word by typing Alt+F3 on Windows, or Ctrl+Command+G on the Mac. Amazing!! 

### color scheme 配置
Windows 下 color scheme 安装方法，就是将 tmTheme 文件放到 `C:\Documents and Settings\<user>\Application Data\Sublime Text 2\Packages\Color Scheme - Default` 下。个人感觉不错的几个 color scheme:

* Espresso libre
* Monokai Bright
* Monokai
* **solarize（Dark）**
* [tomorrow-theme](https://github.com/chriskempson/tomorrow-theme/tree/master/textmate)
* [colour-schemes](https://github.com/daylerees/colour-schemes)

配置方法：

    {
        "color_scheme": "Packages/Color Scheme - Default/Solarized (Dark_net).tmTheme",
    }

### theme markdown 高亮配置
我用的sublime test theme是Solarized (Light).tmTheme，默认配置对Markdown支持不是很好.于是，照着[修改Sublime 新建和保存文件时的默认格式](http://imwuyu.me/blog/sublime-assign-default-file-type-and-ext.html/)中的配置修改了一下，效果不错。

theme 配置文件路径：`~/Library/Application Support/Sublime Text 2/Packages/Color Scheme - Default/Solarized (Light).tmTheme`

### 行间距配置
    {
        "line_padding_top": 2,
        "line_padding_bottom":2
    }
[Sublime Text 2 设置文件详解](http://www.lupaworld.com/article-219857-1.html)

### 字体配置
    {
        "font_face": "Monaco",
        "font_size": 14.0,
    }

---
## REF
* [Sublime Package Control](http://wbond.net/sublime_packages/package_control/installation)
* [Sublime Text 2 Tips and Tricks](http://net.tutsplus.com/tutorials/tools-and-tips/sublime-text-2-tips-and-tricks/comment-page-3/#comments)
* [sublime-text-2相关快捷键](http://www.cnblogs.com/rollenholt/archive/2012/07/30/2616089.html)
* [TmTheme Editor](http://tmtheme-editor.herokuapp.com/#/Solarized%20(dark))
* [sublime-rst-completion](https://github.com/dbousamra/sublime-rst-completion)