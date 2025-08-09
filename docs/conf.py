from sphinx_api_relink.helpers import get_execution_mode

author = "GlueX PWA team"
copyright = "2023"
default_role = "py:obj"
exclude_patterns = [
    "_build",
    "**.ipynb_checkpoints",
    "**.virtual_documents",
]
extensions = [
    "myst_nb",
    "sphinx_book_theme",
    "sphinx_codeautolink",
    "sphinx_copybutton",
    "sphinx_design",
    "sphinx_external_toc",
    "sphinx_togglebutton",
    "sphinx.ext.intersphinx",
]
html_sourcelink_suffix = ""
html_favicon = "_static/favicon.ico"
html_show_copyright = False
html_sourcelink_suffix = ""
html_theme = "sphinx_book_theme"
html_theme_options = {
    "launch_buttons": {
        "notebook_interface": "jupyterlab",
        "binderhub_url": "https://mybinder.org",
        "colab_url": "https://colab.research.google.com",
    },
    "path_to_docs": "docs",
    "repository_branch": "main",
    "repository_url": "https://github.com/ComPWA/gluex-amplitude",
    "use_download_button": False,
    "use_fullscreen_button": False,
    "use_edit_page_button": True,
    "use_issues_button": True,
    "use_repository_button": True,
    "use_source_button": True,
}
intersphinx_mapping = {
    "ampform": ("https://ampform.readthedocs.io/stable", None),
    "IPython": ("https://ipython.readthedocs.io/en/stable", None),
    "ipywidgets": ("https://ipywidgets.readthedocs.io/en/stable", None),
    "matplotlib": ("https://matplotlib.org/stable", None),
    "numpy": ("https://numpy.org/doc/stable", None),
    "python": ("https://docs.python.org/3", None),
    "qrules": ("https://qrules.readthedocs.io/stable", None),
    "sympy": ("https://docs.sympy.org/latest", None),
}
html_title = "GlueX amplitude model"
linkcheck_ignore = [
    "https://doi.org/10.1103/PhysRevD.100.054017",
]
myst_enable_extensions = [
    "amsmath",
    "colon_fence",
    "dollarmath",
    "substitution",
]
myst_heading_anchors = 2
myst_update_mathjax = False
nb_execution_allow_errors = False
nb_execution_mode = get_execution_mode()
nb_execution_show_tb = True
nb_execution_timeout = -1
nb_output_stderr = "show"
nitpicky = True
primary_domain = "py"
pygments_style = "sphinx"
suppress_warnings = ["myst.domains"]
use_multitoc_numbering = True
