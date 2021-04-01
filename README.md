# c-project

## git flow
```bash
git flow init

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