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

# Install Miniconda3.
CONDA_PATH="/usr/local/miniconda"
INSTALLER="Miniconda3-latest-Linux-x86_64.sh"
wget "https://repo.continuum.io/miniconda/${INSTALLER}"
bash "${INSTALLER}" -b -p "${CONDA_PATH}"
# Update conda base to the latest.
"${CONDA_PATH}/bin/conda" update -n base -c defaults conda

# Init python envs.
"${CONDA_PATH}/bin/conda" env update -f py27_conda.yaml
"${CONDA_PATH}/bin/conda" env update -f py37_conda.yaml

# Clean up.
rm -f "${INSTALLER}"
