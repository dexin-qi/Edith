# DustinKsi -- Edith :rocket:
[![Doc Status](https://travis-ci.org/dustinksi/Edith.svg?branch=master)](https://dustinksi.github.io/Edith/)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://github.com/dustinksi/Edith/blob/master/LICENSE)

#### Description
Edith is an Robotic Operation System framework developed by DustinKsi, Youibot Robotic Technology inc.:cn:

![Edith RT logo](docs/images/EidthLogo.png)

Marvel movies :film_projector: not only have world-class special effects, they are also inspiring. In "Avengers 4", Iron Man sacrificed himself for a peaceful world:church:; And in "Spider-Man: Far From Home", Iron Man left this meme "Even dead, I'm the hero":dark_sunglasses:. As a great fan of Iron Man, I decided to design a robot system inspired by Iron Man's armor.
Finally, thanks to Baidu's Apollo open-source framework: CyberRT, EdithRT is designed based on that excellent framework.:rocket:

```
╔═╗┬  ┬┌─┐┌┐┌  ╔╦╗┌─┐┌─┐┌┬┐   ╦┌┬┐  ╔╦╗┬ ┬┌─┐  ╦ ╦┌─┐┬─┐┌─┐
║╣ └┐┌┘├┤ │││   ║║├┤ ├─┤ ││   ║│││   ║ ├─┤├┤   ╠═╣├┤ ├┬┘│ │
╚═╝ └┘ └─┘┘└┘  ═╩╝└─┘┴ ┴─┴┘┘  ╩┴ ┴   ╩ ┴ ┴└─┘  ╩ ╩└─┘┴└─└─┘
```
"Even Dead, I'm The Hero" --- Spider-Man: Far From Home

Welcome to Edith's GitHub page! :rocket:


## Table of Contents

1. [Getting Started](#getting-started)
2. [Installation](#Installation)

## Getting Started
Learn how to use Edith at its [Doxygen site](http://dustinksi.cn/edith/docs).

## Installation
```bash
./[your_edith_root]/docker/script/edith_start.sh [-l/-t/-h]
./[your_edith_root]/docker/script/edith_into.sh
```
****
If you launch edith's docker at the first time, you should build peak can driver first.
```bash
cd /tmp/installers/peak-linux-driver-8.9.3
make -j2
sudo make install
```
After build the canbus's driver, build edith project.
```bash
cd /edith
mkdir build && cd build
cmake .. -DBUILD_EDITH_TEST=false
make -j4
sudo make install
bash scripts/gen_py_proto.sh
bash scripts/gen_py_interface.sh
```
:warning: If your abseil library is not at correct version, Edith may not work well.
****
```bash
docker commit [container_ID] [repo_name]/[image_name]:[image_tag]
```
There are also some useful docker order:
```bash
docker save -o [package_name].tar [repo_name]/[image_name]:[image_tag]
docker load -i [package_name].tar
```
:exclamation: Everytime you change something in the docker container, donnot forget commit it!!!
****

## Questions

You are welcome to submit questions and bug reports as [GitHub Issues](https://github.com/dustinksi/Edith/issues).

## Copyright and License

Edith is provided under the [Apache-2.0 license](https://github.com/dustinksi/Edith/blob/master/LICENSE).

## Connect with me
* [Have suggestions for our GitHub page?](https://github.com/dustinksi/Edith/issues)
* Interested in our turnKey solutions or partnering with us Mail me at: [dustinksi@126.com](mailto:dustinksi@126.com)