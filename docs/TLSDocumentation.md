# PSec TLS Documentation
The certificates and keys in the `keys` directory are used for the TLS 1.2 connections between distributed host machines in our system as well as the KPS. 

### TLS Architecture
A high level overview of this architecture is that the KPS is the central certificate authority and has a self-signed certificate that all host machines in our system trust and have a copy of. The KPS signs the certificates of all distributed host machines in our system so that each distributed host can establish a secure connection with other distributed hosts. Each distributed host validates the certificate of the other party (writes it to a file called `TLSCertReceived.pem` and then verifies it is signed by KPS) before sending data through a secure TLS channel. 

### Key Regeneration Instructions
These keys and certificates can be regenerated as follows:

```shell
cd keys/

openssl genrsa -out KPS.key 2048 #Creates KPS public and private key
openssl req -new -x509 -days 7300 -key KPS.key -sha256 -extensions v3_ca -out KPS.crt -subj "/C=US/ST=California/CN=KPS" #Create KPS root certificate (self signed with KPS key)

openssl genrsa -out dstHost.key 2048 #Creates dstHost public and private key
openssl req -sha256 -new -key dstHost.key -out dstHost.csr -subj "/C=US/ST=California/CN=distHost" #Creates CSR (certificate signing request that is used to request SSL certificate from KPS) for distributed host with the key that is stored is the distributed hosts key to contact it.
openssl x509 -sha256 -req -in dstHost.csr -CA KPS.crt -CAkey KPS.key -CAcreateserial -out dstHost.crt -days 7300 #Uses KPS keys to sign the dstHost CSR and make it an official certificate

openssl genrsa -out dstHost2.key 2048 #Creates dstHost2 public and private key
openssl req -sha256 -new -key dstHost2.key -out dstHost2.csr -subj "/C=US/ST=California/CN=distHost2" #Creates CSR (certificate signing request that is used to request SSL certificate from KPS) for distributed host 2 with the key that is stored is the distributed hosts 2 key to contact it.
openssl x509 -sha256 -req -in dstHost2.csr -CA KPS.crt -CAkey KPS.key -CAcreateserial -out dstHost2.crt -days 7300 #Uses KPS keys to sign the dstHost CSR and make it an official certificate

#Convert crt files to PEM files
openssl x509 -in KPS.crt -out KPS.pem -outform PEM
openssl x509 -in dstHost.crt -out dstHost.pem -outform PEM
openssl x509 -in dstHost2.crt -out dstHost2.pem -outform PEM

openssl verify -CAfile KPS.crt dstHost.crt #Verify dstHost certificate
openssl verify -CAfile KPS.crt dstHost2.crt #Verify dstHost2 certificate

```

