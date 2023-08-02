# Comparison repository for GlueX amplitude models

_Notes for the discussions are taken [here](https://hackmd.io/@QHYjhejHTIWXL2MltV3WNQ/r17prtBo3) on HackMD. Current state of the symbolic implementation can be found on [redeboer.github.io/gluex-amplitude](https://redeboer.github.io/gluex-amplitude)._

## Installation

### C++ implementation

This repository comes with [AmpTools](https://github.com/mashephe/AmpTools) as a submodule. If you clone this repository as:

```shell
git clone https://github.com/redeboer/gluex-amplitude --recurse-submodules
```

you should get AmpTools as well. Navigate to [`extern/AmpTools`](./extern/AmpTools) for further build instructions. Additionally, you need to have ROOT installed. Official installation instructions can be found [here](https://root.cern/install), but alternatively, you can install ROOT in your conda environment (see [Python implementation](#python-implementation)) as follows:

```shell
conda activate gluex-amplitude
conda install root -c conda-forge
```

The benefit of AmpTools as a sub-module and installing ROOT into the conda environment is that you have out-of-the-box [language navigation in VSCode](https://code.visualstudio.com/docs/cpp/cpp-ide#_navigate-source-code).

To build all source code, you first need to compile AmpTools. Either do this by cloning AmpTools and following the instructions, or with:

```shell
cd extern/AmpTools
make
```

You can then compile the code for this repository by navigating back to the root directory (`cd ../../`) and running:

```
make
```

### Python implementation

Install Conda (recommended: [Miniconda](https://docs.conda.io/en/latest/miniconda.html#linux-installers)), then just create a Conda environment from [`environment.yml`](./environment.yml):

```shell
conda env create
conda activate gluex-amplitude
pre-commit install --install-hooks  # optional
```

The Python implementation mainly consists of Jupyter notebooks located under the [`docs`](./docs) folder. It's best to view, run, and edit them with VSCode or with

```shell
jupyter lab
```

You can also run all notebooks and render them as static HTML pages with [Jupyter Book](https://jupyterbook.org) as follows:

```shell
jb build docs/ -W
```

Open `docs/_build/html/index.html` to view the resulting HTML pages. In VSCode, you can view the output HTML files by searching for "Live Preview: Start Server" through the [command pallette](https://code.visualstudio.com/api/ux-guidelines/command-palette) (`Ctrl+Shift+P`).
