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
	mount("/dev/sda2","/mnt","btrfs",MS_NOATIME,"subvol=@");
	unlink("/init"); //Is there any simple and safe method?
	//Is this already simple? syscall No for pivot_root seems unstable.
	chdir("/mnt");
	mount(".", "/", NULL, MS_MOVE, NULL);
	chroot(".");
	chdir(".");
	execv("/sbin/init", (char *[]) {"/sbin/init", NULL});
}
