---
## [How to Install (on Windows, Macs, Ubuntu) and Get Started with SQL](http://www.ntu.edu.sg/home/ehchua/programming/sql/MySQL_HowTo.html)
启动服务器：

    $ sudo ./mysqld_safe --console
关闭服务器：

    $ sudo ./mysqladmin -u root [-p] shutdown 
客户端登入：

    $ mysql -u username      # 不带密码
    $ mysql -u username -p   # 带密码
用户查看：

    mysql> select host, user, password from mysql.user;
密码设置：

    mysql> set password for 'username'@'127.0.0.1'=password('xxxx');
用户创建：

    mysql> create user 'myuser'@'localhost' identified by 'xxxx';

用户权限设置：
    
    mysql> grant all on *.* to 'myuser'@'localhost';

常用 MySQL 命令：

    -- General
    STATUS      -- Displays status such as port number
    ;           -- Sends command to server for processing (or \g)
    \c          -- Cancels (aborts) the current command
    \G          -- Displays the row vertically
     
    -- Database-level
    DROP DATABASE databaseName                 -- Deletes the database
    DROP DATABASE IF EXISTS databaseName       -- Deletes only if it exists
    CREATE DATABASE databaseName               -- Creates a new database
    CREATE DATABASE IF NOT EXISTS databaseName -- Creates only if it does not exists
    SHOW DATABASES                             -- Shows all databases in this server
       
    -- Set current (default) database.
    -- Otherwise you need to use the fully-qualified name, in the form 
    --   of "databaseName.tableName", to refer to a table.
    USE databaseName
    SELECT DATABASE();       -- show the current database
       
    -- Table-level
    DROP TABLE tableName
    DROP TABLE IF EXISTS tableName
    CREATE TABLE tableName (column1Definition, column2Definition, ...)
    CREATE TABLE IF NOT EXISTS tableName (column1Definition, column2Definition, ...)
    SHOW TABLES              -- Shows all the tables in the default database
    DESCRIBE tableName       -- Describes the columns for the table
    DESC tableName           -- Same as above
       
    -- Record-level (CURD - create, update, read, delete)
    INSERT INTO tableName VALUES (column1Value, column2Value,...)
    INSERT INTO tableName (column1Name, ..., columnNName) 
       VALUES (column1Value, ..., columnNValue)
    DELETE FROM tableName WHERE criteria
    UPDATE tableName SET columnName = expression WHERE criteria
    SELECT column1Name, column2Name, ... FROM tableName 
       WHERE criteria
       ORDER BY columnAName ASC|DESC, columnBName ASC|DESC, ...
      
    -- Running a script of MySQL statements
    SOURCE full-Path-Filename

数据库备份：

    $ mysqldump -u myuser -p --databases studentdb > backup_studentdb.sql

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

---
## mysql ubuntu12.04 下源码编译
    $ sudo apt-get source mysql-server-core-5.5
    $ sudo apt-get install cmake
    $ sudo apt-get install libncurses5-dev
    $ cmake . -DCURSES_LIBRARY=/usr/lib/libncurses.so -DCURSES_INCLUDE_PATH=/usr/include

### REF
* [解决Could NOT find Curses (missing: CURSES_LIBRARY CURSES_INCLUDE_PATH)](http://www.cnblogs.com/rooney/archive/2012/06/19/2554581.html)

