Contributing to RAT
===================
You can contribute to the Reflectivity Algorithms Toolbox (RAT) project by either opening an issue 
(please check that the issue has not been reported already) or submitting a pull request.

Create Developer Environment
----------------------------
The MATLAB IDE is recommended for developement, the following toolboxes are required for RAT:

- MATLAB Coder
- MATLAB Compiler
- Parallel Computing Toolbox

After intalling the IDE, proceed by creating a fork of the RAT repo, then clone the fork

    git clone --recurse-submodules https://github.com/<username>/RAT.git
    cd RAT

And finally create a separate branch to begin work

    git checkout -b new-feature

Commit changes with brief but clear commit messages and once feature is complete submit a 
[pull request](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork) via GitHub. 
Ensure to rebase your branch to include the latest changes on your branch and resolve possible merge conflicts.


Unit-testing and coverage
-------------------------
Proper documentation and unit tests is highly recommended. To run unit tests and generate coverage report use TestRATScript.m. 
The code coverage report should be generated to a htmlcov folder after the tests are completed. 

Documentation
-------------
The documentation is currently in the docs folder. Look at the docs [README](docs/README.md) for more info
