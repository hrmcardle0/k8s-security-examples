# Pod Security Admission

The [Pod Security Admission](https://kubernetes.io/docs/concepts/security/pod-security-admission/) controller is an admission controller that can be used to enforce a set of [pod security standards](https://kubernetes.io/docs/concepts/security/pod-security-standards/) across a namespace.


# Usage

The admission controller is transparent to the user, and will not show up in the k8s cluster by using kubectl. 

In order to test this, you must first label the namespace to enforce the restricte set of pod security standards:

`kubectl label namespace secure-namespace pod-security.kubernetes.io/enforce=restricted`

Attempt to apply the vulnerable pod, which will result in getting rejected:

`kubectl apply -f pod-root.yaml`