import os
import shutil
import sys

sys.path.insert(0, os.path.abspath('..'))
DOCS_PATH = os.path.abspath(os.path.dirname(__file__))
VERSION_FILE = os.path.join(DOCS_PATH, '..', 'version.txt')

ref = 'master'

with open(VERSION_FILE, 'r') as version_file:
    version = version_file.read()

if len(sys.argv) > 1 and sys.argv[1].strip().endswith(version):
    ref = version

BUILD_PATH = os.path.join(DOCS_PATH, 'build', 'html')
WEB_PATH = os.path.join(DOCS_PATH, '_web', ref)

if os.path.isdir(WEB_PATH):
    shutil.rmtree(WEB_PATH, ignore_errors=True)

shutil.copytree(BUILD_PATH, WEB_PATH, ignore=shutil.ignore_patterns('.buildinfo', 'objects.inv', '.doctrees', 
                                                                    '_sphinx_design_static'))

if ref == version:
    INDEX_FILE = os.path.join(DOCS_PATH, '_web', 'index.html')
    data = [
        '<!DOCTYPE html>\n',
        '<html>\n',
        '  <head>\n',
        f'    <title>Redirecting to https://reflectivity-algorithms-toolbox.github.io/RAT/{ref}/</title>\n',
        '    <meta charset="utf-8">\n',
        f'    <meta http-equiv="refresh" content="0; URL=https://reflectivity-algorithms-toolbox.github.io/RAT/{ref}/index.html">\n',
        f'    <link rel="canonical" href="https://reflectivity-algorithms-toolbox.github.io/RAT/{ref}/index.html">\n',
        '  </head>\n',
        '</html>',
    ]

    with open(INDEX_FILE, 'w') as index_file:
        index_file.writelines(data)
