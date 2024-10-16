# Gatekeeper

[Gatekeeper](https://github.com/open-policy-agent/gatekeeper) is a policy control application that allows you to enforce policies across your K8s cluster. It does so by implementing multiple CRDs, controllers and webhooks. The controllers create the policies from the CRDs, and the webhooks are called before objects are persisted to etcd in order to apply appropriate actions, such as blocking or alerting.

Policies are written in rego syntax.

## Files

`constraint-template.yaml` - template that defines the custom policy, including the name and rego syntax

`reuqired-labels.yaml` - instantiation of the policy that applies the policies to specific K8s objects, as well as passing parameters to the policies defined above

## Usage

First gatekeeper needs to be installed:

`kubectl apply -f https://github.com/open-policy-agent/gatekeeper`

Check the status of all gatekeeper pods:

`kubectl get pods -n gatekeeper-system`

Proceed to apply the constraint template:

`kubectl apply -f constraint-template.yaml`

Apply the policy:

`kubectl apply -f required-labels.yaml`

To see it in action, attempt to create a namespace that does not conform to the policy:

`kubectl create namespace test`

You should see a denied message, because the namespace does not contain the appropriate labels