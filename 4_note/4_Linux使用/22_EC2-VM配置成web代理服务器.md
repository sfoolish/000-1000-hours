# 将 AWS EC2 VM 配置成 web 代理服务器

## squid 代理安装

	<apple>$ ssh -i ~/.ssh/sf-mac.pem  ubuntu@ec2-xx-xx-xx-xx.ap-southeast-1.compute.amazonaws.com
	<ubuntu>$ sudo apt-get install squid

## 隧道建立

将远程的 3128 映射到本地的 8080

	<apple>$ ssh -f -NC -o ServerAliveInterval=60 -i ~/.ssh/sf-mac.pem -L 8080:localhost:3128 ubuntu@ec2-xx-xx-xx-xx.ap-southeast-1.compute.amazonaws.com

## chrome foxyproxy 安装

先系统全局代理设置，然后安装 chrome foxyproxy 扩展，安装好后配置 foxyproxy， squid 映射到本地的端口是 8080 。
