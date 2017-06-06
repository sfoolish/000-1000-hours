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

```bash
function download_url()
{
    FILE_URL=$1
    while true; do
        curl --connect-timeout 10 -C - -O $FILE_URL > /dev/null 2>&1
        if [ $? == 0 ]; then
            break
        fi
        # if the file finish the download the curl command will print
        # curl: (33) HTTP server doesn't seem to support byte ranges. Cannot resume.
        curl --connect-timeout 10 -C - -O $FILE_URL 2>&1 | grep "Cannot resume." > /dev/null
        if [ $? == 0 ]; then
            break
        fi
    done
}
```

```bash
# copy from apex
# $1 = download url
# $2 = filename to write to
function curl_file {
    local count=0
    if [ -f $CACHE_DIR/$2 ]; then
        echo "Removing stale $2"
        rm -f $CACHE_DIR/$2
    fi
    echo "Downloading $1"
    echo "Cache download location: $CACHE_DIR/$2"
    until curl -C- -L -o $CACHE_DIR/$2 $1  || (( count++ >= 20 )); do
        echo -n '' #do nothing, we just want to loop
    done
    sed -i "/$2/d" $CACHE_DIR/$CACHE_HISTORY
    echo "$(md5sum $CACHE_DIR/$2) $2" >> $CACHE_DIR/$CACHE_HISTORY
}
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
