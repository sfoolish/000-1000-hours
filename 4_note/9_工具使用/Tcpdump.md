## Tcpdump 常用参数与使用示例

### 常用参数

- 抓指定网卡的报文

```bash
# capture all the packets flowing through eth1
tcpdump -i eth1
```

- 抓指定个数的报文

```bash
# Using -c option to specify the number of packets to capture
tcpdump -c 2 -i eth1
```

- 显示报文的具体内容

```bash
# print packets in HEX format
tcpdump -xx -i eth0

# print packets in both ASCII and HEX format
tcpdump -XX -i eth0
```

- 将报文写入指定文件

```bash
# save packets to a file
tcpdump -w 20161224.pcap -i eth0
```

- 从文件中读取报文

```bash
# read packets from a file
tcpdump -r 20161224.pcap
```

- 显示 IP 地址

```bash
# display ip addr instead of host name
tcpdump -n -i eth0
```

- 抓指定协议报文

```bash
# protocols : fddi, tr, wlan, ip, ip6, arp, rarp, decnet, tcp and udp
# receive only arp packages
tcpdump -i eth0 arp
```

- 抓指定目标 IP 和 Port 的报文

```
# capture with a particular destination ip (10.1.0.12) and port number (22)
tcpdump -i eth0 dst 10.1.0.12 and port 22

# capture with a particular source ip (10.1.0.12) and port number (22)
tcpdump -i eth0 src 10.1.0.12 and port 22
```

- 过滤条件判断语句（and, or, not）

```bash
# use condition and, or, not

# capture all the packets other than arp
tcpdump -i eth0 not arp

# capture either arp or icmp packages
tcpdump -i eth0 arp or icmp
```

### 实用抓包示例

- 抓取 DHCP 相关报文

```bash
# https://www.52os.net/articles/tcpdump-capture-packages.html
tcpdump -i any udp port 68
tcpdump -ni tapbb5f0d74-ce udp port 67
```


- 抓取 vxlan 隧道报文

```bash
tcpdump -i mgmt port 4789
```

Openstack 创建的两个虚拟机间 ping 包 vxlan 隧道报文抓取

```
# vm1(10.0.1.3) on host5 ping vm2(10.0.1.4) on host4

# check vxlan tunnel
root@host5:~# ovs-vsctl show
837f4854-cc25-482d-9e63-df89b0322d57
    Bridge br-tun
        Port "vxlan-ac100101"
            Interface "vxlan-ac100101"
                type: vxlan
                options: {df_default="true", in_key=flow, local_ip="172.16.1.5", out_key=flow, remote_ip="172.16.1.1"}

# check which nic with 172.16.1.0/24 subnet
root@host5:~# ip a | grep 172.16.1 -C 2
9: mgmt@eth1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default
    link/ether 52:54:00:16:4b:34 brd ff:ff:ff:ff:ff:ff
    inet 172.16.1.5/24 brd 172.16.1.255 scope global mgmt
       valid_lft forever preferred_lft forever
    inet6 fe80::5054:ff:fe16:4b34/64 scope link

# capture the vxlan packages
root@host5:~# tcpdump -i mgmt port 4789 -xx -c 1
tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
listening on mgmt, link-type EN10MB (Ethernet), capture size 65535 bytes
22:16:08.356862 IP host5.23578 > host4.4789: VXLAN, flags [I] (0x08), vni 1092
IP 10.0.1.3 > 10.0.1.4: ICMP echo request, id 44289, seq 148, length 64
  0x0000:  5254 000c 121f 5254 0016 4b34 0800 4500
  0x0010:  0086 8167 4000 4011 5ed6 ac10 0105 ac10
  0x0020:  0104 5c1a 12b5 0072 0000 0800 0000 0004
  0x0030:  4400 fa16 3e78 e3a6 fa16 3eef fdaf 0800
  0x0040:  4500 0054 4912 4000 4001 db90 0a00 0103
  0x0050:  0a00 0104 0800 c430 ad01 0094 0d10 7929
  0x0060:  0000 0000 0000 0000 0000 0000 0000 0000
  0x0070:  0000 0000 0000 0000 0000 0000 0000 0000
  0x0080:  0000 0000 0000 0000 0000 0000 0000 0000
  0x0090:  0000 0000
```

## Reference

* http://www.thegeekstuff.com/2010/08/tcpdump-command-examples
* http://www.tcpdump.org/tcpdump_man.html
