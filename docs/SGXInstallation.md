# Intel SGX Installation
This installation process was tested on new Azure Confidential Compute Instances (Standard DC2s\_v2 instances with 2 vcpus and 8 GiB memory) running on 3.7GHz Intel Xeon E-2176G Processors with SGX technology on Ubuntu 18.04. For ease of installation, create 2 virtual machines that are connected to the same virtual network where the first VM has a local IP address of 10.0.0.4 while the second one has a local IP address of 10.0.0.5.

After this installation process, Intel SGX should work with both simulation and hardware mode programs.

### Install SGX Packages on Docker
```shell
# Tested on a fresh Azure instance with username shivendra
# Initial directory is home directory
mkdir Research
cd Research
mkdir Intel-SGX-Installation
cd Intel-SGX-Installation
git clone https://github.com/intel/linux-sgx-driver.git
cd linux-sgx-driver
git checkout 4505f07271ed82230fce55b8d0d820dbc7a27c5a
dpkg-query -s linux-headers-$(uname -r)
sudo apt-get install linux-headers-$(uname -r)
# Install make
sudo apt install make      
# Install gcc
sudo apt update
sudo apt install build-essential
# Continue with SGX installation
make
sudo mkdir -p "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"
sudo cp isgx.ko "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"
sudo sh -c "cat /etc/modules | grep -Fxq isgx || echo isgx >> /etc/modules"
sudo /sbin/depmod
sudo /sbin/modprobe isgx
cd ..
git clone https://github.com/intel/linux-sgx.git
cd linux-sgx
git checkout 9671c99941814c57be575cbfebc9fe64a05533a4
# Install unzip
sudo apt-get update
sudo apt-get install zip unzip
# Continue with SGX installation
make preparation
# Following https://docs.docker.com/engine/install/ubuntu/ to download docker
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io
sudo docker run hello-world
sudo groupadd docker
sudo usermod -aG docker $USER
newgrp docker 
# Following https://docs.docker.com/compose/install/ to download docker compose
sudo curl -L "https://github.com/docker/compose/releases/download/1.27.4/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
docker-compose --version
# We should be in linux-sgx directory currently
cd docker/build
```

Next, you need to modify the following files:
- `vim` into `docker-compose.yml`, `build_and_run_aesm_docker.sh`, and `build_and_run_sample_docker.sh`
- Replace all instance of "/dev/sgx/enclave" with "/dev/isgx" and remove all instances of "/dev/sgx/provision" and "--device=/dev/sgx/provision" in `docker-compose.yml`, `build_and_run_aesm_docker.sh`, and `build_and_run_sample_docker.sh`
- Add to `build_and_run_sample_docker.sh` the following command: “— network host” and “--cap-add=SYS_PTRACE --security-opt seccomp=unconfined”. The final command should be `docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined --env http_proxy --env https_proxy --network host --device=/dev/isgx -v aesmd-socket:/var/run/aesmd -it sgx_sample`

To test the installation,
- Run `./build_and_run_aesm_docker.sh`
- Wait until you see the following:
```
Successfully built 264facef24c0
Successfully tagged sgx_aesm:latest
aesmd-socket
The path of system bundle: System Bundle
ecdsa_quote_service_bundle_name:2.0.0
epid_quote_service_bundle_name:2.0.0
le_launch_service_bundle_name:2.0.0
linux_network_service_bundle_name:2.0.0
pce_service_bundle_name:2.0.0
quote_ex_service_bundle_name:2.0.0
system_bundle:4.0.0
```
- In separate terminal (need to relogin and re-ssh), run `./build_and_run_sample_docker.sh`

### Next Steps
In order to build the repo, follow [this](RepoInstallation.md) next. For consistency, clone the repo into the Research folder created in the previous section.

### Troubleshooting
- If you receiving the following error
```
aesmd-socket
docker: Error response from daemon: error gathering device information while adding custom device "/dev/isgx": no such file or directory.
ERRO[0000] error waiting for container: context canceled 
```
- You need to restart the machine. Then, hit stop, and turn it on again.
- Then, you need to reinstall the driver
```shell
cd Research/Intel-SGX-Installation/linux-sgx-driver/
# Uninstall driver
sudo /sbin/modprobe -r isgx
sudo rm -rf "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"
sudo /sbin/depmod
sudo /bin/sed -i '/^isgx$/d' /etc/modules
make clean
# Reinstall
make
sudo /sbin/depmod
sudo /sbin/modprobe isgx
```