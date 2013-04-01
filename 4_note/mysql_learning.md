export DYLD_LIBRARY_PATH=/usr/local/mysql/lib:$DYLD_LIBRARY_PATH


  483  dscl . create /Groups/mysql
  484  sudo dscl . create /Groups/mysql
  485  sudo dscl . create /Groups/mysql gid 296
  486  sudo dscl . -create /Users/mysql
  487  dscl . append /Groups/mysql GroupMembership mysql
  488  sudo dscl . append /Groups/mysql GroupMembership mysql
  489  pwd
  490  chown -R mysql .
  491  sudo chown -R mysql .
  492  ls -al
  493  sudo chgrp -R mysql .
  494  ./scripts/mysql_install_db --user=mysql
  495  sudo ./scripts/mysql_install_db --user=mysql
  496  cd ../
  497  ln -s ~/APP_PRJ/j_mysql/mysql-5.5.29-osx10.6-x86_64/ /usr/local/mysql
  498  sudo ln -s ~/APP_PRJ/j_mysql/mysql-5.5.29-osx10.6-x86_64/ /usr/local/mysql
  499  vim ~/.profile 
  500  source ~/.bashrc 
  501  ls /usr/local/mysql/bin/
  502  vim ~/.profile 
  503  source ~/.bashrc 
  504  mysql
  505  ls
  506  cd APP_PRJ/j_mysql/mysql-5.5.29-osx10.6-x86_64
  507  ls
  508  ./support-files/mysql.server start
  509  sudo ./support-files/mysql.server start

## REF
* [mysql downloads](http://dev.mysql.com/downloads/mysql/)
* [Install MySQL on Mac OS X 10.6 and add StartupItem](http://www.tonyamoyal.com/2010/04/13/install-mysql-on-mac-os-x-10-6-and-add-startupitem/)
* [Python mysqldb: Library not loaded: libmysqlclient.18.dylib](http://stackoverflow.com/questions/6383310/python-mysqldb-library-not-loaded-libmysqlclient-18-dylib)