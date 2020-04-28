# PSec Repo Installation

Build Instructions Below:

```shell
git clone https://github.com/ShivKushwah/PSec.git
cd PSec/
git fetch --all
git submodule init
git submodule update --recursive
cd Submodule/P/
git submodule init
git submodule update --recursive
# if dotnet and JRE are not installed, do below steps to install
wget -q https://packages.microsoft.com/config/ubuntu/18.04/packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo add-apt-repository universe
sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install dotnet-sdk-2.2
sudo apt-get install default-jre
# endif
./Bld/build-compiler.sh
cd .. && cd ..
mkdir build
```

In order to run sample programs, follow [this](Running.md) next.