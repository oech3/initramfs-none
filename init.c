#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <fcntl.h> 

int main() {
	mknod("/dev/sda2", S_IFBLK | 0600, makedev(8, 2));
	mount("/dev/sda2","/mnt","btrfs",MS_NOATIME,(const void *)"subvol=@");
	chroot("/mnt");
	chdir("/");
	execv("/sbin/init", (char *[]) {"/sbin/init", NULL});
}
