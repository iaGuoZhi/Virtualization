../qemu/build/qemu-system-x86_64 \
	-cpu qemu64 -smp 2 -m 2G \
	-kernel ../guest/arch/x86_64/boot/bzImage \
	-append "console=ttyS0 nokaslr root=/dev/vda rootwait" \
	-initrd ../files/initramfs/initramfs.cpio.gz -nographic \
	-device virtio-blk,drive=image \
	-enable-kvm \
	-drive if=none,id=image,file=../files/virtio_blk.img,format=raw \
	-netdev user,id=net0,hostfwd=tcp::5555-:22 -device virtio-net-pci,netdev=net0 \
	-device vhost-vsock-pci,guest-cid=123 \
