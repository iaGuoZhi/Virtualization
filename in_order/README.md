## Project description

VIRTIO\_F\_IN\_ORDER is a new feature presented in VIRTIO 1.1.
Devices and drivers can negotiate this feature when the device uses descriptors in the same order in which they were made available by the driver.
This feature can help devices and drivers batch buffers and improve performance.
Previously the devices and drivers available in Linux and QEMU do not support the VIRTIO\_F\_IN\_ORDER feature.
The only implementation is available in DPDK for the virtio-net driver.
In this project, I implemented the VIRTIO\_F\_IN\_ORDER feature in both Linux and QEMU, and support this feature for vhost\_test, vhost\_vsock, virtio-net three devices.
I sent three patches series to Linux and QEMU community in total, and they are under review at this stage.

## Project roadmap

## Patches sended

### Linux

* vhost, vsock, virtio: https://lkml.org/lkml/2022/9/1/96 
* virtio\_test: https://lkml.org/lkml/2022/7/8/1263

### QEMU

* virtio-net: https://patchwork.kernel.org/project/qemu-devel/cover/20220818151244.2050-1-qtxuning1999@sjtu.edu.cn/
