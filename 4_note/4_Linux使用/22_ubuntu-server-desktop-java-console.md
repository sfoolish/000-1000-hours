## ubuntu 14.04 server install Desktop

	sudo apt-get install xorg gnome-core gnome-system-tools gnome-app-install

### install jre on ubuntu

    # download jre-8u101-linux-x64.tar.gz
    JAVA_HOME=/home/ubuntu/Downloads/jre1.8.0_101
    PATH=$PATH:$HOME/bin:$JAVA_HOME/bin

### install java console plugin

root@ubuntu4:/usr/lib/mozilla/plugins# ln -s /home/ubuntu/Downloads/jre1.8.0_101/lib/amd64/libnpjp2.so .

Type about:plugins check if the Java Plugin is loaded

### REF

http://www.oracle.com/technetwork/java/javase/manual-plugin-install-linux-136395.html

To install the Java Plugin follow these steps:

1. Exit Firefox.

2. Uninstall any previous installations of Java Plugin.

Only one Java Plugin can be used at a time. When you want to use a different plugin, or version of a plugin, remove the symbolic links to any other versions and create a fresh symbolic link to the new one.

Remove the symbolic links (or move them to another directory) to javaplugin-oji.so and libnpjp2.so from the Firefox plugins directory.

3. Create a symbolic link to the Java Plugin in the Firefox plugins directory.

Create a symbolic link to the Java Plugin libnpjp2.so file in the Firefox plugins directory:

    cd  
              
<Firefox>/plugins
    ln -s  
              
<JRE>/lib/i386/libnpjp2.so . 
            
4. Start the Firefox browser .

Type about:plugins in the Location bar to confirm that the Java Plugin is loaded. You can also click the Tools menu to confirm that Java Console is there.
