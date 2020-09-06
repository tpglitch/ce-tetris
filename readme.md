# CE Tetris

Tetris made for the CE graphic calculators, compatible with the TI-83 Premium CE.

# Compile

Precompiled binaries can be found [here](https://github.com/samipourquoi/ce-tetris/releases/).

Make sure you have the [CE toolchain](https://github.com/CE-Programming/toolchain/tree/master) installed. If you are on macOS 10.15+, you must compile the LLVM version yourself [here](https://github.com/CE-Programming/toolchain/wiki/Building-the-toolchain#building-the-llvm-branch).

First clone the repository:
```shell
$ git clone https://github.com/samipourquoi/ce-tetris.git
$ cd ce-tetris
```

Then, run this command to compile:
```shell
$ make
```

The binaries will be at `bin/TETRIS.8xp`. Use [TI Connect CE](https://education.ti.com/en/products/computer-software/ti-connect-ce-sw) to send it to your CE, or use an emulator such as [CEmu](https://github.com/CE-Programming/CEmu).
