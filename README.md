# Pyoro

C++ w/ SFML (unfinished) attempt at Pyoro

This is a educational non-commerical project for the purpose of getting better at C++.

[Here is a video of creating it.](https://www.youtube.com/watch?v=kzaj-PKvoLU)

Originally, this was meant be a race with my friend for creating the game "Pyoro".

![alt text](https://i.ytimg.com/vi/OXBODCkyuHQ/hqdefault.jpg "The original game")

It a game where you play a bird-like thing and have to collect seeds falling from the sky.

If the seeds touch the tiles, the tile is destroyed. It is game over when you are touched by a seed.

My friend and I thought that it would take only a few hours, maybe one to three maximum. But no, it took so much longer. In fact, after 14+ hours for coding for it in my free time after two weekish, I still had no finished it.

It was a huge eye opener for me. The game looked so simple, but it really wasn't. From here on, all my probjects I have worked on for a loong time, and have never questioned it.

Here is what it ended up looking like:

![alt text](http://puu.sh/o9ldO/205a5717ad.png "Result" )

You can walk left and right and press Z to fire out your tongue, and the seeds can be collected, and a fancy flashing text showing the score appears for a few seconds.




## Building and Running

### Windows (Visual Studio)

The easiest way to build is to use [vcpkg](https://vcpkg.io/en/index.html) and install dependencies through this.

```bash
vcpkg install sfml
vcpkg integrate install
```

Then open the Visual Studio project file to build and run.

### Linux

#### Pre-requisites

Install Vcpkg and other required packages using your distribution's package manager:

```sh
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh

# These are required to build some packages
sudo apt install cmake make autoconf libtool pkg-config

# The following are required for SFML
sudo apt install libx11-dev xorg-dev freeglut3-dev libudev-dev
```

Ensure paths are set correctly:

```sh
export VCPKG_ROOT=/path/to/vcpkg
export PATH=$VCPKG_ROOT:$PATH
```

RECOMMENDED: Add the above lines to your `.bashrc` or `.zshrc` file:

```sh
echo 'export VCPKG_ROOT=/path/to/vcpkg' >> ~/.bashrc
echo 'export PATH=$VCPKG_ROOT:$PATH' >> ~/.bashrc
```

#### Build and Run

To build, at the root of the project:

```sh
vcpkg install # First time only
sh scripts/build.sh
```

To run, at the root of the project:

```sh
sh scripts/run.sh
```

To build and run in release mode, simply add the `release` suffix:

```sh
sh scripts/build.sh release
sh scripts/run.sh release
```
