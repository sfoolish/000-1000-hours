# ssh 配置

## ssh key 配置

```bash
ssh-copy-id remote-server.org
ssh-copy-id -i ~/.ssh/id_ecdsa.pub -p 221 username@remote-server.org
```

## hosts 配置

```console
# cat /etc/hosts
192.168.108.2   a8 a108
192.168.21.2    a2
192.168.21.20   a20
192.168.21.21   a21
192.168.107.2   vpod1
192.168.106.2   vpod2
192.168.101.2   vpod3
192.168.103.2   vpod4
192.168.10.6    pod1
192.168.11.2    pod2
```

## ssh tunnel / port forwarding

```bash
ssh -L 0.0.0.0:3128:192.168.21.2:3128 root@a2
```

```bash
ssh -i ~/.minikube/machines/minikube/id_rsa \
    -L 0.0.0.0:8443:$(minikube ip):8443 \
    docker@$(minikube ip)
```

## References

* https://wiki.archlinux.org/index.php/SSH_keys_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)

## 手机代理配置

* [iPhone proxy 配置](http://jingyan.baidu.com/article/adc815134d2294f722bf7347.html)
