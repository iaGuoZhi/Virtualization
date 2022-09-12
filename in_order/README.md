## Project description

VIRTIO\_F\_IN\_ORDER is a new feature presented in VIRTIO 1.1.
Devices and drivers can negotiate this feature when the device uses descriptors in the same order in which they were made available by the driver.
This feature can help devices and drivers batch buffers and improve performance.
Previously the devices and drivers available in Linux and QEMU do not support the VIRTIO\_F\_IN\_ORDER feature.
The only implementation is available in DPDK for the virtio-net driver.
In this project, I implemented the VIRTIO\_F\_IN\_ORDER feature in both Linux and QEMU, and support this feature for vhost\_test, vhost\_vsock, virtio-net three devices.
I sent three patches series to Linux and QEMU community in total, and they are under review at this stage.

## IN ORDER feature demystified

## Project roadmap

- [x] Enhance virito\_test and vhost\_test to support random batch size and random chain length. [link](https://lkml.org/lkml/2022/7/8/1263)
- [x] Add in order feature test in virtio\_test. [link](https://lkml.org/lkml/2022/7/8/1263)
- [x] Support in order feature for split virtqueue. [link](https://lkml.org/lkml/2022/9/1/96)
- [x] Support in order feature combined with indirect feature. [link](https://lkml.org/lkml/2022/9/1/96)
- [x] Pass vhost\_test. [link](https://lkml.org/lkml/2022/9/1/96)
- [x] Support in order feature for vhost\_vsock device. [link](https://lkml.org/lkml/2022/9/1/96)
- [x] Support in order feature for virtio-net device in QEMU. [link](https://lkml.org/lkml/2022/9/1/96), [link](https://patchwork.kernel.org/project/qemu-devel/cover/20220818151244.2050-1-qtxuning1999@sjtu.edu.cn/)
- [ ] Measure performance.
- [ ] Support in order feature for packed virtqueue.
- [ ] Cross test with DPDK.

## Patches sent

### Linux

* [vhost, vsock, virtio](https://lkml.org/lkml/2022/9/1/96)
  * Summary: this series realized IN\_ORDER prototype in virtio driver and vhost. Currently IN\_ORDER feature supported devices are *vhost_test* and *vsock* in vhost and virtio-net in QEMU. IN\_ORDER feature works well combined with INDIRECT feature in this patch series. 
* [virtio\_test](https://lkml.org/lkml/2022/7/8/1263)
  * Summary: original virtio\_test only use add one descriptor for each io event, thus code of descriptor chain and indirection have not been tested(one descriptor will not use indirect feature even indirect feature has been specified). In fact it would have not been possible for vhost\_test to access to the indirect descriptor table, because it's impossible for virtio\_ring.c to allocate it.This series fixes above problems and use descriptor chain to test virtio and enable indirection feature.

### QEMU

* [virtio-net](https://patchwork.kernel.org/project/qemu-devel/cover/20220818151244.2050-1-qtxuning1999@sjtu.edu.cn/)
  * Summary: this series realized IN\_ORDER prototype for virtio-net device in QEMU.

## Run project

Both QEMU and Linux(host and guest) source code are inside this repo as a submodule. The host kernel code is the same with guest for simplicity.
