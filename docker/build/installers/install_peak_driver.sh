#!/usr/bin/env bash

###############################################################################
# Copyright 2020 The Edith Author. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###############################################################################

# Fail on first error.
set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

tar xzvf peak-linux-driver-8.9.3.tar.gz

# pushd peak-linux-driver-8.9.3
# make -j2
# make install
# popd

# rm -rf peak-linux-driver-8.9.3
