../qemu/build/qemu-system-x86_64 \
	-cpu qemu64 -smp 2 -m 9G \
	-kernel ../linux/arch/x86_64/boot/bzImage \
	-append "console=ttyS0 nokaslr root=/dev/vda rootwait" \
	-initrd ../files/initramfs.cpio.gz -nographic \
	-device nvme,serial=deadbeef,drive=image \
	-enable-kvm \
	-drive if=none,id=image,file=../files/virtio_blk.img,format=raw \
	-netdev user,id=net0,hostfwd=tcp::5555-:22 -device virtio-net-pci,netdev=net0 \
	-device vhost-vsock-pci,guest-cid=123 \
