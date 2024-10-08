# Priviledge Escalation

Privilege escalation occurs when a user or process attempts to escalate it's own priviledges. This can be done via the setuid/setgid bit, where a process attempts to run as a UID with more permissions than required.

To deal with this, the `allowPrivilegeEscalation` setting in a `securityContext` must be set to false.

## Files

`pod-escalation.yaml` - pod that runs the C program

`test-setuid.c` - sample C program that attempts to `setuid` itself to root

## Usage

The pod doesn't explictly run the C program, as it must be compiled for the appropriate architecture. In thie example, first start up the pod:

`kubectl apply -f pod-escalation.yaml`

Normally we would mount the C program as a volume in the container, however these examples are typically run on kind and therefore the hostPath is not really the host but a docker container. To avoid complexity, exec into the pod directly:

`kubectl exec -it myapp1 -- bin/bash`

Update and instal gcc:

`apt update`
`apt install gcc`

Add the contents of the `test-setuid.c` file into `test-setuid.c` in the container using `cat <<EOT > test-setuid.c`

Compile:

`gcc -o test-setuid test-setuid.c`

Now, you need to give it a proper permissions to run `setuid`:

`chmod 777 test-setuid`

`chmod u+s test-setuid`

You also must create a user to run it as that is not root:

`useradd test-user`

Switch to the user:

`su test-user`

Attempt to run the executable. It will print out who is running it, in this case it is `test-user`. The program then attempts to escalate it's permissions to root, which fails due to our preventative control applied. 