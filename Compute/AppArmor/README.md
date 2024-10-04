# AppArmor

AppArmor is a linux security module (LSM) that provides mandatory access control (MAC) to limit what containers can do on the host system. An example of this might be limiting the ability of a container to write to disk.

## Usage

In order to use AppArmor, the underlying node must support it. Because it is a kernel module, it requires installing and enabling it on the node itself. 

Install the required packages:

```
sudo apt update
sudo apt install apparmor apparmor-utils
```

Enable AppArmor:

```
sudo systemctl enable apparmor
sudo systemctl start apparmor
sudo modprobe apparmor
```

Check Status:

```
sudo apparmor_status
```

Apply the example configuration that contains the AppArmor config:

`kubectl apply -f apparmor-disk-write-pod.yaml`
