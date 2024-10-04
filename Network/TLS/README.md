# TLS

TLS is transport layer security that is the successor to SSL. It encrypts all traffic in-transit. In our k8s environment, traffic can be encrypted many different ways, such as traffic targeting pods, services and ingresses. 

Traffic that targets a `Service` would have the TLS cert presented by the pod backend, while traffic that targets an `Ingress` would be presented the TLS cert by the Ingress controller backend. This can be setup a variety of different ways, but the easiest way to demonstrate this is to use the [Ingress-NGINX](https://github.com/kubernetes/ingress-nginx) controller. This controller is developed by Kubernetes and exists as a pod within your cluster. In standard cluster setups (exluding cloud CNIs), traffic is routed to the controller pod which handles the TLS process, and forwards to backend pods in plaintext. 

# Files

`ingress-dep.yaml` - deployment of an nginx ingress pod

`ingress-svc.yaml` - service that points to the nginx pod

`ingress-tls-secret.yaml` - secret of type `kubernetes.io/tls` that holds the TLS cert and private key for the ingress to use

`tls-ingress.yaml` - ingress that uses the TLS cert/key for TLS offload and points to our ingress-svc that ultimately forwards to the pod

## Usage

Apply this example by first generating a key and cert:

`openssl req -nodes -new -x509 -keyout tls.key -out tls.crt -subj "/CN=ingress.test"`

Generate base64 strings of the cert and keys

`cat tls.crt | sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' | sed '/-BEGIN CERTIFICATE-/d' | sed '/-END CERTIFICATE-/d' | base64`

`cat tls.key | sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' | sed '/-BEGIN CERTIFICATE-/d' | sed '/-END CERTIFICATE-/d' | base64`

Add these values into the appropriate sections in the `ingress-tls-secret.yaml`

Apply the secret first. Then, create the deployment of the pods in `ingress-dep.yaml`, and the `Service` that points to it. Finally, apply the Ingress specified in `tls-ingress.yaml`. 

This will deploy a simple the ingress. You will need to change the type of the deployed Ingress `ingress-nginx-controller` to NodePort as it defaults to LoadBalancer.
