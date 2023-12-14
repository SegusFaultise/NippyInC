#!/bin/bash

git add --a

read -p "Enter commit msg: " commit_msg

git commit -m "$commit_msg"
git push
