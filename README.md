# c-project

## git flow

### 1. How it works

#### 1.1. Develop and Main Branches

Instead of a single `main` branch (which used to be called `master` branch), **git-flow** uses a couple of branches to versionate a project:
1. `main` branch: stores the official release history
2. `develop` branch: serves as an integration branch for features (it's also useful to tag all commits in the `main` branch with a version number).

The first step is integrating the `main` with a `develop` branch, so you need to create the empty `develop` branch locally and push it to the server with:
```bash
# old way
git branch develop
git push -u origin develop
```

When using the git-flow extension library, executing `git flow init` on an existing repo will create the `develop` branch:
```bash
git flow init
# Initialized empty Git repository in ~/project/.git/
# No branches exist yet. Base branches must be created now.
# Branch name for production releases: [master]
# Branch name for "next release" development: [develop]
#
#
# How to name your supporting branch prefixes?
# Feature branches? [feature/]
# Release branches? [release/]
# Hotfix branches? [hotfix/]
# Support branches? [support/]
# Version tag prefix? []


# git branch
# * develop
#  master
```

### 2. Feature Branches
Each new *feature* should reside in its own branch, which can be pushed to the central repository. But, instead of branching off of master, feature branches use `develop` as their parent branch. When a feature is complete, it gets merged back into `develop`.

**Plase Note**: Features should never interact directly with master.

Feature branches combined with the `develop` branch is known as the **Feature Branch Workflow**.

#### 2.1. Creating a feature branch
Off course, you need to replace `[feature-branch-name]` with a valid branch name (i.e. `adt-integration`, `gui`, `contacts`, ...).

```bash
# without git-flow
git checkout develop
git checkout -b [feature-branch-name]

# with git-flow
git flow feature start [feature-branch-name]

# e. i. create a feature called 'adt-list'
git flow feature start adt-list 
# Switched to a new branch 'feature/adt-list'
#
# Summary of actions:
# - A new branch 'feature/adt-list' was created, based on 'develop'
# - You are now on branch 'feature/adt-list'
#
# Now, start committing on your feature. When done, use:
#
#      git flow feature finish adt-list
```

```bash

git flow feature start adt-list
# Switched to a new branch 'feature/adt-list'
#
# Summary of actions:
# - A new branch 'feature/adt-list' was created, based on 'develop'
# - You are now on branch 'feature/adt-list'
#
# Now, start committing on your feature. When done, use:
#
#      git flow feature finish adt-list

git add .

git commit -m "fixed something"

git push --set-upstream origin feature/adt-list

git add .

git commit -m "fixed something else"
# git add & commit all you need

git flow feature finish adt-list
# Switched to branch 'develop'
# Merge made by the 'recursive' strategy.
# ...
# To https://github.com/PitPietro/c-project
#  - [deleted]         feature/adt-list
# Deleted branch feature/adt-list (was d8038a2).
# 
# Summary of actions:
# - The feature branch 'feature/adt-list' was merged into 'develop'
# - Feature branch 'feature/adt-list' has been locally deleted; it has been remotely deleted from 'origin'
# - You are now on branch 'develop'

git push -u origin develop
# Enumerating objects: 19, done.
# Counting objects: 100% (19/19), done.
# Delta compression using up to 8 threads
# Compressing objects: 100% (15/15), done.
# Writing objects: 100% (15/15), 3.33 KiB | 3.33 MiB/s, done.
# Total 15 (delta 11), reused 0 (delta 0)
# remote: Resolving deltas: 100% (11/11), completed with 3 local objects.
# remote: 
# remote: Create a pull request for 'develop' on GitHub by visiting:
# remote:      https://github.com/PitPietro/c-project/pull/new/develop
# remote: 
# To https://github.com/PitPietro/c-project
#  * [new branch]      develop -> develop
# Branch 'develop' set up to track remote branch 'develop' from 'origin'.

```