# NetworkPolicy

K8s NetworkPolicies are a resource of the kind `NetworkPolicy`. They act as a firewall for blocking/allowing traffic between pods within a k8s cluster. Their are multiple types used, and the Calico CNI extends their functionality to allow more granular control. It's important to remember that the NetworkPolicy is applied to pods, and does not care about the service fronting it. A `Service` in k8s is just an IP tables rule that ultimately forwards traffic to a pod.

For more information, visit the the [Official Kubernetes Documentation](https://kubernetes.io/docs/concepts/services-networking/network-policies/).

## Files

`allow-client.yaml` - allows a client pod to send traffic (Egress) to a target pod based on namespace and pod selector

`client-pod.yaml` - test client pod

`default-deny-all.yaml` - default policy applied to the cluster that denies everything. Similar to the explict deny rule seen on firewalls

`ingress-nginx.yaml` - allow ingress pod to receive traffic (Ingress) from the client pod

`ingress.yaml` - ingress pod

`calico-example.yaml` - example of a Calico network policy

## Usage

Apply this example by first applying the `default-deny-all` policy. This will block all traffic within the cluster, and should be the default when standing up new clusters. This allows you to build your allow rules with a default-deny backing any traffic now allowed.

Then, apply the `ingress-nginx` and `allow-client` policies to allow traffic going from the client to nginx pod.

Finally, apply the `ingress.yaml` and `client-pod` to deploy the actual workload pods.