#!/bin/bash

sudo dnf update
sudo dnf install -y g++ python3 libopenblas-dev
sudo dnf install -y gtest

echo "All necessary packages have been installed!"
