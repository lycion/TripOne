Installing BU from sources and from Ubuntu repos
======================================

Really quick guide to get your triponed/qt up and running

Installing binaries from Tripone Unlimited Official BU repositories
------------------------------------------------------------------

This is valid for Ubuntu Trusty 14.04 and Xenial 16.04. The repos will provide binaries and debug symbols for 4 different architectures: i386, amd64, armhf and arm64.


```sh
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:tripone-unlimited/bu-ppa
sudo apt-get update
sudo apt-get install triponed tripone-qt (# on headlesse server just install triponed)
```

If you are moving from another Tripone compatible implementations (Core, Classic, XT) to BU, make sure to follow this plan before moving:

- backup your wallet (if any)
- make a backup of the `~/.tripone` dir
- if you have installed Core via apt using the ppa tripone core repo:
   - `sudo apt-get remove tripone*`
   - `sudo rm /etc/apt/sources.list.d/tripone-*.*`
- if you have compile Core from source:
   - `cd /path/where/the/code/is/stored`
   - `sudo make uninstall`

Other than the PPA repo mentioned above, serving stable version of Tripone Unlimited, we have set up another repository which will contain binaries built from source code snapshots of the BU development branch (`0.12.1bu` currently). If you're interested in testing the latest features included in BU but still not released just add this repository to your system. Use this commands:

```sh
sudo add-apt-repository ppa:tripone-unlimited/bu-ppa-nightly
sudo apt-get update
sudo apt-get install triponed tripone-qt
```
In case you installed both repos on your system, take into account that binaries belonging to the `nightly` will supersede the ones of the stable one.

Compiling and installing binaries source:
---------------------------------------

This is valid for Ubuntu Trusty 14.04 and Xenial 16.04.

### Installing pre-reqs

If you need `triponed` and `tripone-cli` only:

```sh
sudo apt-get install git
sudo apt-get install build-essential libtool autotools-dev
sudo apt-get install automake pkg-config libssl-dev libevent-dev bsdmainutils libboost-all-dev
```

If you want also to install `tripone-qt`:

```sh
sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler libqrencode
```

This is step is optional, to be done only if you need if you need wallet functionality and you want your wallet created with an earlier version of triponed

```sh
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:tripone-unlimited/bu-ppa
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev
```

### Fetching the code and compile it


```sh
mkdir -p ~/src
cd ~/src
git clone https://github.com/TripOne/TripOne.git bu-src
cd bu-src
git checkout <desired_branch/tag>   # e.g. git checkout 0.12.1c
./autogen.sh
# if you want a plain triponed binary without GUI withou wallet support, use this configure line:
./configure --disable-wallet --without-gui
# otherwise if you need tripone-qt just issue a plain ./configure
export NUMCPUS=`grep -c '^processor' /proc/cpuinfo`
make -j$NUMCPUS
sudo make install #(will place them in /usr/local/bin, this is step is to be considered optional.)
```

### Miscellaneous


- `strip(1)` your binaries, triponed will get a lot smaller, from 73MB to 4.3MB)
- execute `triponed` using the `-daemon` option, bash will fork tripone process without cluttering the stdout

