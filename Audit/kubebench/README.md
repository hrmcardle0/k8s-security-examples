# kube-bench

[kube-bench](https://github.com/aquasecurity/kube-bench) is an audit tool that runs checks against your cluster based on the CIS benchmarks. The configuration is easy as it involves standing up pods as jobs that run various audit scripts.

The audits run based on the type of node, meaning there is an audit for the master control-plane nodes and an audit for the worker nodes. The output can be formatted for consumption via fluentd or some other metric/data ingestion method.

## Usage

Run the control-plane audit:

`kubectl apply -f kube-bench/job-master.yaml`

Run the worker-node audit:

`kubectl apply -f kube-bench/job-node.yaml`