# gVisor

[gVisor](https://gvisor.dev/docs/user_guide/containerd/configuration/) provides a sandbox environment for containers to run in, essentially restricting what they have access to even moreso than normal container controls.

gVisor is enabled by using using `runsc`, which is the OCI compliance runtime that gVisor uses, similiar to the standard `runc`

## Files

`runsc-sandbox.yml` - the `RuntimeClass` resource setup within K8s to allow it to use the `runsc` runtime

`non-sandbox-pod.yml` - example priviledged pod using the standard `runc` runtime

`sandbox-pod.yml` - example pod using the `runsc` runtime

## Usage

gVisor must be configured first according to [the documentation](https://gvisor.dev/docs/user_guide/containerd/configuration/).

This involves configurating the containerd runtime on your nodes.

Once configured, apply the `RuntimeClass`:

`kubectl apply -f runsc-sandbox`

Then, as an example, create the normal priviledged pod:

`kubectl apply -f non-sandbox-pod.yml`

Run the `dmesg` command to grab all kernel messages, which includes those running on the host:

`kubectl exec non-sandbox-pod -- dmesg`

This should print out a very long stream of kernel messages. Next, see what kernel messages you can get from the pod running via `runsc`:

`kubectl apply -f sandbox-pod.yml`

`kubectl exec sandbox-pod -- dmesg`

Notice how there are much fewer messages, and those specifically related to gVisor. This is because gVisor provides more protection and isolation against the host OS.