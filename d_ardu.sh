#!/bin/bash

# Comment the line below when you are sure what this script will do to /dev/sdb
exit 0
####################################################
# Device that we will write to
DISK="/dev/sdb"
IMAGE_SIZE="700MB"
DISK_SIZE="2000MB"
# Update to the latest version
IMAGE_NAME="arduinix_0_1.img"
##################################################


if [ `whoami` != root ]
then
	echo "Please run as root"
	exit 2
fi


if [ ! -e /sbin/parted ]
then	
	echo "Unable to find parted. Please install with "
	echo "# apt-get install parted"
	exit 2
fi

if [ ! -e ${IMAGE_NAME} ]
then
	echo "Unable to find image ${IMAGE_NAME}"
	exit 2
fi

RETURN_DIR=${CWD}
umount ${DISK}1
umount ${DISK}2
time dd if=${IMAGE_NAME} of=${DISK} bs=4096k
umount ${DISK}1
time parted ${DISK} mkpart primary ext4 ${IMAGE_SIZE} ${DISK_SIZE}
time mkfs.ext4 -L persistence ${DISK}2
mount -t ext4 ${DISK}2 /mnt
echo "/home union" >> /mnt/live-persistence.conf
sync; sync
umount ${DISK}1
umount ${DISK}2
