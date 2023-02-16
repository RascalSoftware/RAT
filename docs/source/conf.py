# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------
# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
import os
import sys

# -- Project information -----------------------------------------------------
# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
exclude_patterns = []
current_dir = os.path.dirname(os.path.abspath(__file__))
matlab_src_dir = os.path.abspath(os.path.join(current_dir, '..','..'))
sys.path.insert(0, matlab_src_dir)

project = 'RAT'
copyright = '2022, Arwel Hughes,Sethu Pastula'
author = 'Arwel Hughes,Sethu Pastula'

# The full version, including alpha/beta/rc tags
with open(os.path.join(matlab_src_dir, 'version.txt'), 'r') as version_file:
    release = version_file.read()

# -- General configuration ---------------------------------------------------
extensions = ['sphinxcontrib.matlab', 'sphinx.ext.autodoc', 'sphinx_design']

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# -- Options for HTML output -------------------------------------------------
#set primary_domain = 'matlab'
primary_domain = 'mat'
# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
html_theme =  'sphinx_rtd_theme'
bgcolor = 'white'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
pygments_dark_style  = 'monokai'

html_logo = 'images/ratLogo.png'

html_theme_options = { 'logo_only': True }

rst_prolog = """
.. |RAT banner| image:: images/ratBanner.png
    :alt: RAT banner
"""