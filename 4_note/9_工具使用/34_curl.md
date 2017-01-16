## curl 断点续传

```bash
curl -C - -O <URL>
```

## download_file with retry

```bash
function download_file()
{
    file=$1

    while true
    do
        curl -C - -O $file
        if [ $? == 0 ];then
            break
        fi
    done
}

download_file http://205.177.226.237:9999/dt/compass4nfv_dt.tar.bz2
```

## curl call keystone api

```bash
curl -H "Content-Type: application/json" -X POST -d '
{
    "auth": {
        "tenantName": "admin",
        "passwordCredentials": {
            "username": "admin",
            "password": "console"
        }
    }
}
' http://172.16.1.222:35357/v2.0/tokens \
  | python -m json.tool

export OS_TOKEN=91f81b81ea88426ab4101f793c12f78a
export OS_TENANT_NAME=e5f6e2c3734d4554a62fb86be6d4592b
curl -s -H "X-Auth-Token: $OS_TOKEN" \
  http://172.16.1.222:8774/v2/$OS_TENANT_NAME/flavors \
  | python -m json.tool
```
