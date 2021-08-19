# RAT
Reflectivity Algorithms Toolbox for Rascal


# Github Workflow 

 We follow [Github Flow](https://guides.github.com/introduction/flow/index.html) using branches for new work and pull requests for verifying the work.
 
 
 The steps for a new piece of work can be summarised as follows:
   1. Push up or create an issue 
   2. Create a branch from master using the naming convention described at *Naming Branches*
   3. Do the work and commit changes to the newly created branch. On commit, the pre-commit framework will run, it will check all your changes for formatting, linting, and perform static code analysis. 
   4. Push the branch regularly to GitHub to make sure no work is accidentally lost.
   5. When you are finished with the work, ensure that all of the unit tests, documentation tests and system tests if necessary pass on your own machine
   6. Open a pull request (Pull Requests) from the GitHub branches page
   7. This will check with the buildservers for cross-platform compatibility
   8. If any issues come up, continue working on your branch and push to GitHub - the pull request will update automatically
 
# Naming Branches
When naming public branches that will be pushed to GitHub, please follow the convention of 'issuenumber_short_description'. This will allow others to discover what the branch is for (issue number) and quickly know what is being done there (short description).

#### Example: '32125_extract_load_from_rilap'


# Pull Requests
For an general overview of using pull requests on GitHub look here.

When creating a pull request you should:

1. Ensure that the title succinctly describes the changes so it is easy to read on the overview page
2. The title should not contain the issue number
3. [Reference the issue which the pull request is closing](https://github.com/blog/1506-closing-issues-via-pull-requests), using one of [these](https://help.github.com/articles/closing-issues-via-commit-messages) keywords
4. State the user and facility (if relevant) who initiated the original issue, if they are named in the issue. Please do not put full email addresses on the Pull Request, as it is publicly accessible. If the user would not be easily identified by someone picking up the ticket, be prepared to act as a point of contact with the reporter.
5. Ensure the description follows the format described by the Pull Request template below

A good example from Mantid Project is [This](https://github.com/mantidproject/mantid/pull/18713)

Recommended reading: [How to Write the Perfect Pull Request](https://github.com/blog/1943-how-to-write-the-perfect-pull-request)

For further information about the review process see reviewing a pull request.

# Pull Request Template

#### To test:

Fixes #xxxx.

#### Reviewer
* Please comment on the following (full description):

#### Code Review
* Is the code of an acceptable quality?
* Does the code conform to the coding standards?
* Are the unit tests small and test the class in isolation?
* If there is GUI work does it follow the GUI standards?
* If there are changes in the release notes then do they describe the changes appropriately?
#### Functional Tests
* Do changes function as described? Add comments below that describe the tests performed?
* Do the changes handle unexpected situations, e.g. bad input?
* Has the relevant (user and developer) documentation been added/updated?
* Does everything look good? Mark the review as Approve.
