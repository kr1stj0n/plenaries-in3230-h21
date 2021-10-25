#!/bin/sh

# Improve your workflow

git_push() {
    git add .
    git commit -m "changes"
    git push
}


git_pull() {
        local vm_ip="www.xx.yy.zz"

        # this command will automatically run upon connecting to the host
        CMD="cd oblig;
             git pull"
        ssh debian@$vm_ip $CMD

        echo "Whoa! Why haven't I used this before?"
}

# main() method
main() {
    git push
    git pull
}

# Call the main function here
main
