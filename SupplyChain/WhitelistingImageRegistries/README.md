# Whitelisting Registeries

[Gatekeeper](https://github.com/open-policy-agent/gatekeeper) can be used to restrict which registries the container runtime is allowed to pull from, ensuring that images are only pulled from a secure, trusted source.

This example uses Gatekeeper's rego policies to allow the K8s user to pass in values, which are whitelisted registries.

## Files

`allowedreposTemplate.yml` - constraint template that defines the actual rego policy which inspects the container spec

`whitelist-dockerhub.yml` - instantiation of the allowed-repos template which puts the policy into effect

`dockerhub-busybox.yml` - example pod that will run successfully as it is pulling from Docker

`gcr-busybox.yml` - example pod that will fail tlo run because it attempts to pull from GCR

## Usage

First apply the contstraint template:

`k apply -f allowedreposTemplate.yml`

Nexts, apply the policy itself based on the template:

`k apply -f whitelist-dockerhub.yml`

Attempt to apply either the Docker or GCR example and observe the behavior