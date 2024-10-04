# Kubernetes Security Examples

A repository containing various examples of how common Kubernetes security configurations are implemented. The examples in this project are using a [Kind Cluster](https://kind.sigs.k8s.io/) but most are applicable to standard Kubernetes clusters. 

The goal of this repo is to create a central place to store example configurations that can be directly applied to your cluster as simply as possible. Ideally, you can `kubectl apply` anything in project and have it up and running for observation quickly. 

## Requirements

The following requirements are expected to be installed and in-place before implementing these examples.

- Docker
- Kubectl
- [Kind Cluster](https://kind.sigs.k8s.io/) - sets up a local Kubernetes cluster running on Docker. This is the most efficient and recommended vs minikube due to the ability to customize and implement a varying number of nodes for a more production-like cluster
- [Calico CNI](https://github.com/projectcalico/calico) - required to fine tune `NetworkPolicy`

## Structure

The folder structure will be implemented as follows:

    .
    ├── Network/                        # high level category
    │   └── NetworkPolicy/             # one complete implementation component
    │       ├── (various yaml files)    # yaml configuration files to directly apply to k8s cluster
    │       └── README.md               # details, links to documentation and instructions for implelmenting
    ├── Kind/                           # Kind cluster configuration
    |   ├── kind.yaml
    |   └── bootstrap.sh                # bootstrap Kind cluster
    └── README.md


## Usage

```
# clone repo
git clone https://github.com/hrmcardle0/k8s-security-examples.git`

# bootstrap kind cluster
cd kind && ./bootstrap.sh

# pick a security configuration
cd NetworkPolicy

# apply yaml files
kubectl apply -f [file].yaml

# observe & test examples
kubectl exec -it [pod] -- /bin/bash # exec into a pod
touch test.text # attempt to create a file, used for testing process permissions and container hardening
curl my-blocked-svc:8080 # attempt to curl a service, used for testing network policies
openssl s_client -showcerts -connect my-tls-svc:443 </dev/null # validate pod TLS cert
 
```
