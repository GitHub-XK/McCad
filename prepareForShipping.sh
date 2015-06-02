#!/bin/sh

#
# remove all developer content unneccessary for the end user
#

rm McCad.creator
rm McCad.files
rm McCad.config
rm McCad.includes
rm -rf assets
find . -name ".svn" -exec rm -rf {} \;
rm prepareForShipping.sh
echo "done"
