#!/usr/bin/perl

# scoretable.pl
#
# Takes the scores.txt from Rick Umali's Tetris, and dumps it with 
# a human-readable time.

# USAGE: ./scoretable.pl < scores.txt

# The scores.txt file contains:
# 1293244545 0 1
# 1293245269 14260 4
# 1293418884 2280 2
# 1293419560 13500 4

# The output of this program looks like:
# 1: Fri Dec 24 21:35:45 2010     0
# 2: Fri Dec 24 21:47:49 2010     14260
# 3: Sun Dec 26 22:01:24 2010     2280
# 4: Sun Dec 26 22:12:40 2010     13500

# NOTE: This program does NOT print out the level information
$count = 0;
while (<>) {
	$count++;
	@F = split(' ');
	print "$count: " . localtime($F[0]) . "\t$F[1]\n";
}
