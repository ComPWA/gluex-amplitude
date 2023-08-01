

# Comparison repository for GlueX amplitude models

_Notes for the discussions are taken [here](https://hackmd.io/@QHYjhejHTIWXL2MltV3WNQ/r17prtBo3) on HackMD._

Intensity function for two-pseudoscalar system:

$$
I(\Omega,\Phi)=2\kappa\sum_{k}\left((1-P_{\gamma})\left[\sum_{l,m}[l]_{m;k}^{(-)}\Re[Z_{l}^{m}(\Omega,\Phi)]\right]^2 \right. +(1-P_{\gamma})\left[\sum_{l,m}[l]_{m;k}^{(+)}\Im[Z_{l}^{m}(\Omega,\Phi)]\right]^2 \\ \left.+(1+P_{\gamma})\left[\sum_{l,m}[l]_{m;k}^{(+)}\Re[Z_{l}^{m}(\Omega,\Phi)]\right]^2+(1+P_{\gamma})\left[\sum_{l,m}[l]_{m;k}^{(-)}\Im[Z_{l}^{m}(\Omega,\Phi)]\right]^{2}\right)\label{eqn:zlm_intensity}
$$

where $Z_{l}^{m}(\Omega,\Phi)=Y_{l}^{m}e^{-i\Phi}$ is a phase-rotated spherical harmonic, $\Omega$ is the solid angle, $\Phi$ is the angle between the production and polarization planes,  $P_{\gamma}$ is the polarization magnitude, $[l]$ are the partial wave amplitudes, $m$ is the associated m-projection, $k$ refers to a spin flip ($k=1$) or non-flip ($k=0$) at the nucleon vertex, and $\kappa$ is an overall phase space factor.
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
