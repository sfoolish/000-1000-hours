## curl 断点续传

    curl -C - -O <URL>

## download_file with retry

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

