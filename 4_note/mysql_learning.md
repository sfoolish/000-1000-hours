---
## Install MySQL on Mac OS X 10.6
    $ dscl . create /Groups/mysql
    $ sudo dscl . create /Groups/mysql
    $ sudo dscl . create /Groups/mysql gid 296
    $ sudo dscl . -create /Users/mysql
    $ dscl . append /Groups/mysql GroupMembership mysql
    $ sudo dscl . append /Groups/mysql GroupMembership mysql
    
    $ cd ~/APP_PRJ/j_mysql/
    $ tar xvf mysql-5.5.29-osx10.6-x86_64.tar.gz
    $ cd mysql-5.5.29-osx10.6-x86_64
    $ sudo chown -R mysql .
    $ sudo chgrp -R mysql .
    $ ./scripts/mysql_install_db --user=mysql
    $ sudo ./scripts/mysql_install_db --user=mysql
    $ sudo ln -s ~/APP_PRJ/j_mysql/mysql-5.5.29-osx10.6-x86_64/ /usr/local/mysql
    $ vim ~/.profile 
    $ source ~/.bashrc 
    $ sudo ./support-files/mysql.server start

    $ export DYLD_LIBRARY_PATH=/usr/local/mysql/lib:$DYLD_LIBRARY_PATH

## REF
* [mysql downloads](http://dev.mysql.com/downloads/mysql/)
* [Install MySQL on Mac OS X 10.6 and add StartupItem](http://www.tonyamoyal.com/2010/04/13/install-mysql-on-mac-os-x-10-6-and-add-startupitem/)
* [Python mysqldb: Library not loaded: libmysqlclient.18.dylib](http://stackoverflow.com/questions/6383310/python-mysqldb-library-not-loaded-libmysqlclient-18-dylib)