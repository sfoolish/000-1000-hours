## [How to create a bootable USB stick on OS X](http://www.ubuntu.org.cn/download/help/create-a-usb-stick-on-mac-osx)

    # hdiutil convert -format UDRW -o ~/path/to/target.img ~/path/to/ubuntu.iso
    # diskutil list
    # diskutil unmountDisk /dev/diskN
    # sudo dd if=/path/to/downloaded.img of=/dev/rdiskN bs=1m
    # diskutil eject /dev/diskN
    # Restart your Mac and press alt/option 
