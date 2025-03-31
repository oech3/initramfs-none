pkgname=initramfs-none
pkgver=1
pkgrel=1
pkgdesc="Minimal and hardcoted initramfs to mount root with noatime directly"
arch=('any')
makedepends=(musl findutils cpio)
provides=(initramfs)
source=(init.c)
sha512sums=('SKIP')
build() {
	mkdir -p initramfs/mnt
	musl-gcc -O3 -march=native -s -static -o initramfs/init init.c
	cd initramfs
	find . -print | cpio -o --format=newc > ../none.img
}
package() {
	install -Dm644 none.img "$pkgdir"/boot/none.img
}
