# Kind

Kind is a local K8s environment that runs on top of docker, allowing the testing of K8s resources on your local machine. 

For detailed instructions, visit the [official Kind documentation](https://kind.sigs.k8s.io/docs/user/quick-start/#installation).

## Setup

Run the bootstrap script depending on your local environment. The `kind` cli does the rest by appropriately adding the context to your `KUBECONFIG` file