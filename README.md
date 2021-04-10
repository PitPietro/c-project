# c-project

## git flow

### 1. How it works

#### 1.1. Develop and Main Branches

Instead of a single `main` branch (which used to be called ``main`` branch), **git-flow** uses a couple of branches to versionate a project:
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
# Branch name for production releases: [`master`]
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
#  main
```

### 2. Feature Branches
Each new *feature* should reside in its own branch, which can be pushed to the central repository. But, instead of branching off of `main`, feature branches use `develop` as their parent branch. When a feature is complete, it gets merged back into `develop`.

**Plase Note**: Features should never interact directly with `main`.

Feature branches combined with the `develop` branch is known as the **Feature Branch Workflow**.

#### 2.1. Create a feature branch
In the snippet below, off course, you need to replace `[feature-branch-name]` with a valid branch name (i.e. `adt-integration`, `gui`, `contacts`, ...).

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

#### 2.2. Finish a feature branch
Merge the `[feature-branch-name]` branch into `develop`.

```bash
git add .
git commit -m "fixed something"

# at the first push, you need to set the remote branch
git push --set-upstream origin feature/[feature-branch-name]

# e. i. push a feature called 'adt-list'
git push --set-upstream origin feature/adt-list

# make all the commits you need to complete the development of the branch
git add .
git commit -m "fixed something else"
git push
# ...

# complete the feature and merge into develop

# without git-flow
git checkout develop
git merge [feature-branch-name]

# with git-flow
git flow feature finish [feature-branch-name]

# e.i. finish a feature called 'adt-list'
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

# push the updated develop branch
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

### 3. Release Branches
Once `develop` has enough features for a release, you need to fork a `release` branch off of `develop`. By creating this branch, you starts the next *release cycle*: so no new features can be added after this point (only bug fixes, documentation generation, and other release-oriented tasks should go in this branch).
Once it's ready to ship, `release` branch gets merged into `main` and tagged with a version number. In addition, it should be merged back into `develop`, which may have progressed since the release was initiated.

Using a dedicated branch to prepare releases makes it possible for one team to publish the current release while another team continues working on features for the next release. It also creates well-defined phases of development.

Just like `feature` branches, `release` branches are based on `develop` branch too:

```bash
# start a release branch

# without git-flow
git checkout develop
git checkout -b release/[version-number]
# git checkout -b release/0.1.0

# with git-flow
git flow release start [version-number]
# git flow release start 0.1.0
```

Once the release is ready to ship, you'll merge it into `main` and `develop`, then the `release` branch will be deleted. It's important to merge back into `develop` because updates may have been added to the `release` branch and they need to be accessible to new features.

```bash
# finish a release branch

# without git-flow
git checkout main
git merge release/[version-number]
# git merge release/0.1.0

# with git-flow
git flow release finish '[version-number]'
# git flow release finish '0.1.0'
```

### 4.Hotfix Branches
`hotfix` branches (maintenance) quickly patch production releases. They're very similar to `release` and `feature` branches except they're based on `main` instead of `develop`.
It's the only branch that should fork directly off of `main`. As soon as the fix is complete, it should be merged into both `main` and `develop` (or the current `release` branch), and `main` should be tagged with an updated version number.

Having a dedicated line of development for bug fixes lets your team address issues without interrupting the rest of the workflow or waiting for the next release cycle. Maintenance branches are *ad hoc* release branches that work directly with `main`.

```bash
# start an hotfix branch

# without git-flow
git checkout main
git checkout -b [hotfix-branch]
# git checkout -b avatar-animation

# with git-flow
git flow hotfix start [hotfix-branch]
# git flow hotfix start avatar-animation

# finish an hotfix branch

# without git-flow
git checkout main
git merge [hotfix-branch]
git checkout develop
git merge [hotfix-branch]
git branch -D [hotfix-branch]

# with git-flow
git flow hotfix finish [hotfix-branch]
```

## Reference
- [git-flow Workflow by Atlassian](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow)