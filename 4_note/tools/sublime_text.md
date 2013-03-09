### color scheme
Windows 下 color scheme 安装方法，就是将 tmTheme 文件放到 `C:\Documents and Settings\<user>\Application Data\Sublime Text 2\Packages\Color Scheme - Default` 下。个人感觉不错的几个 color scheme:
* Espresso libre
* Monokai Bright
* Monokai
* **solarize（Dark）**
* [tomorrow-theme](https://github.com/chriskempson/tomorrow-theme/tree/master/textmate)

### 中文乱码
* Sublime Text2 目前还不支持gbk编码，UTF-8完美支持；
* sublime text2 支持 GBK 编码插件，https://github.com/akira-cn/sublime-gbk；
* UTF8 通用性比GBK要强，中文用3个字节来表示，GBK只需要两个字节；
* 它对英文使用8位（即一个字节），中文使用24为（三个字节）来编码。UTF-8包含全世界
  所有国家需要用到的字符，是国际编码，通用性强。
* GBK是国家标准GB2312基础上扩容后兼容GB2312的标准,GBK的文字编码是用双字节来表示；

### 行间距设置
	"line_padding_top": 2,
	"line_padding_bottom":2
[Sublime Text 2 设置文件详解](http://www.lupaworld.com/article-219857-1.html)