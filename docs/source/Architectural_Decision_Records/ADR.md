**Alexandrian pattern**

# Introduction

-   Prologue (Summary)

-   Discussion (Context)

-   Solution (Decision)

-   Consequences (Results)

# Specifics

-   Prologue (Summary)

    -   Statement to summarize:

        -   In the context of (use case)\
            facing (concern)\
            we decided for (option)\
            to achieve (quality)\
            accepting (downside).

-   Discussion (Context)

    -   Explain the forces at play (technical, political, social,
        project).

    -   This is the story explaining the problem we are looking to
        resolve.

-   Solution

    -   Explain how the decision will solve the problem.

-   Consequences

    -   Explain the results of the decision over the long term.

    -   Did it work, not work, was changed, upgraded, etc.

**TLDR: This record contains justifications, reasons as to why something
had to be done, the way it was done, and how to improve on it (as of
July 2022)**

# Decision Record 1: Using Anvil as a webhook and Pull Request trigger for merge checks

# Introduction

[Anvil](https://anvil.softeng-support.ac.uk/) is a research software
testing platform built by STFC (Science and Technology Facilities
Council) to run tests on a range of platforms in an automated manner.
Anvil is based on Jenkins, a famous DevOps tool, which helps to automate
the mundane tasks of running tests, compilation, etc.

RAT Toolbox is a CLI application in MATLAB which needs a test suite in
an automated manner and Jenkins proved to be a worthy tool for this job
after talks between Lamar, Martyn and Arwel.

With Anvil being run on Jenkins, it is decided that Anvil is an
excellent choice to manage the webhooks and merge checks.

# Specifics

## Discussion

RAT Toolbox is going to be an open-source data analysis software for
Neutron Reflectivity calculations. Once it has become public, it
attracts a wide range of contributors, especially on GitHub. It is
important that the contributors follow certain instructions to NOT break
the code. To ensure that, every time a contributor tries to commit code
into the repository through a pull request, it is decided that the
repository needs to be put through a series of automated tasks to ensure
nothing has been changed in a way that could break the code or result in
unexpected outputs.

## Solution

The whole thing can be automated using a Jenkins pipeline with Anvil as
a trigger and manager for the webhooks and pull requests, respectively.
Anvil is available to GitHub repositories as a GitHub App that can be
'downloaded' into desired repositories from GitHub Marketplace. This
allows Anvil to have proper rights and settings to tether the Pull
Requests to an instance of Jenkins that builds the job in a freshly
created Virtual Machine to make sure everything works in order.

## Consequences

This idea seems to be working very well for now and the foreseeable
future as long as Anvil and its dependencies (STFC Cloud) are also
functional. Although, occasional system-wide shutdown causes disruptions
in availability of the nodes in which case developer needs to manually
login to the machine to ssh back to the Jenkins instance of Anvil.
Contact Alan Kyffin for more details on this.

# Decision Record 2: Converting MATLAB code to C++

# Introduction

RAT is made of MATLAB and so was RasCal. Arwel decided to introduce some
major performance upgrades to RAT by converting MATLAB code base to C++.
A MATLAB app called MATLAB Coder can be used to automatically convert
the MATLAB code into C++ as opposed to the mundane task of
hand-scripting MATLAB to C++.

# Specifics

"C++ averages a processing speed that is over **500 times** faster than
Matlab code. Not only does this apply for this code, but this can also
be applied for any other code comparison between Matlab and C++
MEX-files " ([Andrews](https://core.ac.uk/download/pdf/19152615.pdf))

To be able to use C++ MEX files, MATLAB coder can integrate the
generated code into the projects as source code, static libraries, or
dynamic libraries. The generated code can also be packaged as a
MEX-function for use in MATLAB. Moreover, the generated code is readable
and portable.

## Consequences

MATLAB coder is a fantastic way to do this task, especially with great
technical support from MathWorks. I**mproved speed but introduced a
little bit of complexity to the code.** This could be a stable,
long-standing approach to converting MATLAB code to C++, but more
efficient converters could be on their way, especially with OpenAI's
[Codex models](https://www.infoq.com/news/2021/08/openai-codex/)

## Decision Record 3: Using MATLAB's Project environment for internal MATLAB workflow

## Introduction

MATLAB's Project is a scalable environment where one can manage,
customize tasks, put all the files in one place and use version control
from MATLAB. Using such an environment can help reduce time and effort
in simple tasks like running tests, checks etc. So, Arwel and Sethu has
decided to make use of this by putting RAT into this scalable project
environment.

## Specifics

RAT has many folders with many files in it. Project environment has a
dependency checker which analyses the relations between all the folders
and it also helps prevent unexpected folder/file 'moves' which might
bring dependency issues. Moreover, the Project environment can run tests
which is useful, especially while working with the DevOps side. It can
ease the process of code generation since selected files can do selected
tasks. RAT has a file which adds folders to the path so that they can be
accessed straight away while a program is running but this is a manual
task. With the Project environment, the task can be automated using a
startup file that does whatever needs to be done when the Project
environment is instantiated. MATLAB Coder can directly accept a .prj
(project file similar file type for Matlab Coder) and convert desired
files to C++.

## Consequences

The Project environment eases many mundane tasks hence enabling
automation and solving the problem of adding paths in a separate file
and updating it as new files are being added. The Project environment is
a relatively new feature from MATLAB, with time it can only get better
and assist RAT with more useful tools.

**Update**: The Project does get complicated especially if a developer
pushes one commit from the Project environment (GUI) which is,
surprising, highly recommended and the other from the command line. It
gets even worse as multiple commits from multiple people follow the
same. This would cause problems of merge conflicts if one were not
careful.

**Update**:

Project env has been removed since it is too underdeveloped/too messy to
act as a rigid base for version control and continuous integration. It
is very prone to merge conflicts. Especially, when working from
different OS.

## Decision Record 4: Enabling users to use custom scripts from multiple languages

## Introduction

The idea of custom scripts is a jail-break way of achieving extreme
flexibility in terms of data analysis of desired inputs. Having the
flexibility of being able to support languages like python, MATLAB and
C++ really multiplies the users and also provides the feasibility of
adapting to new features by simply adding those corresponding libraries
to the code base. Irrespective of the language used, the compiler adapts
to the language and automatically manages the compatibility issues.

**Why**

Flexibility. A user does not have to code in an unfamiliar language to
use the software. Also, increases the user base.

**Specifics**

As of July 2022, RAT supports 2 famous languages for the custom models
feature. Matlab and C++. The way it works is as follows:

1.  Converting user's cpp file into a .dll or .so dynamic lib (in short)

2.  Using an open-source project called dylib to help extract the user
    function from the dynamic library made by user and then pass the
    inputs to that. (Check dev docs for more)

3.  Get the outputs back.

## Future

There are plans to add Python to the list of supported languages once
the current iteration is stable enough.

## Decision Record 5: Increasing Error Tolerance to ignore the slight differences in Mex functions in Unit Tests

## Introduction

There was an error just beyond the RelTol (relative tolerance) limit set
by Arwel which is 4.44089209850063e-15. There are 3 test cases that
crossed the tolerance limit. One of the failed tests has an error of
1.30104260698261e-17.

**Why**

Such micro-errors may creep in from compilers and may vary by OS
(Operating System) as well. Since the current experience with error
tolerances is too limited, the ideal tolerance shall be set in the later
stages of development.

**How**

The tolerances can be set for each test file in the testSuite folder of
the RAT home directory. Tolerances can also be set by each test as well.
This gives flexibility if one of the functions acts mysteriously.

## Decision Record 6: Use C API to manage custom scripts instead of C++ API for Matlab and back to C++

**Introduction**\
The whole RAT toolbox is *technically a* C++ codebase and in order to
manage custom scripts from users, the RAT needs to talk to the user
script's language and make a connection to seek the variables from the
script.

## History

At first, Arwel and Sethu decided to create a C++ class that constructs
MATLAB Engine pointer which can be referenced to a feval() command to
exercise in MATLAB workspace. This feature helps us exercise user's
scripts and get them back to C++. The problem with this approach is that
MATLAB Coder is internally embedded with MATLAB Data array and t*hese
classes are really bad when we include engine.h as a header in our C++.*
A total week of trying to make it work in multiple only concluded that
the approach is impossible.

As a plan B, Arwel suggested Sethu to create a class that inherits from
Handle class. This MATLAB class creates an instance of MATLAB Engine
which can started,closed and used to execute a MATLAB function. This
superficially looks absurd especially with executing MATLAB from MATLAB
but the main reason to do this was to have the Handle class converted to
a pointer with Coder's help. Sethu and Arwel got to a really good stage
with this and then one fine morning, Arwel found out that the MATLAB
coder allows only one instance of handle class to go through which means
we cannot parallelize over multiple instances. This meant we could not
use the MATLAB class anymore.\
\
This brought us to a new blended idea of using C function in C++ to
eliminate the need for MATLAB in between. This is currently being worked
on but god help us.

## Update:

God did help us. This method didn't work out but this work can be used
to compile RAT successfully! (A diff use currently being planned)

**ss**
