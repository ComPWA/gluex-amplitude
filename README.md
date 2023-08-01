# Comparison repository for GlueX amplitude models

_Notes for the discussions are taken [here](https://hackmd.io/@QHYjhejHTIWXL2MltV3WNQ/r17prtBo3) on HackMD._

## Installation

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
jb build docs/
```

Open `docs/_build/html/index.html` to view the resulting HTML pages. In VSCode, you can view the output HTML files by searching for "Live Preview: Start Server" through the [command pallette](https://code.visualstudio.com/api/ux-guidelines/command-palette) (`Ctrl+Shift+P`).
