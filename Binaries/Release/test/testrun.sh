#!/bin/bash

rm *.gcda
rm ./profile/data/.gcda

mkdir testreport
mkdir profile
mkdir profile/data
mkdir profile/genhtml


ORIGPREFIX="$GCOV_PREFIX"
ORIGSTRIP="$GCOV_PREFIX_STRIP"

export GCOV_PREFIX=./profile/data
export GCOV_PREFIX_STRIP=8


./test -xml -o TestResult.xml


mv *.xml ./testreport
mv *.html ./testreport

mv *.gcno ./profile/data
mv *.gcda ./profile/data

lcov --capture --directory profile/data --output-file profile/coverage.info
genhtml profile/coverage.info --output-directory profile/genhtml

export GCOV_PREFIX="$GCOV_PREFIX"
export GCOV_PREFIX_STRIP="$GCOV_PREFIX_STRIP"
