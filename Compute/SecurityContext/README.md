# Security Context

[Security Context](https://kubernetes.io/docs/tasks/configure-pod-container/security-context/) details various security settings for a pod or container. It can be specified on either, and provides the ability to apply more granular controls to your workloads

# Usage

The example provided is a simple pod with a `securityContext` configured that enforces certain controls. To apply the pod, run:

`kubectl apply -f pod-security-context.yaml`.

Exec into the container and observe the the processes and files to understand how the controls apply.