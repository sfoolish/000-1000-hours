## openvpn mac install

    brew install Caskroom/cask/tuntap
    brew install openvpn

    curl http://swupdate.openvpn.org/community/releases/openvpn-2.3.6.tar.gz \
    	-o openvpn-2.3.6.tar.gz 
    openvpn-2.3.6.tar.gz
    tar  xvf openvpn-2.3.6.tar.gz 
    cd openvpn-2.3.6
    ./configure 
    make
    # openvpn client 路径：
    openvpn-2.3.6/src/openvpn/openvpn

## run openvpn on mac

    sudo killall openvpn
    sleep 2
    sudo ./openvpn --config client.conf --daemon ovpn-client --script-security 2
    # sleep 20
    # sudo ifconfig utun0 mtu 1300
    # sudo route -nv add -net 192.168.50.1 -netmask 255.255.255.0 -interface utun0
    # netstat -r
    # sudo route -nv delete -net 192.168.50.1 -netmask 255.255.255.0 -interface utun0

## run openvpn on ubuntu 

	/usr/sbin/openvpn --writepid /run/openvpn/client.pid --daemon ovpn-client —status /run/openvp/client.status 10 --cd /etc/openvpn --config /etc/openvpn/client.conf --script-security 2

## REF

* http://m.blog.csdn.net/blog/u014761344/39505747
* http://swupdate.openvpn.org/community/releases/

