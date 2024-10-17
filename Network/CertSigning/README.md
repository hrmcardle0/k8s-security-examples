# Certificate Signing

Kubernetes natively provides the ability to validate a CSR and create a signed certificate based on the request. This involves creating a `CertificateSigningRequest` resource and passing it the CSR

## Files

`tls-svc-csr.yml` - CertificateSigningRequest that contains a the CSR as well as user-defined uses for the certificate

## Usage

In the `tls-svc-csr.yml` file, replace the `request` field with your base64 CSR. Then, apply:

`kubectl apply -f tls-svc-csr.yml` to apply the request.

Next, approve the request:

`kubectl certificate approve tls-svc-csr`

This then generates and issues a certificate which can be gotten by viewing the full `CertificateSigningRequest` yaml:

`k get csr tls-svc-csr -o yaml`